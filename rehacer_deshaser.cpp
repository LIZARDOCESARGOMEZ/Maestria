// editorTexto.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <stack>
#include <string>
#include <fstream>

using namespace std;
class EditorTexto {
private:
    string textoActual;
    stack<string> historial;
public:
    EditorTexto() {
        textoActual = "";
    }
    void escribir(const string& nuevoTexto) {
        historial.push(textoActual); // Guardamos el estado anterior
        textoActual += nuevoTexto;
        cout << "Texto agregado.\n";
    }
    void mostrarTexto() {
        cout << "\nTexto actual:\n";
        cout << textoActual << "\n";
    }
    void deshacer() {
        if (!historial.empty()) {
            textoActual = historial.top(); // Recuperar el último estado
            historial.pop(); // Eliminar el estado restaurado del historial
            cout << "Se ha deshecho la última acción.\n";
        }
        else {
            cout << "No hay acciones para deshacer.\n";
        }
    }
    void borrarTodo() {
        historial.push(textoActual);
        textoActual = "";
        cout << "Texto borrado.\n";
    }
    void escribeArchivo()
    {
        fstream archivo;
        archivo.open("historial.txt", ios::out);
        if (!archivo) {
            cout << "archivo no creado!";
        }
        else {
            stack<string> temp;

            string cadena;

            while (!historial.empty())
            {
                cadena = historial.top();
                temp.push(cadena);
                historial.pop();
            }

            while (!temp.empty())
            {
                cadena = temp.top();
                historial.push(cadena);
                archivo << "------"<<endl;
                archivo << cadena;
                temp.pop();
            }

            archivo.close();
            cout << "Archivo escrito!";
        }
    }
};
int main() {
    EditorTexto editor;
    int opcion;
    string entrada;
    do {
        cout << "\n--- Editor de Texto ---\n";
        cout << "1. Escribir texto\n";
        cout << "2. Mostrar texto\n";
        cout << "3. Deshacer\n";
        cout << "4. Borrar todo\n";
        cout << "5. Escribir archivo\n";
        cout << "0. Salir\n";
        cout << "Opción: ";
        cin >> opcion;
        cin.ignore();
        switch (opcion) {
        case 1:
            cout << "Escribe una línea: ";
            getline(cin, entrada);
            editor.escribir(entrada + "\n");
            break;
        case 2:
            editor.mostrarTexto();
            break;
        case 3:
            editor.deshacer();
            break;
        case 4:
            editor.borrarTodo();
            break;
        case 5:
            editor.escribeArchivo();
            break;            
        case 0:
            cout << "Saliendo del editor...\n";
            break;
        default:
            cout << "Opción inválida.\n";
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