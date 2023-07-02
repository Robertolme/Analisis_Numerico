/* 		Metodo de punto fijo.cpp
 * Este programa permite determinar las raices de una fucion 
 * utilizando el metodo de punto fijo de la funcion
 * " x * x - 4;" con una epsilon y numero
 * de iteraciones definida por el usuario
 */

#include <iostream>
#include <cmath>

using namespace std;

double funcion(double x) {
    return  x * x - 4;;
}

double puntoFijo(double x0, double tolerancia, int iteracionesMax) {
    double x = x0;
    int iteraciones = 0;
    
    while (iteraciones < iteracionesMax) {
        double xAnterior = x;
        x = funcion(xAnterior);
        
        if (abs(x - xAnterior) < tolerancia) {
            cout << "El método convergió en " << iteraciones + 1 << " iteraciones." << endl;
            return x;
        }
        
        iteraciones++;
    }
    
    cout << "El método no converge después de " << iteraciones << " iteraciones." << endl;
    return x;
}

void puntoFijo_main() {
    double x0, tolerancia;
    int iteracionesMax;
    
    cout << "Introduce el valor inicial (x0): ";
    cin >> x0;
    
    cout << "Introduce la tolerancia: ";
    cin >> tolerancia;
    
    cout << "Introduce el número máximo de iteraciones: ";
    cin >> iteracionesMax;
    
    double raiz = puntoFijo(x0, tolerancia, iteracionesMax);
    
    cout << "La raíz aproximada es: " << raiz << endl;
    
}


int main(){
	puntoFijo_main();
	return 0;
}
