import numpy as np
import matplotlib.pyplot as plt
from myfunc import *

p1 = Parabola(1, 3, 2)
p2 = Parabola(1, -3, 2)
p3 = Parabola(4, -16.8, 17.6)

x = np.linspace(0,3,100)

p1.evaluate(x)
p1.plot()
p2.evaluate(x)
p2.plot()
p3.evaluate(x)
p3.plot()

e = Ellipse(1, 2)
e.evaluate(x)
e.plot()

# a = 1.
# b = 20

# e1 = 1.-(x/a)**2
# domain = np.where(e1>0)
# e1 = b*np.sqrt(e1[domain])

# plt.plot(x[domain],e1)
# plt.grid()
# plt.show()
#
# For some reason i need here the p1 coefficents...
