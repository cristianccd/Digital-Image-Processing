//Procesamiento Digital de Imágenes
//Universidad Favaloro
//Bioing. Sebastián Graf


#include "matriz.h"
#include "math.h"
#include "vector.h"

Matriz::Matriz()
{
Bmp = 0;
Bmp_r = 0;
Bmp_g = 0;
Bmp_b = 0;
NumeroFilas = 256;
NumeroColumnas = 256;
Bmp = new unsigned char [long(256)*long(256)];
Bmp_r = new unsigned char [long(256)*long(256)];
Bmp_g = new unsigned char [long(256)*long(256)];
Bmp_b = new unsigned char [long(256)*long(256)];
for( int f = 0; f < NumeroFilas; f++)
        for( int c = 0; c < NumeroColumnas; c++)
        {
                buffer(f,c) = 0;
                buffer_r(f,c) = 0;
                buffer_g(f,c) = 0;
                buffer_b(f,c) = 0;
        }

}

Matriz::Matriz( int filas, int columnas)
{
NumeroFilas = filas;
NumeroColumnas = columnas;
Bmp = 0;
Bmp_r = 0;
Bmp_g = 0;
Bmp_b = 0;
Bmp = new unsigned char [long(filas)*long(columnas)];
Bmp_r = new unsigned char [long(filas)*long(columnas)];
Bmp_g = new unsigned char [long(filas)*long(columnas)];
Bmp_b = new unsigned char [long(filas)*long(columnas)];
for( int f = 0; f < NumeroFilas; f++)
        for( int c = 0; c < NumeroColumnas; c++)
        {
                buffer(f,c) = 0;
                buffer_r(f,c) = 0;
                buffer_g(f,c) = 0;
                buffer_b(f,c) = 0;
        }
}

Matriz & Matriz::operator=(Matriz &original)
{
        NumeroFilas = original.NumeroFilas;
        NumeroColumnas = original.NumeroColumnas;
        for( int f = 0; f < NumeroFilas; f++)
                for( int c = 0; c < NumeroColumnas; c++)
                {
                        buffer(f,c) = original.buffer(f,c);
                        buffer_r(f,c) = original.buffer_r(f,c);
                        buffer_g(f,c) = original.buffer_g(f,c);
                        buffer_b(f,c) = original.buffer_b(f,c);
                }
        return *this;
}

Matriz & Matriz::operator-(Matriz &Mat1)
{
        for( int f = 0; f < NumeroFilas; f++)
                for( int c = 0; c < NumeroColumnas; c++)
                {
                        Mat1.buffer(f,c)=buffer(f,c)-Mat1.buffer(f,c);
                        Mat1.buffer_r(f,c)=buffer_r(f,c)-Mat1.buffer_r(f,c);
                        Mat1.buffer_g(f,c)=buffer_g(f,c)-Mat1.buffer_g(f,c);
                        Mat1.buffer_b(f,c)=buffer_b(f,c)-Mat1.buffer_b(f,c);
                }
        return Mat1;
}

Matriz & Matriz::operator*(int n)
{
        for( int f = 0; f < NumeroFilas; f++)
                for( int c = 0; c < NumeroColumnas; c++)
                {
                        buffer(f,c)=buffer(f,c)*n;
                }
        return *this;
}

Matriz::~Matriz()
{
if(Bmp)delete Bmp;

Bmp = 0;
Bmp_r = 0;
Bmp_g = 0;
Bmp_b = 0;
}

void Matriz::Cargar(TImage *Image1)
{
/*BYTE * LinePtr;
for (int f = 0; f <= 255; f++)
        {
        LinePtr = (BYTE *) Image1->Picture->Bitmap->ScanLine[f];
        for (int c = 0; c <= 255; c++)
                buffer(f,c) = LinePtr[c];
        }  */
}

void Matriz::Graficar(TImage *Image1)
{
BYTE *LinePtr;
typedef struct
        {
        TLogPalette lpal;
        TPaletteEntry dummy[256];
        } LogPal;
//genero la paleta
Image1->Picture->Bitmap->PixelFormat = pf8bit;
Image1->Picture->Bitmap->Width = 256;
Image1->Picture->Bitmap->Height = 256;
LogPal SysPal;
SysPal.lpal.palVersion = 0x300;
SysPal.lpal.palNumEntries = 256;
//aca esta el color del buffer
for (int i = 0; i < 256; i++)
        {
        SysPal.lpal.palPalEntry[i].peRed = i;
        SysPal.lpal.palPalEntry[i].peGreen = i;
        SysPal.lpal.palPalEntry[i].peBlue = i;
        SysPal.lpal.palPalEntry[i].peFlags = 0;
        }

Image1->Picture->Bitmap->Palette = CreatePalette(&SysPal.lpal);
// Copia la imagen de vuelta para visualizar
for (int f = 0; f <= 255; f++)
        {
        LinePtr = (BYTE *) Image1->Picture->Bitmap->ScanLine[f];
        for (int c = 0; c <= 255; c++)
                LinePtr[c]   = buffer(f,c);
        }
Image1->Refresh();
}
//-------------------------------------------------------------------

void Matriz::BarrasH(int ancho)
{
for(int f = 0; f <NumeroFilas; f++ )
        for(int c = 0; c <NumeroColumnas; c++ )
                buffer(f,c) = (f%ancho)<(ancho/2)?0:255;
}

