clc 
clear all 
close all 

[ip, fs] = audioread('E4_3sek_mono.wav');


t = 0:1/fs:1;

ip2 = resample(ip,4,2);
fs2 = 2*fs;
t2 = 0:1/fs2:1;
sound(ip,fs);
sound(ip2,fs2);
figure
plot(ip)
figure
plot(ip2)