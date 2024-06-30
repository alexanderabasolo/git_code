import math
from scipy import stats
import numpy as np

##################################################################################################
# author: alexabasolo99@gmail.com
# master industrial mathematics
##################################################################################################

def montecarlo(S0, K, r, sigma, T, I, N, option, D0):
    dt = T / N
    S = np.zeros((N+1, I))
    S[0] = S0
    for t in range(1, N+1):
        Z = np.random.standard_normal(I)
        S[t] = S[t-1] * np.exp((r - D0 - 0.5 * sigma ** 2) * dt + sigma * np.sqrt(dt) * Z)

    if option == 'call':
        hT = np.maximum(S[-1] - K, 0)
    elif option == 'put':
        hT = np.maximum(K - S[-1], 0)
    else:
        raise ValueError('La opcion deberia ser call o put. Introduce una opcion valida')

    V0 = np.exp(-r * T) * np.mean(hT)
    std = np.sqrt(np.var(np.exp(-r * T) * hT) / I)
    s = '%'
    print('El precio de la opcion es %f' % V0)
    print('Intervalo de confianza al 95'+s+' (%f, %f)' % (V0 - 1.96 * std, V0 + 1.96 * std))
    return V0, std

def bsm(S0, K, T, t, r, D0, sigma, option):
    d1 = (math.log(S0 / K) + (r - D0 + 0.5 * sigma ** 2) * (T - t)) / (sigma * math.sqrt(T - t))
    d2 = d1 - sigma * math.sqrt(T - t)
    if option == 'call':
        valor = (S0 * math.exp(-D0 * (T - t)) * stats.norm.cdf(d1, 0.0, 1.0) - 
                 K * math.exp(-r * (T - t)) * stats.norm.cdf(d2, 0.0, 1.0))
    elif option == 'put':
        valor = (K * math.exp(-r * (T - t)) * stats.norm.cdf(-d2, 0.0, 1.0) - 
                 S0 * math.exp(-D0 * (T - t)) * stats.norm.cdf(-d1, 0.0, 1.0))
    else:
        raise ValueError('La opcion deberia ser call o put. Introduce una opcion valida')
    return valor

z = bsm(17.00, 15.00, 0.25, 0, 0.03, 0.015, 0.25, 'call')
w, std = montecarlo(17.00, 15.00, 0.03, 0.25, 0.25, 100000, 50, 'put', 0.015)

print('La opcion de compra esta valorada en: {:.2f}'.format(z))
print('La opcion de venta esta valorada en: {:.2f} con una desviación estándar de {:.2f}'.format(w, std))