void Matriz::BarrasV(int ancho)
{
for(int f = 0; f <NumeroFilas; f++ )
        for(int c = 0; c <NumeroColumnas; c++ )
                buffer(c,f) = (f%ancho)<(ancho/2)?0:255;
}

void Matriz::Circunf(int radio)
{
int ctroy = NumeroColumnas/2;
int ctrox = NumeroFilas/2;

for(int f = 0; f <NumeroFilas; f++ )
        for(int c = 0; c <NumeroColumnas; c++ )
                if(pow(f-ctroy,2)+pow(c-ctrox,2)<=pow(radio,2))
                        buffer(f,c)=255;
                else
                        buffer(f,c)=0;

}

void Matriz::Cuadrado(int lado)
{
for(int f = 0; f <NumeroFilas; f++ )
        for(int c = 0; c <NumeroColumnas; c++ )
                if(c<lado&&f<lado)
                        buffer(f,c)=255;
                else
                        buffer(f,c)=0;

}

void Matriz::Cruz(int ancho)
{
int ctroy = NumeroColumnas/2;
int ctrox = NumeroFilas/2;

for(int f = 0; f <NumeroFilas; f++ )
        for(int c = 0; c <NumeroColumnas; c++ )
                if(c<ctrox+ancho/4&&c>ctrox-ancho/4||f<ctroy+ancho/4&&f>ctroy-ancho/4)
                        buffer(f,c)=255;
                else
                        buffer(f,c)=0;

}

void Matriz::VerContras(int fuerte, int claro, int ladocuadr)
{
int ctroy = NumeroColumnas/2-ladocuadr/2;
int ctrox = NumeroFilas/2-ladocuadr/2;

for(int f = 0; f <NumeroFilas; f++ )
        for(int c = 0; c <NumeroColumnas; c++ )
                if(c>ctrox&&f>ctroy&&f<ctroy+ladocuadr&&c<ctrox+ladocuadr)
                        buffer(f,c)=claro;
                else
                        buffer(f,c)=fuerte;

}

void Matriz::IzqDer()
{
for(int f = 0; f <NumeroFilas; f++ )
        for(int c = 0; c <NumeroColumnas; c++ )
                        buffer(f,c)=c;
}

void Matriz::DerIzq()
{
for(int f = 0; f <NumeroFilas; f++ )
        for(int c = 0; c <NumeroColumnas; c++ )
                        buffer(f,c)=255-c;
}

void Matriz::UpDown()
{
for(int f = 0; f <NumeroFilas; f++ )
        for(int c = 0; c <NumeroColumnas; c++ )
                        buffer(f,c)=f;
}

void Matriz::DownUp()
{
for(int f = 0; f <NumeroFilas; f++ )
        for(int c = 0; c <NumeroColumnas; c++ )
                        buffer(f,c)=255-f;
}

//---------------------------------------------

void Matriz::SIzqDer(double freq)
{
for(int f = 0; f <NumeroFilas; f++ )
        for(int c = 0; c <NumeroColumnas; c++ )
                buffer(f,c)=NumeroFilas/2*sin(2*M_PI*freq*c/(NumeroFilas-1))+NumeroFilas/2;
}

void Matriz::SDerIzq(double freq)
{
for(int f = 0; f <NumeroFilas; f++ )
        for(int c = 0; c <NumeroColumnas; c++ )
                buffer(f,c)=NumeroFilas/2*sin(2*M_PI*freq*(255-c)/(NumeroFilas-1))+NumeroFilas/2;
}

void Matriz::SUpDown(double freq)
{
for(int f = 0; f <NumeroFilas; f++ )
        for(int c = 0; c <NumeroColumnas; c++ )
                buffer(f,c)=NumeroFilas/2*sin(2*M_PI*f*freq/(NumeroFilas-1))+NumeroFilas/2;
}

void Matriz::SDownUp(double freq)
{
for(int f = 0; f <NumeroFilas; f++ )
        for(int c = 0; c <NumeroColumnas; c++ )
                buffer(f,c)=NumeroFilas/2*sin(2*M_PI*(255-f)*freq/(NumeroFilas-1))+NumeroFilas/2;
}

void Matriz::NivGris(int cant)
{
        int aux;
        for(int f = 0; f <NumeroFilas; f++ )
                for(int c = 0; c <NumeroColumnas; c++ )
                        {
                                 buffer(f,c)=buffer(f,c)>>(8-cant);
                                 buffer(f,c)=buffer(f,c)<<(8-cant);
                        }
}

void Matriz::IIzqDer()
{
for(int f = 0; f <NumeroFilas; f++ )
        for(int c = 0; c <NumeroColumnas; c++ )
                buffer(f,c)=buffer(f,c)*(256-c);

}

void Matriz::IDerIzq()
{
for(int f = 0; f <NumeroFilas; f++ )
        for(int c = 0; c <NumeroColumnas; c++ )
                buffer(f,c)=buffer(f,c)*(c);
}

void Matriz::IUpDown()
{
for(int f = 0; f <NumeroFilas; f++ )
        for(int c = 0; c <NumeroColumnas; c++ )
                buffer(f,c)=buffer(f,c)*(256-f);
}

