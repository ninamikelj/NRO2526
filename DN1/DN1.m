% Domača naloga 1


% 1. NAL - Branje datoteke 1

filename = 'C:\Users\Nina Mikelj\NRO_2526_vaja1\nro\NRO_DN1\naloga1_1.txt';
skiprows = 2;
podatki = importdata(filename, ' ', skiprows);
t = podatki.data;


% 2. NAL - Branje datoteke 2

fid = fopen("C:\Users\Nina Mikelj\NRO_2526_vaja1\nro\NRO_DN1\naloga1_2.txt", 'r');
prva_vrstica = fgetl(fid);   % prebere celotno prvo vrstico kot besedilo

% Izloči število iz te vrstice
st_podatkov = sscanf(prva_vrstica, 'stevilo_podatkov_P: %d');

P = zeros(st_podatkov, 1);

for i = 1:st_podatkov
    vrstica = fgetl(fid);      % prebere naslednjo vrstico
    P(i) = str2double(vrstica); % pretvori besedilo v številko
end

fclose(fid);

plot(t,P);
xlabel('t[s]');
ylabel('P[W]');
title('Graf P(t)');


% 3. NAL - Trapezna metoda

n = length(t); % ugotovimo število točk
dt = t(2) - t(1);
I = 0;

for i = 1:n-1
    I = I + (P(i) + P(i+1)) * (t(i+1) - t(i)) / 2;
end

fprintf('Integral s trapezno metodo (ročno): %.6f\n', I);

I_trapz = trapz(t, P);
fprintf('Integral s trapz funkcijo: %.6f\n', I_trapz);