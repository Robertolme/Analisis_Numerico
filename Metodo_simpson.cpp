/* 	  Metdo de simpson.cpp
 * Este programa resulve una integral de 
 * manera numerica usando el metodo del 
 * simpson 1/3
 */

#include <iostream>
#include <cmath>

using namespace std;

double funcion(double x) {
    // Aquí defines la función que quieres integrar
    // Por ejemplo, vamos a integrar la función f(x) = x^2
    return x * x;
}

double integracionNumerica(double a, double b, int n) {
    double h = (b - a) / n; // Tamaño del intervalo
    double suma = 0.0;

    // Calculamos la suma de los términos impares
    for (int i = 1; i < n; i += 2) {
        double x = a + i * h;
        suma += funcion(x);
    }

    // Calculamos la suma de los términos pares
    for (int i = 2; i < n; i += 2) {
        double x = a + i * h;
        suma += 2.0 * funcion(x);
    }

    // Aplicamos la fórmula de Simpson 1/3
    double integral = (h / 3.0) * (funcion(a) + funcion(b) + 4.0 * suma);

    return integral;
}

void simpson_main() {
    double a, b;
    int n;
    double resultado;

    cout << "Ingrese el límite inferior de integración (a): ";
    cin >> a;

    cout << "Ingrese el límite superior de integración (b): ";
    cin >> b;

    cout << "Ingrese el número de subintervalos (n): ";
    cin >> n;

    resultado = integracionNumerica(a, b, n);

    cout << "El valor de la integral numérica es: " << resultado << endl;
}

int main(){
	simpson_main();
	return 0;
}

