/* 		Metodo de Newton.cpp
 * Este programa resuleve un sistema de 2
 * ecuaciones no lineales usando el metodo de newton
 */

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

typedef vector<double> Fila;
typedef vector<Fila> Matriz;

void imprimirSolucion(const Fila& solucion) {
    int n = solucion.size();

    cout << "La solución del sistema de ecuaciones es:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "x" << i + 1 << " = " << solucion[i] << endl;
    }
}

Fila evaluarFunciones(const Fila& x) {
    // Funciones que representan el sistema de ecuaciones no lineales
    double f1 = pow(x[0], 2) + pow(x[1], 2) - 4;
    double f2 = pow(x[0], 2) - pow(x[1], 2) + 1;

    return Fila{f1, f2};
}

Matriz evaluarJacobiano(const Fila& x) {
    // Calcula el jacobiano del sistema de ecuaciones no lineales
    double j11 = 2 * x[0];
    double j12 = 2 * x[1];
    double j21 = 2 * x[0];
    double j22 = -2 * x[1];

    return Matriz{{j11, j12}, {j21, j22}};
}

Fila restarFilas(const Fila& a, const Fila& b) {
    int n = a.size();
    Fila resultado(n);

    for (int i = 0; i < n; i++) {
        resultado[i] = a[i] - b[i];
    }

    return resultado;
}

Fila newton(const Fila& x0, double tolerancia, int iteracionesMax) {
    Fila x = x0;
    int iteraciones = 0;

    while (iteraciones < iteracionesMax) {
        Fila f = evaluarFunciones(x);
        Matriz J = evaluarJacobiano(x);

        if (abs(f[0]) < tolerancia && abs(f[1]) < tolerancia) {
            cout << "El método converge en " << iteraciones << " iteraciones." << endl;
            return x;
        }

        Matriz J_inv(2, Fila(2));
        double determinante = J[0][0] * J[1][1] - J[0][1] * J[1][0];
        J_inv[0][0] = J[1][1] / determinante;
        J_inv[0][1] = -J[0][1] / determinante;
        J_inv[1][0] = -J[1][0] / determinante;
        J_inv[1][1] = J[0][0] / determinante;

        Fila delta = restarFilas(J_inv[0], J_inv[1]);

        x = restarFilas(x, delta);
        iteraciones++;
    }

    cout << "El método no converge después de " << iteraciones << " iteraciones." << endl;
    return Fila();
}

void newton_main() {
    Fila x0(2);
    double tolerancia;
    int iteracionesMax;

    cout << "Ingrese el valor inicial x1: ";
    cin >> x0[0];

    cout << "Ingrese el valor inicial x2: ";
    cin >> x0[1];

    cout << "Ingrese la tolerancia: ";
    cin >> tolerancia;

    cout << "Ingrese el número máximo de iteraciones: ";
    cin >> iteracionesMax;

    Fila solucion = newton(x0, tolerancia, iteracionesMax);

    if (!solucion.empty()) {
        imprimirSolucion(solucion);
    }
}


int main(){
	newton_main();
	return 0;
}
