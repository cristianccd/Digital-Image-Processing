//Procesamiento Digital de Imágenes
//Universidad Favaloro
//Bioing. Sebastián Graf

#include <vcl.h>
#include <math.h>
#include <stdio.h>
#if !defined(__MATRIZ_H)
#define __MATRIZ_H

class Matriz
        {
	private:
	unsigned char* Bmp;
        unsigned char* Bmp_r;
        unsigned char* Bmp_g;
        unsigned char* Bmp_b;
        int LUT[256];
        double Mascara[9];
        double Real[256][256];
        double Imag[256][256];


	public:
        int NumeroFilas;
	int NumeroColumnas;
        Matriz();
        Matriz(int filas,int columnas);
        Matriz & operator=(Matriz &);
        Matriz & operator-(Matriz &);
        Matriz & operator*(int);
	~Matriz();
        void Graficar(TImage *);
        void GraficarColor(TImage *);
        void Cargar(TImage *);
        void BarrasH(int);
        void BarrasV(int);
        void Circunf(int);
        void Cuadrado(int);
        void Cruz(int);
        void VerContras(int, int, int);
        void IzqDer();
        void DerIzq();
        void UpDown();
        void DownUp();
        void IIzqDer();
        void IDerIzq();
        void IUpDown();
        void IDownUp();
        void SIzqDer(double);
        void SDerIzq(double);
        void SUpDown(double);
        void SDownUp(double);
        void NivGris(int);
        void Leer(AnsiString &);
        void True_NG();
        void loadLUT(double *);
        void applyLUT();
        double getLUT(int);
        void setMask(double *);
        void applyMask(Matriz &);
        void Negative();
        void briycontr(int, int);
        void dinrange(int);
        void binarizacion(int);
        double Histograma(int index);
        void Ecualizar();
        void SaltPepper(int);
        void PBajos(Matriz &);
        void PAltos(Matriz &);
        void HighBoost(Matriz &,double);
        void Sobel(Matriz &);
        void Laplaciano(Matriz &);
        void Prewitt(Matriz &);
        void Mediana(Matriz &);
        void Escalar(Matriz &, double, int, int);
        void Bilinear(Matriz &, double, int, int);
        void Rotar(Matriz &,int,int,int);
        void Trasladar(Matriz &,int,int);
        int IBR(int m, int v);
        void FFT(double *, double *, double *, double *, bool);
        void applyFFT(Matriz &, bool);
        void FNotch(Matriz &, int, int, int);
        void FPAltos(Matriz &, int, int);
        void FPBajos(Matriz &, int, int);
        void DetectPtos(Matriz &, float);
        void DetectLineas(Matriz &, float, double*);
        void UmbralFijo(Matriz &,double);
        double Isodata(Matriz &);
        void LadyBug(Matriz &, int posx, int posy);


        unsigned char& buffer( int filas, int columnas){
                static unsigned char nada = 0;
		long jj = long(columnas)+long(filas)*long(NumeroColumnas);
		if( filas >= 0 && columnas >= 0)
			return Bmp[jj];
		else
			return nada;
		}
       unsigned char& buffer_r( int filas, int columnas){
                static unsigned char nada = 0;
		long jj = long(columnas)+long(filas)*long(NumeroColumnas);
		if( filas >= 0 && columnas >= 0)
			return Bmp_r[jj];
		else
			return nada;
		}
        unsigned char& buffer_g( int filas, int columnas){
                static unsigned char nada = 0;
		long jj = long(columnas)+long(filas)*long(NumeroColumnas);
		if( filas >= 0 && columnas >= 0)
			return Bmp_g[jj];
		else
			return nada;
		}
        unsigned char& buffer_b( int filas, int columnas){
                static unsigned char nada = 0;
		long jj = long(columnas)+long(filas)*long(NumeroColumnas);
		if( filas >= 0 && columnas >= 0)
			return Bmp_b[jj];
		else
			return nada;
		}
        void Slicing(Matriz & Mat, int sup, int inf);
        void ContrastStrech(Matriz & Mat);




        };
#endif