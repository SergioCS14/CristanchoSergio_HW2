import numpy as np
import matplotlib.pylab as plt

Piso1t = np.genfromtxt('Piso1.dat',delimiter=',')
Piso1 = np.transpose(Piso1t)
Piso2t = np.genfromtxt('Piso2.dat',delimiter=',')
Piso2 = np.transpose(Piso2t)
Piso3t = np.genfromtxt('Piso3.dat',delimiter=',')
Piso3 = np.transpose(Piso3t)

plt.figure()
plt.plot(Piso1[0],Piso1[1], label='Piso 1')
plt.xlabel('$t$')
plt.ylabel('$A$')
plt.savefig('Piso1.pdf')

plt.figure()
plt.plot(Piso2[0],Piso2[1], label='Piso 2')
plt.xlabel('$t$')
plt.ylabel('$A$')
plt.savefig('Piso2.pdf')

plt.figure()
plt.plot(Piso3[0],Piso3[1], label='Piso 3')
plt.xlabel('$t$')
plt.ylabel('$A$')
plt.savefig('Piso3.pdf')