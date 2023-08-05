class Fort:
    def __init__(self, lst = []):
        self.lst = lst

    def APPEND(self, elem):
        try:
            int(elem)
            self.lst.append(int(elem))
            return True
        except ValueError:
            return False
    
    def DROP(self):
        if len(self.lst) == 0:
            return False
        else:
            self.lst.pop()
            return True
        
    def SWAP(self):
        if len(self.lst) < 2:
            return False
        else:
            tmp = self.lst[-1]
            self.lst[-1] = self.lst[-2]
            self.lst[-2] = tmp
            return True
    def DUP(self):
        if len(self.lst) == 0:
            return False
        else:
            self.lst.append(self.lst[-1])
            return True
        
    def OVER(self):
        if len(self.lst) < 2:
            return False
        else:
            self.lst.append(self.lst[-2])
            return True
        
    def plus(self):
        if len(self.lst) < 2:
            return False
        else:
            self.lst[-2] += self.lst[-1]
            self.lst.pop()
            return True  
        
    def minus(self):
        if len(self.lst) < 2:
            return False
        else:
            self.lst[-2] -= self.lst[-1]
            self.lst.pop()
            return True  
        
    def mult(self):
        if len(self.lst) < 2:
            return False
        else:
            self.lst[-2] *= self.lst[-1]
            self.lst.pop()
            return True  
        
    def div(self):
        if len(self.lst) < 2:
            return False
        else:
            if self.lst[-1] == 0:
                return False
            else:
                self.lst[-2] //= self.lst[-1]
                self.lst.pop()
                return True  
        
    def __del__(self):
        if(len(self.lst) == 0):
            print('EMPTY', file=fout)
        else:
            print(*self.lst, file=fout)

a = Fort()

with open('input.txt', 'r') as fin:
    for line in fin:
        
        state = False
            
        s = line.split()
        s = ''.join(s)
        
        if(s == 'DROP'):
            state = a.DROP()
        elif(s == 'SWAP'):
            state = a.SWAP()
        elif(s == 'DUP'):
            state = a.DUP()
        elif(s == 'OVER'):
            state = a.OVER()
        elif(s == '+'):
            state = a.plus()
        elif(s == '-'):
            state = a.minus()
        elif(s == '*'):
            state = a.mult()
        elif(s == '/'):
            state = a.div()
        else:
            state = a.APPEND(s)
            
        if(state == False):
            break
            
with open('output.txt', 'w') as fout:
    if(state):
        del a
    else:
        fout.write('ERROR')