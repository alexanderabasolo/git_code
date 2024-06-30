# hipoteca.py

def cuota(h, n, i):
    r = i / (100 * 12)
    return h * r / (1 - (1 + r) ** (-12 * n))

def cantidad_pagada(h, n, i):
    cuota_mensual = cuota(h, n, i)
    return cuota_mensual * 12 * n

def intereses(h, n, i):
    total_pagado = cantidad_pagada(h, n, i)
    return total_pagado - h

def porcentaje_intereses(h, n, i):
    total_intereses = intereses(h, n, i)
    return (total_intereses / h) * 100
