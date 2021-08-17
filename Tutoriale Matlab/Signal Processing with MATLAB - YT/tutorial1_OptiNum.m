%Tutorial z yt - "Signal Processing with MATLAB" autor: Opti-Num Solutions 
%Generacja podsawowych sygna³ów

close all
clear all 
clear all


Fs = 2000;                  %Czêstotliwoœæ próbkowania
T = 1/Fs;                   %Okres
t = 0:T:1;                  %czas 1 sekunda trwania
f = 5;                      %50 Hz




sqWave = square(2*pi*f*t);          %Generowanie fali prostok¹tnej
sawtoothWave = sawtooth(2*pi*f*t);  %Generowanie sygna³u pi³owego
sineWave = sin(2*pi*f*t);
chirpSig = chirp(t,0, 0.5, 150);

figure('Name', 'Generacja podstawowych sygna³ów', 'NumberTitle','off');
subplot(2,2,1)
plot(t,sqWave);
title('Square Wave');
%xlim([0 0.7])
ylim([-1.2 1.2])
grid on;

subplot(2,2,2)
%figure('Name', 'Sawtooth Wave', 'NumberTitle','off');
plot(t,sawtoothWave);
title('Sawtooth Wave');
%xlim([0 0.7])
ylim([-1.2 1.2])
grid on;

subplot(2,2,3)
plot(t,sineWave);
title('Sine Wave');
%xlim([0 0.7])
ylim([-1.2 1.2])
grid on;

subplot(2,2,4)
plot(t,chirpSig);
title('Linear Chirp Signal');
xlim([0 0.35])
ylim([-1.2 1.2])
grid on;