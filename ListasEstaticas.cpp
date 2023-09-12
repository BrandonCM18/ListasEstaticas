#include <iostream>
#include <string>

const int MAX = 10; // Tamaño máximo de la lista estática

class ListaEstatica {
private:
    int Tam; // Tamaño actual de la lista
    std::string Datos[MAX]; // Datos de la lista (cambiar a la clase Empleado)

public:
    ListaEstatica() : Tam(0) {}

    int Agrega(std::string dato) {
        if (Tam < MAX) {
            Datos[Tam] = dato;
            Tam++;
            return 1; // Éxito
        } else {
            return 0; // Lista llena
        }
    }

    int Busca(std::string dato) {
        if (Tam == 0) {
            std::cout << "La lista esta vacia." << std::endl;
            return -1;
        }

        for (int i = 0; i < Tam; i++) {
            if (Datos[i] == dato) {
                std::cout << "El dato se encuentra en la posicion " << i << std::endl;
                return i;
            }
        }

        std::cout << "No se encontro el dato en la lista." << std::endl;
        return -1;
    }

    int Elimina(int posicion) {
        if (Tam == 0) {
            std::cout << "La lista esta vacia." << std::endl;
            return -1;
        }

        if (posicion < 0 || posicion >= Tam) {
            std::cout << "Posicion invalida." << std::endl;
            return 0;
        }

        for (int i = posicion; i < Tam - 1; i++) {
            Datos[i] = Datos[i + 1];
        }

        Tam--;
        std::cout << "Dato eliminado correctamente." << std::endl;
        return 1;
    }

    int Inserta(std::string dato, int posicion) {
        if (Tam == MAX) {
            std::cout << "La lista esta llena, no se puede insertar." << std::endl;
            return 0;
        }

        if (posicion < 0 || posicion > Tam) {
            std::cout << "Posicion de insercion invalida." << std::endl;
            return 0;
        }

        for (int i = Tam; i > posicion; i--) {
            Datos[i] = Datos[i - 1];
        }

        Datos[posicion] = dato;
        Tam++;
        std::cout << "Dato insertado correctamente." << std::endl;
        return 1;
    }

    int Muestra() {
        if (Tam == 0) {
            std::cout << "La lista esta vacia." << std::endl;
            return 0;
        }

        std::cout << "Elementos en la lista:" << std::endl;
        for (int i = 0; i < Tam; i++) {
            std::cout << i << ": " << Datos[i] << std::endl;
        }

        return Tam;
    }
};

int main() {
    ListaEstatica lista;
    int opcion;

    do {
        std::cout << "Menu:" << std::endl;
        std::cout << "1. Agregar" << std::endl;
        std::cout << "2. Buscar" << std::endl;
        std::cout << "3. Eliminar" << std::endl;
        std::cout << "4. Insertar" << std::endl;
        std::cout << "5. Mostrar" << std::endl;
        std::cout << "6. Salir" << std::endl;
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1: {
                std::string dato;
                std::cout << "Ingrese el dato a agregar: ";
                std::cin >> dato;
                if (lista.Agrega(dato)) {
                    std::cout << "Dato agregado correctamente." << std::endl;
                } else {
                    std::cout << "No se pudo agregar el dato, la lista esta llena." << std::endl;
                }
                break;
            }
            case 2: {
                std::string dato;
                std::cout << "Ingrese el dato a buscar: ";
                std::cin >> dato;
                lista.Busca(dato);
                break;
            }
            case 3: {
                int posicion;
                std::cout << "Dame el empleado a eliminar: ";
                std::cin >> posicion;
                lista.Elimina(posicion);
                break;
            }
            case 4: {
                std::string dato;
                int posicion;
                std::cout << "Dame el empleado a insertar: ";
                std::cin >> dato;
                std::cout << "Dame la posicion donde se debe insertar el empleado: ";
                std::cin >> posicion;
                lista.Inserta(dato, posicion);
                break;
            }
            case 5: {
                lista.Muestra();
                break;
            }
            case 6: {
                std::cout << "Saliendo del programa." << std::endl;
                break;
            }
            default:
                std::cout << "Opcion no valida. Intente nuevamente." << std::endl;
        }

    } while (opcion != 6);

    return 0;
}
