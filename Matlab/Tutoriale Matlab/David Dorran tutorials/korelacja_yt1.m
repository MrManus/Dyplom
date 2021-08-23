%YT tutorial - Correlation Explained with Demo, Autor: David Dorran
%https://www.youtube.com/watch?v=_r_fDlM0Dx0
%Skrypt licz�cy korrelacje d�wch sygnal�w o takiej samej ilo�ci pr�bek

function [wartosc_kor] = korelacja_yt1(a,b)

if length(a) == length(b)
    N = length(a);
    
    wartosc_kor = 0;
    
    for n = 1:N
        wynik_mnozenia = a(n)*b(n);
        wartosc_kor = wartosc_kor + wynik_mnozenia;
    end
    
    disp(['Wynik korelacji to: ' num2str(wartosc_kor)])
else 
    disp('B��dne wektory')
end