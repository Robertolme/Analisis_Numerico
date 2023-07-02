/*Este programa nos ayuda a verificar cual es el modo 
 * en el que trabaja la maquina es decir si la pc 
 * emplea radianes o grados para operar*/

#include <iostream>
#include <cmath>

using namespace std;
void Modo_main();

int main(int argc, char* argv[]){
	Modo_main();
	return 0;
}

void Modo_main(){
	cout<<"Sen(1)="<<sin(1)<<endl;
	cout<<"Sen(2)="<<sin(2)<<endl;

	cout<<"Podemos observar que la computadora por defecto opera en radianes\n";
}