void Matriz::IDownUp()
{
for(int f = 0; f <NumeroFilas; f++ )
        for(int c = 0; c <NumeroColumnas; c++ )
                buffer(f,c)=buffer(f,c)*(f);
}


void Matriz::True_NG()
{
 for(int f = 0; f <NumeroFilas; f++ )
        for(int c = 0; c <NumeroColumnas; c++ )
                buffer(f,c)=buffer(f,c);
}

void Matriz::Leer(AnsiString &Archivo)
{
 BITMAPFILEHEADER fh;
 BITMAPINFOHEADER fi;
 RGBQUAD rgb;
 FILE* fp;



 fp=fopen(Archivo.c_str(),"rb");
 fread(&fh,sizeof(BITMAPFILEHEADER),1,fp);
 if(fh.bfType!=0x4D42)
        MessageBox(NULL, "Error al cargar el archivo!", "Error", MB_OK|MB_ICONERROR);
 fseek(fp,-2,SEEK_CUR);
 fread(&fi,sizeof(BITMAPINFOHEADER),1,fp);
 if(fi.biBitCount==8)
 {
  fseek(fp,256*sizeof(RGBQUAD),SEEK_CUR);//evito la paleta

  for(int f = 0; f <NumeroFilas; f++ )
        for(int c = 0; c <NumeroColumnas; c++ )
                buffer(255-f,c)=fgetc(fp);
 //Tiene Paleta
 }
 if(fi.biBitCount==24)
 {
  for(int f = 0; f <NumeroFilas; f++ )
        for(int c = 0; c <NumeroColumnas; c++ )
        {
                buffer_r(255-f,c)=fgetc(fp);
                buffer_g(255-f,c)=fgetc(fp);
                buffer_b(255-f,c)=fgetc(fp);
                buffer(255-f,c)=(buffer_r(255-f,c)+buffer_g(255-f,c)+buffer_b(255-f,c))/3;
        }
  //No tiene paleta, TRUE COLOR
 }

 fclose(fp);
}

void Matriz::loadLUT(double *valor)
{
        for(int i=0;i<256;i++)
        {
                LUT[i]=valor[i];
                if(LUT[i]>255)
                        LUT[i]=255;
                if(LUT[i]<0)
                        LUT[i]=0;
        }
}

void Matriz::applyLUT()
{
       for(int f = 0; f <NumeroFilas; f++ )
                for(int c = 0; c <NumeroColumnas; c++ )
                {
                        buffer(f,c)=LUT[buffer(f,c)];
                }
}

double  Matriz::getLUT(int i)
{
        return LUT[i];
}

void Matriz::Negative()
{
        double Neg[256];
        for(int i=0;i<256;i++)
        {
                Neg[i]=255-i;
        }
        loadLUT(Neg);
        applyLUT();
}

void Matriz::briycontr(int brillo, int contr)
{
        double output[256];
        for(int i=0;i<256;i++)
        {
                output[i]=(double)contr/100*i+brillo;
        }
        loadLUT(output);
        applyLUT();
}

void Matriz::dinrange(int c)
{

        double output[256];
        for(int i=0;i<256;i++)
        {
                output[i]=(double)c*log(1+abs(i));
        }
        loadLUT(output);
        applyLUT();
}

void Matriz::binarizacion(int m)
{

        double output[256];
        for(int i=0;i<256;i++)
        {
                if(i>m)
                        output[i]=255;
                else
                        output[i]=0;
        }
        loadLUT(output);
        applyLUT();
}

double Matriz::Histograma(int index)
{
        double apariciones[256];
        for(int i=0;i<256;i++)
                apariciones[i]=0;
        for(int f = 0; f <NumeroFilas; f++ )
                for(int c = 0; c <NumeroColumnas; c++ )
                        apariciones[buffer(f,c)]++;

        return apariciones[index];
}

void Matriz::GraficarColor(TImage *Image1)
{
BYTE *LinePtr;
BITMAPINFOHEADER fi;

        typedef struct
        {
        TLogPalette lpal;
        TPaletteEntry dummy[256];
        } LogPal;
        //genero la paleta
        Image1->Picture->Bitmap->PixelFormat = pf24bit;
        Image1->Picture->Bitmap->Width = 256;
        Image1->Picture->Bitmap->Height = 256;
        /*LogPal SysPal;
        SysPal.lpal.palVersion = 0x300;
        SysPal.lpal.palNumEntries = 256;
        //aca esta el color del buffer
        for (int i = 0; i < 256; i++)
        {
                SysPal.lpal.palPalEntry[i].peRed = i;
                SysPal.lpal.palPalEntry[i].peGreen = i;
                SysPal.lpal.palPalEntry[i].peBlue = i;
                SysPal.lpal.palPalEntry[i].peFlags = 0;
        }

        Image1->Picture->Bitmap->Palette = CreatePalette(&SysPal.lpal);*/
        // Copia la imagen de vuelta para visualizar
        for (int f = 0; f <= 255; f++)
        {
                LinePtr = (BYTE *) Image1->Picture->Bitmap->ScanLine[f];
                for (int c = 0; c <= 255; c++)
                {
                        LinePtr[3*c]= buffer_r(f,c);
                        LinePtr[3*c+1]= buffer_g(f,c);
                        LinePtr[3*c+2]= buffer_b(f,c);
                }
        }
        Image1->Refresh();
}//fin GraficarColor

