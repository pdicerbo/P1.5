import numpy as np
import matplotlib.pyplot as plt
from myfunc import *

p1 = Parabola(1, 3, 2)
p2 = Parabola(1, -3, 2)
p3 = Parabola(4, -16.8, 17.6)

x = np.linspace(0,3,100)

p1.evaluate(x)
p1.plot()
# p2.evaluate(x)
# p2.plot()
# p3.evaluate(x)
# p3.plot()

e = Ellipse(1, 2)
e.evaluate(x)
e.plot()

g = lambda z : np.sin(z)

x = np.linspace(0, 8, 100)

my_f = Function(1, 1)
my_f.evaluate(g, x)
my_f.plot()

par = lambda x, y: 5.*(x - 2)**2 + 3.5*(y - 2)**2 + 2. * x - 3. * y - x * y - 2.

three = Function(2, 1)
three.evaluate(par, x)
three.functype = "Paraboloid"
three.plot()

osc = lambda x, y: np.sin(x + y)

y = np.linspace(0, 10, 500)
new_f = Function(2, 1)
new_f.evaluate(osc, x, y)
new_f.functype = "3D Sin"
new_f.plot()

# For some reason i need here the p1 coefficents...
