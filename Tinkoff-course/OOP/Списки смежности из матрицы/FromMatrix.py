class Vert:
    def __init__(self, name, vert=[]):
        self.name = name
        self.vert = vert

    def add(self, i):
        self.vert.append(i)
    
    def name(self):
        return self.name
    
    def read(self, s):
        lst = s.split()
        for i in range(len(lst)):
            if int(lst[i]) == 1:
                self.vert.append(i+1)
    
    def write(self):
        if len(self.vert) == 0:
            print(0, file=fout)
        else:
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
        a.read(line)
        arr.append(a)
        
            
with open('output.txt', 'w') as fout:
    for i in range(N):
        arr.el(i).write()