close all
clear all
clc

f_prob = 48000;
% f_prob = 96000;
% f_prob = 192000;
f_sin = 360;

sig = gen_zaszum_sin(f_prob, f_sin); %wygeneruj sygna³ o czêstotliwosci podstawowej 329Hz próbkowany z czêstotliwosci¹ 44kHz
temp_sig = sig; %stwórz kopie sygnalu na której dokonywane bêd¹ obliczenia

figure
plot(temp_sig);

[sig_cor, lag] = xcorr(temp_sig,temp_sig); %wykonaj korelacjê sygna³u 

figure
plot(lag, sig_cor,'r')
sig_cor(find(sig_cor < 0)) = 0; %ustaw wszystkie ujemne wartoœci korelacji jako zero

sig_len = length(temp_sig);%ustal d³ugoœæ ca³ego sygna³u 
%korelacja sygna³u bêdzie dwa razy d³u¿sza ni¿ sygna³ a œrodek korelacji
%czyli d³ugoœæ sygna³u wyznacza œrodek korelacji

center_peak_half_width = find(sig_cor(sig_len:end) == 0, 1); %wyznacz (po³owê) szrokoœæ centralnego szczytu
sig_cor(sig_len - center_peak_half_width : sig_len + center_peak_half_width) = min(sig_cor); %przyrównaj ca³y œrodkowy szczyt do zera

hold on
plot(lag, sig_cor, 'g');

[max_val, loc] = max(sig_cor);
period = abs(loc - sig_len);
periodHz = f_prob/period;

title(['Okres wynosi = ' num2str(period) ' próbek czyli ' num2str(periodHz) 'Hz']);


