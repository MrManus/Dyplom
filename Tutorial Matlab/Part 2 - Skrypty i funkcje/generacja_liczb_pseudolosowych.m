%% Generacja liczb pseudolosowych - pierwszy program w Matlabie
% Generacaj liczb pseudolosowych o rozkładzie normalnym i rysowanie
% histogramu
%
% Autor: Maciej Manuszewski
% Data: 28.06.2021

clear all 
close all
clc

%% Generacja liczb pseudolosowych

N = 1000;
x = randn(N,1);

%% Histogram
% Wyświetlanie histogramu
histogram (x,50)                    % K = 50 - liczba przedziałów histogramu

title('Histogram liczb pseudolosowych');
xlabel('Wartość zmiennej losowej [-]');
ylabel('Liczność [-]');
grid on;

x2 = randn(N,1);

x3 = x.^2;

figure; histogram (x3,50)                    % K = 50 - liczba przedziałów histogramu

title('Histogram liczb pseudolosowych');
xlabel('Wartość zmiennej losowej [-]');
ylabel('Liczność [-]');
grid on;