void Matriz::Ecualizar()
{
        double apariciones[256],pepe;
        for(int i=0;i<256;i++)
                apariciones[i]=apariciones[i-1]+Histograma(i);
        for(int i=0;i<256;i++)
                apariciones[i]=apariciones[i]/apariciones[255]*256;
        loadLUT(apariciones);
        applyLUT();
}

void Matriz::setMask(double *Mask)
{
        for(int i=0;i<9;i++)
                Mascara[i]=Mask[i];
}

void Matriz::applyMask(Matriz &Mat)
{
        for(int f = 0; f <NumeroFilas; f++ )
                for(int c = 0; c <NumeroColumnas; c++ )
                {
                        if(f==0||c==0||f==NumeroFilas-1||c==NumeroColumnas-1)
                                buffer(f,c)=buffer(f,c);
                        else
                        {
                                Mat.buffer(f,c)=Mascara[0]*buffer(f-1,c-1)+Mascara[1]*buffer(f-1,c)+
                                Mascara[2]*buffer(f-1,c+1)+Mascara[3]*buffer(f,c-1)+
                                Mascara[4]*buffer(f,c)+Mascara[5]*buffer(f,c+1)+
                                Mascara[6]*buffer(f+1,c-1)+Mascara[7]*buffer(f+1,c)+
                                Mascara[8]*buffer(f+1,c+1);
                        }

                }
}


void Matriz::SaltPepper(int n)
{
        for(int f = 0; f <NumeroFilas; f++ )
                for(int c = 0; c <NumeroColumnas; c++ )
                        if(f==0||c==0||f==NumeroFilas-1||c==NumeroColumnas-1)
                                buffer(f,c)=buffer(f,c);
                        else
                        {
                                if(random(100)>n)
                                        if(random(100)>50)
                                                buffer(f,c)=0;
                                else
                                        buffer(f,c)=255;
                        }

}

void Matriz::Mediana(Matriz &Mat)
{
        double aux;
        for(int f = 0; f <NumeroFilas; f++ )
                for(int c = 0; c <NumeroColumnas; c++ )
                {
                        if(f==0||c==0||f==NumeroFilas-1||c==NumeroColumnas-1)
                                Mat.buffer(f,c)=buffer(f,c);
                        else
                        {
                                Mascara[0]=buffer(f-1,c-1);
                                Mascara[1]=buffer(f-1,c);
                                Mascara[2]=buffer(f-1,c+1);
                                Mascara[3]=buffer(f,c-1);
                                Mascara[4]=buffer(f,c);
                                Mascara[5]=buffer(f,c+1);
                                Mascara[6]=buffer(f+1,c-1);
                                Mascara[7]=buffer(f+1,c);
                                Mascara[8]=buffer(f+1,c+1);
                                aux=0;
                                for(int i=0;i<9;i++)
                                        for(int j=0;j<8;j++)
                                        {
                                            if(Mascara[j]>Mascara[j+1])
                                            {
                                                aux=Mascara[j+1];
                                                Mascara[j+1]=Mascara[j];
                                                Mascara[j]=aux;
                                            }
                                        }
                         }
                        Mat.buffer(f,c)=Mascara[4];
                }
        //ordeno y reemplazo
}

void Matriz::Escalar(Matriz &Mat, double fescala, int posx, int posy)
{
        int x=posx,y=posy,x1,y1;
        fescala=1/fescala;
        for(int f = 0; f <NumeroFilas; f++ )
                for(int c = 0; c <NumeroColumnas; c++ )
                {
                        x1=fescala*(c-x)+x;
                        y1=fescala*(f-y)+y;

                        if(x1>255||x1<0||y1>255||y1<0)
                        {
                                  Mat.buffer(f,c)=0;
                        }
                        else
                        {
                                  Mat.buffer(f,c)=buffer(y1,x1);
                        }
                }
}

void Matriz::Bilinear(Matriz &Mat, double fescala, int posx, int posy)
{
        int x=posx,y=posy,b1,b2,b3,b4;
        double x1,y1,dx,dy;
        fescala=1/fescala;
        for(int f = 0; f <NumeroFilas-1; f++ )
                for(int c = 0; c <NumeroColumnas-1; c++ )
                {
                        x1=fescala*(c-x)+x;
                        y1=fescala*(f-y)+y;

                        if(x1>=255||x1<=0||y1>=255||y1<=0)
                        {
                                  Mat.buffer(f,c)=0;
                        }
                        else
                        {
                                dy=y1-(int)y1;
                                dx=x1-(int)x1;
                                Mat.buffer(f,c)=(1-dx)*(1-dy)*buffer(y1,x1)+
                                (1-dx)*dy*buffer(y1+1,x1)+dx*(1-dy)*buffer(y1,x1+1)+
                                dx*dy*buffer(y1+1,x1+1);

                                /*dy=y1-(int)y1;
                                Mat.buffer(f,c)=(1-dy)*(buffer(y1,x1)+
                                buffer(y1,x1+1))/2+dy*(buffer(y1+1,x1)+
                                buffer(y1+1,x1+1))/2;*/
                        }


                }
}

