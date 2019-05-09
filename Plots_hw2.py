import numpy as np
import matplotlib.pylab as plt

Piso1t = np.genfromtxt('3_Piso1.dat',delimiter=',')
Piso1 = np.transpose(Piso1t)
Piso2t = np.genfromtxt('3_Piso2.dat',delimiter=',')
Piso2 = np.transpose(Piso2t)
Piso3t = np.genfromtxt('3_Piso3.dat',delimiter=',')
Piso3 = np.transpose(Piso3t)

plt.figure()
plt.title("Primer intento de la trayectoria del edificio")
plt.plot(Piso1[0],Piso1[1], label='Piso 1')
plt.plot(Piso2[0],Piso2[1], label='Piso 2')
plt.plot(Piso3[0],Piso3[1], label='Piso 3')
plt.legend()
plt.xlabel('$t$')
plt.ylabel('$u(t)$')
plt.savefig('3_PrimerEdificio.pdf')

MPiso1t = np.genfromtxt('3_MaximoP1.dat',delimiter=',')
MPiso1 = np.transpose(MPiso1t)
MPiso2t = np.genfromtxt('3_MaximoP2.dat',delimiter=',')
MPiso2 = np.transpose(MPiso2t)
MPiso3t = np.genfromtxt('3_MaximoP3.dat',delimiter=',')
MPiso3 = np.transpose(MPiso3t)

plt.figure()
plt.title("Amplitud maxima en funcion de $\omega$")
plt.plot(MPiso1[0],MPiso1[1], label='Piso 1')
plt.plot(MPiso2[0],MPiso2[1], label='Piso 2')
plt.plot(MPiso3[0],MPiso3[1], label='Piso 3')
plt.legend()
plt.xlabel('$\omega$')
plt.ylabel('$u_{max}$')
plt.savefig('3_Maximos.pdf')

SMPisos = MPiso1[1]+MPiso2[1]+MPiso3[1] 
print('La amplitud maxima tiene maximos locales - en los tres pisos - en las frecuencias: ')
print(MPiso1[0,np.argmax(SMPisos[MPiso1[0]<1])])
print(MPiso1[0,np.argmax(SMPisos[np.logical_and(MPiso1[0]>1,MPiso1[0]<2)])])
print(MPiso1[0,np.argmax(SMPisos[MPiso1[0]>2])])

