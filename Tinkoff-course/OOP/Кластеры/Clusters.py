class Cluster:
    lst = []
    
    def __init__(self, a):
        self.lst = a

    def stdprint(self):
        print(*self.lst)

    def fileprint(self, filename):
        print(*self.lst, file=filename)
        
class Storage:
    def __init__(self, a):
        self.lst = a

    def std_len(self):
        print(len(self.lst))

    def file_len(self, filename):
        print(len(self.lst), file=filename)
        
    def el(self, i):
        return self.lst[i]
    
    def length(self):
        return len(self.lst)
    
    def append(self, a):
        self.lst.append(a)
    
x = []
lst = []

with open('input.txt', 'r') as fin:
    a = fin.readline().split()
    x = fin.readline().split() 

N = int(a[0])
L = int(a[1][:len(a[1])])

lst = list([int(item) for item in x])
lst.sort()

with open('output.txt', 'w') as fout:
    if N == 1:
        clusters = Storage([Cluster(lst)])
        clusters.file_len(fout)
        clusters.el(0).fileprint(fout)
    else:
        clusters = Storage([])
        j = 0
        
        for i in range(1, N):
            if abs(lst[i] - lst[i-1]) > L:
                clusters.append(Cluster(lst[j:i]))
                j = i
        clusters.append(Cluster(lst[j:N]))
        
        clusters.file_len(fout)
       
        for i in range((clusters.length())):
            clusters.el(i).fileprint(fout)