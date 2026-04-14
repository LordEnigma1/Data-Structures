/*ANGEL GUADALUPE MELGAR GONZALEZ
225994353
4/13/2026
Este programa es para convertir un numero a otra base; decimal, octal, decimal,  y hexadecimal.
*/

#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
#include <algorithm>

using namespace std;

// --- Prototipos de funciones ---
bool check_num(string num, int opcion);
long long aDecimal(string num, int baseOrigen);
string decimalABase(long long decimal, int baseDestino);

int main() {
    int opc_orig, opc_conv;
    string num;
    
    do {
        system("cls"); 
        cout << "--- Convertidor Universal de Numeros ---\n";
        cout << "Seleccione la base del numero ORIGINAL:\n";
        cout << "1. Binario\n2. Octal\n3. Decimal\n4. Hexadecimal\n";
        cout << "Cualquier otro numero para salir\nOpcion: ";
        cin >> opc_orig;
        
        if (opc_orig < 1 || opc_orig > 4) break;

        do { //validacion de numero
            cout << "\nIngrese el numero: ";
            cin >> num;

            if (!check_num(num, opc_orig)) {
                cout << ">> Error: El numero no pertenece a la base seleccionada. Reintente.";
            } else {
                break; 
            }
        } while (true);
        
        cout << "\nBase a convertir:\n";
        cout << "1. Binario\n2. Octal\n3. Decimal\n4. Hexadecimal\nOpcion: ";
        cin >> opc_conv;

        if (opc_conv < 1 || opc_conv > 4) {
        	break;	
		} 

        if (opc_orig == opc_conv) {
            cout << "\nResultado: " << num;
        } else {
            long long decimal = aDecimal(num, opc_orig); //primero convertimos a decimal y de ahi a los otros
            string resultado = decimalABase(decimal, opc_conv);
            cout << "\nConversion: " << resultado;
        }

        cout << "\nPresione una tecla para continuar...";
        fflush(stdin); // limpia los caracteres
        getchar();

    } while (true);
    
    return 0;
}


bool check_num(string num, int opcion) {
    if (num.empty()) return false;
    for (char c : num) {
        c = toupper(c);
        switch (opcion) {
            case 1: if (c != '0' && c != '1') return false; break;
            case 2: if (c < '0' || c > '7') return false; break;
            case 3: if (!isdigit(c)) return false; break;
            case 4: if (!isxdigit(c)) return false; break;
            default: return false;
        }
    }
    return true;
}


long long aDecimal(string num, int baseOrigen) {
    int bases[] = {0, 2, 8, 10, 16};
    int b = bases[baseOrigen];
    return stoll(num, nullptr, b); // stoll convierte string a long long segun la base
}


string decimalABase(long long decimal, int baseDestino) { // convierte de decimal a la base elegida
    if (decimal == 0) return "0";
    int bases[] = {0, 2, 8, 10, 16};
    int b = bases[baseDestino];
    string caracteres = "0123456789ABCDEF";
    string res = "";
    
    while (decimal > 0) {
        res += caracteres[decimal % b];
        decimal /= b;
    }
    reverse(res.begin(), res.end()); //invierte la cadena
    return res;
}