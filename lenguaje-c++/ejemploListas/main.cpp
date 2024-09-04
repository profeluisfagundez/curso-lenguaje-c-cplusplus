#include <iostream>
using namespace std;

struct nodo {
    int info;
    nodo* sig;
};

typedef nodo* lista;

void insFront(lista& L, int n);
void mostrar(const nodo* L);
void borrar(lista& L, int n);
void mostrarMenu();

int main() {
    int op = -1;
    lista milista = nullptr;

    while (op) {
        mostrarMenu();
        cin >> op;
        switch (op) {
        case 1:
            int numNuevo;
            cout << "Ingrese el numero para agregar a la lista:\n";
            cin >> numNuevo;
            insFront(milista, numNuevo);
            break;

        case 2:
            cout << "Los numeros cargados en la lista:\n\n";
            mostrar(milista);
            break;

        case 3:
            int n;
            cout << "Ingrese el numero para borrar de la lista:\n";
            cin >> n;
            borrar(milista, n);
            break;
        }
    }
    return 0;
}

void insFront(lista& L, int n) {
    nodo* aux = new nodo;
    aux->info = n;
    aux->sig = L;
    L = aux;
    cout << "Se agrego el " << n << " a la lista\n";
}

void mostrar(const nodo* L) {
    while (L != nullptr) {
        cout << L->info << " - ";
        L = L->sig;
    }
    cout << "\n";
}

void borrar(lista& L, int n) {
    if (L == nullptr) {
        return;
    }
    if (L->info == n) {
        nodo* aux = L;
        L = L->sig;
        delete aux;
        return;
    }
    nodo* current = L;
    while (current->sig != nullptr) {
        if (current->sig->info == n) {
            nodo* aux = current->sig;
            current->sig = current->sig->sig;
            delete aux;
            return;
        }
        current = current->sig;
    }
}

void mostrarMenu() {
    cout << "Ejemplo con Listas\n";
    cout << "Seleccione una opcion\n";
    cout << "1. Agregar elemento al frente\n";
    cout << "2. Mostrar lista\n";
    cout << "3. Borrar un elemento\n";
    cout << "0. Salir\n";
}
