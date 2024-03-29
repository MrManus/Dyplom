%% Generacja sygnałów zdeterminowanych
% Generacja sygnałów monoharminicznego, poliharmonicznego,
% prawieokresowego i przejściowego oraz ich analiza widmowa
%
% Autor: Piotr Burnos
% Data: 20.02.2018

%%
clear all; 
close all;
clc

%% Sygnały zdeterminowane
% Generacja sygnałów zdeterminowanych: mono i poli-harmonicznego, prawie
% okresowego i przejściowego.

% parametry próbkowania

fpr= 1000; dt= 1/fpr;         % częstotliwość próbkowania (dobrana tak by było spełnione twierdzenie o próbkowaniu)
t0= .5;                 % czas obserwacji sygnałów
N= t0/dt;                 % liczba próbek
t= (0:N-1) * dt;                 % wektor czasu

df=fpr/N; f=df*(0:N-1);     %wektor częstotliwości (potrzebny przy analizie fft)

%% parametry sygnałów
%
A1=1; f1=50; fi1=0;         % amplituda, częstotliwość, przesunięcie fazowe
A2=0.5; f2=125; fi2=pi/2;
A3=0.3; f3=200; fi3=0;      
A4=1; f4n=sqrt(6013.543); fi4=0;   %f4 - niewymierna

%% generowanie sygnału monoharmonicznego
%
y1= A1 * sin(2*pi*f1*t + fi1) ;
Y1= 2*abs(fft(y1)) / N ;      % transformata Fourieria

figure(1);
subplot(421); plot(t,y1); grid on; xlabel('Czas [s]');ylabel('Amplituda');title(['Sygnał monoharmoniczny o f=' num2str(f1) 'Hz']);
subplot(422); stem(f(1,(1:N/2)),Y1(1,(1:N/2)));xlabel('Czestotliwość [Hz]'); ylabel('Amplituda'); grid on;

% %% generowanie sygnału poliharmonicznego (trzy harmoniczne f1, f2 i f3)
% %
% y2= ........ ;
% Y2= ........ ;
% 
% subplot(423); plot(t,y2); grid on;xlabel('Czas [s]');ylabel('Amplituda');title(['Sygnał poliharmoniczny o f1=' num2str(f1) 'Hz, ' 'f2=' num2str(f2) 'Hz, ' 'f3=' num2str(f3) 'Hz']);
% subplot(424); stem(f(1,(1:N/2)),Y2(1,(1:N/2)));xlabel('Czestotliwość [Hz]'); ylabel('Amplituda'); grid on;
% 
% %% generowanie sygnału prawie okresowego (dwie harmoniczne f1 i f4n)
% %
% y3= ........ ;
% Y3= ........ ;
% 
% subplot(425); plot(t,y3); grid on;xlabel('Czas [s]');ylabel('Amplituda');title(['Sygnał prawieokresowy o f1=' num2str(f1) 'Hz, ' 'f2=' num2str(f4n) 'Hz']);
% subplot(426); stem(f(1,(1:N/2)),Y3(1,(1:N/2)));xlabel('Czestotliwość [Hz]'); ylabel('Amplituda'); grid on;
% 
% %% generowanie sygnału przejściowego (przez modulację amplitudy sygnału y1)
% %
% y4= ........ ;
% Y4= ........ ;
% 
% subplot(427); plot(t,y4); grid on;xlabel('Czas [s]');ylabel('Amplituda');title(['Sygnał przejściowy o f1=' num2str(f1) 'Hz, ' 'modulowany amplitudowo']);
% subplot(428); stem(f(1,(1:N/2)),Y4(1,(1:N/2)));xlabel('Czestotliwość [Hz]'); ylabel('Amplituda'); grid on;
% 
% 
% 


