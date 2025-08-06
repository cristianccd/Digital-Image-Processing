% Cristian D'Alessandro 2011 PDS
% grad es un vector auxiliar que contiene los alfa y los betas
% W es el vector de los coeficientes a y b que varian con cada muestra
% delta es otro vector auxiliar para el calculo de mis nuevos coeficientes

clc;
clear;

fs=1000;
ts=1/fs;
a0=1;
b1=1.2;
b2=-0.6;
t=0:ts:10-ts;
M=length(t);
N=5;
delta=zeros(M,N);
W=zeros(M,N);
W(1,:)=[a0 0 0 b1 b2];
x=0.5*randn(1,10000);
yk=zeros(1,M);
dk(1)=W(1,1)*x(1);
dk(2)=W(1,1)*x(2)+W(1,4)*dk(1);
ek=zeros(1,M);
ek(1)=dk(1);
ek(2)=dk(2);

grad=zeros(M,N);
grad(1,:)=[x(1) 0 x(1) 0 0];
grad(2,:)=[x(2) x(1) x(1) 0 0];
mu=[0.05 0.005 0.0025];

for k=3:10000
yk(k)=W(k,1)*x(k)+W(k,2)*x(k-1)+W(k,3)*x(k-2)+W(k,4)*yk(k-1)+W(k,5)*yk(k-2);
dk(k)=W(1,1)*x(k)+W(1,4)*dk(k-1)+W(1,5)*dk(k-2);
ek(k)=dk(k)-yk(k);

grad(k,1)=x(k)+W(k,4)*grad(k-1,1)+W(k,5)*grad(k-2,1);
grad(k,2)=x(k-1)+W(k,4)*grad(k-1,2)+W(k,5)*grad(k-2,2);
grad(k,3)=x(k-2)+W(k,4)*grad(k-1,3)+W(k,5)*grad(k-2,3);
grad(k,4)=yk(k-1)+W(k,4)*grad(k-1,4)+W(k,5)*grad(k-2,4);
grad(k,5)=yk(k-2)+W(k,4)*grad(k-1,5)+W(k,5)*grad(k-2,5);

delta(k,:)=2*ek(k)*[mu(1)*grad(k,1) mu(1)*grad(k,2) mu(1)*grad(k,3) mu(2)*grad(k,4) mu(3)*grad(k,5)];
W(k+1,:)=W(k,:)+delta(k,:);
end

subplot(811)
plot(t,dk);
ylabel('dk');
subplot(812)
plot(t,yk);
ylabel('yk');
subplot(813)
plot(t,ek);
ylabel('ek')
subplot(814)
plot(t(1:10000),W(1:10000,1));
ylabel('a0k');
subplot(815)
plot(t(1:10000),W(1:10000,2));
ylabel('a1k');
subplot(816)
plot(t(1:10000),W(1:10000,3));
ylabel('a2k');
subplot(817)
plot(t(1:10000),W(1:10000,4));
ylabel('b1k');
subplot(818)
plot(t(1:10000),W(1:10000,5));
ylabel('b2k');