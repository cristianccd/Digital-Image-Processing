package PDS;

public abstract class OpFrec extends Senales
{
    public abstract void run();

    public void DFT(double[] xr,double[] xi,double XR[], double XI[],boolean inverse)
    {
    	
    //ENTRADAS
    // xr parte real de la señal
    // xi parte imaginaria de la señal
    // inverse == true/false  -> realiza la transformada inversa/directa     	
    // SALIDAS
    // XR parte real de la señal transformada
    // XI parte imaginaria de la señal transformada
    	
    	double A=1;
    	double S=1;
    	
    	if (inverse==true){
    		S=-1;
    		A=1/1024.0;
    	}

    	
    	double N=1024;
    	
    	for(int k=0;k<1024;k++){
    		XR[k]=0; XI[k]=0;
    		
    		for (int n=0;n<1024;n++){
    			
    		XR[k]=XR[k]+A*((xr[n]*Math.cos(2*Math.PI*k*n/N))+S*(xi[n]*Math.sin(2*Math.PI*k*n/N)));
    		
    		XI[k]=XI[k]+A*((xi[n]*Math.cos(2*Math.PI*k*n/N))-S*(xr[n]*Math.sin(2*Math.PI*k*n/N)));
    			
    		}
    		
    	}
    }
    
    	public void AmpFase(double[] real,double[] img, double[] mod, double[] fase)
    {
    // ENTRADAS
	// xr parte real señal
	// xi parte imaginaria señal
    // SALIDAS
    // mod modulo de la señal
    // fase fase de la señal
    	
    	double e=0.0000001;	
    		
    	for (int k=0;k<1024;k++){
    		
			mod[k]=Math.sqrt(real[k]*real[k]+img[k]*img[k]);
    		
			if (mod[k]<e){
				fase[k]=0;
			}
			else {
				
				if (real[k]<e){

					if(img[k]>0){
						fase[k]=Math.PI/2;
					}
					else if(img[k]<0){
						fase[k]=-1*Math.PI/2;
					}

				}
				else {
					
					fase[k]=Math.atan(img[k]/real[k]);
					
				}
			}
    	
    	}	
    		
    }


   int Inverted_bit_rutine(int m, int v)
    {
	   int p=0;
	   int c;
	   
	   for (int i=0;i<v;i++){
		   c=(m>>i)&1;
		   p+=c<<(v-i-1);
	   }
	   
	   return p;
    }

