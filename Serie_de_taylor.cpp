/* 		Serie_de_taylor.cpp
 * Este programa nos sirve para aproximar la serie de taylor
 * de la funcion e^1 usando n iteraciones definidas por el usuario. 
 *
 */

#include <iostream>
#include <cmath>

using namespace std;

double calcularFactorial(int n) {
    if (n <= 1)
        return 1;
    else
        return n * calcularFactorial(n - 1);
}

double calcularExp(double x, int n) {
    double resultado = 0.0;
    for (int i = 0; i <= n; i++) {
        double termino = std::pow(x, i) / calcularFactorial(i);
        resultado += termino;
    }
    return resultado;
}

void taylor_main() {
    double x = 1;
    int n;

    cout << "Ingrese la cantidad de iteraciones (n): ";
    cin >> n;

    double resultado = calcularExp(x, n);

    cout << "El resultado de exp(" << x << ") utilizando " << n << " términos es: " << resultado << endl;
}

int main(){
	taylor_main();
	return 0;
}

