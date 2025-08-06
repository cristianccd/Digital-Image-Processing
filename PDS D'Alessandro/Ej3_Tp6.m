% Cristian D'Alessandro 2011 PDS
% grad es un vector auxiliar que contiene los alfa y los betas
% W es el vector de los coeficientes a y b que varian con cada muestra
% delta es otro vector auxiliar para el calculo de mis nuevos coeficientes

clc;
clear;
fc=60;
fs=1000;
ts=1/fs;
wc=2*pi*fc;
a0=(wc*ts)/(wc*ts+2);
a1=a0;
b1=(wc*ts-2)/(wc*ts+2);
t=0:ts:10;
M=length(t);
% SENAL
x=2.*randn(M,1);
% Si la desviacion aumenta levemente, el sistema tardara mas en adaptarse
% Si el incremento es > a 0.5 el sistema diverge y no se puede adaptar.
% ------------------------------------------------------------------------
delta=zeros(M,3);
W=zeros(M,3);
W(1,:)=[a0 a1 b1];
grad=zeros(M,3);
grad(1,:)=[x(1) 0 0];

yk=zeros(1,M);
dk=zeros(1,M);
dk(1)=W(1,1)*x(1);
ek=zeros(1,M);
ek(1)=dk(1)-yk(1);
mu=[0.05 0.005 0.0025];

for k=2:M
yk(k)=W(k,1)*x(k)+W(k,2)*x(k-1)+W(k,3)*yk(k-1);
dk(k)=W(1,1)*x(k)+W(1,2)*x(k-1)-W(1,3)*dk(k-1);
ek(k)=dk(k)-yk(k);

grad(k,1)=x(k)+W(k,3)*grad(k-1,1);
grad(k,2)=x(k-1)+W(k,3)*grad(k-1,2);
grad(k,3)=yk(k-1)+W(k,3)*grad(k-1,3);

delta(k,:)=2*ek(k)*[mu(1)*grad(k,1) mu(2)*grad(k,2) mu(3)*grad(k,3)];
W(k+1,:)=W(k,:)+delta(k,:);
end

subplot(311)
plot(t,dk);
ylabel('d[k]');
subplot(312)
plot(t,yk);
ylabel('y[k]');
subplot(313)
plot(t,ek);
ylabel('e[k]');