#include <iostream>
#include <string>

using namespace std;

struct Atleta {
    string nombre;
    string nacionalidad;
    double tiempo1;
    double tiempo2;
    Atleta* left;
    Atleta* right;
};

Atleta* insertarAtleta(Atleta* root, string nombre, string nacionalidad, double tiempo1, double tiempo2) {
    if (root == NULL) {
        Atleta* nuevoAtleta = new Atleta;
        nuevoAtleta->nombre = nombre;
        nuevoAtleta->nacionalidad = nacionalidad;
        nuevoAtleta->tiempo1 = tiempo1;
        nuevoAtleta->tiempo2 = tiempo2;
        nuevoAtleta->left = NULL;
        nuevoAtleta->right = NULL;
        return nuevoAtleta;
    }

    if (nombre < root->nombre) {
        root->left = insertarAtleta(root->left, nombre, nacionalidad, tiempo1, tiempo2);
    } else {
        root->right = insertarAtleta(root->right, nombre, nacionalidad, tiempo1, tiempo2);
    }

    return root;
}

void mostrarAtletas(Atleta* root) {
    if (root == NULL) {
        return;
    }
    mostrarAtletas(root->left);
    cout << root->nombre << " (" << root->nacionalidad << "): " << root->tiempo1 << ", " << root->tiempo2 << endl;
    mostrarAtletas(root->right);
}

void mostrarPromediosAscendente(Atleta* root) {
    if (root == NULL) {
        return;
    }
    mostrarPromediosAscendente(root->left);
    double promedio = (root->tiempo1 + root->tiempo2) / 2.0;
    cout << root->nombre << " (" << root->nacionalidad << "): " << promedio << endl;
    mostrarPromediosAscendente(root->right);
}

void liberarMemoria(Atleta* root) {
    if (root == NULL) {
        return;
    }
    liberarMemoria(root->left);
    liberarMemoria(root->right);
    delete root;
}

int main() {
    Atleta* root = NULL;
    int choice;

    do {
        cout << endl <<"---MENU DE REGISTRO DE ATLETAS---" << endl;
        cout << "1. AGREGAR ATLETA" << endl;
        cout << "2. MOSTRAR ATLETAS (ORDENADO ALFABETICAMENTE)" << endl;
        cout << "3. MOSTRAR PROMEDIO DE LOS TIMPOS (ORGANIZADOS DE MANERA ASCENDENTE)" << endl;
        cout << "4. SALIR" << endl;
        cout << "Seleccione una opcion:): ";
        cin >> choice;
        system("cls");

        switch (choice) {
            case 1: {
                string nombre;
                string nacionalidad;
                double tiempo1, tiempo2;
                cout << "INGRESE EL NOMBRE DEL ATLETA: ";
                cin >> nombre;
                cout << "INGRESE EL PAÍS DEL ATLETA: ";
                cin >> nacionalidad;
                cout << "INGRESE EL TIEMPO 1 DE ESTE CORREDOR: ";
                cin >> tiempo1;
                cout << "INGRESE EL TIEMPO 2 DE ESTE CORREDOR: ";
                cin >> tiempo2;
                root = insertarAtleta(root, nombre, nacionalidad, tiempo1, tiempo2);
                system("cls");
                break;
            }
            case 2:
                cout << endl << "LOS DATOS DE LOS ATLTAS  (ORDENADOS POR TIEMPO) SON <3:" << endl;
                mostrarAtletas(root);
                system("pause");
                system("cls");
                break;
                
            case 3:
                cout << endl << "EL PROMEDIO DE LOS TIEMPOS (ORGANIZADOS DE MANERA ASCENTENTE) SON *__*:" << endl;
                mostrarPromediosAscendente(root);
                system("pause");
                system("cls");
                break;               
               
            case 4:
                liberarMemoria(root);
                break;
            default:
                cout << "Opcion invalida" << endl;
                break;
        }
    } while (choice != 4);

    return 0;
}
