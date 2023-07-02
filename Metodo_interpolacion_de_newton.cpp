/* 	   Metodo de interpolacion de newton.cpp
 * Este programa resulve problemas de interpolacion 
 * usando el metodo de interpolacion de newton
 *
 */

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

typedef vector<double> Fila;
typedef vector<Fila> Matriz;

double diferenciaDividida(const Fila& x, const Fila& y, int inicio, int fin) {
    if (inicio == fin) {
        return y[inicio];
    } else {
        return (diferenciaDividida(x, y, inicio + 1, fin) - diferenciaDividida(x, y, inicio, fin - 1)) / (x[fin] - x[inicio]);
    }
}

double interpolacionNewton(const Fila& x, const Fila& y, double xi) {
    int n = x.size();
    double resultado = 0.0;

    for (int i = 0; i < n; i++) {
        double termino = diferenciaDividida(x, y, 0, i);
        for (int j = 0; j < i; j++) {
            termino *= (xi - x[j]);
        }
        resultado += termino;
    }

    return resultado;
}

int newton_main() {
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

    double resultado = interpolacionNewton(x, y, xi);

    cout << "El valor interpolado es: " << resultado << endl;

    return 0;
}


int main(){
	newton_main();
	return 0;
}
