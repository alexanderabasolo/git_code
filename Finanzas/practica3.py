# main.py
import hipoteca

##################################################################################################
# author: alexabasolo99@gmail.com
# master industrial mathematics
##################################################################################################

def main():
    h = float(input("Ingrese el capital de la hipoteca en euros: "))
    i = float(input("Ingrese el interes anual en porcentaje: "))
    n = int(input("Ingrese el numero de años: "))

    cuota = hipoteca.cuota(h, n, i)
    pagado = hipoteca.cantidad_pagada(h, n, i)
    intereses = hipoteca.intereses(h, n, i)
    porcentaje_interes = hipoteca.porcentaje_intereses(h, n, i)

    print(f"La cuota mensual para amortizar la hipoteca es de: {cuota:.2f} euros.")
    print(f"La cantidad total pagada al banco sera de: {pagado:.2f} euros.")
    print(f"La cantidad de intereses pagados sera de: {intereses:.2f} euros.")
    print(f"Esto corresponde al {porcentaje_interes:.2f}% del capital inicial.")

if __name__ == "__main__":
    main()
