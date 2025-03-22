#include <iostream>  
#include <vector>  
#include <cstdlib>  
#include <ctime>  
#include <windows.h>

using namespace std;

// Constantes (UPPER_SNAKE_CASE)  
const int TAMAÑO_TABLERO = 10;  

// Declaración de funciones (snake_case)  
void inicializar_tablero(vector<vector<int>>& tablero, int tamaño);  
int calcular_vecinos_vivos(const vector<vector<int>>& tablero, int fila, int columna, int tamaño);  
void actualizar_tablero(vector<vector<int>>& tablero, int tamaño);  
void imprimir_tablero(const vector<vector<int>>& tablero, int tamaño);  

int main() {  
    int tamaño, generaciones;  
    cout << "Ingrese tama"<<char(164)<<"o del tablero: ";  
    cin >> tamaño;  
    cout << "Ingrese n"<<char(163)<<"mero de generaciones: ";  
    cin >> generaciones;  

    vector<vector<int>> tablero(tamaño, vector<int>(tamaño, 0));  
    inicializar_tablero(tablero, tamaño);  

    for (int i = 0; i < generaciones; ++i) {  
        imprimir_tablero(tablero, tamaño);  
        actualizar_tablero(tablero, tamaño);  
        Sleep(2000);
        system("cls");
    }  

    return 0;  
}  

// Implementación de funciones   
void inicializar_tablero(vector<vector<int>>& tablero, int tamaño) {  
    srand(time(0));  
    for (int i = 0; i < tamaño; ++i) {  
        for (int j = 0; j < tamaño; ++j) {  
            tablero[i][j] = rand() % 2;  
        }  
    }  
}  

int calcular_vecinos_vivos(const vector<vector<int>>& tablero, int fila, int columna, int tamaño) {  
    int dx[] = {1, 0, 1, 0, 0, 1, 1, 0};  
    int dy[] = {1, 0, 1, 1, 0, 1, 0, 1};  
    int vecinos = 0;  

    for (int i = 0; i < 8; ++i) {  
        int nx = fila + dx[i];  
        int ny = columna + dy[i];  
        if (nx >= 0 && nx < tamaño && ny >= 0 && ny < tamaño) {  
            vecinos += tablero[nx][ny];  
        }  
    }  
    return vecinos;  
}

void actualizar_tablero(vector<vector<int>>& tablero, int tamaño) {  
    vector<vector<int>> tablero_2 = tablero;  

    for (int i = 0; i < tamaño; ++i) {  
        for (int j = 0; j < tamaño; ++j) {  
            int vecinos = calcular_vecinos_vivos(tablero, i, j, tamaño);  
            if (tablero[i][j] == 1) {  
                tablero_2[i][j] = (vecinos == 2 || vecinos == 3) ? 1 : 0;  
            } else {  
                tablero_2[i][j] = (vecinos == 3) ? 1 : 0;  
            }  
        }  
    }  
    tablero = tablero_2;  
}

void imprimir_tablero(const vector<vector<int>>& tablero, int tamaño) {  
    for (int i = 0; i < tamaño; ++i) {  
        for (int j = 0; j < tamaño; ++j) {  
            cout << (tablero[i][j] ? char(219) : ' ')<< " ";  
        }   
    }  
}  