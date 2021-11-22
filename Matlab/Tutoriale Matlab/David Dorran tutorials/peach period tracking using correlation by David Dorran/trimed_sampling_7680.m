clc 
clear all 
close all 

[ip, fs] = audioread('trimed_E4_mono192kHz.wav');


for i = 1:1:7680
    signal(i) = ip(i);
    
end

data_to_export = single(signal);
dlmwrite('trimed_E4_mono192kHz.txt',data_to_export,'delimiter',',','precision','%.9f');