#include "func_pract1.h"

long double calculate_serie(){
    float suma=0;
    int k,n;

    //Validacion de tipo entero
    while(true){
        cout<<"\nIntroduce el numero entero de n terminos: \n";
        if (cin>>n){
            break;
        }else{
            cout<<"\nEntrada no válida. Por favor, ingrese un número entero válido.\n" << endl;
            cin.clear();  // Limpiar el estado de error
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Descartar la entrada no válida
        }
    }

    cout<<"\nNumero de términos(n): "<<n;

    for (k=0;k<n;k++){
        suma += pow(3.0, k) / tgamma(3.0 + k);
    }

    return suma;
}

int get_n(){
    srand(time(0));
    long double n;

    cout << "Este programa calcula una aproximación al número pi con el método de Montecarlo." << endl;
    cout << "Consiste en generar puntos aleatorios en un cuadrado con un círculo inscrito en él, y luego ver la proporción de puntos que está en el círculo." << endl;
    cout << "Cuando el número de puntos tiende a infinito, ese numero es aproximadamente pi/4" << endl;

    cout << "\nIntroduce el número de puntos aleatorios generados (se ha de aclarar que a más puntos, más precisión, pero también más tiempo de espera de la ejecucion): ";
    cin >> n;

    return n;
}

long double calculate_pi(int n){

    srand(time(0));
    long double pi;
    long double x, y;          // corresponde con las coordenadas aleatorias
    long double dentro_circulo = 0;

    ofstream dataFile("montecarlo_data.dat");

    for (int i = 0; i < n; i++)
    {
        x = (long double)rand() / (long double)(RAND_MAX); // generar número aleatorio de tipo double entre 0 y 1
        y = (long double)rand() / (long double)(RAND_MAX);
        // Teniendo en cuenta el espacio geométrico del círculo en R^2 (x^2 + y^2 = r^2), podemos saber si (x, y) está dentro del círculo
        if (x * x + y * y <= 1.0)
        {
            dentro_circulo += 1;
            dataFile << x << " " << y << " 1\n";
        }
        else
        {
            dataFile << x << " " << y << " 2\n"; // Marcar puntos fuera del círculo con 2
        }
    }
    pi = (dentro_circulo / n) * 4.0;
    cout << "\nAproximadamente, utilizando " << n << " puntos, pi es " << pi;
    cout<<" "<<endl;

    return pi;
}

long double calculator(){   
    int option;
    double a,b;
    cout<<"¡Bienvenido! Esto es un programa que realiza las operaciones simples de suma, resta, multiplicacion y division de dos numeros"<<endl;
    cout<<"Segun el numero que introduzcas en la terminal hara una operacion u otra."<<endl;
    cout<<"A continuacion, se muestran los numeros enteros que debes seleccionar para hacer las siguientes operaciones: "<<endl;

    // Bucle para que continue hasta que se cumpla la condicion
    while(true){
        cout<<"\n1 : Suma\n2 : Resta\n3 : Multiplicacion\n4 : Division\n5 : Salir del programa"<<endl;
        cout<<"\nElija una opcion: "<<endl;

        // Bucle para validacion de la variable option, se requerira un input al usuario hasta que cumpla una de las cinco opciones descritas
        // Se introduce el input del usuario en el bucle si cumple con esas condiciones para pedir de nuevo la opcion, static_cast sirve para convertir la variable option a un entero
        // Se utiliza el clear y ignore para descartar errores en la terminal y el usuario pueda introducir el dato correcto en caso de equivocarse con el tipado y
        // numeric_limits<streamsize>::max() lo utilizamos para ignorar todo el contenido hasta la siguiente linea
        while(!(cin>>option) || option <1 || option>5 || option!= static_cast<int>(option)){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<<"\nEntrada no valida. Por favor, introduzca un numero entero valido del 1 al 5. \n";
            cout<<"\nElija una opcion: ";}
        if (option ==5){
            cout<<"\nSaliendo del programa. \n";
            break;
        }

        cout<<"Introduzca el primer numero: ";
        cin>>a;
        cout<<"Introduzca el segundo numero: ";
        cin>>b;

        // Utilizamos el switch como menu de operaciones
        switch (option) {
            case 1:
            cout<<"\nSuma: "<< a+b<<"\n";
                break;
            case 2:
            cout<<"\nResta: "<<a-b<<"\n";
                break;
            case 3:
            cout<<"\nMultiplicacion: "<<a*b<<"\n";
                break;
            case 4:
                if (b !=0){
                    cout<<"\nDivision: "<<a/b<<"\n";
                } else{
                    cout<<"\nError: No se puede dividir por cero.\n";
                    continue;
                }
                break;
            default:
                cout<<"\nOpcion no valida. Por favor, elija una opcion del 1 al 5. n/";
                continue;
        }
    }
    return 0;
}

