#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <cctype>
#include <algorithm>
#include "utils.h"


using namespace std;

void conteoTexto() {
    cout << "\n--- Conteo sobre texto ---\n";
    cout << "Ingrese un texto: ";
    string texto;
    getline(cin, texto);

    int vocales = 0, consonantes = 0, especiales = 0, palabras = 0;
    bool enPalabra = false;

    for (char c : texto) {
        if (isalpha(static_cast<unsigned char>(c))) {
            char lower = tolower(c);
            if (lower=='a'||lower=='e'||lower=='i'||lower=='o'||lower=='u')
                vocales++;
            else
                consonantes++;
            enPalabra = true;
        } else if (isspace(static_cast<unsigned char>(c))) {
            if (enPalabra) {
                palabras++;
                enPalabra = false;
            }
        } else {
            especiales++;
        }
    }
    if (enPalabra) palabras++; // contar última palabra

    cout << "Vocales: " << vocales << "\n";
    cout << "Consonantes: " << consonantes << "\n";
    cout << "Caracteres especiales: " << especiales << "\n";
    cout << "Palabras: " << palabras << "\n";
}

void calcularFuncion() {
    cout << "\n--- Calculo de f(x) = x*x + 2x + 8 ---\n";
    cout << "Ingrese un valor para x: ";
    double x;
    cin >> x;
    cin.ignore();
    double resultado = x*x + 2*x + 8;
    cout << "f(" << x << ") = " << resultado << "\n";
}

void iniciarJuego() {
    cout << "[Juego] Módulo en construccion\n";
}

void multiplicarMatrices() {
    cout << "[Matrices] Multiplicacion de matrices NxN (en construccion)\n";
}

bool isPalindrome(const string &text) {
    string clean;
    for (char c : text) {
        if (isalnum(static_cast<unsigned char>(c))) {
            clean.push_back(tolower(c));
        }
    }
    string reversed = clean;
    reverse(reversed.begin(), reversed.end());
    return clean == reversed;
}

void opcionPalindromo() {
    cout << "\n--- Verificar Palindromo ---\n";
    cout << "Ingrese un texto: ";
    string texto;
    getline(cin, texto);

    cout << "1) Validar\n2) Cancelar\n";
    int subop;
    cin >> subop;
    cin.ignore();

    if (subop == 1) {
        if (isPalindrome(texto))
            cout << "✅ Es un palindromo.\n";
        else
            cout << "❌ No es un palindromo.\n";
    } else {
        cout << "Operacion cancelada.\n";
    }
}

void adminUsuarios() {
    cout << "[ADMIN] Gestion de usuarios y perfiles (en construccion)\n";
}

