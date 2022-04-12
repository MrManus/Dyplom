f = [1, 10, 100,1000, 10000, 100000, 1000000,10000000];
y = [115, 100, 80, 60, 40, 20, 1, 0];

Ry=20000;
Rz=1000;
% Rx1 = 100;
% Rx2 = 20000;
% Rx3 = 50000;
% Rx4 = 100000;



A= 10.^(y/20);
B= 1/(1+Ry/Rz);
% B1 = 1/(1+Rx1/Rz);
% B2 = 1/(1+Rx2/Rz);
% B3 = 1/(1+Rx3/Rz);
% B4 = 1/(1+Rx4/Rz);




Av = A./(1+A.*B);
% Av1 = A./(1+A.*B1);
% Av2 = A./(1+A.*B2);
% Av3 = A./(1+A.*B3);
% Av4 = A./(1+A.*B4);

semilogx(f,20*log10(Av));
% semilogx(f,20*log10(Av1));
% hold on
% semilogx(f,20*log10(Av2),'m');
% semilogx(f,20*log10(Av3),'g');
% semilogx(f,20*log10(Av4),'r');
title('Wykres rzeczywistego wzmocnienia w pêtli zamkniêtej')
xlabel('Czêstotliwoœæ [Hz]')
ylabel('Av [dB]')
% hold off
% legend({'Rx = 100 Ohm','Rx = 20 kOhm','Rx = 50 kOhm', 'Rx = 100 kOhm'},'Location','northeast','Orientation','vertical')
