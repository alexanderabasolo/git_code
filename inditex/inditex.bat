import pandas as pd

# Rutas de los archivos CSV
ruta_archivo1 = 'C:\Users\Alejandro\Downloads\courier_fare.csv'
ruta_archivo2 = 'C:\Users\Alejandro\Downloads\orders.csv'
ruta_archivo3 = 'C:\Users\Alejandro\Downloads\trucker_capacity.csv'
ruta_archivo4 = 'C:\Users\Alejandro\Downloads\trucker_fare.csv'

# Cargar datos en DataFrames individuales
datos1 = pd.read_csv(ruta_archivo1)
datos2 = pd.read_csv(ruta_archivo2)
datos3 = pd.read_csv(ruta_archivo3)
datos4 = pd.read_csv(ruta_archivo4)

# Mostrar los primeros registros de cada DataFrame
print("Datos del archivo 1:")
print(datos1.head())
print("\nDatos del archivo 2:")
print(datos2.head())
print("\nDatos del archivo 3:")
print(datos3.head())
print("\nDatos del archivo 4:")
print(datos4.head())