    public void FFT(double[] xr, double[] xi, double[] XR, double[]XI, boolean inverse)
    {
        //ENTRADAS
        // xr parte real de la señal
        // xi parte imaginaria de la señal
        // inverse == true/false  -> realiza la transformada directa/inversa     	
        // SALIDAS
        // XR parte real de la señal transformada
        // XI parte imaginaria de la señal transformada
    	
    	double N=1024.0;
    	
    	double v;
    	
    	double A=1.0;
    	
    	double s=1;
    	
    	if (inverse==true){
    		
    		s=-1.0;
    		
    	}
    	
    	
    	v=Math.log(N)/Math.log(2);
    	
    	double WRn[]=new double[(int)N];
    	double WIn[]=new double[(int)N];  	
    	
    	for (int d=0;d<(int)N;d++){
    		
    		XR[d]=xr[d];			//copio los valores
    		XI[d]=xi[d];
    		WRn[d]=Math.cos(2*Math.PI*d/N);
    		WIn[d]=s*Math.sin(2*Math.PI*d/N);
    		
    	}
    	
    	
    	int k=0;
    	int L=1;
    	double N2=N/2;
		
		double m;
		int p;
		double T1R,T1I;
		double Aux;
		
		
		
    	while (L<=v){					//mientras L menor q v
    		int I=0;
    		m=(k>>((int)v-L));

    		p=Inverted_bit_rutine((int)m,(int)v);
    		
    		while(I<N2){
    			
    			T1R=(WRn[p]*XR[k+(int)N2]-WIn[p]*XI[k+(int)N2]); 
    			T1I=(WIn[p]*XR[k+(int)N2]+WRn[p]*XI[k+(int)N2]);
    			
    			XR[k+(int)N2]=(XR[k]-T1R);
    			XI[k+(int)N2]=(XI[k]-T1I);
    										//butterfly
    			XR[k]=(XR[k]+T1R);
    			XI[k]=(XI[k]+T1I);
    			
    			
    			k++;
    			I++;

    			}
			
    		k+=N2;
			
			if(k>=N-1){
				L++;
				N2=N2/2;
				k=0;
    		}
    	}
    	

    	
    	
    	k=0;
    	
    	if (inverse==true){
    		A=1/N;
    		
    		for(int d=0;d<(int)N;d++){
    			XR[d]=A*XR[d];
    			XI[d]=A*XI[d];
    		}
    		
    	}

    	while (k<N-1){	//ordeno el vector
    		
    		m=Inverted_bit_rutine((int)k,(int)v);
    	
    		if(m>k){
    			
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
  
    public void filtroFrecuencialPasaBajo(double[] XR, double[] XI, double fc)
    {
     //ENTRADAS
     // XR parte real de la señal transformada
     // XI parte imaginaria de la señal transformada
     // fc frecuencia de corte
     // SALIDAS
     // XR parte real de la señal transformada filtrada
     // XI parte imaginaria de la señal transformada filtrada
    
    int N=1024;
    
    	for (int k=0;k<N;k++){
    		
       		if(k>=(int)fc && k<N-(int)fc)
        		XR[k]=0;
        		XI[k]=0;
    	}
        	
    }

    public void filtroFrecuencialPasaAlto(double[] XR, double[] XI, double fc)
    {
    	 //ENTRADAS
        // XR parte real de la señal transformada
        // XI parte imaginaria de la señal transformada
        // fc frecuencia de corte
        // SALIDAS
        // XR parte real de la señal transformada filtrada
        // XI parte imaginaria de la señal transformada filtrada
    	
        int N=1024;
        
    	for (int k=0;k<N;k++){
    		
    		if(k<(int)fc||k>=N-(int)fc)
    		XR[k]=0;
    		XI[k]=0;
    	}	
    	}
  

    public void filtroFrecuencialPasaBanda(double[] XR, double[] XI, double fci, double fcs)
    {
    	 //ENTRADAS
        // XR parte real de la señal transformada
        // XI parte imaginaria de la señal transformada
        // fc frecuencia de corte
        // SALIDAS
        // XR parte real de la señal transformada filtrada
        // XI parte imaginaria de la señal transformada filtrada
    	
        int N=1024;
        
    	for (int k=0;k<N;k++){
    		
    		if(k<(int)fci||k>=N-(int)fci){
    		XR[k]=0;
    		XI[k]=0;
    		}
    		else if(k>(int)fcs && k>=N-(int)fcs){
    		XR[k]=0;
    		XI[k]=0;
    		}
    	}
    	
         }
    public void filtroFrecuencialEliminaBanda(double[] XR, double[] XI, double fci, double fcs)
    {
    	 //ENTRADAS
        // XR parte real de la señal transformada
        // XI parte imaginaria de la señal transformada
        // fc frecuencia de corte
        // SALIDAS
        // XR parte real de la señal transformada filtrada
        // XI parte imaginaria de la señal transformada filtrada
    	
        int N=1024;
        
    	for (int k=0;k<N;k++){
    		
    		if(k>(int)fci && k<=(int)fcs){
    			XR[k]=0;
    			XI[k]=0;
    		}
    		
    		if(k>N-(int)fcs && k<=N-(int)fci){
    			XR[k]=0;
    			XI[k]=0;
    		}
    	}

    	
           }

    public void FiltroNivel(double[] XR,double[]  XI, double porc)
    {
    	 //ENTRADAS
        // XR parte real de la señal transformada
        // XI parte imaginaria de la señal transformada
        // porc porcentaje de energìa a filtrar 
        // SALIDAS
        // XR parte real de la señal transformada filtrada
        // XI parte imaginaria de la señal transformada filtrada
    	
    	int N=1024;
    	double max=0;
    	
    	for (int k=0;k<N;k++){
    		
    		double pot;
    		
    		pot=XR[k]*XR[k]+XI[k]*XI[k];
    		
    		if(pot>max) max=pot;
    		
    	}
    	
    	max=max*(porc)/100;	//porcentaje del maximo valor de potencia
    	
    	for (int k=0;k<N;k++){
    		
    		double pot;
    		
    		pot=XR[k]*XR[k]+XI[k]*XI[k];
    		
    		if(pot<max){
    			
    			XR[k]=0;
    			XI[k]=0;
    			
    		}
    		
    	}
    	
    	
    }
   

    public void correlacion(double[] x, double[] h, double[] y)
    {
   	    //ENTRADAS
        // x señal a correlacionar x[n]
        // h señal a correlacionar h[n]
        // SALIDAS
        // y señal y[n] resultado de la correlacion de x[n] con h[n]
    
    	int N=1024;
    	
    	double XR[]=new double[N];
    	double HR[]=new double[N];
    	double XI[]=new double[N];
    	double HI[]=new double[N];
    	double xi[]=new double[N];
    	
    	for(int d=0;d<(int)N;d++){
    		
    		xi[d]=0;
    	}
    	
    	FFT(x,xi,XR,XI, false);
    	FFT(h,xi,HR,HI, false);
    	
    	double GxxR[]=new double[N];
    	double GxxI[]=new double[N];
    	
    	for(int d=0;d<N;d++){
    		
    		HI[d]=-HI[d]; //conjugado
    		
    		GxxR[d]=XR[d]*HR[d]-XI[d]*HI[d];
    		GxxI[d]=XR[d]*HI[d]+XI[d]*HR[d];
    		
    	}
    	
    	FFT(GxxR,GxxI,y,xi,true);
    	
    	    	
    }

}
