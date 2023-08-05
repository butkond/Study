class Vert:
    def __init__(self, name, vert=[]):
        self.name = name
        self.vert = vert

    def add(self, i):
        self.vert.append(i)
    
    def name(self):
        return self.name
    
    def read(self, s, N):
        lst = s.split()
        ss = set(lst)
        for i in range(N):
            if str(i+1) in ss:
                self.vert.append(1)
            else:
                self.vert.append(0)
    
    def write(self):
        print(*self.vert, file=fout)
        
class Storage:
    def __init__(self, lst=[]):
        self.lst = lst
        
    def el(self, i):
        return self.lst[i]
    
    def length(self):
        return len(self.lst)
    
    def append(self, a):
        self.lst.append(a)

        
arr = Storage()

with open('input.txt', 'r') as fin:
    N = int(fin.readline().split()[0])
    for i in range(N):
        line = fin.readline()
        a = Vert(i+1, [])
        a.read(line, N)
        arr.append(a)
        
            
with open('output.txt', 'w') as fout:
    for i in range(N):
        arr.el(i).write()