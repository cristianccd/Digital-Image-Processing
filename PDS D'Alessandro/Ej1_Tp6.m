% Cristian D'Alessandro 2011 PDS

clear;
clc;
L=2;
N=5;
M=1000;
for k=1:M
    X(k)=sin(2*pi*k/N);
    D(k)=2*cos(2*pi*k/N);
end

W=zeros(1,L);%[w0 w1]
u=0.01;

for k=2:M
    Xk=[X(k) X(k-1)];
    Y(k)=Xk*W';
    e(k)=D(k)-Y(k);
    W=W+2*u*e(k)*Xk;
end

subplot(711);
plot(1:M,Y);
xlabel('k');
ylabel('Y');
subplot(712);
plot(1:M,e);
xlabel('k');
ylabel('e');
subplot(713);
plot(1:M,X);
xlabel('k');
ylabel('X');

[W1,W2]=meshgrid(-10:.2:10,-10:.2:10);
S=2+0.5*(W1.^2+W2.^2)+W2.^2*cos(2*pi/N)+2*W1*sin(2*pi/N);
subplot(7,1,4:7);
mesh(W1,W2,S)