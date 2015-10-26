from mymodule import *

class Parabola(Function):
    def __init__(self, a, b, c):
        Function.__init__(self, 1, 1)
        self.a = a
        self.b = b
        self.c = c
        self.functype = 'Parabola'

    def evaluate(self, x):
        self.domain = x
        self.codomain = self.a * x**2 + self.b * x + self.c


class Ellipse(Function):
    def __init__(self, a, b):
        Function.__init__(self, 1, 1)
        self.a = a
        self.b = b
        self.functype = 'Ellipse'

    def evaluate(self, x):
        el = 1. - ( x / self.a )**2
        mask = np.where(el > 0.)
        self.domain = x[mask]
        self.codomain = self.b * np.sqrt(el[mask])
