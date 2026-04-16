/*ANGEL GUADALUPE MELGAR GONZALEZ
225994353
4/15/2026
Este programa es para resolver las torres de hanoi con discos del 3 al 7.
*/

#include <iostream>
#include <cmath>

using namespace std;


void resolverHanoi(int n, int origen, int destino, int auxiliar, int &contador); //funcion para resolver la torre

int main() {
    int numDiscos;
    char opcion;

    do {
    	system("cls");
        cout << "--- Torres de Hanoi ---" << endl;
        cout << "Introduce el numero de discos (3 - 7): ";
        cin >> numDiscos;

        while (numDiscos < 3 || numDiscos > 7) {
            cout << "Elige un numero entre 3 y 7 ";
            cin >> numDiscos;
        }

        int discos[numDiscos]; //lo interpretamos como un arreglo;
        cout << "Discos cargados en Torre 1:  \n";
        for (int i = 0; i < numDiscos; i++) {
            discos[i] = i + 1; // Llenado del arreglo del 1 al N
            cout << discos[i] << " ";
        }
        cout << "\n Resolucion: \n";

        int contadorMovimientos = 0;
        
        resolverHanoi(numDiscos, 1, 3, 2, contadorMovimientos);

        cout << "Movimientos totales realizados: " << contadorMovimientos;
        cout << "\nMovimientos minimos teoricos (2^n - 1): " << pow(2, numDiscos) - 1 << endl;
        //pow se usa para elevar un numeero a otro

        cout << "Repetir programa? (s/n): ";
        cin >> opcion;

    } while (opcion == 's' || opcion == 'S');

    return 0;
}

void resolverHanoi(int n, int origen, int destino, int auxiliar, int &contador) {
    if (n == 1) {
        contador++;
        cout << "Movimiento " << contador << ": Mover disco 1 de Torre " << origen << " a Torre " << destino << endl;
        return;
    }

    resolverHanoi(n - 1, origen, auxiliar, destino, contador);

    contador++;
    cout << "Movimiento " << contador << ": Mover disco " << n << " de Torre " << origen << " a Torre " << destino << endl;

    resolverHanoi(n - 1, auxiliar, destino, origen, contador);
    //como en matematicas discretas, si el metodo funciona para n discos, funciona para n-1 discos, y para n-2, etc.
}