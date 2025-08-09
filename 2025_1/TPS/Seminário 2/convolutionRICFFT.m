function xhat = compactric(x, C)
  L = length(x) / C;
  xhat = zeros(1, C);
  for c = 0:C-1
    for l = 0:L-1
      a = c + 1 + l * C;
      xhat(c+1) = xhat(c+1) + x(a);
    end
  end
end
%% SIGNALS
clear; clc; close all;

% Parameters just for signal generation
fs = 32;                    
t = 0:1/fs:5;            
x = sin(2*pi*1*t) + sin(2*pi*2*t) + sin(2*pi*3*t) + sin(2*pi*4*t);
h = sin(2*pi*5*t) + sin(2*pi*6*t) + sin(2*pi*7*t) + sin(2*pi*8*t);

% L = convolution size, upped to 2-power for the FFT
L = 2^nextpow2(length(x)+length(h)-1); 

C = L/2;
n = 0:L-1;

%% RIC FFT for x
% Zero-padding
x_padded = [x, zeros(1, L - length(x))];
% FFT original 
X = fft(x_padded);
mag_orig = abs(X)/L;
f = (0:L-1)*(fs/L);

% RIC Compactation
x_comp = compactric(x_padded, C);
X_comp = fft(x_comp);

%shift keying
x_shifted = x_padded .* exp(-1j*2*pi*n/L); 
x_shifted_comp = compactric(x_shifted, C);
X_shifted_comp = fft(x_shifted_comp);

% Print first 10 elements to check shift keying
disp('First 10 values X_padded:');
disp(X(1:10));

disp('First 10 values X_comp:');
disp(X_comp(1:10));

disp('First 10 values X_shifted_comp');
disp(X_shifted_comp(1:10));

% Allocate frequency vectors
X_comp_adjusted = zeros(1, L);        % even positions
X_shifted_comp_adjusted = zeros(1, L);     % odd positions
X_comp_adjusted(1:2:end) = X_comp;
X_shifted_comp_adjusted(2:2:end) = X_shifted_comp;

% Get indices of valid (non-zero) values
even_indices = 1:2: L;  % even DFT positions
odd_indices  = 2:2:L;  % odd DFT positions

% Frequency axes
f_even = (even_indices - 1) * (fs/L);
f_odd  = (odd_indices - 1) * (fs/L);

% Get only non-zero magnitudes
mag_even = abs(X_comp_adjusted(even_indices)) / L;
mag_odd  = abs(X_shifted_comp_adjusted(odd_indices)) / L;

% Plotting
figure;
stem(f_even, mag_even, 'b', 'LineWidth', 1.5); hold on;
stem(f_odd, mag_odd, 'r', 'LineWidth', 1.5); hold on;
plot(f, mag_orig, 'm', 'LineWidth',1.5);
xlabel('Frequency (Hz)');
ylabel('Magnitude');
legend('Even-indexed frequencies (X_{comp})', 'Odd-indexed frequencies (X_{shifted})','FFT Original');
title('X: Even RIC and Odd RIC vs FFT Frequencies');
grid on;
xlim([0 10]);

%% RIC FFT for h

h_padded = [h, zeros(1, L - length(h))];

h_comp = compactric(h_padded, C);
h_shifted = h_padded .* exp(-1j*2*pi*n/L);
h_shifted_comp = compactric(h_shifted, C);
H_comp = fft(h_comp);
H_shifted_comp = fft(h_shifted_comp);

H = fft(h_padded);
magH_orig = abs(H)/L;

% Allocate frequency vectors
H_comp_adjusted = zeros(1, L);        % even positions
H_shifted_comp_adjusted = zeros(1, L);     % odd positions 

H_comp_adjusted(1:2:end) = H_comp;
H_shifted_comp_adjusted(2:2:end) = H_shifted_comp;

% Get only non-zero magnitudes
magH_even = abs(H_comp_adjusted(even_indices)) / L;
magH_odd  = abs(H_shifted_comp_adjusted(odd_indices)) / L;

% Plotting
figure;
stem(f_even, magH_even, 'b', 'LineWidth', 1.5); hold on;
stem(f_odd, magH_odd, 'r', 'LineWidth', 1.5); hold on;
plot(f, magH_orig, 'm', 'LineWidth',1.5);
xlabel('Frequency (Hz)');
ylabel('Magnitude');
legend('Even-indexed frequencies (H_{comp})', 'Odd-indexed frequencies (H_{shifted})','FFT Original');
title('H: Even RIC and Odd RIC vs FFT Frequencies');
grid on;
xlim([0 10]);

%% Convolution Theorem 

% Frequency-domain multiplication (RIC style)
Y = X_comp_adjusted .* H_comp_adjusted + X_shifted_comp_adjusted .* H_shifted_comp_adjusted;

% Back to time domain
y_ric = ifft(Y);

% For comparison: regular convolution
conv_ref = conv(x, h);
conv_ref = [conv_ref, zeros(1, L - length(conv_ref))];

% Plot comparison
figure;
subplot(2,1,1);
plot(real(y_ric), 'b', 'LineWidth', 1.5); hold on;
plot(conv_ref, '--r', 'LineWidth', 1.5);
legend('RIC-based convolution', 'MATLAB conv()');
xlabel('Sample index');
ylabel('Amplitude');
title('Comparison: RIC Convolution vs Time-Domain conv()');
grid on;
xlim([0,L]);

subplot(2,1,2);
stem(real(y_ric), 'b', 'LineWidth', 1.5); hold on;
stem(conv_ref, '--r', 'LineWidth', 1.5);
legend('RIC-based convolution', 'MATLAB conv()');
xlabel('Sample index');
ylabel('Amplitude');
title('Comparison: RIC Convolution vs Time-Domain conv()');
grid on;
xlim([0,L]);

%% Error comparison
error = real(y_ric) - conv_ref;
figure;
plot(error, 'k');
title('Error between RIC convolution and MATLAB conv');
xlabel('Sample index');
ylabel('Amplitude Error');
grid on;
