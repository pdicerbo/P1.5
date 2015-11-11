import matplotlib.pyplot as plt
from MyTriang import *

T = Triangulation()

T.load_msh("anulus.msh")

TAcc = TriaAccessor(T)
TIt = TriaIterator(TAcc)

plt.figure()

print("\n\tstarting loop:")
for MyIt in TIt:
    X = np.append(TAcc.get_nodes_x(), TAcc.get_nodes_x()[0])
    Y = np.append(TAcc.get_nodes_y(), TAcc.get_nodes_y()[0])
    plt.plot(X, Y)

# plt.show()
plt.xlabel("x")
plt.ylabel("y")
plt.axes().set_aspect("equal")
plt.savefig("mesh_plot.png")
