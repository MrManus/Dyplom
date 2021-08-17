%YT tutorial - Correlation Explained with Demo, Autor: David Dorran
%https://www.youtube.com/watch?v=_r_fDlM0Dx0
%kod maj¹cy pokazaæ ¿e czasem nie znormalizowana korelacja jest lepsza ni¿
%korelacja znormalizowania

clc
clear all
close all

t = [0:100-1]/100;
s1 = cos(2*pi*1*t);
s2 = cos(2*pi*4*t);
s3 = cos(2*pi*10*t);

%sygna³y a i b zawieraj¹ sygna³y poni¿ej 
%sygna³ s1 jest 2 razy bardziej obecny w sygnale a ni¿ w sygnale b
a = 2*s1+4*s2+s3;
b = s1 +s2;

%Porównanie wyników poznawla zauwa¿yæ ¿e nieznormalizowana korelacja jest
%przydatna przy identyfikacji jak mocno obecny jest day sygna³ w innym
%sygnale

corr_res = sum(a.*s1)
norm_corr_res1 = sum(a.*s1)/sqrt((sum(a.^2).*sum(s1.^2)))

corr_res = sum(b.*s1)
norm_corr_res1 = sum(b.*s1)/sqrt((sum(b.^2).*sum(s1.^2)))

figure
plot(t,s1,'b',t,s2,'r',t,s3,'g');
grid on

figure
plot(t,a,t,b,'r');
grid on


