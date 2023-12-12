#include <iostream>
#include <cmath>

using namespace std;

long long potencia_modular(long long base, long long exponente, long long modulo) {
    long long resultado = 1;
    while (exponente > 0) {
        if (exponente % 2 == 1) {
            resultado = (resultado * base) % modulo;
        }
        base = (base * base) % modulo;
        exponente /= 2;
    }
    return resultado;
}

int main() {
    // Valores compartidos publicamente
    long long primo = 23;  // Un numero primo comunmente utilizado en ejemplos
    long long raiz_primitiva = 5;  // Raiz primitiva modulo primo

    // Alice genera su par de claves
    long long clave_privada_alice = rand() % (primo - 1) + 1;
    long long clave_publica_alice = potencia_modular(raiz_primitiva, clave_privada_alice, primo);

    // Bob genera su par de claves
    long long clave_privada_bob = rand() % (primo - 1) + 1;
    long long clave_publica_bob = potencia_modular(raiz_primitiva, clave_privada_bob, primo);

    // Se intercambian las claves publicas
    long long secreto_compartido_alice = potencia_modular(clave_publica_bob, clave_privada_alice, primo);
    long long secreto_compartido_bob = potencia_modular(clave_publica_alice, clave_privada_bob, primo);

    // Verificacion de que ambos obtienen el mismo secreto compartido
    if (secreto_compartido_alice == secreto_compartido_bob) {
        cout << "Secreto compartido: " << secreto_compartido_alice << endl;
    } else {
        cerr << "Error: Los secretos compartidos no coinciden." << endl;
    }

    return 0;
}