void Matriz::Rotar(Matriz &Mat,int grad,int posx,int posy)
{
        int x1,y1;
        for(int f = 0; f <NumeroFilas; f++ )
                for(int c = 0; c <NumeroColumnas; c++ )
                {
                        x1=(c-posx)*cos(2*M_PI/360*grad)-(f-posy)*sin(2*M_PI/360*grad);
        	        y1=(c-posx)*sin(2*M_PI/360*grad)+(f-posy)*cos(2*M_PI/360*grad);
                        if(x1+posx<0||x1+posx>255||y1+posy<0||y1+posy>255)
                                Mat.buffer(f,c)=0;
                        else
                                Mat.buffer(f,c)=buffer(y1+posy,x1+posx);
                }

}

void Matriz::Trasladar(Matriz &Mat,int posx,int posy)
{
        for(int f = 0; f <NumeroFilas; f++ )
                for(int c = 0; c <NumeroColumnas; c++ )
                {
                        if(c+posx<0||c+posx>255||f+posy<0||f+posy>255)
                                Mat.buffer(f,c)=0;
                        else
                                Mat.buffer(f,c)=buffer(posy+f,posx+c);
                }
}

void Matriz::PBajos(Matriz &Mat)
{
     double Mask[9]={(double)1/9,(double)1/9,(double)1/9,(double)1/9,(double)1/9,
     (double)1/9,(double)1/9,(double)1/9,(double)1/9};
     setMask(Mask);
     applyMask(Mat);
}

void Matriz::PAltos(Matriz &Mat)
{
     double Mask[9]={(double)-1/9,(double)-1/9,(double)-1/9,(double)-1/9,(double)8/9,(double)-1/9,(double)-1/9,(double)-1/9,(double)-1/9};
     setMask(Mask);
     applyMask(Mat);
}

void Matriz::HighBoost(Matriz &Mat,double A)
{
        //Matriz PB;
        double aux;
        //this->PBajos(PB);
        for(int f = 0; f <NumeroFilas; f++ )
                for(int c = 0; c <NumeroColumnas; c++ )
                {
                        if(f==0||f==255||c==255||c==0)
                                Mat.buffer(f,c)=A*buffer(f,c);
                        else
                                Mat.buffer(f,c)=A*buffer(f,c)-1/9*(buffer(f-1,c-1)+
                                buffer(f-1,c)+buffer(f-1,c+1)+buffer(f,c-1)+buffer(f,c)+
                                buffer(f,c+1)+buffer(f+1,c-1)+buffer(f+1,c)+buffer(f+1,c+1));

                        //Mat.buffer(f,c)=A*Mat.buffer(f,c);
                        /*if(aux>255)
                                        aux=255;
                        if(aux<0)
                                        aux=0;
                        Mat.buffer(f,c)=aux; */
                }
        //Mat=Mat-PB;
}

void Matriz::Sobel(Matriz &Mat)
{
        double SH[] = {-1, 0, 1, -2, 0, 2, -1, 0, 1};
        double SV[] = {1, 2, 1, 0, 0, 0, -1, -2, -1};
        float SobelH[256][256], SobelV[256][256];
        for(int f = 0; f <NumeroFilas; f++ )
                for(int c = 0; c <NumeroColumnas; c++ )
                {
                        if(f==0||c==0||f==NumeroFilas-1||c==NumeroColumnas-1)
                                Mat.buffer(f,c)=buffer(f,c);
                        else
                        {
                                SobelH[f][c]=SH[0]*buffer(f-1,c-1)+SH[1]*buffer(f-1,c)+
                                SH[2]*buffer(f-1,c+1)+SH[3]*buffer(f,c-1)+SH[4]*buffer(f,c)+SH[5]*buffer(f,c+1)+
                                SH[6]*buffer(f+1,c-1)+SH[7]*buffer(f+1,c)+SH[8]*buffer(f+1,c+1);

                                SobelV[f][c]=SV[0]*buffer(f-1,c-1)+SV[1]*buffer(f-1,c)+
                                SV[2]*buffer(f-1,c+1)+SV[3]*buffer(f,c-1)+SV[4]*buffer(f,c)+SV[5]*buffer(f,c+1)+
                                SV[6]*buffer(f+1,c-1)+SV[7]*buffer(f+1,c)+SV[8]*buffer(f+1,c+1);
                        }
                }
         for(int f = 0; f <NumeroFilas; f++ )
                for(int c = 0; c <NumeroColumnas; c++ )
                        Mat.buffer(f,c)=sqrt(pow((int)SobelH[f][c],2)+pow((int)SobelV[f][c],2));
}

void Matriz::Prewitt(Matriz &Mat)
{
        int PH[] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
        int PV[] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
        float PreH[256][256], PreV[256][256];
        for(int f = 0; f <NumeroFilas; f++ )
                for(int c = 0; c <NumeroColumnas; c++ )
                {
                        if(f==0||c==0||f==NumeroFilas-1||c==NumeroColumnas-1)
                                buffer(f,c)=buffer(f,c);
                        else
                        {
                                PreH[f][c]=PH[0]*buffer(f-1,c-1)+PH[1]*buffer(f-1,c)+
                                PH[2]*buffer(f-1,c+1)+PH[3]*buffer(f,c-1)+PH[4]*buffer(f,c)+PH[5]*buffer(f,c+1)+
                                PH[6]*buffer(f+1,c-1)+PH[7]*buffer(f+1,c)+PH[8]*buffer(f+1,c+1);

                                PreV[f][c]=PV[0]*buffer(f-1,c-1)+PV[1]*buffer(f-1,c)+
                                PV[2]*buffer(f-1,c+1)+PV[3]*buffer(f,c-1)+PV[4]*buffer(f,c)+PV[5]*buffer(f,c+1)+
                                PV[6]*buffer(f+1,c-1)+PV[7]*buffer(f+1,c)+PV[8]*buffer(f+1,c+1);
                        }
                }
         for(int f = 0; f <NumeroFilas; f++ )
                for(int c = 0; c <NumeroColumnas; c++ )
                        Mat.buffer(f,c)=sqrt(pow((int)PreH[f][c],2)+pow((int)PreV[f][c],2));
}

