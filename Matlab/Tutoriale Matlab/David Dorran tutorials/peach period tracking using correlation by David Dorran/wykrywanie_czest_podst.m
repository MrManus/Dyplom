close all
clear all
clc

f_prob = 48000;
% f_prob = 96000;
% f_prob = 192000;
f_sin = 360;

sig = gen_zaszum_sin(f_prob, f_sin); %wygeneruj sygna� o cz�stotliwosci podstawowej 329Hz pr�bkowany z cz�stotliwosci� 44kHz
temp_sig = sig; %stw�rz kopie sygnalu na kt�rej dokonywane b�d� obliczenia

figure
plot(temp_sig);

[sig_cor, lag] = xcorr(temp_sig,temp_sig); %wykonaj korelacj� sygna�u 

figure
plot(lag, sig_cor,'r')
sig_cor(find(sig_cor < 0)) = 0; %ustaw wszystkie ujemne warto�ci korelacji jako zero

sig_len = length(temp_sig);%ustal d�ugo�� ca�ego sygna�u 
%korelacja sygna�u b�dzie dwa razy d�u�sza ni� sygna� a �rodek korelacji
%czyli d�ugo�� sygna�u wyznacza �rodek korelacji

center_peak_half_width = find(sig_cor(sig_len:end) == 0, 1); %wyznacz (po�ow�) szroko�� centralnego szczytu
sig_cor(sig_len - center_peak_half_width : sig_len + center_peak_half_width) = min(sig_cor); %przyr�wnaj ca�y �rodkowy szczyt do zera

hold on
plot(lag, sig_cor, 'g');

[max_val, loc] = max(sig_cor);
period = abs(loc - sig_len);
periodHz = f_prob/period;

title(['Okres wynosi = ' num2str(period) ' pr�bek czyli ' num2str(periodHz) 'Hz']);


