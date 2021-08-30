close all
clear all
clc

fs = 44000;
T = 1/fs;
N = 1000;
t = [0:N-1]*T;
f1 = 329;
f2 = f1*2;

syg1 = sin(2*pi*f1*t);
syg2 = sin(2*pi*f2*t-pi/2);

czysty_sin = syg1 + syg2;



sigma = 0.2;
szum = sigma*randn(1,N);
zaszumiony = czysty_sin + szum;

figure

subplot(5,1,5)
plot(syg1);
hold on
plot(syg2, 'r');
grid on
ylim([-1.2 1.2])

subplot(5,1,1);
plot(t,szum)
% ylim([-1.2 1.2])
grid on
title('Szum')

subplot(5,1,2);
plot(t,zaszumiony,'r')
% hold on
% plot(t,czysty_sin)
% % ylim([-1.2 1.2])
grid on
title('Wygenerowany Sinus')


%% Determine the autocorrelation function
[rxx, lags] = xcorr(czysty_sin,czysty_sin);
subplot(5,1,3);
plot(lags, rxx)
xlabel('Lag')
ylabel('Correlation Measure')
title('Autokorelacja czystego sygna³u')
grid on

[rxx2, lags2] = xcorr(zaszumiony,zaszumiony);
subplot(5,1,4);
plot(lags2, rxx2)
xlabel('Lag')
ylabel('Correlation Measure')
title('Autokorelacja zaszumionego sygna³u')
grid on
