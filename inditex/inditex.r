# Cargar las bibliotecas necesarias
install.packages("readr")
library(readr)

# Rutas de los archivos CSV
ruta_archivo1 <- 'C:/Users/Alejandro/Downloads/courier_fare.csv'
ruta_archivo2 <- 'C:/Users/Alejandro/Downloads/orders.csv'
ruta_archivo3 <- 'C:/Users/Alejandro/Downloads/trucker_capacity.csv'
ruta_archivo4 <- 'C:/Users/Alejandro/Downloads/trucker_fare.csv'

# Cargar datos en DataFrames individuales
datos1 <- read_csv(ruta_archivo1)
datos2 <- read_csv(ruta_archivo2)
datos3 <- read_csv(ruta_archivo3)
datos4 <- read_csv(ruta_archivo4)

# Mostrar los primeros registros de cada DataFrame
cat("Datos del archivo 1:\n")
print(head(datos1))
cat("\nDatos del archivo 2:\n")
print(head(datos2))
cat("\nDatos del archivo 3:\n")
print(head(datos3))
cat("\nDatos del archivo 4:\n")
print(head(datos4))
