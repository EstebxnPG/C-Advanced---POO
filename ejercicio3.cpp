#include <iostream>
using namespace std;

class Libro {
private:
    string titulo;
    string autor;
    int anio;
    bool disponible;

public:
    Libro() {}
    Libro(string titulo, string autor, int anio) {
        this->titulo = titulo;
        this->autor = autor;
        this->anio = anio;
        this->disponible = true;
    }

    string getTitulo() { return titulo; }
    bool estaDisponible() { return disponible; }

    void mostrarInfo() {
        cout << "Titulo: " << titulo << endl;
        cout << "Autor: " << autor << endl;
        cout << "Año: " << anio << endl;
        cout << "Estado: " << (disponible ? "Disponible" : "No disponible") << endl;
    }

    void prestarLibro() {
        if (disponible) {
            disponible = false;
            cout << "Libro prestado con éxito.\n";
        } else {
            cout << "El libro ya está prestado.\n";
        }
    }

    void devolverLibro() {
        if (!disponible) {
            disponible = true;
            cout << "Libro devuelto con éxito.\n";
        } else {
            cout << "El libro ya está disponible.\n";
        }
    }
};

class Biblioteca {
private:
    Libro libros[10];
    int cantidad;

public:
    Biblioteca() { cantidad = 0; }

    void agregarLibro(Libro libro) {
        if (cantidad < 10) {
            libros[cantidad] = libro;
            cantidad++;
            cout << "Libro agregado con éxito.\n";
        } else {
            cout << "No se pueden agregar más libros.\n";
        }
    }

    void mostrarLibros() {
        if (cantidad == 0) {
            cout << "No hay libros en la biblioteca.\n";
            return;
        }
        for (int i = 0; i < cantidad; i++) {
            cout << "---- Libro " << i + 1 << " ----\n";
            libros[i].mostrarInfo();
            cout << endl;
        }
    }

    int buscarLibro(string titulo) {
        for (int i = 0; i < cantidad; i++) {
            if (libros[i].getTitulo() == titulo) {
                return i;
            }
        }
        return -1;
    }

    void prestarLibro(string titulo) {
        int index = buscarLibro(titulo);
        if (index != -1) {
            libros[index].prestarLibro();
        } else {
            cout << "Libro no encontrado.\n";
        }
    }

    void devolverLibro(string titulo) {
        int index = buscarLibro(titulo);
        if (index != -1) {
            libros[index].devolverLibro();
        } else {
            cout << "Libro no encontrado.\n";
        }
    }
};

int main() {
    Biblioteca biblioteca;
    int opcion;
    string titulo, autor;
    int anio;

    while (true) {
        cout << "\n---- MENU BIBLIOTECA ----\n";
        cout << "1) Agregar libro\n";
        cout << "2) Mostrar libros\n";
        cout << "3) Prestar libro\n";
        cout << "4) Devolver libro\n";
        cout << "0) Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1:
                cout << "Ingrese titulo: ";
                getline(cin, titulo);
                cout << "Ingrese autor: ";
                getline(cin, autor);
                cout << "Ingrese año de publicación: ";
                cin >> anio;
                biblioteca.agregarLibro(Libro(titulo, autor, anio));
                break;
            case 2:
                biblioteca.mostrarLibros();
                break;
            case 3:
                cout << "Ingrese el título del libro a prestar: ";
                getline(cin, titulo);
                biblioteca.prestarLibro(titulo);
                break;
            case 4:
                cout << "Ingrese el título del libro a devolver: ";
                getline(cin, titulo);
                biblioteca.devolverLibro(titulo);
                break;
            case 0:
                cout << "Saliendo del sistema...\n";
                return 0;
            default:
                cout << "Opción no válida.\n";
        }
    }
}