void Matriz::Laplaciano(Matriz &Mat)
{
        double Mask[9]={0,(double)-1/4,0,(double)-1/4,(double)1,(double)-1/4,0,(double)-1/4,0};
        setMask(Mask);
        applyMask(Mat);
}

int Matriz::IBR(int m, int v)
{
        int p=0, c;
	for (int i=0;i<v;i++)
        {
	        c=(m>>i)&1;
	        p+=c<<(v-i-1);
	}

        return p;
}

void Matriz::FFT(double *xr, double *xi, double *XR, double *XI, bool inverse)
{
        //ENTRADAS
        // xr parte real de la señal
        // xi parte imaginaria de la señal
        // inverse == true/false  -> realiza la transformada directa/inversa
        // SALIDAS
        // XR parte real de la señal transformada
        // XI parte imaginaria de la señal transformada
    	double N=256;
    	double v;
    	double A=1.0;
    	double s=1;
    	if (inverse==true)
                s=-1.0;
    	v=log(N)/log(2);
    	double *WRn=new double[(int)N];
    	double *WIn=new double[(int)N];

    	for (int d=0;d<(int)N;d++)
        {
        	XR[d]=xr[d];			//copio los valores
    		XI[d]=xi[d];
    		WRn[d]=cos(2*M_PI*d/N);
    		WIn[d]=s*sin(2*M_PI*d/N);
    	}
    	int k=0;
    	int L=1;
    	double N2=N/2;
        double m;
        int p;
        double T1R,T1I;
        double Aux;
    	while (L<=v)
        {					//mientras L menor q v
                int I=0;
    		m=(k>>((int)v-L));
    		p=IBR((int)m,(int)v);
    		while(I<N2)
                {
                        T1R=(WRn[p]*XR[k+(int)N2]-WIn[p]*XI[k+(int)N2]);
    			T1I=(WIn[p]*XR[k+(int)N2]+WRn[p]*XI[k+(int)N2]);
    			XR[k+(int)N2]=(XR[k]-T1R);
    			XI[k+(int)N2]=(XI[k]-T1I);
    	  		XR[k]=(XR[k]+T1R);
    			XI[k]=(XI[k]+T1I);
    			k++;
    			I++;
                }
    		k+=N2;
                if(k>=N-1)
                {
                        L++;
			N2=N2/2;
			k=0;
    		}
    	}
        k=0;
        if (inverse==true)
        {
    		A=1/N;
    	        for(int d=0;d<(int)N;d++)
                {
                        XR[d]=A*XR[d];
                        XI[d]=A*XI[d];
    		}
    	}

    	while (k<N-1)
        {
                m=IBR((int)k,(int)v);
     		if(m>k)
                {
    			Aux=XR[k];
    			XR[k]=XR[(int)m];
    			XR[(int)m]=Aux;
    			Aux=XI[k];
    			XI[k]=XI[(int)m];
    			XI[(int)m]=Aux;
    	        }
    		k++;
    	}
}

