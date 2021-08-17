%YT tutorial - Correlation Explained with Demo, Autor: David Dorran
%https://www.youtube.com/watch?v=_r_fDlM0Dx0
%Skrypt licz¹cy ZNOMALIZOWANA korrelacje dówch sygnalów o takiej samej iloœci próbek

function [wartosc_kor_norm] = korelacja_yt2(a,b)

if length(a) == length(b)
    N = length(a);
    
    wartosc_licznika = 0;
    wartosc_mianownika = 0;
    wartosc_kor_norm = 0;
    a2_sum = 0;
    b2_sum = 0;
    for n = 1:N
        wynik_mnozenia_l = a(n)*b(n);
        wartosc_licznika = wartosc_licznika + wynik_mnozenia_l;
    
       a2_sum = a2_sum + a(n)^2
       b2_sum = b2_sum +b(n)^2;            
%         wynik_mnozenia_m = sqrt((a(n)^2)*(b(n)^2));
%         wartosc_mianownika = wartosc_mianownika + wynik_mnozenia_m;
    end
    disp(num2str(a2_sum))
    disp(num2str(b2_sum))
    wartosc_mianownika = sqrt(a2_sum*b2_sum)
    wartosc_kor_norm = wartosc_licznika/wartosc_mianownika;
    
    disp(['Wynik korelacji znormalizowanej to: ' num2str(wartosc_kor_norm)])
else 
    disp('B³êdne wektory')
end