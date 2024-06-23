import sys

def calcular_e(n):
    """
    Calcula e elevado a 1 utilizando la serie de Taylor hasta el n-ésimo término.
    
    Args:
    - n (int): Número de términos a considerar en la serie de Taylor.
    
    Returns:
    - e_aprox (float): Aproximación de e elevado a 1.
    """
    e_aprox = 0
    factorial = 1
    for i in range(n):
        e_aprox += 1 / factorial
        factorial *= (i + 1)
    return e_aprox

def encontrar_terminos_minimos(error_deseado):
    """
    Encuentra el número mínimo de términos necesarios para calcular e elevado a 1
    con el error especificado.
    
    Args:
    - error_deseado (float): Error máximo permitido en la aproximación.
    
    Returns:
    - n (int): Número mínimo de términos necesarios.
    - e_aprox (float): Aproximación de e elevado a 1 con n términos.
    """
    n = 1
    e_aprox = calcular_e(n)
    error_actual = abs(e_aprox - sys.float_info.epsilon)  # Error inicial
    
    while error_actual > error_deseado:
        n += 1
        e_aprox = calcular_e(n)
        error_actual = abs(e_aprox - sys.float_info.epsilon)
    
    return n, e_aprox

# Precisión de la máquina
epsilon = sys.float_info.epsilon

# Calculamos el número mínimo de términos con un error deseado de la mitad de la precisión de la máquina
error_deseado = epsilon / 2
n_minimo, e_aprox_minimo = encontrar_terminos_minimos(error_deseado)

print(f"Número mínimo de términos: {n_minimo}")
print(f"Aproximación de e elevado a 1 con {n_minimo} términos: {e_aprox_minimo}")