void Matriz::applyFFT(Matriz &Mat, bool inverse)
{
        float FFTR[256][256],FFTI[256][256];
        double Vector[256],Vector2[256], zeros[256],TR[256],TI[256],tr[256],ti[256];

        for(int f=0;f<NumeroFilas;f++)
                zeros[f]=0.0;

        if(inverse==false) //Si es directa...
        {
                for(int c=0;c<NumeroColumnas;c++)
                {
                        for(int f=0;f<NumeroFilas;f++)
                                Vector[f]=pow(-1,f+c)*buffer(f,c);

                        FFT(Vector,zeros,TR,TI,inverse);

                        for(int f=0;f<NumeroFilas;f++)
                        {
                                FFTR[f][c]=TR[f];
                                FFTI[f][c]=TI[f];
                        }
                }

                for(int f=0;f<NumeroFilas;f++)
                {
                        for(int c=0;c<NumeroColumnas;c++)
                        {
                                Vector[c]=FFTR[f][c];
                                Vector2[c]=FFTI[f][c];
                        }
                        FFT(Vector,Vector2,TR,TI,inverse);
                        for(int c=0;c<NumeroColumnas;c++)
                        {
                                FFTR[f][c] = TR[c];
                                FFTI[f][c] = TI[c];
                        }
                }
                double max=0;
                for(int f=0;f<NumeroFilas;f++)
                        for(int c=0;c<NumeroColumnas;c++)
                        {
                                if(sqrt(FFTR[f][c]*FFTR[f][c]+FFTI[f][c]*FFTI[f][c])>max)
                                        max=sqrt(FFTR[f][c]*FFTR[f][c]+FFTI[f][c]*FFTI[f][c]);
                        }
                float coef=255.00/log10(1+abs(max));
                for(int f=0;f<NumeroFilas;f++)
                        for(int c=0;c<NumeroColumnas;c++)
                        {
                                Mat.buffer(f,c)=255/max*sqrt(FFTR[f][c]*FFTR[f][c] + FFTI[f][c]*FFTI[f][c]);
                                Mat.buffer(f,c)=coef*log10(1+abs(Mat.buffer(f,c)));
                                Mat.Real[f][c]=FFTR[f][c];
                                Mat.Imag[f][c]=FFTI[f][c];
                        }
        }
        else  //Si es inversa...
        {
                for(int c=0;c<NumeroColumnas;c++)
                {
                        for(int f=0;f<NumeroFilas;f++)
                        {
                                Vector[f]=Mat.Real[f][c];
                                Vector2[f]=Mat.Imag[f][c];
                        }

                        FFT(Vector,Vector2,tr,ti,inverse);


                        for(int f=0;f<NumeroFilas;f++)
                        {
                                FFTR[f][c]=tr[f];
                                FFTI[f][c]=ti[f];
                        }
                }

                for(int f=0;f<NumeroFilas;f++)
                {
                        for(int c=0;c<NumeroColumnas;c++)
                        {
                                Vector[c]=FFTR[f][c];
                                Vector2[c]=FFTI[f][c];
                        }

                        FFT(Vector,Vector2,tr,ti,inverse);

                        for(int c=0;c<NumeroColumnas;c++)
                        {
                                FFTR[f][c]=tr[c];
                                FFTI[f][c]=ti[c];
                        }
                }
                float max=0;
                        for(int f=0;f<NumeroFilas;f++)
                                for(int c=0;c<NumeroColumnas;c++)
                                {
                                        if(sqrt(FFTR[f][c]*FFTR[f][c]+FFTI[f][c]*FFTI[f][c])>max)
                                        max=sqrt(FFTR[f][c]*FFTR[f][c]+FFTI[f][c]*FFTI[f][c]);
                                }

                for(int f=0;f<NumeroFilas;f++)
                        for(int c=0;c<NumeroColumnas;c++)
                                Mat.buffer(f,c)=sqrt(FFTR[f][c]*FFTR[f][c] + FFTI[f][c]*FFTI[f][c]);
        }
}

void Matriz::FNotch(Matriz &Mat,int posx,int posy,int diam)
{
        int distx=NumeroColumnas/2-posx;
        int disty=NumeroFilas/2-posy;
        for(int f = 0; f <NumeroFilas; f++ )
                for(int c = 0; c <NumeroColumnas; c++ )
                {
                        if(pow(f-posy,2)+pow(c-posx,2)<=pow(diam/2,2))
                        {
                                Mat.buffer(f,c)=0;
                                Mat.buffer(f+2*disty,c+2*distx)=0;
                                Mat.Real[f][c]=0;
                                Mat.Imag[f][c]=0;
                                Mat.Real[f+2*disty][c+2*distx]=0;
                                Mat.Imag[f+2*disty][c+2*distx]=0;
                        }
                }
}

void Matriz::FPAltos(Matriz &Mat, int radext, int radint)
{
        for(int f = 0; f <NumeroFilas; f++ )
                for(int c = 0; c <NumeroColumnas; c++ )
                {
                        if(pow(f-NumeroFilas/2,2)+pow(c-NumeroColumnas/2,2)<=pow(radext/2,2)&&
                        pow(f-NumeroFilas/2,2)+pow(c-NumeroColumnas/2,2)>=pow(radint/2,2))
                        {
                                Mat.buffer(f,c)=0;
                                Mat.Real[f][c]=0;
                                Mat.Imag[f][c]=0;
                        }

                }
}

void Matriz::FPBajos(Matriz &Mat, int radext, int radint)
{
        for(int f = 0; f <NumeroFilas; f++ )
                for(int c = 0; c <NumeroColumnas; c++ )
                {
                        if(pow(f-NumeroFilas/2,2)+pow(c-NumeroColumnas/2,2)>=pow(radext/2,2)||
                        pow(f-NumeroFilas/2,2)+pow(c-NumeroColumnas/2,2)<=pow(radint/2,2))
                        {
                                Mat.buffer(f,c)=0;
                                Mat.Real[f][c]=0;
                                Mat.Imag[f][c]=0;
                        }

                }
}
void Matriz::DetectPtos(Matriz &Mat,float Treshold)
{
        double Mask[9]={-1,-1,-1,-1,8,-1,-1,-1,-1};
        float L;
        for(int f = 0; f <NumeroFilas; f++ )
                for(int c = 0; c <NumeroColumnas; c++ )
                {
                        if(f==0||c==0||f==NumeroFilas-1||c==NumeroColumnas-1)
                                Mat.buffer(f,c)=0;
                        else
                        {
                                L=fabs(Mask[0]*buffer(f-1,c-1)+Mask[1]*buffer(f-1,c)+
                                Mask[2]*buffer(f-1,c+1)+Mask[3]*buffer(f,c-1)+Mask[4]*buffer(f,c)+
                                Mask[5]*buffer(f,c+1)+Mask[6]*buffer(f+1,c-1)+Mask[7]*buffer(f+1,c)+
                                Mask[8]*buffer(f+1,c+1));
                                if(L>=Treshold)
                                        Mat.buffer(f,c)=buffer(f,c);
                                else
                                        Mat.buffer(f,c)=0;
                        }
                }
}

