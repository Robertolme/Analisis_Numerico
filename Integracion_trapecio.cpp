/* 	   Integracion trapecio.cpp
 * Este programa resulve una integral de 
 * manera numerica usando el metodo del 
 * trapecio
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

    // Calculamos la suma de los trapecios
    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        suma += funcion(x);
    }

    // Aplicamos la fórmula del trapecio
    double integral = h * ((funcion(a) + funcion(b)) / 2.0 + suma);

    return integral;
}

int trapecio_main() {
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

    return 0;
}

int main(){
	trapecio_main();
	return 0;
}
