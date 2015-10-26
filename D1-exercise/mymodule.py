import numpy as np
import matplotlib.pyplot as plt

class Function():
    def __init__(self):
        self.dim_domain = 1
        self.dim_codomain = 1
        self.domain = np.array([])
        self.codomain = np.array([])
        self.functype = "Not Specified"
        return

    def evaluate(self):
        raise NotImplementedError()

    def plot(self):
        if(self.dim_domain == 1 and self.dim_codomain == 1):
            plt.plot(self.domain, self.codomain)
            plt.title(self.functype)
            plt.show()

