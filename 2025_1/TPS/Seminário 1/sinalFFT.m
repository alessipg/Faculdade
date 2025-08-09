% === CONFIGURAÇÃO INICIAL ===
clear; clc; close all;

% Caminho do arquivo EEG (.set)
filename = 'exemplo.set'; % <-- Substitua pelo nome correto
channel_index = 10;        % Canal de EEG a ser analisado

% === CARREGAR O SINAL COM EEGLAB ===
[ALLEEG, EEG, CURRENTSET] = eeglab;
EEG = pop_loadset(filename);
signal = EEG.data(channel_index, :);

% === PARÂMETROS ===
q = 11;
Nfft = 2^q;                      % Número de pontos da análise
x = signal(1:Nfft);               % Segmento do sinal EEG
p = 9;
C = 2^p;
L = 2^(q-p);
figure;

windowfft = hann(Nfft); 
x_windowedfft = x(1:Nfft) .* windowfft';
yfft=fft(x_windowedfft); 
xhatric=compactric(x(1:Nfft), C);
windowric = hann(C);
xhatwindowedric = xhatric(1:C) .* windowric';
Yric=zeros(1,Nfft);
Yric(Yric == 0) = 10e-8; %assumed noise floor level
Yricaux=fft(xhatwindowedric);
for c = 1:C
    Yric((c-1)*L+1) = Yricaux(c);
end


% === EIXO DE FREQUÊNCIA ===
f = (0:Nfft-1) * (EEG.srate / Nfft);

% === CÁLCULO EM dB (COM OFFSET PARA EVITAR log(0)) ===
offset = 1e-12;
Y_dB = 20 * log10(abs(yfft) + offset);
Yhat2_dB = 20 * log10(abs(Yric) + offset);

% === PLOTAGEM ===

plot(f, Y_dB, 'b', 'LineWidth', 1.5); hold on;
plot(f, Yhat2_dB, 'r--', 'LineWidth', 1.5);
xlabel('Frequência (Hz)');
ylabel('Magnitude (dB)');
title('Canal 10 - FFT vs RIC FFT(Hann)');
legend(sprintf('FFT %d pts',Nfft), sprintf('RIC FFT %d pts',C));
xlim([0 45]);
ylim([0,100]);
grid on;

% === FUNÇÃO COMPACTRIC ===
function xhat = compactric(x, C)
    L = floor(length(x) / C);
    xhat = zeros(1, C);
    for c = 0:C-1
        for l = 0:L-1
            xhat(c+1) = xhat(c+1) + x(c + 1 + l * C);
        end
    end
end
