import math

##################################################################################################
# author: alexabasolo99@gmail.com
# master industrial mathematics
##################################################################################################

def calcular_e(precision):
    # acumuladores e y num_terminos, termino es la x en el ejercicio
    e = 0
    termino = 1
    num_terminos = 0
    
    while abs(termino) > precision:
        e += termino
        num_terminos += 1
        termino = 1 / math.factorial(num_terminos)
    # e es una aproximacion
    return e, num_terminos

target_precision = 2.22e-16
e, num_terminos = calcular_e(target_precision)

# no utilizamos las tildes para que no haya ninguna incidencia
print(f"La proximación de e resulta ser: {e}.")
print(f"El numero de terminos utilizados corresponde con: {num_terminos}.")