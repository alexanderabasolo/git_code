#include "malla.h"

int main() {
    Malla malla("nodes.txt", "triang.txt"); //inicializa la malla leyendo estos dos archivos
    malla.areashow();

    return 0;
}