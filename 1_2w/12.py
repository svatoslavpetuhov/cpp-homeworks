#%%
import matplotlib.pyplot as plt
import numpy as np

t = np.arange(0, 4 * np.pi, 0.01)

fig, axes = plt.subplots(3, 3, figsize=(10, 10))
fig.suptitle("Lissajous figures")

frequencies = [(1, 1), (1, 2), (9, 8)]
phases = [0, np.pi / 4, np.pi / 2]

for row_idx, (a, b) in enumerate(frequencies):
    for col_idx, d in enumerate(phases):
        
        ax = axes[row_idx, col_idx]
        
        x = np.sin(a * t + d)
        y = np.sin(b * t)
        
        ax.plot(x, y)
        
        ax.set_title(f"a:b = {a}:{b}, δ = {col_idx}π/4")
        ax.grid(True)
        ax.axis("equal")

plt.tight_layout()
plt.show()

# %%
