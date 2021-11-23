close all
clear all
clc

thining_rate = 200;

[E4_ip, E4_fs] = audioread('trimed_E4_mono192kHz.wav');
E4_signal = E4_ip(1:7680);

[E4_corr,E4_lag] = xcorr(E4_signal,E4_signal);

scarce_E4_corr = E4_corr(1:thining_rate:15359);
scarce_E4_lag = E4_lag(1:thining_rate:15359);

subplot(3,1,1)
plot(E4_signal)

subplot(3,1,2)
plot(E4_lag,E4_corr)

subplot(3,1,3)
plot(scarce_E4_lag,scarce_E4_corr)

%%
[E2_ip, E2_fs] = audioread('trimed_E2_mono192kHz.wav');
E2_signal = E2_ip(1:7680);

[E2_corr,E2_lag] = xcorr(E2_signal,E2_signal);

scarce_E2_corr = E2_corr(1:thining_rate:15359);
scarce_E2_lag = E2_lag(1:thining_rate:15359);

figure
subplot(3,1,1)
plot(E2_signal)

subplot(3,1,2)
plot(E2_lag,E2_corr)

subplot(3,1,3)
plot(scarce_E2_lag,scarce_E2_corr)