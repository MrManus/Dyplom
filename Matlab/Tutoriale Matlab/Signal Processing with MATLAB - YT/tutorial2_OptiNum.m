%Tutorial z yt - "Signal Processing with MATLAB" autor: Opti-Num Solutions 
%

close all
clear all
clc

%stworzenie losowego sygna³u ¿eby odtworzæ operacje z tutorialu
n = 0:0.1:500;
o = sqrt(0.5);                                  %odchylenie
mi = 0;                                         %wartosc srednia

zaklocenie = mi + o.*randn(1,length(n));        %mój losowy sygna³

figure
plot(n,zaklocenie)
xlim([0 5])

[pks,locs] = findpeaks(zaklocenie);

hold on
plot(n(locs),pks,'vr', 'MarkerFaceColor','r')
xlim([0 5])