void Matriz::DetectLineas(Matriz &Mat,float Treshold, double *Mask)
{
        float L,L1,L2,L3;

        for(int f = 0; f <NumeroFilas; f++ )
                for(int c = 0; c <NumeroColumnas; c++ )
                {
                        if(f==0||c==0||f==NumeroFilas-1||c==NumeroColumnas-1)
                                Mat.buffer(f,c)=0;
                        else
                        {
                                L=fabs(Mask[0]*buffer(f-1,c-1)+Mask[1]*buffer(f-1,c)+
                                Mask[2]*buffer(f-1,c+1)+Mask[3]*buffer(f,c-1)+Mask[4]*buffer(f,c)+
                                Mask[5]*buffer(f,c+1)+Mask[6]*buffer(f+1,c-1)+Mask[7]*buffer(f+1,c)+
                                Mask[8]*buffer(f+1,c+1));

                                if(L>=Treshold)
                                        Mat.buffer(f,c)=255;
                                else
                                        Mat.buffer(f,c)=0;
                        }
                }
}
void Matriz::UmbralFijo(Matriz &Mat,double L)
{
        for(int f = 0; f <NumeroFilas; f++ )
                for(int c = 0; c <NumeroColumnas; c++ )
                {
                        if(Mat.buffer(f,c)>=L)
                                Mat.buffer(f,c)=255;
                        else
                                Mat.buffer(f,c)=0;
                }
}

double Matriz::Isodata(Matriz &Mat)
{
        double SumaHI=0,SumaH=0,SumaHI1=0,SumaH1=0,anterior;
        double Umean=128, U0=0, U1=255, min=0, max=255;

        while(Umean-anterior<0.1)
        {
                anterior=Umean;
                for(int i=min;i<max;i++)
                {
                        if(i<=Umean&&i>=min)
                        {
                                SumaHI=SumaHI+Histograma(i)*i;
                                SumaH=SumaH+Histograma(i);
                        }
                        if(i>Umean&&i<=max)
                        {
                                SumaHI1=SumaHI1+Histograma(i)*i;
                                SumaH1=SumaH1+Histograma(i);
                        }
                }
                U0=SumaHI/SumaH;
                U1=SumaHI1/SumaH1;
                Umean=U0+U1/2;
        }
        return Umean;
}

void Matriz::LadyBug(Matriz &Mat,int posx, int posy)
{
        for(int f = 0; f <NumeroFilas; f++ )
                for(int c = 0; c <NumeroColumnas; c++ )
                        Mat.buffer(f,c)=0;

        //         1
        //    4    *    2
        //         3
        int dir=1,startx,starty,nextx,nexty,n=0;

        while(buffer(posy,posx)!=255&&posy>=0&&posx<=255)//&&posy!=0&&posy!=255)
        {
                posy--;
        }
        posy++;
        startx=posx;
        starty=posy;
        nextx=posx;
        nexty=posy;
        while(n!=2)
        {
                switch (dir)
                {
                        case 1:
                                nexty--;
                                if(buffer(nexty,nextx)==255&&nexty>=0&&nextx<=255&&nextx>=0&&nexty<=255)
                                        dir=2;
                                else
                                        dir=4;
                                Mat.buffer(nexty,nextx)=255;
                                break;
                        case 2:
                                nextx++;
                                if(buffer(nexty,nextx)==255&&nexty>=0&&nextx<=255&&nextx>=0&&nexty<=255)
                                        dir=3;
                                else
                                        dir=1;
                                Mat.buffer(nexty,nextx)=255;
                                break;
                        case 3:
                                nexty++;
                                if(buffer(nexty,nextx)==255&&nexty>=0&&nextx<=255&&nextx>=0&&nexty<=255)
                                        dir=4;
                                else
                                        dir=2;
                                Mat.buffer(nexty,nextx)=255;
                                break;
                        case 4:
                                nextx--;
                                if(buffer(nexty,nextx)==255&&nexty>=0&&nextx<=255&&nextx>=0&&nexty<=255)
                                        dir=1;
                                else
                                        dir=3;
                                Mat.buffer(nexty,nextx)=255;
                                break;
                        default:
                                break;
                }
                if(startx==nextx&&starty==nexty)
                        n++;
        }
}

void Matriz::Slicing(Matriz & Mat, int sup, int inf)
{
         for(int f = 0; f <NumeroFilas; f++ )
                for(int c = 0; c <NumeroColumnas; c++ )
                        if(Mat.buffer(f,c)>sup||Mat.buffer(f,c)<inf)
                                Mat.buffer(f,c)=0;
}

void Matriz::ContrastStrech(Matriz & Mat)
{
        int min=0, max=0;
        for(int i=0;i<256;i++)
        {
                if(Histograma(i)>0)
                {
                        min=i;
                        break;
                }
        }
        for(int i=0;i<256;i++)
        {
                if(Histograma(255-i)>0)
                {
                        max=255-i;
                        break;
                }
        }
        for(int f = 0; f <NumeroFilas; f++ )
                for(int c = 0; c <NumeroColumnas; c++ )
                {
                        Mat.buffer(f,c)=(buffer(f,c)-min)*(255-0)/(max-min)+0;
                }
}
