#include <iostream>
#include <limits>
#include <conio.h>
#include <cmath>

using namespace std;

int obtener_num_valido();
void suma_primo(int n);

int main (){
	char salir;
	do {
		system("cls");
		int num = obtener_num_valido();
		cout<< "Los numeros primos son: 3";
		suma_primo(num);
		cout << "\nPresiona [S] si deseas reiniciar el programa, u otra tecla para salir del programa: ";
		cin >> salir;
	} while (salir == 'S' || salir == 's');
	return 0;
}

int obtener_num_valido() {
    int num_valido;
    bool es_valido = false;

    while (!es_valido) {
        cout << "Ingresa un numero mayor a dos: ";
        if (cin >> num_valido) {
            if (num_valido > 2 ) {
                es_valido = true;
            } else {
                cout << "Error: El numero debe ser mayor a 2 " << endl;
            }
        } else {
            cout << "Entrada no valida. Solo se permiten enteros." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    return num_valido;
}

void suma_primo (int n) {
	int suma = 0;
	for (int i = 2; i<= n; i++){
		int conta = 0;
		for (int j = 2; j <= i/2; j++){
			if (i % j == 0){
				conta=0;
				break;
			} else {
				conta++;
			}
		}
		if (conta>0){
			cout<< " " << i;
			suma+=i;
		}
	}
	cout<< " La suma de los numeros primos es: " << suma+3;
}