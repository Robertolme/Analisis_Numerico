#include <iostream>

using namespace std;

int x = 4;
int y = 3;

int** insertar_matrix(){
	int** mat = new int*[y];
	for (int i = 0; i < y; i++) {
        mat[i] = new int[x];
    }
	cout<<"*********************\n***Insertar matrix***\n*********************\n"<<endl;
	for(int i=0;i<y;i++)
		for(int e=0;e<x;e++){
			cout<<"Dame el valor ("<<i<<e<<")"<<endl;
			cin>>mat[i][e];
		}
		
	return mat;
			
}

void imprimir_matrix(int** a){
	cout<<"***Matrix***"<<endl;
	for(int i=0;i<y;i++){
		for(int e=0;e<x;e++){
		cout<<a[i][e]<<"|";
		}
	 cout<<"\n";
	}
}

void multiplicar_linea(int **a, int i, int m){ //direccion de memmoria de la matrix, numero de linea
	for(int e=0;e<x;e++)
		a[i][e]*=m; 	
}


void restar_linea(int **a, int i, int m){ //direccion de memmoria de la matrix, numero de linea
	for(int e=0;e<x;e++)
		a[i][e]-=m; 	
}

int* matriz_diagonal(int **a){
	int* A = new int[y];
	for(int i=0;i<y;i++)
		A[i] = a[i][i];
	return A;
}

int main(){
	int **mat1 = insertar_matrix();
	int *diag = matriz_diagonal(mat1);
	
	multiplicar_linea(mat1, 0, 1/diag[0]);
	
	imprimir_matrix(mat1);
	
	
	
	
}
