import math

#definir la funcion
def ecuacion(x):
    return x**3+math.exp(-x)-1.5

#algoritmo de biseccion
def biseccion(a,b,precision,n):
    # bucle hasta 40 iteraciones y la precision mayor que 10^-6
    while n<40 and precision>10**(-6):
        # punto medio
        x=(a+b)/2
        
        if ecuacion(a)*ecuacion(b)<0:
            # Si hay una raiz en [a, x], actualizar b
            if ecuacion(a)*ecuacion(x)<0:
                b=x
            # Si hay una raiz en [x, b], actualizar a
            else:
                a=x
        else:
            # mostrar que no hay raiz si no se cumplen las condiciones y salir del bucle
            print("No hay raiz en el intervalo.")
            break
        # Actualizacion de la precisión siendo este la longitud del intervalo
        precision=abs(b-a)
        n+=1
    return x,ecuacion(x),precision,n

data=biseccion(-1,1,2,0)
print("La raiz resulta ser: ",data)