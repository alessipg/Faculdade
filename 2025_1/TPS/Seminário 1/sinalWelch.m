function xhat = compactric(x, C)
    L = length(x) / C;  
    xhat = zeros(1, C);
    for c = 0:C-1
        xhat(c+1) = 0;
        for l = 0:L-1
            xhat(c+1) = xhat(c+1) + x(c + 1 + l * C);
        end
    end
    %xhat = xhat / L;
end
clear; clc; close all;
% === Caminho do arquivo ===
filename = 'exemplo.set';

% === Carregando EEG ===
EEG = pop_loadset(filename);

% === Canal de interesse ===
dados = double(EEG.data(10, :)); 
fs = EEG.srate;

% === FFT tradicional com pwelch ===
q = 11;
p = 10;
nfft = 2^q;
win = 4* fs;               % janela = 4 * fs 
noverlap = win/2;        % 50% de sobreposição
[pxx, f] = pwelch(dados, win, noverlap, nfft, fs);
C = 2^p;  % número de pontos compactados
xhat = compactric(dados, C);  % ainda no tempo!
L = nfft/C;
% Janela para o xhat
win_ric = C/2;            
noverlap_ric = win_ric / 2;

% FFT do sinal compactado com pwelch
[pxxhat, fhat] = pwelch(xhat, win_ric, noverlap_ric, C, fs);
% === Plot ===
figure;
plot(f, 10*log10(pxx), 'b', 'LineWidth', 1.5); hold on;
plot(fhat, 10*log10(pxxhat), 'r--', 'LineWidth', 1.5);
xlabel('Frequência (Hz)');
ylabel('Densidade espectral de potência [dB (µV²/Hz)]');
title('Canal 10 - Welch Matlab');
legend(sprintf('Welch %d pts',nfft), sprintf('RIC %d pts',C), 'Location', 'northeast');
xlim([0 50]);
grid on;
% ===> Cálculo da Relative Band Power (RBP)

% Definição das bandas clássicas do EEG
bands = [0.5 4; 4 8; 8 12; 12 30; 30 45];
band_labels = {'Delta', 'Theta', 'Alpha', 'Beta', 'Gamma'};

% PSD total na faixa de interesse (0.5-45 Hz)
total_idx = find(f >= 0.5 & f <= 45);
psd_total = sum(pxx(total_idx));

total_idx_ric = find(fhat >= 0.5 & fhat <= 45);
psd_total_ric = sum(pxxhat(total_idx_ric));

% Inicialização dos vetores de RBP
rbp = zeros(1, size(bands,1));
rbp_ric = zeros(1, size(bands,1));

for b = 1:size(bands,1)
    % Índices da banda atual
    idx = find(f >= bands(b,1) & f <= bands(b,2));
    idx_ric = find(fhat >= bands(b,1) & fhat <= bands(b,2));
    
    % Somatório da PSD na banda
    psd_band = sum(pxx(idx));
    psd_band_ric = sum(pxxhat(idx_ric));
    
    % Cálculo da RBP
    rbp(b) = psd_band / psd_total;
    rbp_ric(b) = psd_band_ric / psd_total_ric;
end

% Cálculo da diferença absoluta
rbp_diff = abs(rbp - rbp_ric);

% Exibição numérica
fprintf('\n=== Relative Band Power (RBP) Comparativo ===\n');
fprintf('Banda\t\tOriginal\tRIC(N/%d)\tDiferença\n',L);
acumulo = 0;
for b = 1:length(band_labels)
    fprintf('%-6s\t\t%.4f\t\t%.4f\t\t%.4f\n', ...
            band_labels{b}, rbp(b), rbp_ric(b), rbp_diff(b));
    acumulo = acumulo + rbp_diff(b);
end
fprintf('Acumulo %.4f\n', acumulo);