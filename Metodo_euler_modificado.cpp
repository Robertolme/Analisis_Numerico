/* 	  Metdo de euler modificado.cpp
 * Este programa resulve una ecuacion
 * dieferncial usando el metodo de euler modificad modificadoo
 */


#include <iostream>
#include <cmath>

using namespace std;

double funcion(double x, double y) {
    // Aquí defines la ecuación diferencial que quieres resolver
    // Por ejemplo, vamos a resolver la ecuación y' = x + y
    return x + y;
}

void metodoEulerModificado(double x0, double y0, double h, double xf) {
    double x = x0;
    double y = y0;

    while (x <= xf) {
        cout << "x = " << x << ", y = " << y << endl;

        // Calculamos los valores auxiliares para el método de Euler modificado
        double k1 = h * funcion(x, y);
        double k2 = h * funcion(x + h, y + k1);

        // Calculamos el siguiente valor de y utilizando el método de Euler modificado
        y = y + 0.5 * (k1 + k2);
        x = x + h;
    }
}

int eulerm_main() {
    double x0, y0, h, xf;

    cout << "Ingrese el valor inicial de x (x0): ";
    cin >> x0;

    cout << "Ingrese el valor inicial de y (y0): ";
    cin >> y0;

    cout << "Ingrese el tamaño del paso (h): ";
    cin >> h;

    cout << "Ingrese el valor final de x (xf): ";
    cin >> xf;

    metodoEulerModificado(x0, y0, h, xf);

    return 0;
}

int main(){
	eulerm_main();
	return 0;
}
