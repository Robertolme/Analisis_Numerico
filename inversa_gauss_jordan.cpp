/* 	Inversa por Gauss- Jordan.cpp
 * Este programa determina la matriz inversa para
 * un sistema de ecuaciones usando el metodo
 * de gauss jordan
 */

#include <iostream>
#include <vector>

using namespace std;

typedef vector<double> Fila;
typedef vector<Fila> Matriz;

void intercambiarFilas(Matriz& matriz, int fila1, int fila2) {
    Fila temp = matriz[fila1];
    matriz[fila1] = matriz[fila2];
    matriz[fila2] = temp;
}

void dividirFila(Matriz& matriz, int fila, double divisor) {
    int n = matriz[fila].size();

    for (int i = 0; i < n; i++) {
        matriz[fila][i] /= divisor;
    }
}

void restarFilas(Matriz& matriz, int fila1, int fila2, double factor) {
    int n = matriz[fila1].size();

    for (int i = 0; i < n; i++) {
        matriz[fila1][i] -= matriz[fila2][i] * factor;
    }
}

Matriz obtenerMatrizInversa(Matriz matriz) {
    int n = matriz.size();
    Matriz matrizExtendida(n, Fila(2 * n));

    // Crear matriz extendida con la matriz original y una matriz identidad
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrizExtendida[i][j] = matriz[i][j];
        }
        matrizExtendida[i][i + n] = 1;
    }

    // Aplicar Gauss-Jordan a la matriz extendida
    for (int i = 0; i < n; i++) {
        // Paso 1: Encontrar el elemento pivote máximo en la columna actual
        int filaPivote = i;
        for (int j = i + 1; j < n; j++) {
            if (abs(matrizExtendida[j][i]) > abs(matrizExtendida[filaPivote][i])) {
                filaPivote = j;
            }
        }

        // Paso 2: Intercambiar filas si es necesario
        if (filaPivote != i) {
            intercambiarFilas(matrizExtendida, i, filaPivote);
        }

        // Paso 3: Convertir el elemento pivote en 1 y dividir la fila
        dividirFila(matrizExtendida, i, matrizExtendida[i][i]);

        // Paso 4: Eliminación hacia adelante y hacia atrás
        for (int j = 0; j < n; j++) {
            if (j != i) {
                restarFilas(matrizExtendida, j, i, matrizExtendida[j][i]);
            }
        }
    }

    // Extraer la matriz inversa de la matriz extendida
    Matriz matrizInversa(n, Fila(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrizInversa[i][j] = matrizExtendida[i][j + n];
        }
    }

    return matrizInversa;
}

void imprimirMatriz(Matriz& matriz) {
    int filas = matriz.size();
    int columnas = matriz[0].size();

    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

void inversa_main() {
    int n;

    cout << "Ingrese el número de ecuaciones: ";
    cin >> n;

    Matriz matriz(n, Fila(n));

    cout << "Ingrese los coeficientes de las ecuaciones:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "Ingrese el coeficiente A(" << i + 1 << "," << j + 1 << "): ";
            cin >> matriz[i][j];
        }
    }

    Matriz matrizInversa = obtenerMatrizInversa(matriz);

    cout << "La matriz inversa es:" << endl;
    imprimirMatriz(matrizInversa);

    return;
}

int main(){
	inversa_main();
	return 0;
}



