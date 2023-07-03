/* 	   Diferenciacion numerica.cpp
 * Este programa resulve derivadas de manera
 * numerica
 */

#include <iostream>
#include <vector>

using namespace std;

double diferenciacionNumerica(const vector<double>& x, const vector<double>& y, int i) {
    double derivada;

    // Calculamos la diferencia hacia adelante
    derivada = (y[i + 1] - y[i]) / (x[i + 1] - x[i]);

    return derivada;
}

int dif_main() {
    int n;
    vector<double> x;
    vector<double> y;

    cout << "Ingrese el número de puntos de datos: ";
    cin >> n;

    cout << "Ingrese los valores de x:" << endl;
    for (int i = 0; i < n; i++) {
        double valorX;
        cout << "x" << i << ": ";
        cin >> valorX;
        x.push_back(valorX);
    }

    cout << "Ingrese los valores de y:" << endl;
    for (int i = 0; i < n; i++) {
        double valorY;
        cout << "y" << i << ": ";
        cin >> valorY;
        y.push_back(valorY);
    }

    int puntoInteres;
    cout << "Ingrese el índice del punto en el que desea calcular la derivada: ";
    cin >> puntoInteres;

    double resultado = diferenciacionNumerica(x, y, puntoInteres);

    cout << "La derivada numérica en x[" << puntoInteres << "] es: " << resultado << endl;

    return 0;
}

int main(){
	dif_main();
	return 0;
}
