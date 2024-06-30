#include "func_pract2.h"

int main() {
    const char *archivoMatrizA = "matrizA.txt";
    const char *archivoMatrizB = "matrizB.txt";

    int filasA, columnasA, filasB, columnasB;

    int **matrizA = nullptr, **matrizB = nullptr, **resultado = nullptr; //recomendable usar nullptr

    //entramos en un bucle while que solo saldra si se introduce la opcion 4
    while (true) {

        cout<<"----------------------------------"<<endl;
        cout << "\nSeleccione una operación:\n" << endl;
        cout << "1. Sumar matrices" << endl;
        cout << "2. Restar matrices" << endl;
        cout << "3. Multiplicar matrices" << endl;
        cout << "4. Salir\n" << endl;
        cout<<"----------------------------------"<<endl;

        //valor de entrada option
        cout<<"Operacion: ";
        int option;
        while (!(cin >> option)){
            // Limpia la entrada en caso de error
            cin.clear();
            // Descarta cualquier entrada incorrecta
            cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada invalida. Por favor, introduce un numero entero: ";
        }
        cout<<"----------------------------------"<<endl;

        if (option == 4) {
            cout<<"\nSaliendo del programa...\n";
            break; // Salir del bucle si la opción es 4
        }

        // Lee los datos de los archivos
        read(archivoMatrizA, matrizA, filasA, columnasA);
        read(archivoMatrizB, matrizB, filasB, columnasB);

        // Verifica las dimensiones antes de realizar la operación correspondiente
        if (filasA != filasB || columnasA != columnasB) {
            cerr << "Las matrices deben tener las mismas dimensiones para realizar la operación." << endl;
            continue; // Continuar al siguiente ciclo del bucle
        }

        // Reserva memoria para la matriz de salida (resultado)
        resultado = new int *[filasA];
        for (int i = 0; i < filasA; ++i) {
            resultado[i] = new int[columnasA];
        }

        // Realiza la operación que haya escogido el usuario
        switch (option) {
            case 1:
                add((const int **)matrizA, (const int **)matrizB, resultado, filasA, columnasA);
                cout << "\nResultado de la suma:\n" << endl;
                break;
            case 2:
                restar((const int **)matrizA, (const int **)matrizB, resultado, filasA, columnasA);
                cout << "\nResultado de la resta:\n" << endl;
                break;
            case 3:
                mu((const int **)matrizA, (const int **)matrizB, resultado, filasA, columnasA, filasB, columnasB);
                cout << "\nResultado de la multiplicación:\n" << endl;
                break;
            default:
                cerr << "\nOpción no válida.\n" << endl;
                break;
        }

        // Imprime el resultado
        print((const int **)resultado, filasA, columnasA);

        // Liberar la memoria de todos los punteros
        for (int i = 0; i < filasA; ++i) {
            delete[] matrizA[i];
            delete[] matrizB[i];
            delete[] resultado[i];
        }
        delete[] matrizA;
        delete[] matrizB;
        delete[] resultado;
    }

    return 0;
}