/*		Newton_rhapson.cpp
 * Este programa sirve para aproximar las raices de una funcion
 * usando el metodo de Newton-rhapson.
 * En este ejemplo se utilizara la funcion x³ + 4x -10  
*/ 
#include <cmath>
#include <iostream>

using namespace std;

float resolverEcuacion(float valor) {
  // Con la ecuación: x^3 + 4x^2 -10
  return pow(valor, 3) + 4 * pow(valor, 2) - 10;
}

float resolverDerivada(float valor) {
  // Con la ecuación: 2x^2 + 8x
  return pow((2 * valor), 2) + 8 * valor;
}

void Newton_main() {
  int iterador = 0;
  float xi = 0.75;
  float xi_xi = 0;
  float ultimo_xi = 0;
  printf("Método de Newton\n");
  printf("Problema: x^3 + 4x^2 -10\n");
  printf("Derivado: 2x^2 + 8x\n\n\n");
  printf("+----+-------------+-------------+-------------+-------------+-------"
         "-----+\n");
  printf("+ i  |      xi     |    f(xi)    |    f'(xi)   |    xi + 1   |    "
         "xi_xi   |\n");
  printf("+----+-------------+-------------+-------------+-------------+-------"
         "-----+\n");
  while (1) {
    float fxi = resolverEcuacion(xi);
    float _fxi = resolverDerivada(xi);
    float xi_1 = xi - (fxi / _fxi);
    printf("|%3d |%12.8f |%12.8f |%12.8f |%12.8f |%12.8f|\n", iterador, xi, fxi,
           _fxi, xi_1, xi_xi);
    iterador++;
    ultimo_xi = xi;
    xi = xi_1;
    xi_xi = abs(xi - ultimo_xi);
    if (xi_xi == 0) {
      printf("+----+-------------+-------------+-------------+-------------+---"
             "---------+\n");
      break;
    }
  }
}

int main(){
	Newton_main();
	return 0;
}
