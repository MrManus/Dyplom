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
%% synthesise a periodic signal to use as a basic demo
fs = 500;
T = 1/fs;
N = 250; % desired length of signal
t = [0:N-1]*T; %time vector 
f1 = 8; f2=f1*2; 
x = sin(2*pi*f1*t-pi/2) + sin(2*pi*f2*t);
% x = sin(2*pi*f1*t-pi/2);
plot(t, x)
ylabel('Amplitude')
xlabel('Time (seconds)')
title('Synthesised Signal');

%% Zapis do pliku
% data_to_export = single(x);
% dlmwrite('sin_exported.txt',data_to_export,'delimiter',',','precision',9)
% [export_corr, export_lag] = xcorr(data_to_export,data_to_export)
% dlmwrite('corr_exported.txt',export_corr,'delimiter',',','precision',9)
%% Determine the autocorrelation function
[rxx, lags] = xcorr(x,x);
figure
plot(lags, rxx)
xlabel('Lag')
ylabel('Correlation Measure')
title('Auto-correlation Function')
 
%% Illustrate the auto correlation process
%function available from https://dadorran.wordpress.com
illustrate_xcorr(x,x) 

%% Identify most prominent peaks
% Most prominent peak will be at the center of the correlation function
first_peak_loc = length(x) + 1;
 
% Lots of possible ways to identify second prominent peak. Am going to use a crude approach
% relying on some assumed prior knowledge of the signal. Am going to assume
% that the signal has a minimum possible period of .06 seconds = 30 samples;
min_period_in_samples = 30; 
half_min = min_period_in_samples/2 ;
 
seq = rxx;
seq(first_peak_loc-half_min: first_peak_loc+half_min) = min(seq);
figure
plot(lags,rxx,'rx');
hold on
plot(lags,seq)

[max_val, second_peak_loc] = max(seq);
period_in_samples =  abs(second_peak_loc -first_peak_loc)
period = period_in_samples*T
fundamental_frequency = 1/period