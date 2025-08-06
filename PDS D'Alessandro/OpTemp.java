package PDS;

public abstract class OpTemp extends Senales
{
    public abstract void run();

    public static void suma(double[] x, double[] h, double[] y)
    {
  	    //ENTRADAS
        // x señal a sumar x[n]
        // h señal a sumar h[n]
        // SALIDAS
        // y señal y[n] resultado de la suma de x[n] con h[n]
    	
    	int N=1024;
    	
    	for(int d=0;d<N;d++){
    		
    		y[d]=x[d]+h[d];
    		
    	}
    	
    	
    }

    public void derivada(double[] x, double[] y)
    { 
  	    //ENTRADAS
        // x señal a derivar x[n]
        // SALIDAS
        // y señal y[n], derivada de x[n]
		int i=0;
    	double N=1024;
    	for(i=0;i<N;i++)y[i]=(x[i+1]-x[i]);
    }

    public static void convolucion(double[] x, double[] h, double[] y )
    {
  	    //ENTRADAS
        // x señal a convolucionar x[n]
        // h señal a convolucionar h[n]
        // SALIDAS
        // y señal y[n] resultado de la convolución de x[n] con h[n]
    	
    	int N=y.length;
    	
        for(int n=0;n<N;n++){
        	y[n]=0;	
        }
        
              
        for (int n=0;n<N;n++){
        	
        	for (int v=0;v<n;v++){
        	
        		y[n]=y[n]+h[v]*x[n-v];
                	
        	}
        }
    	
    	
     }

    public static void ventana(double[] x, double[] h, double[] y)
    {
  	    //ENTRADAS
        // x señal original x[n]
        // h ventana h[n]
        // SALIDAS
        // y señal y[n] resultado multiplicación de x[n] con h[n]
    	int i=0;
    	double N=1024;
    	for(i=0;i<N;i++)y[i]=x[i]*h[i];
    }

    public void FiltroDigital(double[] x, double[] y, double a0,double a1,double a2,double a3,double a4,double b0,double b1,double b2,double b3,double b4)
    {
  	    //ENTRADAS
        // x señal a filtrar x[n]
        // a0,... ,a4  b0,..., b4 coeficientes del filtro (denominador y numerador respectivamente)
    	// SALIDAS
        // y señal y[n], resultado de filtrar x[n] en un filtro con coef a0,... ,a4  b0,..., b4
    	double N=1024;
    	int n=0;
    	
    	y[0]=(1/a0)*b0*x[0];
    	y[1]=(1/a0)*((b1*x[0]+b0*x[1])-(a1*y[0]));	
    	y[2]=(1/a0)*((b2*x[0]+b1*x[1]+b0*x[2])-(a2*y[0]+a1*y[1]));
    	y[3]=(1/a0)*((b3*x[0]+b2*x[1]+b1*x[2]+b0*x[3])-(a3*y[0]+a2*y[1]+a1*y[2]));
    	y[4]=(1/a0)*((b4*x[0]+b3*x[1]+b2*x[2]+b1*x[3]+b0*x[4])-(a4*y[0]+a3*y[1]+a2*y[2]+a1*y[3]));
    	for(n=5;n<N;n++)
    	{
    		y[n]=(1/a0)*((b0*x[n]+b1*x[n-1]+b2*x[n-2]+b3*x[n-3]+b4*x[n-4])-(a1*y[n-1]+a2*y[n-2]+a3*y[n-3]+a4*y[n-4]));	
    	}
    }
}
