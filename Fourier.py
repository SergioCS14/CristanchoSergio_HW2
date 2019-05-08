import numpy as np
import matplotlib.pylab as plt

signalt = np.genfromtxt('signal.dat')
signal = np.transpose(signalt)
signalSumat = np.genfromtxt('signalSuma.dat')
signalSuma = np.transpose(signalSumat)

plt.figure(figsize=(14,10))
plt.subplot(2,1,1)
plt.plot(signal[0],signal[1])
plt.xlabel('$t$')
plt.ylabel('$A$')
plt.title('Signal')

plt.subplot(2,1,2)
plt.plot(signalSuma[0],signalSuma[1])
plt.xlabel('$t$')
plt.ylabel('$A$')
plt.title('Signal Suma')

plt.savefig('2_Signal.pdf')