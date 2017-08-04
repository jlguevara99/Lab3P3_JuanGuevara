#include<iostream>
using namespace std;



char** provisionarMatriz(int);
void liberarMatriz(char**,int);
void imprimir(char**,int,int,int);
char** llenarJugador1(char**);
char** llenarJugador2(char**);

int main(){
	char** referenciaJ1;
	char** referenciaJ2;
	referenciaJ1 = provisionarMatriz(8);
	referenciaJ2 = provisionarMatriz(8);

	cout<<"Bienvenidos a Battleshot"<<endl;
	
	referenciaJ1 = llenarJugador1(referenciaJ1);
	



	return 0;
}

char** provisionarMatriz(int size){
	char** matriz = new char*[size];
	for(int i = 0; i < size; i++) {
		matriz[i] = new char[size];
	}
	return matriz;
}

void liberarMatriz(char** matriz, int size){
	for(int i = 0; i < size; i++) {
		delete[] matriz[i];
		matriz[i] = NULL;
	}
	delete[] matriz;
}

void imprimir(char** matriz, int i, int j, int size){
	cout<<"["<<matriz[i][j]<<"]";
	if(i == size-1 && j == size-1){
		cout<<endl;
	}else{
		if(j == size-1){
			i++;
			j = 0;
			cout<<endl;
		}else{
			j++;
		}
		imprimir(matriz,i,j,size);
	}
}

char** llenarJugador1(char** matriz){
	
	for(int i = 0; i < 8; i++) {
		for(int j = 0; j < 8; j++) {
			matriz[i][j] = '_';
		}
	}
	matriz[1][1] = '*';
	matriz[1][2] = '*';
	matriz[1][3] = '*';
	matriz[3][4] = '*';
	matriz[4][4] = '*';
	matriz[5][4] = '*';
	matriz[2][7] = '*';
	matriz[3][7] = '*';
	matriz[4][7] = '*';
	matriz[7][1] = '*';
	matriz[7][2] = '*';
	matriz[7][3] = '*';
	
	return matriz;
}

char** llenarJugador2(char** matriz){
	for(int i = 0; i < 8; i++) {
		for(int j = 0; j < 8; j++) {
			matriz[i][j] = '_';
		}
	}
	matriz[0][1] = '*';
	matriz[0][2] = '*';
	matriz[0][3] = '*';
	matriz[3][5] = '*';
	matriz[3][6] = '*';
	matriz[3][7] = '*';
	matriz[4][4] = '*';
	matriz[5][4] = '*';
	matriz[6][4] = '*';
	matriz[5][1] = '*';
	matriz[6][1] = '*';
	matriz[7][1] = '*';

	return matriz;
}


