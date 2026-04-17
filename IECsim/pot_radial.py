import pandas as pd
import matplotlib.pyplot as plt

run = 'run4/'
plots = run + 'plots/'

x = pd.read_csv(run + 'potential_radial_x.dat', sep=r'\s+', comment='#', header=None, names=['r', 'potential'])
y = pd.read_csv(run + 'potential_radial_y.dat', sep=r'\s+', comment='#', header=None, names=['r', 'potential'])
z = pd.read_csv(run + 'potential_radial_z.dat', sep=r'\s+', comment='#', header=None, names=['r', 'potential'])

fig, axes = plt.subplots(1, 3, figsize=(15, 5))

axes[0].plot(x['r'], x['potential'])
axes[0].set_xlabel('r (m)')
axes[0].set_ylabel('potential (V)')
axes[0].set_title('Radial potential - X axis')
axes[0].grid(True)

axes[1].plot(y['r'], y['potential'])
axes[1].set_xlabel('r (m)')
axes[1].set_ylabel('potential (V)')
axes[1].set_title('Radial potential - Y axis')
axes[1].grid(True)

axes[2].plot(z['r'], z['potential'])
axes[2].set_xlabel('r (m)')
axes[2].set_ylabel('potential (V)')
axes[2].set_title('Radial potential - Z axis')
axes[2].grid(True)

plt.tight_layout()
plt.savefig(plots + 'potential_radial_all_axes.png', dpi=150)