close all
clear all
clc

a = [0.1:5.1]
b = [0:5]

x = single(a)
y = single(b)

% [c,lags] = xcorr(a,b)

dlmwrite('tabledate.txt',x)