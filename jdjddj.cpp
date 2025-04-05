// reproMusica.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>
using namespace std;
// Nodo de la lista (canción)
struct Cancion {
    string titulo;
    Cancion* anterior;
    Cancion* siguiente;
    Cancion(string t) {
        titulo = t;
        anterior = nullptr;
        siguiente = nullptr;
    }
};
// Clase Reproductor
class Reproductor {
private:
    Cancion* actual;
public:
    Reproductor() {
        actual = nullptr;
    }
    void agregarCancion(string titulo) {
        Cancion* nueva = new Cancion(titulo);
        if (!actual) {
            actual = nueva;
        }
        else {
            Cancion* temp = actual;
            while (temp->siguiente) {
                temp = temp->siguiente;
            }
            temp->siguiente = nueva;
            nueva->anterior = temp;
        }
        cout << "Canción agregada: " << titulo << endl;
    }
    void mostrarLista() {
        if (!actual) {
            cout << "Lista de reproducción vacía." << endl;
            return;
        }
        Cancion* temp = actual;
        while (temp->anterior) {
            temp = temp->anterior; // Ir al inicio
        }
        cout << "\nLista de reproducción:\n";
        while (temp) {
            if (temp == actual)
                cout << "-> "; // Marca la canción actual
            cout << temp->titulo << endl;
            temp = temp->siguiente;
        }
    }
    void reproducirActual() {
        if (!actual) {
            cout << "No hay canciones para reproducir." << endl;
        }
        else {
            cout << "Reproduciendo: " << actual->titulo << endl;
        }
    }

    void siguienteCancion() {
        if (actual && actual->siguiente) {
            actual = actual->siguiente;
            reproducirActual();
        }
        else {
            cout << "No hay siguiente canción." << endl;
        }
    }
    void anteriorCancion() {
        if (actual && actual->anterior) {
            actual = actual->anterior;
            reproducirActual();
        }
        else {
            cout << "No hay canción anterior." << endl;
        }
    }
    void eliminarActual() {
        if (!actual) {
            cout << "No hay canción para eliminar." << endl;
            return;
        }
        Cancion* eliminar = actual;
        if (actual->anterior)
            actual->anterior->siguiente = actual->siguiente;
        if (actual->siguiente)
            actual->siguiente->anterior = actual->anterior;
        if (actual->siguiente)
            actual = actual->siguiente;
        else if (actual->anterior)
            actual = actual->anterior;
        else
            actual = nullptr;
        cout << "Canción eliminada: " << eliminar->titulo << endl;
        delete eliminar;
    }
    void buscarCancion(string cadbusqueda) {
        if (!actual) {
            cout << "Lista de reproducción vacía." << endl;
            return;
        }
        Cancion* temp = actual;
        while (temp->anterior) {
            temp = temp->anterior; // Ir al inicio
        }
        cout << "\nCanciones encontradas:\n";
        while (temp) {
//            if (temp == actual)
//                cout << "-> "; // Marca la canción actual

            size_t found = temp->titulo.find(cadbusqueda);

            if(found != string::npos)
                cout << temp->titulo << endl;
            temp = temp->siguiente;
        }
    }
    ~Reproductor()
    {
        while (actual)
        {
            eliminarActual();
        }
        cout << "Lista liberada" << endl;
    }
};

int main()
{
//    std::cout << "Hello World!\n";

    Reproductor miReproductor;

    miReproductor.agregarCancion("amor y odio");
    miReproductor.agregarCancion("cervezero");
    miReproductor.agregarCancion("los fieles");

    int opcion;
    string titulo;

    do {
        cout << "\n--- Reproductor de Música ---\n";
        cout << "1. Agregar canción\n";
        cout << "2. Mostrar lista\n";
        cout << "3. Reproducir actual\n";
        cout << "4. Siguiente canción\n";
        cout << "5. Canción anterior\n";
        cout << "6. Eliminar canción actual\n";
        cout << "7. Buscar canción\n";
        cout << "0. Salir\n";
        cout << "Opción: ";
        cin >> opcion;
        cin.ignore(); // Limpiar buffer
        switch (opcion) {
        case 1:
            cout << "Ingrese título de la canción: ";
            getline(cin, titulo);
            miReproductor.agregarCancion(titulo);
            break;
        case 2:
            miReproductor.mostrarLista();
            break;
        case 3:
            miReproductor.reproducirActual();
            break;
        case 4:
            miReproductor.siguienteCancion();
            break;
        case 5:
            miReproductor.anteriorCancion();
            break;
        case 6:
            miReproductor.eliminarActual();
            break;
        case 7:
            cout << "Ingrese texto a buscar: ";
            getline(cin, titulo);
            miReproductor.buscarCancion(titulo);
            break;
        case 0:
            cout << "Saliendo del reproductor...\n";
            break;
        default:
            cout << "Opción inválida." << endl;
        }
    } while (opcion != 0);
    return 0;



}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
