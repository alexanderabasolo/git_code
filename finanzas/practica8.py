import QuantLib as ql

# Definicion y configuracion de parametros de entrada
S0 = ql.QuoteHandle(ql.SimpleQuote(127.62))
K = 130.00
r = ql.QuoteHandle(ql.SimpleQuote(0.001))
q = ql.QuoteHandle(ql.SimpleQuote(0.0163))
sigma = ql.QuoteHandle(ql.SimpleQuote(0.20))
start_date = ql.Date(26, 4, 2024)
end_date = ql.Date(26, 1, 2025)

# Configuracion de los tiempos (fechas)
ql.Settings.instance().evaluationDate = start_date
numberday = ql.Actual365Fixed()
calendar = ql.UnitedStates(ql.UnitedStates.NYSE)

# Curvas de tipos de interes y dividendos
spot_handle = S0
rate_handle = ql.YieldTermStructureHandle(ql.FlatForward(start_date, r, numberday))
dividend_handle = ql.YieldTermStructureHandle(ql.FlatForward(start_date, q, numberday))
volatility_handle = ql.BlackVolTermStructureHandle(ql.BlackConstantVol(start_date, calendar, sigma, numberday))

# Proceso del activo subyacente
process = ql.BlackScholesMertonProcess(spot_handle, dividend_handle, rate_handle, volatility_handle)

# Pago a vencimiento de opcion Europea
payoff = ql.PlainVanillaPayoff(ql.Option.Call, K)
exercise = ql.EuropeanExercise(end_date)
option = ql.VanillaOption(payoff, exercise)

# Metodo de valoración: Monte Carlo
engine_mc = ql.MCEuropeanEngine(process, 'pseudorandom', antitheticVariate=True, timeSteps=50, requiredSamples=100000)
option.setPricingEngine(engine_mc)
mc_price = option.NPV()
mc_error = option.errorEstimate()

# Metodo de valoracion: Formula Analitica de Black-Scholes
engine_bs = ql.AnalyticEuropeanEngine(process)
option.setPricingEngine(engine_bs)
bs_price = option.NPV()

# Metodo de valoración: Diferencias Finitas, 800 nodos = 800 pasos en el tiempo, 800 nodos en la malla temporal
engine_fd = ql.FdBlackScholesVanillaEngine(process, 800, 800)
option.setPricingEngine(engine_fd)
fd_price = option.NPV()

# Impresion con formato de resultados
print(f"Resultados de valoración de la opcion europea (Call):")
print(f"{'-'*50}")
print(f"Precio por Monte Carlo (MC):         {mc_price:10.4f}")
print(f"Error cometido con Monte Carlo (MC): {mc_error:10.4f}")
print(f"{'-'*50}")
print(f"Precio por formula Black-Scholes (BS): {bs_price:10.4f}")
print(f"{'-'*50}")
print(f"Precio por Diferencias Finitas (FD): {fd_price:10.4f}")