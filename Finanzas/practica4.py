##################################################################################################
# author: alexabasolo99@gmail.com
# master industrial mathematics
##################################################################################################

class Punto:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __str__(self):
        return f"({self.x}, {self.y})"

class Linea:
    def __init__(self, inicio, fin):
        self.inicio = inicio
        self.fin = fin

    def __str__(self):
        return f"Inicio: {self.inicio}, Fin: {self.fin}"

    def modificar_inicio(self, nuevo_inicio):
        self.inicio = nuevo_inicio

    def modificar_fin(self, nuevo_fin):
        self.fin = nuevo_fin

    def __add__(self, nueva_linea):
        nuevo_inicio = Punto(self.inicio.x + nueva_linea.inicio.x, self.inicio.y + nueva_linea.inicio.y)
        nuevo_fin = Punto(self.fin.x + nueva_linea.fin.x, self.fin.y +nueva_linea.fin.y)
        return Linea(nuevo_inicio, nuevo_fin)

# Ejemplos
punto_inicio = Punto(0, 0)
punto_fin = Punto(7, 7)
linea1 = Linea(punto_inicio, punto_fin)
print("Linea 1:", linea1)

nuevo_inicio = Punto(2, 1)
linea1.modificar_inicio(nuevo_inicio)
print("Linea 1 con nuevo inicio:", linea1)

linea2 = Linea(Punto(4, 1), Punto(5, 4))
print("Linea 2:", linea2)

nuevo_fin = Punto(5, 5)
linea2.modificar_fin(nuevo_fin)
print("Linea 2 con nuevo fin:", linea2)

linea_suma = linea1 + linea2
print("Suma de Linea 1 y Linea 2:", linea_suma)