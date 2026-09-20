#%%
import numpy as np
import matplotlib.pyplot as plt

A = 2.5
B = 1.0
num_points = 200

X = np.linspace(0, 20, num_points)

# noise = np.random.standard_normal(size=num_points)

mu, sigma = 0, 1.5
noise = np.random.normal(loc=mu, scale=sigma, size=num_points)

Y = A * X + B + noise

M = np.vstack([X, np.ones(len(X))]).T
A_fit, B_fit = np.linalg.lstsq(M, Y, rcond=None)[0]

plt.figure(figsize=(10, 6))
plt.scatter(X, Y, )
plt.plot(X, A * X + B, color='blue', linestyle='--',label='True line')
plt.plot(X, A_fit * X + B_fit, color='red', label='Approx linr')

plt.xlabel('X')
plt.ylabel('Y')
plt.legend()
plt.grid(True)
plt.show()
# %%
