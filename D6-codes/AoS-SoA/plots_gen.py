import numpy as np
import matplotlib.pyplot as plt

AoS = 'data_AoS'
SoA = 'data_SoA'

m1 = np.loadtxt(AoS)
m2 = np.loadtxt(SoA)

pt1   = m1[:,0]
iter1 = m1[:,1]
t1    = m1[:,2]

pt2   = m2[:,0]
iter2 = m2[:,1]
t2    = m2[:,2]

diff = abs(t1 - t2) * 2. / (t1 + t2)

pts = np.array([2e5, 5e5, 1e6, 2e6])

for n_point in pts:
    mask = np.where(pt1 == n_point)
    p1  = pt1[mask]; p2 = pt2[mask]
    it1 = iter1[mask]; it2 = iter2[mask]
    t_1 = t1[mask]; t_2 = t2[mask]
    
    plt.figure()
    plt.plot(it1, t_1, label = 'AoS')
    plt.plot(it2, t_2, label = 'SoA')

    plt.xscale('log')
    plt.xlabel('N_Iter')
    plt.ylabel('Used time (s)')
    plt.title('Number of points = %d' % n_point)
    plt.legend( bbox_to_anchor=(.215, 1))
    namef = 'AoS_vs_Soa_NPt%d.png' % n_point
    plt.savefig(namef)
    
