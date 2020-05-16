#include <iostream>
#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <cstdlib>

using namespace std;
void conway (int**&,int,int,int);

void ImprimirMatriz (int** matriz, int filas, int columnas){
	for (int i = 0; i < filas; i++){
		for (int j = 0; j < columnas;j++){
			if (matriz[i][j] == 3){
				cout << "[#] ";
			} else if (matriz[i][j] == 1){
				cout << "[*] ";
			} else {
				cout << "[ ] ";
			}
		}
		cout << endl;
	}
	cout << endl;
}

int main (){
	srand((int)time(0));
	while (true){
		int opcion;
		cout << "1. Jugar con matriz random." << endl;
		cout << "2. Jugar con matriz predefinida." << endl;
		cout << "3. Salir." << endl;
		cout << "Ingrese opcion: "; cin >> opcion; cout << endl;
		
		if (opcion == 1){
			int filas,columnas,turnos;
			cout << "Ingrese numero de filas del tablero: "; cin >> filas;
			cout << "Ingrese numero de columnas del tablero: "; cin >> columnas;
			cout << "Ingrese cantidad de turnos: "; cin >> turnos; cout << endl;
						
			filas += 2;
			columnas +=2;
			
			int** matriz;
			matriz = new int *[filas];
			for (int j = 0; j < filas; j++){
				matriz[j] = new int[columnas];
			}
			
			for (int i = 0; i < filas; i++){
				for (int j = 0; j < columnas; j++){
					matriz[i][j] = 3;
				}
			}
				
			for (int i = 1; i < filas-1; i++){
				for (int j = 1; j < columnas-1; j++){
					int random = rand() % 100;
					if (random > 40){
						matriz[i][j] = 1; 
					} else {
						matriz[i][j] = 0;
					}
				}
			}
			
			ImprimirMatriz(matriz,filas,columnas);
			cout<<endl;
			
			conway(matriz,filas,columnas,turnos);
			
			
		} else if (opcion == 2){
			int turnos = 0;			
			cout << "Ingrese cantidad de turnos: "; cin >> turnos; cout << endl;
			int filas = 22; int columnas = 22;
			int temp_mat [20][20] = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,1,0,0,0,0,0,0,0,1,1,1,0,0,0,1,1,0,0},{0,0,1,0,0,0,0,0,0,1,1,1,0,0,0,0,1,0,1,0},{0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0},{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};
			
			int** matriz;
			matriz = new int *[filas];
			for (int i = 0; i < filas; i++){
				matriz[i]= new int[columnas];
				for (int j = 0; j < columnas; j++){
					matriz[i][j] = 3;
				}
			}
			
			int contf = 0,contc = 0;
			for (int i = 1; i < filas-1; i++){
				for (int j = 1; j < columnas-1; j++){
					matriz[i][j] = temp_mat[contf][contc];
					contc++;
				}
				contc = 0;
				contf++;
			}
			
			ImprimirMatriz(matriz,filas,columnas);
			cout<<endl;
			
			conway(matriz,filas,columnas,turnos);
			
			
		} else if (opcion == 3){
			break;
		} else {
			cout << "Opcion Incorrecta" << endl;
		}
		
		cout << endl;
	}
	
}

void conway (int**& matriz,int filas, int columnas, int turnos){
	int cont = 1;
	char avance;		
	
	int matrizflag [filas][columnas];
	for (int i = 0; i < filas ; i++){
		for (int j = 0; j < columnas ; j++){
			matrizflag[i][j] = matriz[i][j];
		}
	}
	int contvivas = 0;
	while (cont < turnos){
		if (getch()){
			for (int i = 0; i < filas; i++){
				for (int j = 0; j < columnas; j++){
					contvivas = 0;
					if (matriz[i][j] == 1 || matriz[i][j] == 0){
						if (matriz[i][j+1] == 1){
						contvivas++;
						}
						if (matriz[i][j-1] == 1){
							contvivas++;
						}
						if (matriz[i-1][j] == 1){
							contvivas++;
						}
						if (matriz[i-1][j+1] == 1){
							contvivas++;
						}
						if (matriz[i-1][j-1] == 1){
							contvivas++;
						}
						if (matriz[i+1][j] == 1){
							contvivas++;
						}
						if (matriz[i+1][j+1] == 1){
							contvivas++;
						}
						if (matriz[i+1][j-1] == 1){
							contvivas++;
						}
						
						if (matriz[i][j] == 1){
							if (contvivas == 2 || contvivas == 3){
								matrizflag[i][j] = 1;
							} else {
								matrizflag[i][j] = 0;
							}					
						} else if (matriz[i][j] == 0) {
							if (contvivas == 3){
								matrizflag[i][j] = 1;
							}
						}
					}
										
				}
			}		
			
			for (int i = 0; i < filas ; i++){
				for (int j = 0; j < columnas ; j++){
					matriz[i][j] = matrizflag[i][j];
				}
			}
			ImprimirMatriz(matriz,filas,columnas);
			cout << endl;
			
			cont++;			
		}
		
	}
	
	for (int i = 0; i < filas; i++){
		
	}
}
