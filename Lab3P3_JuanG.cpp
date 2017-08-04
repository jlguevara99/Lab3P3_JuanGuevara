#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;



char** provisionarMatriz(int);
void liberarMatriz(char**,int);
void imprimir(char**,int,int,int);
char** llenarJugador1(char**);
char** llenarJugador2(char**);
char** LlenarMatriz(char**);
void EleccionShot();

int main(){
	char** referenciaJ1;
	char** referenciaJ2;
	char** tableroJ1;
	char** tableroJ2;
	referenciaJ1 = provisionarMatriz(8);
	referenciaJ2 = provisionarMatriz(8);
	tableroJ1 = provisionarMatriz(8);
	tableroJ2 = provisionarMatriz(8);

	cout<<"Bienvenidos a Battleshot"<<endl;
	
	referenciaJ1 = llenarJugador1(referenciaJ1);
	referenciaJ2 = llenarJugador2(referenciaJ2);
	tableroJ1 = LlenarMatriz(tableroJ1);
	tableroJ2 = LlenarMatriz(tableroJ2);
	int shotsJ1 = 0;
	int shotsJ2 = 0;
	bool salir = false;
	do {
		if(shotsJ1 == 5 || shotsJ2 == 5){
			salir = false;
		}else{
			int fila1;
			int columna1;
			cout<<"Turno del jugador 1"<<endl;
			cout<<"Ingrese la fila: "<<endl;
			cin>>fila1;
			cout<<"Ingrese la columna: "<<endl;
			cin>>columna1;
			while((fila1 < 0 || fila1 >= 8) || (columna1 < 0 || columna1 >= 8)  ){
				cout<<"Ingresó un dato incorrecto, vuleva a hacerlo"<<endl;
				cout<<"Ingrese fila: "<<endl;
				cin>>fila1;
				cout<<"Ingrese columna: "<<endl;
				cin>>columna1;
			}
			if(referenciaJ2[fila1][columna1] == '*'){
				tableroJ2[fila1][columna1] = 'X';
				cout<<"Acertaste"<<endl;
				cout<<"El jugador 2 debe tomar un: ";
				EleccionShot();
				shotsJ2++;
			}else{
				cout<<"Fallaste"<<endl;
			}

			//turno del jugador 2
			int fila2;
			int columna2;
			cout<<"Turno del jugador 2"<<endl;
			cout<<"Ingrese la fila: "<<endl;
			cin>>fila2;
			cout<<"Ingrese la columna: "<<endl;
			cin>>columna2;
		
		}
		liberarMatriz(referenciaJ1,8);
		liberarMatriz(referenciaJ2,8);
		liberarMatriz(tableroJ1,8);
		liberarMatriz(tableroJ2,8);



	} while (salir);
	
	


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

char** LlenarMatriz(char** matriz){
	for(int i = 0; i < 8; i++) {
		for(int j = 0; j < 8; j++) {
			matriz[i][j] = '_';
		}
	}
	return matriz;
}

void EleccionShot(){
	int numero;
	srand (time(NULL));
	numero = rand() % 7+1;
	if(numero == 1){
		cout<<"Cheap_tequila"<<endl;
	}else if(numero == 2){
		cout<<"Jell-O"<<endl;
	}else if(numero == 3){
		cout<<"Kamikaze"<<endl;
	}else if(numero == 4){
		cout<<"MindEraser"<<endl;
	}else if(numero == 5){
		cout<<"Bombs"<<endl;
	}else if(numero == 6){
		cout<<"Fireballs"<<endl;
	}else{
		cout<<"Whiskey"<<endl;
	}
}






