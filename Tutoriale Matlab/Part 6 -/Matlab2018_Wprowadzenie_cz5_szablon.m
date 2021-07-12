%% Generacja sygna��w losowych
% Generacja sygna��w losowych o rozk�adzie normalnym i Chi2
%
% Autor: Piotr Burnos
% Data: 20.02.2018

%%
clear all; close all; clc

%% Generacja sygna��w losowych 
%

% parametry pr�bkowania
fpr = 1000;                 % cz�stotliwo�� pr�bkowania 1kHz, N=1k
t0 = 1.5;
 
t= ........ ;                   % wektor czasu
    .........;
    
df= ........ ; 
f= ........ ;                   % wektor cz�stotliwo�ci (potrzebny przy analizie fft)


% typ=1 - rozk�ad normalny, typ=2 - rozk�ad Chi-kwadrat
typ=1;

switch(typ)
    case(1)
        u=0; s=1;           % u - warto�� oczekiwana, s - odchylenie standardowe
        x= ........ ;       % generujemy sygna� losowy o rozk�adzie normalnym
    case (2)
        L=4;                % L - liczba stopni swobody
        x= ........ ;       % generujemy sygna� losowy o rozk�adzie chi-kwadrat
    otherwise
        return;
end
X= ........ ;               % fft wygenerowanego sygna�u

% rysunki:
figure; subplot(211); plot(t,x); 
grid on; xlabel('Czas [s]');ylabel('Warto�� zmiennej losowej [-]');title(['Sygna� stochastyczny']);
subplot(212); stem(f(1,(1:N/2)),X(1,(1:N/2)));legend(['FFT']); xlabel('Cz�stotliwo�� [Hz]'); ylabel('Warto�� [-]'); grid on;


%% Obliczanie parametr�w sygna�u (moment�w)
% 

% warto�� �rednia
xu= ........ ;
disp(['warto�� srednia = ' num2str(xu) ])

%odchylenie standardowe
xs= ........ ;
disp ........ ;

% wariancja
xs2= ........ ;       % lub xs2=xs^2;
 ........ ;

% warto�� �redniokwadratowa
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
K=100;                  %liczba przedzia��w
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
    
%% Por�wnanie estymaty fgp z rozk�adem teoretycznym 
% 

switch(typ)
    case(1)
        Xf=-5:0.01:5;
        f=normpdf(Xf,u,s);         % rozk�ad teoretyczny funkcja 'normpdf'
    case(2)
        Xf=-5:0.01:15;
        f=chi2pdf(Xf,L);           % rozk�ad teoretyczny Chi-kwadrat
    otherwise
        return;
end
hold on; plot(Xf,f,'r:');
legend('rozk�ad empiryczny','rozk�ad teoretyczny');

%% Naniesienie na rysunki warto�ci oblicznonych parametr�w (�rednia, mediana i moda)
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
legend('rozk�ad empiryczny ','rozk�ad teoretyczny','warto�� �rednia','mediana','moda')


%% Obliczenie dystrybuanty jako ca�ki z fgp
%

dx= ........ ;              % krok ca�kowania

% ca�kujemy metod� prostok�t�w
 ........ ;
      ........ ;
       ........ ;

   
% dystrybuanty teoretyczne dla rozk�adu normalnego i chi-kwadrat
switch(typ)
    case(1)
        Pt=normcdf(xx,u,s);        % dystrybuanta teoretyczna; funkcja 'normcdf'
    case(2)
        Pt=chi2cdf(xx,L);          % dystrybuanta teoretyczna; funkcja 'chi2cdf'
    otherwise
        return;
end

% por�wnanie wyniku ca�kowania z dystrybuant� teoretyczn�
figure;  ........ ;

