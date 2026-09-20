#%%
import matplotlib.pyplot as plt
import numpy as np

a = 9
b = 8
d = np.pi / 5

N = 500
t = np.linspace(0, 2 * np.pi, N)
x = np.sin(a * t + d)
y = np.sin(b * t)

X1, X2 = np.meshgrid(x, x)
Y1, Y2 = np.meshgrid(y, y)
distance_matrix = (X1 - X2) ** 2 + (Y1 - Y2) ** 2

for i in range(N):
    distance_matrix[i, max(0, i - 12) : min(N, i + 13)] = 10.0

intersection_x = []
intersection_y = []

for i in range(1, N - 1):
    for j in range(i + 13, N - 1):
        if distance_matrix[i, j] < 0.005:
            sub_matrix = distance_matrix[i - 1 : i + 2, j - 1 : j + 2]
            if distance_matrix[i, j] == np.min(sub_matrix):
                intersection_x.append((x[i] + x[j]) / 2)
                intersection_y.append((y[i] + y[j]) / 2)

fig, (ax1, ax2) = plt.subplots(1, 2, figsize=(14, 6))

ax1.plot(x, y, color="gainsboro")
ax1.scatter(
    intersection_x,
    intersection_y,
    color="crimson"
)

ax1.set_xlabel("X")
ax1.set_ylabel("Y")
ax1.grid(True)
ax1.axis("equal")

ax2.hist(
    intersection_x,
    bins=40,
    color="crimson",
    edgecolor="black",

)

ax2.set_xlabel("Координата X точки пересечения")
ax2.set_ylabel("Плотность вероятности")
ax2.grid(True)

plt.tight_layout()
plt.show()