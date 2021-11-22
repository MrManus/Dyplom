clc 
clear all 
close all 

[ip, fs] = audioread('05_E4_mono192kHz.wav');

max_expected_period = round(1/50*fs);
min_expected_period = round(1/400*fs);
frame_len = 1*max_expected_period;

length(ip)/frame_len -1

for k = 1 : length(ip)/frame_len -1  %wykonujemy tyle razy ile razy ramka mie�cie sie w sygnale
    range = (k-1)*frame_len + 1:k*frame_len; %zasi�g pr�bek od pr�bki = (k-1) razu d�ugo�� ramki plus jedna pr�bka koniec ramki dal k krotno�ci d�ugosci ramki 
    frame = ip(range); % stworzenie kopi fragmentu sygna�u kt�rego zakres okreslony jest zmienna range
    %7
    if(k == 7)
        k
        range_of_export = range;
%       data_to_export = frame;
        [rxx, lag] = xcorr(frame, frame);
        
        data_to_export = single(frame);
        dlmwrite('05_E4_mono192kHz.txt',data_to_export,'delimiter',',','precision',9)
        [export_corr, export_lag] = xcorr(data_to_export,data_to_export);
        dlmwrite('corr_05_E4_mono192kHz.txt',export_corr,'delimiter',',','precision',9)
    end
        
end