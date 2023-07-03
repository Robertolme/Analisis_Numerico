/* 	  Metdo de euler.cpp
 * Este programa resulve una ecuacion
 * dieferncial usando el metodo de euler
 */

#include <iostream>
#include <cmath>

using namespace std;

double funcion(double t, double y) {
    // Aquí defines la ecuación diferencial que quieres resolver
    // Por ejemplo, vamos a resolver la ecuación y' = x + y
    return t + y;
}

void metodoEuler(double t0, double y0, double h, double tf) {
    double t = t0;
    double y = y0;

    while (t <= tf) {
        cout << "x = " << t << ", y = " << y << endl;

        // Calculamos el siguiente valor de y utilizando el método de Euler
        y = y + h * funcion(t, y);
        t = t + h;
    }
}

int euler_main() {
    double t0, y0, h, tf;

    cout << "Ingrese el valor inicial de x (t0): ";
    cin >> t0;

    cout << "Ingrese el valor inicial de y (y0): ";
    cin >> y0;

    cout << "Ingrese el tamaño del paso (h): ";
    cin >> h;

    cout << "Ingrese el valor final de t (tf): ";
    cin >> tf;

    metodoEuler(t0, y0, h, tf);

    return 0;
}


int main(){
	euler_main();
	return 0;
}
