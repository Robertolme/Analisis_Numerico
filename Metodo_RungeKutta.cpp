/* 	  Metdo de RungeKutta.cpp
 * Este programa resulve una ecuacion
 * dieferncial usando el metodo de runge - Kutta
 */

#include <iostream>
#include <cmath>

using namespace std;

double funcion(double x, double y) {
    // Aquí defines la ecuación diferencial que quieres resolver
    // Por ejemplo, vamos a resolver la ecuación y' = x + y
    return x + y;
}

void metodoRungeKutta(double x0, double y0, double h, double xf) {
    double x = x0;
    double y = y0;

    while (x <= xf) {
        cout << "x = " << x << ", y = " << y << endl;

        // Calculamos los valores auxiliares para el método de Runge-Kutta de cuarto orden
        double k1 = h * funcion(x, y);
        double k2 = h * funcion(x + 0.5 * h, y + 0.5 * k1);
        double k3 = h * funcion(x + 0.5 * h, y + 0.5 * k2);
        double k4 = h * funcion(x + h, y + k3);

        // Calculamos el siguiente valor de y utilizando el método de Runge-Kutta de cuarto orden
        y = y + (1.0 / 6.0) * (k1 + 2.0 * k2 + 2.0 * k3 + k4);
        x = x + h;
    }
}

int runge_main() {
    double x0, y0, h, xf;

    cout << "Ingrese el valor inicial de x (x0): ";
    cin >> x0;

    cout << "Ingrese el valor inicial de y (y0): ";
    cin >> y0;

    cout << "Ingrese el tamaño del paso (h): ";
    cin >> h;

    cout << "Ingrese el valor final de x (xf): ";
    cin >> xf;

    metodoRungeKutta(x0, y0, h, xf);

    return 0;
}

int main(){
	runge_main();
	return 0;
}

