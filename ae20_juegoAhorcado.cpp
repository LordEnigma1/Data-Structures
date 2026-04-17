#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void dibujarAhorcado(int fallos);
bool verificarLetra(char letra, string palabra, string &progreso);



int main() {
    char jugarDeNuevo;
    
    do {
        string palabraSecreta;
        int modo;
        
        cout << "--- JUEGO DEL AHORCADO ---" << endl;
        cout << "1. Jugar contra la computadora" << endl;
        cout << "2. Jugar contra otro usuario" << endl;
        cout << "Selecciona modo: ";
        cin >> modo;

        if (modo == 2) {
            cout << "Ingresa la palabra secreta: ";
            cin >> palabraSecreta;
            system("cls"); // Limpia la pantalla para que el otro no vea
        } else {
            string banco[] = {"programacion", "miriam", "computadora", "codigo", "angel", "ingenieria", "microcontrolador"};
            palabraSecreta = banco[rand() % 7];
        }

        string progreso(palabraSecreta.length(), '_');
        string falladas = "";
        int intentosFallidos = 0;
        int maxIntentos = 6;

        while (intentosFallidos < maxIntentos && progreso != palabraSecreta) {
            dibujarAhorcado(intentosFallidos);
            cout << "\nPalabra: ";
            for (char c : progreso) cout << c << " ";
            cout << "\nFalladas: " << falladas;
            cout << "\nIntroduce una letra: ";
            
            char intento;
            cin >> intento;

            if (!verificarLetra(intento, palabraSecreta, progreso)) {
                if (falladas.find(intento) == string::npos) {
                    falladas += intento;
                    falladas += " ";
                    intentosFallidos++;
                }
            }
            system("cls || clear");
        }

        dibujarAhorcado(intentosFallidos);
        if (progreso == palabraSecreta) {
            cout << "\nGanaste. La palabra era: " << palabraSecreta << endl;
        } else {
            cout << "\nPerdiste. La palabra era: " << palabraSecreta << endl;
        }

        cout << "\nDeseas jugar de nuevo? (s/n): ";
        cin >> jugarDeNuevo;
        system("cls");

    } while (jugarDeNuevo == 's' || jugarDeNuevo == 'S');

    return 0;
}

void dibujarAhorcado(int fallos) {
    string figuras[] = { //arreglo con todas las posibles formas del ahorcado
        "  +---+\n  |   |\n      |\n      |\n      |\n      |\n=========",
        "  +---+\n  |   |\n  O   |\n      |\n      |\n      |\n=========",
        "  +---+\n  |   |\n  O   |\n  |   |\n      |\n      |\n=========",
        "  +---+\n  |   |\n  O   |\n /|   |\n      |\n      |\n=========",
        "  +---+\n  |   |\n  O   |\n /|\\  |\n      |\n      |\n=========",
        "  +---+\n  |   |\n  O   |\n /|\\  |\n /    |\n      |\n=========",
        "  +---+\n  |   |\n  O   |\n /|\\  |\n / \\  |\n      |\n========="
    };
    cout << figuras[fallos] << endl;
}

bool verificarLetra(char letra, string palabra, string &progreso) { // Funcion para procesar la logica de la letra y actualizar el progreso
    bool acierto = false;
    for (int i = 0; i < palabra.length(); i++) {
        if (palabra[i] == letra) {
            progreso[i] = letra;
            acierto = true;
        }
    }
    return acierto;
}

