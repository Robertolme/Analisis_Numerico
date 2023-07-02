/* 		Gauss- Jordan.cpp
 * Este programa resuleve las soluciones para
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

void gaussJordan(Matriz& matriz) {
    int filas = matriz.size();
    int columnas = matriz[0].size();
    
    for (int i = 0; i < filas; i++) {
        // Paso 1: Encontrar el elemento pivote máximo en la columna actual
        int filaPivote = i;
        for (int j = i + 1; j < filas; j++) {
            if (abs(matriz[j][i]) > abs(matriz[filaPivote][i])) {
                filaPivote = j;
            }
        }
        
        // Paso 2: Intercambiar filas si es necesario
        if (filaPivote != i) {
            intercambiarFilas(matriz, i, filaPivote);
        }
        
        // Paso 3: Convertir el elemento pivote en 1 y dividir la fila
        dividirFila(matriz, i, matriz[i][i]);
        
        // Paso 4: Eliminación hacia adelante y hacia atrás
        for (int j = 0; j < filas; j++) {
            if (j != i) {
                restarFilas(matriz, j, i, matriz[j][i]);
            }
        }
    }
}

void imprimirSolucion(Matriz& matriz) {
    int filas = matriz.size();
    int columnas = matriz[0].size();
    
    cout << "La solución del sistema de ecuaciones es:" << endl;
    for (int i = 0; i < filas; i++) {
        cout << "x" << i + 1 << " = " << matriz[i][columnas - 1] << endl;
    }
}

void gauss_main() {
    int n;
    
    cout << "Ingrese el número de ecuaciones: ";
    cin >> n;
    
    Matriz matriz(n, Fila(n + 1));
    
    cout << "Ingrese los coeficientes de las ecuaciones:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n + 1; j++) {
            cout << "Ingrese el coeficiente A(" << i + 1 << "," << j + 1 << "): ";
            cin >> matriz[i][j];
        }
    }
    
    gaussJordan(matriz);
    imprimirSolucion(matriz);
    
}


int main(){
	gauss_main();
	return 0;
}
