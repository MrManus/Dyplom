clc 
close all
clear all

fs = 500;
T = 1/fs;
N = 2000; % desired length of signal
t = [0:N-1]*T; %time vector 
f1 = 8; f2=f1*2; 

test_f = 1;

% x = sin(2*pi*f1*t-pi/2) + sin(2*pi*f2*t);
y = sin(2*pi*f1*t-pi/2);
z = sin(2*pi*f2*t);
x = y+z;

test_sin = sin(2*pi*test_f*t);

figure
plot(t,test_sin)
grid on

% illustrate_xcorr2(x,x) 