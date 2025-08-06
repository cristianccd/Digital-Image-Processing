package PDS;

public abstract class Senales extends Thread
{
    public abstract void run();

    public void rectangular(double amplitud, double desplaz, double actividad, double[] y)
    {
  	    //ENTRADAS
        // amplitud amplitud del pulso rectangular
    	// desplaz desplazamiento del pulso en muestras
    	// actividad porcentaje del pulso en estado activo
        // SALIDAS
        // y pulso rectangular y[n]
    
    double a=y.length;
    
    for(int n=0;n<a;n++){
    	y[n]=0;	
    }
    
    double duracion=(actividad/100)*(a-desplaz);
    double i=desplaz+duracion;
    
    if(i<a-1){
    	
    	for (int n=(int)desplaz;n<i;n++){
    		
    		y[n]=amplitud;
    	}
    }
    
    }

   public void triangular(double[] y)
    {
       // SALIDAS
       // y señal y[n] triangular
	   
	    double a=y.length;
	    
	    for(int n=0;n<a;n++){
	    	y[n]=0;	
	    }
	    
	    double cruce=512;
    
	    //double primero=cruce/2;
	    //double segundo=cruce+cruce/2;
	    //double pendiente=amplitud/cruce;
	    
   	
	    	for (int n=0;n<cruce/2;n++){
	    		y[n]=n;
	    	}
	    	    	
	    	int i=-1;
	    	
	    	for (int n=(int)cruce/2;n<cruce;n++){
	    		y[n]=i*n+512;
	    	} 
	   
	    	//double h=(cruce/2)+cruce;
	    	
	    	//for (int n=0;n<h;n++){
	    	//	y[n]=-n;
	    	//}
	    	    	
    	
	    	//for (int n=(int)h;n<y.length;n++){
	    	//	y[n]=-i*n+1024;
	    	//} 
    }

    public void delta (double altura, double desplaz, double[] y)
    {
        double a=y.length;
        
        for(int n=0;n<a;n++){
        	y[n]=0;	
        }
        		
        		y[(int)desplaz]=altura;
       
        }


    public void exponencial(double amplitud,double exponente,double desplaz,double[] y)
    {
  	    //ENTRADAS
        // amplitud amplitud inicial de la exponencial
    	// exponente coeficiente de la exponencial
        // desplaz desplazamiento en muestras
        // SALIDAS
        // y señal y[n] exponencial
    	
    	int N=y.length;
    	
        for(int n=0;n<N;n++){
        	y[n]=0;	
        }
        
        if (desplaz<N){
        
        	for (int n=(int)desplaz;n<N;n++){
        		y[n]=amplitud*Math.exp(n*exponente);    		
        	}
    	
        }
    	
    	
    }

    public void senoidal(double amplitud, double periodos, double fase, double[] y)
    {
 	    //ENTRADAS
        // amplitud amplitud maxima del seno
    	// periodos cantidad de periodos presentes en la salida
        // fase corrimiento de fase de la señal
        // SALIDAS
        // y señal y[n] senoidal
    	
    	int N=y.length;
    	
        for(int n=0;n<N;n++){
        	y[n]=0;	
        }
    	
    	for (int n=0;n<N;n++){
    		y[n]=amplitud*Math.sin(2*Math.PI*(periodos/N)*n+fase);    		
    	}
    	
    	
    }

    public void sinc(double desplaz, double Periodos, double[] y)
    {
        //ENTRADAS
    	// desplaz desplazamiento del pico maximo de la señal
    	// periodos cantidad de periodos presentes en la salida
        // SALIDAS
        // y señal y[n] sinc
    	
	int N=y.length;
    	
        for(int n=0;n<N;n++){
        	y[n]=0;	
        }
    	
        
        
    	for (int n=0;n<N;n++){
    		double h=2*Math.PI*(Periodos/N)*(n-desplaz);
    		if(h!=0){
    		y[n]=Math.sin(h)/h;
    		}
    		else y[n]=1;
    	}
    	
    	
    }

