/* 			epsilon.cpp
 * Este programa sirve para determinar el 0 de la maquina es decir
 * la precicion que tiene la maquina para determinar el 0
 */

#include <iostream>
#include <limits>

void main_epsilon();

int main() {
	main_epsilon();
	return 0;
}

void main_epsilon(){
    // Obtener el epsilon de la máquina para números de punto flotante
    float epsilonFloat = std::numeric_limits<float>::epsilon();
    double epsilonDouble = std::numeric_limits<double>::epsilon();

    std::cout << "Epsilon de la máquina (float): " << epsilonFloat << std::endl;
    std::cout << "Epsilon de la máquina (double): " << epsilonDouble << std::endl;


}

