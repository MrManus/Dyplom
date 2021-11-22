%% Using Autocorrelation to track the local period of a signal
% This code is used as part of a youtube video demonstration 
% See http://youtube.com/ddorran
%
% Code available at https://dadorran.wordpress.com       
%
% The following wav file can be downloaded from 
%       https://www.dropbox.com/s/3y25abf1xuqpizj/speech_demo.wav
%% speech analysis example
clc 
clear all 
close all 
 
% [ip, fs] = audioread('speech_demo.wav');

[ip, fs] = audioread('trimed_E4_mono192kHz.wav');

%sekcja do testów resampling
% [ipold, fsold] = audioread('E4_3sek_mono.wav');
% ip = resample(ipold,20,2);
% fs = 10*fsold;
% % 
% [ipold, fsold] = audioread('E2_mono176kHz.wav');
% ip = resample(ipold,20,2);
% fs = 10*fsold;

max_expected_period = round(1/50*fs);
min_expected_period = round(1/400*fs);
frame_len = 4*max_expected_period;

 
for k = 1 : length(ip)/frame_len -1  %wykonujemy tyle razy ile razy ramka mieœcie sie w sygnale
    range = (k-1)*frame_len + 1:k*frame_len; %zasiêg próbek od próbki = (k-1) razu d³ugoœæ ramki plus jedna próbka koniec ramki dal k krotnoœci d³ugosci ramki 
    frame = ip(range); % stworzenie kopi fragmentu sygna³u którego zakres okreslony jest zmienna range
     
    %show the input in blue and the selected frame in red
    plot(ip);
    set(gca, 'xtick',[],'position',[ 0.05  0.82   0.91  0.13])
    hold on;
    temp_sig = ones(size(ip))*NaN;
    temp_sig(range) = frame; %stworzenie macierzy temp_sig która wszedzie poza akurat badanym zakresem próbek zawiera NaN
    plot(temp_sig,'r'); %wyrysowania wszystkich wartoœci z temp_sig które nie s¹ NaN
    hold off
     
    %use xcorr to determine the local period of the frame
    [rxx, lag] = xcorr(frame, frame);
    subplot(3,1,3)
    plot(lag, rxx,'r')
    rxx(find(rxx < 0)) = 0; %set any negative correlation values to zero
    center_peak_width = find(rxx(frame_len:end) == 0 ,1); %find first zero after center
    %center of rxx is located at length(frame)+1
    rxx(frame_len-center_peak_width : frame_len+center_peak_width  ) = min(rxx);
    hold on
    plot(lag, rxx,'g');
    hold off
    [max_val, loc] = max(rxx);
    period = abs(loc - length(frame)+1); 
     
    title(['Period estimate = ' num2str(period) ' samples (' num2str(fs/period) 'Hz)']);
    set(gca, 'position', [ 0.05  0.07    0.91  0.25])
     
    [max_val, max_loc] = max(frame);
    num_cycles_in_frame = ceil(frame_len/period);
    test_start_positions = max_loc-(period*[-num_cycles_in_frame:num_cycles_in_frame]);
    index = find(test_start_positions > 0,1, 'last');
    start_position = test_start_positions(index);
    colours = 'rg';
     
    subplot(3,1,2)
    plot(frame);
     
    set(gca, 'position',[ 0.05 0.47 0.91 0.33])
    pause
    for g = 1 : num_cycles_in_frame
        if(start_position+period*(g) <= frame_len && period > min_expected_period)
            cycle_seg = ones(1, frame_len)*NaN;
            cycle_seg(start_position+period*(g-1):start_position+period*(g))  =...
                            frame(start_position+period*(g-1):start_position+period*(g));
            hold on
             
            plot(cycle_seg,colours(mod(g, length(colours))+1)) %plot one of the available colors
            hold off
        end
    end
    pause
end
 