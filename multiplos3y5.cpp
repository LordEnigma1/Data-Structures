#include <iostream>
#include <limits>
#include <conio.h>

using namespace std;


int obtener_num_valido();
void ciclo_3y5(int n); 

int main() {
    
    char salir;
    do {
        system("cls");
        int num = obtener_num_valido(); 
        ciclo_3y5(num);
        cout<< "Presiona [S] si deseas reiniciar el programa, o cualquier otra tecla para cerrarlo ";
        cin >> salir;
    } while (salir == 's' || salir == 'S');
    
    return 0;
}

int obtener_num_valido() {
    int num_valido;
    bool es_valido = false;

    while (!es_valido) {
        cout << "Ingresa un numero del 1 al 1000: ";
        if (cin >> num_valido) {
            if (num_valido > 0 && num_valido <= 1000) {
                es_valido = true;
            } else {
                cout << "Error: El numero debe estar entre 1 y 1000." << endl;
            }
        } else {
            cout << "Entrada no valida. Solo se permiten enteros." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    return num_valido;
}

void ciclo_3y5(int n) {
    int suma3 = 0, suma5 = 0, conta3 = 0, conta5 = 0;

    for (int i = 1; i <= n; i++) {
        if (i % 3 == 0) {
            conta3++;
            suma3 += i;
        }
        if (i % 5 == 0) {
            conta5++;
            suma5 += i;
        }
    }
    cout << "Multiplos de 3: " << conta3 << " | Suma: " << suma3 << endl;
    cout << "Multiplos de 5: " << conta5 << " | Suma: " << suma5 << endl;
}