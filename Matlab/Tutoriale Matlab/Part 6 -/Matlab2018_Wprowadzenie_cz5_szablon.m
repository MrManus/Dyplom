%% Generacja sygna³ów losowych
% Generacja sygna³ów losowych o rozk³adzie normalnym i Chi2
%
% Autor: Piotr Burnos
% Data: 20.02.2018

%%
clear all; close all; clc

%% Generacja sygna³ów losowych 
%

% parametry próbkowania
fpr = 1000;                 % czêstotliwoœæ próbkowania 1kHz, N=1k
t0 = 1.5;
 
t= ........ ;                   % wektor czasu
    .........;
    
df= ........ ; 
f= ........ ;                   % wektor czêstotliwoœci (potrzebny przy analizie fft)


% typ=1 - rozk³ad normalny, typ=2 - rozk³ad Chi-kwadrat
typ=1;

switch(typ)
    case(1)
        u=0; s=1;           % u - wartoœæ oczekiwana, s - odchylenie standardowe
        x= ........ ;       % generujemy sygna³ losowy o rozk³adzie normalnym
    case (2)
        L=4;                % L - liczba stopni swobody
        x= ........ ;       % generujemy sygna³ losowy o rozk³adzie chi-kwadrat
    otherwise
        return;
end
X= ........ ;               % fft wygenerowanego sygna³u

% rysunki:
figure; subplot(211); plot(t,x); 
grid on; xlabel('Czas [s]');ylabel('Wartoœæ zmiennej losowej [-]');title(['Sygna³ stochastyczny']);
subplot(212); stem(f(1,(1:N/2)),X(1,(1:N/2)));legend(['FFT']); xlabel('Czêstotliwoœæ [Hz]'); ylabel('Wartoœæ [-]'); grid on;


%% Obliczanie parametrów sygna³u (momentów)
% 

% wartoœæ œrednia
xu= ........ ;
disp(['wartoœæ srednia = ' num2str(xu) ])

%odchylenie standardowe
xs= ........ ;
disp ........ ;

% wariancja
xs2= ........ ;       % lub xs2=xs^2;
 ........ ;

% wartoœæ œredniokwadratowa
xu2= ........ ;
 ........ ;

% mediana
xm= ........ ;
 ........ ;

% moda
xM= ........ ;
 ........ ;

%% Wyznaczenie histogramu
% 

% histogram
K=100;                  %liczba przedzia³ów
[Ni,xx] = hist(x, K)  ;     % histogram, histcounts
figure;  bar(xx, Ni, 1) ;

%% Wyznaczenie estymaty fgp - na podstawie histogramu
%

a= min(x) ; b= max(x); 
Z = (b - a);

p1 = (Ni * K) / (N * Z)

% rysujemy fgp
figure;
.......... ;
    ...............;
    
%% Porównanie estymaty fgp z rozk³adem teoretycznym 
% 

switch(typ)
    case(1)
        Xf=-5:0.01:5;
        f=normpdf(Xf,u,s);         % rozk³ad teoretyczny funkcja 'normpdf'
    case(2)
        Xf=-5:0.01:15;
        f=chi2pdf(Xf,L);           % rozk³ad teoretyczny Chi-kwadrat
    otherwise
        return;
end
hold on; plot(Xf,f,'r:');
legend('rozk³ad empiryczny','rozk³ad teoretyczny');

%% Naniesienie na rysunki wartoœci oblicznonych parametrów (œrednia, mediana i moda)
%

plot(xu,0,'^g');
plot(xm,0,'^r');
plot(xM,0,'^b');

switch(typ)
    case(1)
        line([xu xu], [0 normpdf(xu,u,s)],'color','g')
        line([xm xm], [0 normpdf(xm,u,s)],'color','r')
        line([xM xM], [0 normpdf(xM,u,s)],'color','r')
    case(2)
        line([xu xu], [0 chi2pdf(xu,L)],'color','g')
        line([xm xm], [0 chi2pdf(xm,L)],'color','r')
        line([xM xM], [0 chi2pdf(xM,L)],'color','b')
    otherwise
         return;
end
legend('rozk³ad empiryczny ','rozk³ad teoretyczny','wartoœæ œrednia','mediana','moda')


%% Obliczenie dystrybuanty jako ca³ki z fgp
%

dx= ........ ;              % krok ca³kowania

% ca³kujemy metod¹ prostok¹tów
 ........ ;
      ........ ;
       ........ ;

   
% dystrybuanty teoretyczne dla rozk³adu normalnego i chi-kwadrat
switch(typ)
    case(1)
        Pt=normcdf(xx,u,s);        % dystrybuanta teoretyczna; funkcja 'normcdf'
    case(2)
        Pt=chi2cdf(xx,L);          % dystrybuanta teoretyczna; funkcja 'chi2cdf'
    otherwise
        return;
end

% porównanie wyniku ca³kowania z dystrybuant¹ teoretyczn¹
figure;  ........ ;

