import numpy as np

##################################################################################################
# author: alexabasolo99@gmail.com
# master industrial mathematics
##################################################################################################

#valor inicial
S0 = 17
K = 15
#tipo de interes constante
r = 0.03
#volatilidad
sigma = 0.25
#periodo de tiempo (en años)
T = 0.25
#numero de pasos
M = 50
#numero de simulaciones
I = 100000
delta = T / M
S = np.zeros([M + 1, I])
S[0] = S0

option = 'call'

# Cada fila representa un momento t y cada columna una simulacion
for t in range(1, M + 1):
    S[t] = S[t - 1] * np.exp((r - 0.5 * sigma ** 2) * delta + sigma * np.sqrt(delta) * np.random.standard_normal(I))

#payoff segun la opcion vainilla
if option == 'call':
    hT = np.maximum(S[-1] - K, 0)
elif option == 'put':
    hT = np.maximum(K - S[-1], 0)
else:
    print('La opción debería ser call o put')

# estimador del precio de la opcion de compra
V0 = np.exp(-r * T) * np.sum(hT) / I

print('El precio de la opción es %f' % V0)

#desviacion tipica
std = np.sqrt(np.sum((np.exp(-r * T) * hT - V0) ** 2) / I)

s = r'% '
print('Intervalo de confianza al 95' + s + '(%f,%f)' % (V0 - 1.96 * std / np.sqrt(I), V0 + 1.96 * std / np.sqrt(I)))