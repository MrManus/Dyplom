%YT tutorial - Cross Correlation Demo using Matlabs xcorr function, Autor: David Dorran
%https://www.youtube.com/watch?v=RO8s1TrElEw

clc
clear all
close all
a = [0.1 0.2 -0.1 4.1 -2 1.5 -0.1];
b = [0.1 4 -2.2 1.6 0.1 0.1 0.2];

len = length(a);
if(len ~= length(b))
    error('vectors supplied must be the same leght');
end
figure 
set(gcf, 'position', [285 347 642 367]);
plot(a);
hold on
plot(b,);

max_amp = max([max(a) max(b)]);
min_amp = min([min(a) min(b)]);