%% Generacja liczb pseudolosowych - pierwszy program w Matlabie
% Generacaj liczb pseudolosowych o rozk³adzie normalnym i rysowanie
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
% Wyœwietlanie histogramu
histogram (x,50)                    % K = 50 - liczba przedzia³ów histogramu

title('Histogram liczb pseudolosowych');
xlabel('Wartoœæ zmiennej losowej [-]');
ylabel('Licznoœæ [-]');
grid on;

x2 = randn(N,1);

x3 = x.^2;

figure; histogram (x3,50)                    % K = 50 - liczba przedzia³ów histogramu

title('Histogram liczb pseudolosowych');
xlabel('Wartoœæ zmiennej losowej [-]');
ylabel('Licznoœæ [-]');
grid on;

