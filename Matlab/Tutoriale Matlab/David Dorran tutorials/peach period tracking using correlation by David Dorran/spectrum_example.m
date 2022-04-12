% [E4_ip, Fs] = audioread('trimed_E4_mono192kHz.wav');
[E4_ip, Fs] = audioread('trimed_E2_mono192kHz.wav')

L = 192000;

Y =fft(E4_ip);

P2 = abs(Y/L);
P1 = P2(1:L/2+1);
P1(2:end-1) = 2*P1(2:end-1);



f = Fs*(0:(L/2))/L;
% semilogx(f,20*log(P1)) 
plot(f,P1);
% ylim([-0.005 0.065])
xlim([20 20000])
title('Single-Sided Amplitude Spectrum of X(t)')
xlabel('f (Hz)')
ylabel('|P1(f)|')