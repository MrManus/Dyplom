clc
clear all
close all

[E4_ip, E4_fs] = audioread('trimed_E4_mono192kHz.wav');
SignalBuffer = E4_ip(1:7680)

SignalLength = 7680;
CrossCorrLength = SignalLength/2;

% LagAmount = SignalLength/2;
LagAmount = 3840;
Nominator = 0;




MiddleLag = 1;
SecHighPeakValue = 0;

SamplingFrequency = 192000;
Period = 0;
PeriodHz = 0;

for i= 1: 1: LagAmount
    SamplesAmount = (SignalLength - i);
    Nominator = 0;
    StarterSample = SignalLength - SamplesAmount;
    
    for j = 1:1:SamplesAmount
        
        Nominator = Nominator + (SignalBuffer(StarterSample + j) * SignalBuffer(j));
        
        if(Nominator < 0)
            Nominator = 0;
        end
    end
        CrossCorrBuffer(i) = Nominator;
end

% plot(CrossCorrBuffer)
% xlim([-110 inf])
% ylim([-5 80])


