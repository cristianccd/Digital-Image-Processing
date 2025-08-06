package PDS;

import Grafica.VentanaMenu;
import Grafica.VentanaParametros;


public class Main {
    static public double buffer1[]= new double[1024];
    static public double buffer2[]= new double[1024];
    static public double buffer3[]= new double[1024];
    public static VentanaParametros Parametros;
    public static VentanaMenu ventana;

    public static void main(String[ ] arg)
    {
        ventana = new VentanaMenu();
        Parametros =new VentanaParametros();
        Parametros.setVisible(false);
    }


}