    public void amortiguada (double amplitud,double periodos,double exponente, double[] y)
    {
        //ENTRADAS
        // amplitud amplitud de la senoidal
    	// cantidad del periodos de la senoidal
    	// exponente coeficiente de la exponencial
        // SALIDAS
        // y señal y[n] senoidal amortiguada
    	
    	int N=y.length;
    	
        for(int n=0;n<N;n++){
        	y[n]=0;	
        }
        
        for (int n=0;n<N;n++){
    		y[n]=amplitud*Math.sin(2*Math.PI*(periodos/N)*n)*Math.exp(n*exponente);   		
    	}
    	
    	
        }

    public void senalAM (double a0,double ampPor,double ampMod, double[] y)
    {
        //ENTRADAS
        // a0 señal de continua
    	// ampPor amplitud de la portadora
    	// ampMod amplitud de la modulada
        // SALIDAS
        // y señal y[n] modulada en amplitud
    	
    	int N=y.length;
    	
        for(int n=0;n<N;n++){
        	y[n]=0;	
        }
    	
        
    	double fc,fm,Ac,Am;
    	fc=2*Math.PI*20/N;
    	fm=2*Math.PI*2/N;
    	Ac=ampPor;
    	Am=ampMod;
    	
    	
        for (int n=0;n<N;n++){
    		y[n]=a0+Ac*(1+(Am/Ac)*Math.sin(fm*n)*Math.cos(fc*n));   		
    	}
    	
        }

    public void senalFM(double[] y)
    {
        // SALIDAS
        // y señal y[n] modulada en frecuencia
    	
    	int N=y.length;
    	
        for(int n=0;n<N;n++){
        	y[n]=0;	
        }
    	
        
    	double fc,fm,Ac,Am;
    	fc=2*Math.PI*20/N;
    	fm=2*Math.PI*2/N;
    	Ac=2;
    	Am=2*Ac;
    	
    	
        for (int n=0;n<N;n++){
    		y[n]=Ac*Math.cos(fc*n+Am*Math.sin(n*fm));   		
    	}
    	
    	
    }

    public void ruido(double amplitudMax, double[] y)
    {
        //ENTRADAS
    	// amplitudMax amplitud maxima del ruido
        // SALIDAS
        // y señal y[n] ruido blanco
    
    	int N=y.length;
    	
        for(int n=0;n<N;n++){
        	y[n]=0;	
        }
        
        for (int n=0;n<N;n++){
    		y[n]=amplitudMax*Math.random();   		
    	}
    	
    	
    }
    	
    public void hanning (double[] y)
    {   
        // SALIDAS
        // y señal y[n] ventana de Hanning
    	double N=1024;
    	int i=0;
    	for(i=0;i<N;i++)y[i]=0.5*(1-Math.cos(2*Math.PI*i/(N-1)));
    }

    public void hamming (double[] y)
    {   
        // SALIDAS
        // y señal y[n] ventana de Hamming
    	double N=1024;
    	int i=0;
    	for(i=0;i<N;i++)y[i]=0.54-0.46*Math.cos(2*Math.PI*i/(N-1));
    }

    public void barlett (double[] y)
    {
    	double N=1024;
    	int i=0;
    	for(i=0;i<=(N/2)-1;i++)y[i]=2/(N-2)*i;
    	for(;i<N;i++)y[i]=(-2)/(N-2)*(i-N+1);
    }

    public void blackman (double[] y)
    {
        // SALIDAS
        // y señal y[n] ventana de Blackman
    	double N=1024;
    	int i=0;
    	for(i=0;i<N;i++)y[i]=0.54-0.46*Math.cos(2*Math.PI*i/(N-1))-0.04*Math.cos(4*Math.PI*i/(N-1));
    }

    public void ResultadoAOrigen(double[] bufferResultado, double[] bufferOrigen)
    {   int largo=bufferResultado.length;
        System.arraycopy(bufferResultado, 0, bufferOrigen, 0, largo);
    }
}
