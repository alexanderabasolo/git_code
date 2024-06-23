import math
from scipy import stats

def bsm_call(S0, K, T, r, sigma):
    d1 = (math.log(S0 / K) + (r + 0.5 * sigma ** 2) * T) / (sigma * math.sqrt(T))
    d2 = d1 - sigma * math.sqrt(T)
    valor = (S0 * stats.norm.cdf(d1, 0, 1)) - K * math.exp(-r * T) * stats.norm.cdf(d2, 0, 1)
    return valor

def bsm_put(S0, K, T, r, sigma):
    d1 = (math.log(S0 / K) + (r + 0.5 * sigma ** 2) * T) / (sigma * math.sqrt(T))
    d2 = d1 - sigma * math.sqrt(T)
    valor = math.exp(-r * T) * K * stats.norm.cdf(-d2, 0, 1) - S0 * stats.norm.cdf(-d1, 0, 1)
    return valor

z = bsm_put(17, 15, 0.25, 0.03, 0.25)
print(z)