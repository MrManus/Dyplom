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
%% powtórne utworzenie sygna³u z sekcji 2 - potrzebny jest wektor t
fs = 500;
T = 1/fs;
N = 250; % desired length of signal
t = [0:N-1]*T; %time vector 

%% Autocorrelation technique can be problematic!
% Consider the following signal
f1 = 8; f2=f1*2; 
x3 = sin(2*pi*f1*t) + 5*sin(2*pi*f2*t);
plot(t, x3)
ylabel('Amplitude')
xlabel('Time (seconds)')
title('Synthesised Signal');
 
[rxx3, lags] = xcorr(x3,x3,'unbiased');
figure
plot(lags, rxx3)
xlabel('Lag')
ylabel('Correlation Measure')
title('Auto-correlation Function')

%% Identify most prominent peaks - KOPIA Z SEKCJI 2
% Most prominent peak will be at the center of the correlation function
first_peak_loc = length(x3) + 1; %x zmienione na x3
 
% Lots of possible ways to identify second prominent peak. Am going to use a crude approach
% relying on some assumed prior knowledge of the signal. Am going to assume
% that the signal has a minimum possible period of .06 seconds = 30 samples;
min_period_in_samples = 30; 
half_min = min_period_in_samples/2 ;
 
seq = rxx3;
seq(first_peak_loc-half_min: first_peak_loc+half_min) = min(seq);
plot(seq)
 
[max_val, second_peak_loc] = max(seq);
period_in_samples =  abs(second_peak_loc -first_peak_loc)