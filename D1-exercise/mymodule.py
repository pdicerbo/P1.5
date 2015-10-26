import numpy as np
import matplotlib.pyplot as plt

class Function():
    def __init__(self, d, c):
        self.dim_domain = d
        self.dim_codomain = c
        self.domain = np.array([])
        self.codomain = np.array([])
        self.functype = "Not Specified"

    def evaluate(self, func, x, y = None):
        if y is None:
            if(self.dim_domain == 1 and self.dim_codomain == 1):
                self.domain = x
                self.codomain = func(x)
            elif(self.dim_domain == 2 and self.dim_codomain == 1):
                x1, x2 = np.meshgrid(x, x)
                self.domain = np.meshgrid(x, x)
                self.codomain = func(x1, x2)
        else:
            self.domain = np.meshgrid(x, y)
            self.codomain = func(self.domain[0], self.domain[1])

    def plot(self):
        if(self.dim_domain == 1 and self.dim_codomain == 1):
            plt.plot(self.domain, self.codomain)
            plt.title(self.functype)
            plt.xlabel('x'); plt.ylabel('y')
            plt.show()
        elif(self.dim_domain == 2 and self.dim_codomain == 1):
            from mpl_toolkits.mplot3d import Axes3D
            fig = plt.figure()
            ax = fig.add_subplot(111, projection='3d')
            ax.plot_surface(self.domain[0], self.domain[1], self.codomain,  rstride=4, cstride=4, color='b')
            plt.title(self.functype)
            plt.xlabel('x'); plt.ylabel('y')
            plt.show()
        else:
            print("\n\tNothing to plot\n")
