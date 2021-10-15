% Ta funkcja s³u¿y do generowania zaszumionego sygna³u sinusoidalnego symuluj¹ce nagrany
% dzwiêk giaty elektryzcznej o okreœlonej czêstotliwoœæi podstawowej
% 
% Wykrozystanie:
%     f_prob - jest o czêstotliwoœæ z jak¹ zosta³ spróbkowany symulowany
%     sygna³ gitary elektrycznej
%    
%     f_sin - jest to czêstotliwoœæ z podstawowa symulowanego dŸwiêku np.
%     329(Hz) jest to czêstotliowœc dŸwiêku E4
% 
%     By wygenerowaæ sygna³ Sinusoidalny o czêstotliwoœci prodstawowej 329Hz
%     sprobkowany z czêstotliwosæi¹ 44kHZ:
%     
%     f_prob = 44000;
%     f_sin = 329;
%     
%     symulowana_probka = gen_zaszum_sin(f_prob, f_sin);


function zaszumiony = gen_zaszum_sin(f_prob, f_sin)

% fs = 44000;
fs = f_prob;
T = 1/fs;
N = 10000;
t = [0:N-1]*T;
% f1 = 329;
f1 = f_sin;
% f2 = f1*2;
f2 = 500;

text1 = ['Czêstotliwoœæ próbkowania to: ', num2str(fs),'Hz'];
text2 = ['Czêstotliwoœæ podstawowa sinusa to: ', num2str(f1),'Hz'];
disp(text1);
disp(text2);

syg1 = 0.1*sin(2*pi*f1*t);
syg2 = 0.03*sin(2*pi*f2*t);

czysty_sin = syg1 + syg2 ;



sigma = 0;
szum = sigma*randn(1,N);
% szum = 0;
zaszumiony = czysty_sin + szum;


% figure
% 
% subplot(5,1,5)
% plot(syg1);
% hold on
% plot(syg2, 'r');
% grid on
% ylim([-1.2 1.2])
% 
% subplot(5,1,1);
% plot(t,szum)
% % ylim([-1.2 1.2])
% grid on
% title('Szum')
% 
% subplot(5,1,2);
% plot(t,zaszumiony,'r')
% % hold on
% % plot(t,czysty_sin)
% % % ylim([-1.2 1.2])
% grid on
% title('Wygenerowany Sinus')
% 
% 
% %% Determine the autocorrelation function
% [rxx, lags] = xcorr(czysty_sin,czysty_sin);
% subplot(5,1,3);
% plot(lags, rxx)
% xlabel('Lag')
% ylabel('Correlation Measure')
% title('Autokorelacja czystego sygna³u')
% grid on
% 
% [rxx2, lags2] = xcorr(zaszumiony,zaszumiony);
% subplot(5,1,4);
% plot(lags2, rxx2)
% xlabel('Lag')
% ylabel('Correlation Measure')
% title('Autokorelacja zaszumionego sygna³u')
% grid on
