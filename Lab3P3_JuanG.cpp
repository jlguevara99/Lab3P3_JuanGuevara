#include<iostream>
using namespace std;



char** provisionarMatriz(int);
void liberarMatriz(char**,int);
void imprimir(int);


int main(){

	cout<<"Bienvenidos a Battleshot"<<endl;





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

void imprimir(char** matriz, int size){
	for(int i = 0; i < size; i++) {
		for(int j = 0; j < size; j++) {
			cout<<" "<<matriz[i][j];
		}
		cout<<endl;
	}
}






