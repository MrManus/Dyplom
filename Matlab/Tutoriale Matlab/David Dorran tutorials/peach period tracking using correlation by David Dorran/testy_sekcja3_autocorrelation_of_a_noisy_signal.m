%% Using Autocorrelation to track the local period of a signal
% This code is used as part of a youtube video demonstration 
% See http://youtube.com/ddorran
%
% Code available at https://dadorran.wordpress.com       
%
% The following wav file can be downloaded from 
%       https://www.dropbox.com/s/3y25abf1xuqpizj/speech_demo.wav
clc 
clear all
close all
%% powtórne utworzenie sygna³u z sekcji 2
fs = 500;
T = 1/fs;
N = 250; % desired length of signal
t = [0:N-1]*T; %time vector 
f1 = 8; f2=f1*2; 
x = sin(2*pi*f1*t-pi/2) + sin(2*pi*f2*t);
%% Autocorrelation of a noisy signal 
x2 = x + randn(1, length(x))*0.2;
plot(x2)
ylabel('Amplitude')
xlabel('Time (seconds)')
title('Noisy Synthesised Signal');
 
[rxx2 lags] = xcorr(x2,x2);
figure
plot(lags, rxx2)
xlabel('Lag')
ylabel('Correlation Measure')
title('Auto-correlation Function')