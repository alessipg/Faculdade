%{
 * Copyright 2024 Saulo Jorge Beltrao de Queiroz
 * Licensed under the Apache License, Version 2.0
%}
%pkg load signal % For Octave only
clear; clc; close all;
% RIC DFT algorithm
function xhat = compactric(x, C)
  L = length(x) / C;
  xhat = zeros(1, C);
  for c = 0:C-1
    xhat(c+1) = 0;
    for l = 0:L-1
      xhat(c+1) = xhat(c+1) + x(c + 1 + l * C);
    end
  end
end

% Carregar EEG
EEG = pop_loadset('exemplo.set');
channel = 10;
x = EEG.data(channel, :);
Fs = EEG.srate;
window_length = 2^nextpow2(4 * Fs);       
overlap = round(0.5 * window_length);
p = 11;
q = 9;
C = 2^q;
nfft = 2^p;
L = nfft/C;
frequencies = (0:nfft/2 - 1) * Fs / nfft;

% Frequências de interesse
fmin = 2;
fmax = 45;
freq_idx = find(frequencies >= fmin & frequencies <= fmax);

% Segmentação e janela
[S, ~] = buffer(x, window_length, overlap, 'nodelay');
window = hann(window_length);

% Matriz para FFT
psd_matrix_fft = zeros(nfft, size(S,2));

% Matriz para RIC
psd_matrix_ric = zeros(nfft, size(S,2));

for i = 1:size(S,2)
    seg = S(:,i) .* window;

    % FFT tradicional
    y = fft(seg, nfft);
    psd_fft = abs(y(1:nfft)).^2 / (Fs * sum(window.^2));
    psd_matrix_fft(:,i) = psd_fft;

    % RIC
    xric = compactric(seg, C);
    xric_windowed = xric .* hann(C)';
    Yric = fft(xric_windowed);
    
    % Distribui os valores no espectro final
    Y_full = zeros(1, nfft);
    for cidx = 1:C
        Y_full((cidx-1)*L + 1) = Yric(cidx);
    end

    % calculo da magntude^2 normalizada 
    psd_ric = abs(Y_full(1:nfft)).^2 / (Fs * sum(window.^2));

    psd_matrix_ric(:,i) = psd_ric;
end

% Médias
mean_psd_fft = mean(psd_matrix_fft, 2);
mean_psd_ric = mean(psd_matrix_ric, 2);

scaling_factor = nfft / C;
mean_psd_ric_scaled = mean_psd_ric;% * scaling_factor; %descomentar para tentativa de normalização
psd_db_fft = 10 * log10(mean_psd_fft + eps);
psd_db_ric = 10 * log10(mean_psd_ric_scaled + eps);

% ===> Plot FFT e RIC na mesma janela
figure;
plot(frequencies(freq_idx), psd_db_fft(freq_idx), 'b', 'LineWidth', 1.5); hold on;
plot(frequencies(freq_idx), psd_db_ric(freq_idx), 'r--', 'LineWidth', 1.5); hold off;

legend(sprintf('FFT %d pts', nfft), ...
       sprintf('RIC %d pts', C), ...
       'Location', 'best');
title(sprintf('Canal %d - Welch 2', channel));
xlabel('Frequência (Hz)');
ylabel('Densidade espectral de potência [dB (µV²/Hz)]');
xlim([fmin fmax]);
ylim([-30 20]);
grid on;
set(gca, 'FontSize', 12);
% ===> Cálculo da Relative Band Power (RBP)

% Definição das bandas clássicas do EEG
bands = [0.5 4; 4 8; 8 12; 12 30; 30 45];
band_labels = {'Delta', 'Theta', 'Alpha', 'Beta', 'Gamma'};

% PSD total na faixa de interesse (0.5-45 Hz)
total_idx = find(frequencies >= 0.5 & frequencies <= 45);
psd_total_fft = sum(mean_psd_fft(total_idx));
psd_total_ric = sum(mean_psd_ric(total_idx));

% Inicialização dos vetores de RBP
rbp_fft = zeros(1, size(bands,1));
rbp_ric = zeros(1, size(bands,1));

for b = 1:size(bands,1)
    % Índices da banda atual
    idx = find(frequencies >= bands(b,1) & frequencies <= bands(b,2));
    
    % Somatório da PSD na banda
    psd_band_fft = sum(mean_psd_fft(idx));
    psd_band_ric = sum(mean_psd_ric(idx));
    
    % Cálculo da RBP
    rbp_fft(b) = psd_band_fft / psd_total_fft;
    rbp_ric(b) = psd_band_ric / psd_total_ric;
end

% Cálculo da diferença absoluta
rbp_diff = abs(rbp_fft - rbp_ric);

% Exibição numéricaF
fprintf('\n=== Relative Band Power (RBP) Comparativo ===\n');
fprintf('Banda\t\tFFT\t\tRIC(N/%d)\tDiferença\n',L);
acumulo = 0;
for b = 1:length(band_labels)
    fprintf('%-6s\t\t%.4f\t%.4f\t\t%.4f\n', band_labels{b}, rbp_fft(b), rbp_ric(b), rbp_diff(b));
    acumulo = acumulo + rbp_diff(b);
end
fprintf('Diferença acumulada %.4f\n', acumulo);
