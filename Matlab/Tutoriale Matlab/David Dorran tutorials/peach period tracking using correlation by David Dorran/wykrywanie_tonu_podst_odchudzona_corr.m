clc 
clear all
close all

% [E4_ip, E4_fs] = audioread('trimed_E2_mono48kHz.wav');
% [E4_ip, E4_fs] = audioread('trimed_E2_mono96kHz.wav');
% [E4_ip, E4_fs] = audioread('trimed_E2_mono192kHz.wav');
% [E4_ip, E4_fs] = audioread('trimed_E4_mono48kHz.wav');
% [E4_ip, E4_fs] = audioread('trimed_E4_mono96kHz.wav');
[E4_ip, E4_fs] = audioread('trimed_E4_mono192kHz.wav');
probki = [1 :E4_fs];
thining_rate = 20;

[rxx,lag] = xcorr(E4_ip,E4_ip);
corr_sig_len=length(rxx);
lag_sig_len=length(lag);

scarce_rxx = rxx(1:thining_rate:corr_sig_len);
scarce_lag = lag(1:thining_rate:lag_sig_len);

subplot(2,1,1)
plot(probki,E4_ip)
xlim([0,E4_fs])
% title('Sygna³ z gitary dla struny E dla f_s = 48 kHz')
% title('Sygna³ z gitary dla struny E dla f_s = 96 kHz')
% title('Sygna³ z gitary dla struny E dla f_s = 192 kHz')
% title('Sygna³ z gitary dla struny e^1 dla f_s = 48 kHz')
% title('Sygna³ z gitary dla struny e^1 dla f_s = 96 kHz')
title('Sygna³ z gitary dla struny e^1 dla f_s = 192 kHz')
xlabel('Próbki')
ylabel('Amplituda')

subplot(2,1,2)
plot(lag,rxx)
xlim([-2400,2400])
title('Wykresy funkcji autokorelacji i autokorelacji celowanej')
xlabel('OpóŸnienia n')
ylabel('xcorr(n)')
hold on
plot(scarce_lag,scarce_rxx,'r')
hold off
legend({'autokorelacja','autokorelacja celowana'},'Location','southeast','Orientation','horizontal')
% subplot(3,1,3)
% plot(scarce_lag,scarce_rxx)
% xlim([-2400,2400])
% title('Sygna³ powsta³y po obliczeniu funkcji autokorelacji celowanej')
