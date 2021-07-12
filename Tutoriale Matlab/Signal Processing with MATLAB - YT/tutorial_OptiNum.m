%Tutorial z yt - "Signal Processing with MATLAB" autor: Opti-Num Solutions 

close all
clear all 
clear all


Fs = 2000;                  %Czêstotliwoœæ próbkowania
T = 1/Fs;                   %Okres
t = 0:T:1;                  %czas 1 sekunda trwania
f = 5;                      %50 Hz




sqWave = square(2*pi*f*t);
plot(t,sqWave);
title('Square Wave');
xlim([0 0.5])
ylim([-1.2 1.2])