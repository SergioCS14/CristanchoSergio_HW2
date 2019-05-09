import numpy as np
import matplotlib.pylab as plt

MPiso1t = np.genfromtxt('3_MaximoP1.dat',delimiter=',')
MPiso1 = np.transpose(MPiso1t)
MPiso2t = np.genfromtxt('3_MaximoP2.dat',delimiter=',')
MPiso2 = np.transpose(MPiso2t)
MPiso3t = np.genfromtxt('3_MaximoP3.dat',delimiter=',')
MPiso3 = np.transpose(MPiso3t)

plt.figure()
plt.plot(MPiso1[0],MPiso1[1], label='Piso 1')
plt.plot(MPiso2[0],MPiso2[1], label='Piso 2')
plt.plot(MPiso3[0],MPiso3[1], label='Piso 3')
plt.legend()
plt.xlabel('$\omega$')
plt.ylabel('$u_{max}$')
plt.savefig('3_Maximos.pdf')
