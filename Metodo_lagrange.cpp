/* 	    Metodo de lagrange.cpp
 * Este programa resulve problemas de interpolacion 
 * usando el metodo de minimos lagrange
 *
 */

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

typedef vector<double> Fila;

double lagrange(const Fila& x, const Fila& y, double xi) {
    int n = x.size();
    double resultado = 0.0;

    for (int i = 0; i < n; i++) {
        double termino = y[i];
        for (int j = 0; j < n; j++) {
            if (j != i) {
                termino *= (xi - x[j]) / (x[i] - x[j]);
            }
        }
        resultado += termino;
    }

    return resultado;
}

int lagrange_main() {
    int n;

    cout << "Ingrese el número de puntos de interpolación: ";
    cin >> n;

    Fila x(n);
    Fila y(n);

    cout << "Ingrese las coordenadas x y y de los puntos:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Punto " << i + 1 << ":" << endl;
        cout << "x: ";
        cin >> x[i];
        cout << "y: ";
        cin >> y[i];
    }

    double xi;
    cout << "Ingrese el valor de x para interpolar: ";
    cin >> xi;

    double resultado = lagrange(x, y, xi);

    cout << "El valor interpolado es: " << resultado << endl;

    return 0;
}

int main(){
 lagrange_main();
 return 0;
}

