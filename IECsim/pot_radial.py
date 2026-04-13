import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

df = pd.read_csv('trajectory_lengths.dat', sep='\s+', comment='#', header=None, names=['r', 'potential'])

fig, ax = plt.subplots(figsize=(10,7))
ax.plot(df['r'], df['potential'])
ax.set_xlabel('r (m)')
ax.set_ylabel('potential (V)')
ax.set_title('Radial potential profile')
ax.grid(True)
plt.savefig('potential_radial.png')
plt.show()