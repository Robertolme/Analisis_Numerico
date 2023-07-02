/* 		Metodo de Minimos cuadrados.cpp
 * Este programa resulve problemas de interpolacion 
 * usando el metodo de minimos cuadrados
 * */

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

typedef vector<double> Fila;
typedef vector<Fila> Matriz;

Fila minimosCuadrados(const Fila& x, const Fila& y, int grado) {
    int n = x.size();

    // Construir la matriz A
    Matriz A(grado + 1, Fila(grado + 1, 0.0));
    for (int i = 0; i <= grado; i++) {
        for (int j = 0; j <= grado; j++) {
            for (int k = 0; k < n; k++) {
                A[i][j] += pow(x[k], i + j);
            }
        }
    }

    // Construir el vector b
    Fila b(grado + 1, 0.0);
    for (int i = 0; i <= grado; i++) {
        for (int j = 0; j < n; j++) {
            b[i] += y[j] * pow(x[j], i);
        }
    }

    // Resolver el sistema de ecuaciones lineales
    Fila coeficientes(grado + 1, 0.0);

    for (int i = 0; i <= grado; i++) {
        for (int j = i + 1; j <= grado; j++) {
            double factor = A[j][i] / A[i][i];
            for (int k = i; k <= grado; k++) {
                A[j][k] -= factor * A[i][k];
            }
            b[j] -= factor * b[i];
        }
    }

    for (int i = grado; i >= 0; i--) {
        double suma = 0.0;
        for (int j = i + 1; j <= grado; j++) {
            suma += A[i][j] * coeficientes[j];
        }
        coeficientes[i] = (b[i] - suma) / A[i][i];
    }

    return coeficientes;
}

double evaluarPolinomio(const Fila& coeficientes, double x) {
    int grado = coeficientes.size() - 1;
    double resultado = 0.0;

    for (int i = 0; i <= grado; i++) {
        resultado += coeficientes[i] * pow(x, i);
    }

    return resultado;
}

void minimos_main() {
    int n;
    int grado;

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

    cout << "Ingrese el grado del polinomio de interpolación: ";
    cin >> grado;

    Fila coeficientes = minimosCuadrados(x, y, grado);

    cout << "Los coeficientes del polinomio de interpolación son:" << endl;
    for (int i = 0; i <= grado; i++) {
        cout << "a" << i << " = " << coeficientes[i] << endl;
    }

    double valorInterpolado;
    cout << "Ingrese el valor de x para evaluar el polinomio de interpolación: ";
    cin >> valorInterpolado;

    double resultado = evaluarPolinomio(coeficientes, valorInterpolado);

    cout << "El valor interpolado es: " << resultado << endl;

}

int main(){
	minimos_main();
	return 0;
}

