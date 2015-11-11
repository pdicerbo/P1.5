import numpy as np

class Triangulation:
    def __init__(self):
        self.topo = np.array([[]], dtype = int)
        self.x = np.array([])
        self.y = np.array([])
        return
    
    def load_msh(self, filename):
        f = open ( filename , 'r')
        
        for line in f:
            if line[0] != '$':
                
                l = np.array(line.split(), dtype = float)
                
                if len(l) == 4:
                    self.x = np.append(self.x,l[1])
                    self.y = np.append(self.y,l[2])
                    
                elif len(l) == 8:
                    row = l[5:8]
                    row = np.array(row, dtype=int)
                    self.topo = np.append(self.topo,row)

        self.topo = np.reshape(self.topo,(len(self.topo)/3,3))
        self.topo = self.topo-1
        r_id = 0

        for row in self.topo:
            ck =      (self.x[row[1]]-self.x[row[0]])*(self.y[row[2]]-self.y[row[0]])
            ck = ck - (self.x[row[2]]-self.x[row[0]])*(self.y[row[1]]-self.y[row[0]])
            if ck < 0:
                self.topo[r_id,:] = np.array([[row[0],row[2],row[1]]])
            r_id+=1
        
        print('---------------------')
        print('mesh: '+filename+', loaded.')
        print('# elems: '+str(self.topo.shape[0]))
        print('# nodes: '+str(self.x.shape[0]))
        print('---------------------')
        return

class TriaAccessor:
    def __init__(self, tria):
        self.current_element = 0
        self.tria = tria
        self.n_elems = tria.topo.shape[0]

    def get_nodes_id(self):
        return self.tria.topo[self.current_element]

    def get_nodes_x(self):
        return self.tria.x[self.tria.topo[self.current_element]]

    def get_nodes_y(self):
        return self.tria.y[self.tria.topo[self.current_element]]


class TriaIterator:
    def __init__(self, tria_acc):
        self.tria_acc = tria_acc
        self.i = tria_acc.current_element
        self.n = tria_acc.n_elems

    def __iter__(self):
        # if self.i == 0:
        #     print("\n\tIn __iter__()")
        return self

    def __next__(self):
        # if self.i == 0:
        #     print("\n\tIn __next__()")
        if self.i < self.n:
            i = self.i
            self.tria_acc.current_element = i
            self.i += 1
            return i
        else:
            raise StopIteration()
