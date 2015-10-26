import numpy as np
import matplotlib.pyplot as plt

a = 1
b = 3
c = 2

x = np.linspace(0,3,100)
p1 = a*x**2 + b*x + c

a = 1
b = -3
c = 2

p2 = a*x**2 + b*x + c

a = 4
b = -16.8
c = 17.6

p3 = a*x**2 + b*x + c


plt.plot(x,p1)
plt.plot(x,p2)
plt.plot(x,p3)

a = 1.
b = 20

e1 = 1.-(x/a)**2
domain = np.where(e1>0)
e1 = b*np.sqrt(e1[domain])

plt.plot(x[domain],e1)
plt.grid()
plt.show()
#
# For some reason i need here the p1 coefficents...
