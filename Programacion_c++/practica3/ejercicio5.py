import numpy as np
import matplotlib.pyplot as plt
import matplotlib.tri as tri
import matplotlib

matplotlib.use('TkAgg') #utilizamos la biblioteca Tkinter

# Lee los vértices desde el archivo
with open("nodes.txt", "r") as vertices_file:
    num_vertices = int(vertices_file.readline())
    xy = np.loadtxt(vertices_file)

# Lee las conectividades desde el archivo
with open("triang.txt", "r") as conectividades_file:
    num_triangles = int(conectividades_file.readline())
    triangles = np.loadtxt(conectividades_file, dtype=int)

# Verifica las dimensiones de los datos
print("xy shape:", xy.shape)
print("triangles shape:", triangles.shape)

# triangulo
triang = tri.Triangulation(xy[:, 0], xy[:, 1], triangles)

# Visualizacion de la malla
plt.figure()
plt.triplot(triang, 'go--', markersize=8)
plt.plot(xy[:, 0], xy[:, 1], 'ro')
plt.title('Mallado Triangular')
plt.show()