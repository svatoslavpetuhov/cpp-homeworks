import numpy as np
import scipy.linalg as la

N = 20
diag_1 = np.full(N, 2.0)
diag_2 = np.full(N-1, -1.0)

A = np.diag(diag_1) + np.diag(diag_2, k = 1) + np.diag(diag_2, k = -1)

b = np.full(N, 0.0)
b[0] = 100
b[-1] = 1

x = la.solve(A, b)

print(x)