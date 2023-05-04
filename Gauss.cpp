#include <iostream>

using namespace std;

int** insertar_matrix(){
	int** mat = new int*[3];
	for (int i = 0; i < 3; i++) {
        mat[i] = new int[3];
    }
	cout<<"*********************\n***Insertar matrix***\n*********************\n"<<endl;
	for(int i=0;i<3;i++)
		for(int e=0;e<3;e++){
			cout<<"Dame el valor ("<<i<<e<<")"<<endl;
			cin>>mat[i][e];
		}
		
	return mat;
			
}

void imprimir_matrix(int** a){
	cout<<"***Matrix***"<<endl;
	for(int i=0;i<3;i++){
		for(int e=0;e<3;e++){
		cout<<a[i][e]<<"|";
		}
	 cout<<"\n";
	}
}

void multiplicar_linea(int **a, int i, int m){ //direccion de memmoria de la matrix, numero de linea
	for(int e=0;e<3;e++)
		a[i][e]*=m; 	
}


void restar_linea(int **a, int i, int m){ //direccion de memmoria de la matrix, numero de linea
	for(int e=0;e<3;e++)
		a[i][e]-=m; 	
}

int main(){
	int **mat1 = insertar_matrix();
	
	
	imprimir_matrix(mat1);
	
	multiplicar_linea(mat1,2,5);
	
	imprimir_matrix(mat1);
	
}
