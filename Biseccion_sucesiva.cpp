 /* 		Biseccion_sucesiva.cpp
 * Este programa permite determinar las raices de una fucion 
 * utilizando el metodo de Bisecciones Sucesivas de la funcion
 * "4 x^3 + 5 x^ 2 - 3x - 2" en un itervalo definido por el 
 * usuario.
 */


#include <iostream>
#include <cmath>

using namespace std;

double funcion(double x) {
    // Aquí debes proporcionar la función del polinomio que deseas calcular
    return (4 * x* x * x) + 5 * x * x - 3 * x  - 2; 
}

double calcularRaizBiseccion(double a, double b, double epsilon) {
    double raiz;
    double fa = funcion(a);
    double fb = funcion(b);

    if (fa * fb >= 0) {
        cout << "No se puede aplicar el método de bisección en el intervalo dado." << std::endl;
        return raiz;
    }

    while (std::abs(b - a) > epsilon) {
        raiz = (a + b) / 2;
        double fr = funcion(raiz);

        if (fr == 0) {
            break; // La raíz exacta
        } else if (fa * fr < 0) {
            b = raiz;
            fb = fr;
        } else {
            a = raiz;
            fa = fr;
        }
    }

    return raiz;
}

void Biseccion_main() {
    double a, b, epsilon;

    cout << "Ingrese el intervalo [a, b]: " << std::endl;
    cout << "a: ";
    cin >> a;
    cout << "b: ";
    cin >> b;

    cout << "Ingrese el valor de epsilon: ";
    cin >> epsilon;

    double raiz = calcularRaizBiseccion(a, b, epsilon);

    cout << "La raíz aproximada es: " << raiz << std::endl;

}

int main(){
	Biseccion_main();
	return 0;
}

