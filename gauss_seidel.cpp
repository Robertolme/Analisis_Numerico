/* 		Gauss- seidel.cpp
 * Este programa resuleve las soluciones para
 * un sistema de ecuaciones usando el metodo
 * de gauss seidel
 */

#include <iostream>
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

Fila gaussSeidel(const Matriz& sistema, const Fila& b, double tolerancia, int iteracionesMax) {
    int n = sistema.size();
    Fila solucionAnterior(n, 0.0);
    Fila solucionActual(n, 0.0);
    int iteraciones = 0;
    bool convergencia = false;

    while (!convergencia && iteraciones < iteracionesMax) {
        solucionAnterior = solucionActual;
        for (int i = 0; i < n; i++) {
            double suma = 0.0;
            for (int j = 0; j < n; j++) {
                if (j != i) {
                    suma += sistema[i][j] * solucionActual[j];
                }
            }
            solucionActual[i] = (b[i] - suma) / sistema[i][i];
        }

        double error = 0.0;
        for (int i = 0; i < n; i++) {
            error += abs(solucionActual[i] - solucionAnterior[i]);
        }

        if (error < tolerancia) {
            convergencia = true;
        }

        iteraciones++;
    }

    if (convergencia) {
        cout << "El método convergió en " << iteraciones << " iteraciones." << endl;
        return solucionActual;
    } else {
        cout << "El método no converge después de " << iteraciones << " iteraciones." << endl;
        return Fila();
    }
}

void seidel_main() {
    int n;

    cout << "Ingrese el número de ecuaciones: ";
    cin >> n;

    Matriz sistema(n, Fila(n));
    Fila b(n);

    cout << "Ingrese los coeficientes de las ecuaciones:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "Ingrese el coeficiente A(" << i + 1 << "," << j + 1 << "): ";
            cin >> sistema[i][j];
        }
        cout << "Ingrese el término independiente B(" << i + 1 << "): ";
        cin >> b[i];
    }

    double tolerancia;
    int iteracionesMax;

    cout << "Ingrese la tolerancia: ";
    cin >> tolerancia;

    cout << "Ingrese el número máximo de iteraciones: ";
    cin >> iteracionesMax;

    Fila solucion = gaussSeidel(sistema, b, tolerancia, iteracionesMax);

    if (!solucion.empty()) {
        imprimirSolucion(solucion);
    }
}


int main(){
	seidel_main();
	return 0;
}