long double escalar(){
    //Asignamos al objeto archivo el nombre de vectores.txt
    ifstream archivo("vectores14.txt");

    //Validacion de apertura del archivo
    if (!archivo) {
        cerr << "Error. El archivo no pudo abrirse." << endl;
        return 0;
    }

    int n;
    archivo >> n;

    if (n < 2) {
        cerr << "Error. La dimensión del vector debe ser al menos 2." << endl;
        archivo.close();
        return 0;
    }

    //Declaracion de los vectores
    vector<int> vector1(n);
    vector<int> vector2(n);

    //Lectura de los datos del 1er vector
    for (int i=0; i < n; ++i) {
        archivo >> vector1[i];
    }

    //Lectura de los datos del 2do vector
    for (int i=0; i < n; ++i) {
        archivo >> vector2[i];
    }

    //Cierre del fichero de los datos
    archivo.close();

    if (vector1.size() != vector2.size()) {
        cerr << "El tamaño de los vectores no coinciden." << endl;
        return 0;
    }

    // Calcular el producto escalar
    long double productEscalar = 0;
    for (int i=0; i < n; ++i) {
        productEscalar += vector1[i] * vector2[i];
    }

    return productEscalar;
}

void crear_vectores() {
    int n;
    float max_val = 1000.0;
    float min_val = -1000.0;

    srand(time(NULL));

    cout << "Tamaño de los vectores (n >= 2):" << endl;
    cin >> n;

    while (n < 2) {
        cout << "Tamaño introducido incorrecto. Debe ser al menos 2." << endl;
        cout << "Tamaño de los vectores (n >= 2):" << endl;
        cin >> n;
    }

    float *vector1 = new float[n];
    float *vector2 = new float[n];

    for (int i = 0; i < n; i++) {
        vector1[i] = static_cast<float>(rand()) / RAND_MAX * (max_val - min_val) + min_val;
        vector2[i] = static_cast<float>(rand()) / RAND_MAX * (max_val - min_val) + min_val;
    }

    ofstream file1("vector_41.txt");
    ofstream file2("vector_42.txt");

    if (!file1.is_open() || !file2.is_open()) {
        cerr << "Error al abrir el archivo." << endl;
        delete[] vector1;
        delete[] vector2;
        exit(EXIT_FAILURE);
    }

    file1 << n << endl;
    file2 << n << endl;

    for (int i = 0; i < n; i++) {
        file1 << vector1[i] << endl;
        file2 << vector2[i] << endl;
    }

    file1.close();
    file2.close();

    delete[] vector1;
    delete[] vector2;

    cout << "Se han creado 2 vectores de tamaño " << n << " con valores aleatorios entre " << min_val << " y " << max_val << " y guardados en 'vector_41.txt' y 'vector_42.txt'" << endl;
}

float calculo_prod_esca() {
    int n1, n2;
    float result = 0.0;

    ifstream archivo1("vector_41.txt");
    ifstream archivo2("vector_42.txt");

    if (!archivo1.is_open() || !archivo2.is_open()) {
        cerr << "Error al abrir el archivo." << endl;
        return 1.0f;
    }

    if (!(archivo1 >> n1) || !(archivo2 >> n2)) {
        cerr << "Error al leer el número de elementos." << endl;
        return 1.0f;
    }

    // Comprobar si las dimensiones de los vectores son iguales
    if (n1 != n2) {
        cerr << "Error: Las dimensiones de los vectores no son iguales." << endl;
        return 1.0f;
    }

    float *vector1 = new float[n1];
    float *vector2 = new float[n2];
    float *vector3 = new float[n1];

    for (int i = 0; i < n1; i++) {
        if (!(archivo1 >> vector1[i]) || !(archivo2 >> vector2[i])) {
            cerr << "Error al leer las componentes del vector." << endl;
            delete[] vector1;
            delete[] vector2;
            delete[] vector3;
            return 1.0f;
        }
        vector3[i] = vector1[i] * vector2[i];
        result += vector3[i];
    }

    delete[] vector1;
    delete[] vector2;
    delete[] vector3;

    return result;
}