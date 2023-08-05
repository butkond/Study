class Card:
    def __init__(self, s):
        self.name = s

    def write(self):
        fout.write(self.name+' ')
    
    def __eq__(self, other):
        if self.name == other.name:
            return True
        else:
            return False

class Pack:
    def __init__(self, lst = []):
        self.lst = lst

    def append(self, elem):
        self.lst.append(elem)
        return True

    def drop_up(self):
        if len(self.lst) == 0:
            return False
        else:
            self.lst.pop()
            return True
        
    def add(self, elem):
        l = len(self.lst)
            
        if l == 0:
            self.lst.append(elem)
        elif l == 1:
            tmp = self.lst[0]
            self.lst[0] = elem
            self.lst.append(tmp)
        else:
            tmp = self.lst[l-1]
            for i in range(l-1, 0, -1):
                self.lst[i] = self.lst[i - 1]
            self.lst[0] = elem
            self.lst.append(tmp)
        return True
    
    def drop_down(self):
        l = len(self.lst)
        if l == 0:
            return False
        elif l == 1:
            self.lst.pop()
            return True
        else:
            for i in range(l-1):
                self.lst[i] = self.lst[i + 1]
            self.lst.pop()
            return True
        
    def elem(self, i):
        if len(self.lst) == 0:
            return -1
        else:
            return self.lst[i]
        
    def length(self):
        return len(self.lst)
    
    def printf(self):
        if len(self.lst) == 0:
            fout.write('EMPTY')
        else:
            for i in range(len(self.lst)-1, -1, -1):
                self.lst[i].write()
        
pack = Pack()

with open('input.txt', 'r') as fin:
    for line in fin:
        
        state = False
            
        s = line.split()
        s = ''.join(s)

        if(s == '^'):
            state = pack.drop_up()
        elif(s == '/'):
            state = pack.drop_down()
        else:
            if(s[0] == '+'):
                if len(s) == 3:
                    if ((s[1:2] == 'C' or s[1:2] == 'S' or s[1:2] == 'H' or s[1:2] == 'D') and 
                        (s[2:] == 'A' or s[2:] == 'T' or s[2:] == 'J' or s[2:] == 'Q' or 
                          s[2:] == 'K' or s[2:] == '2' or s[2:] == '3' or s[2:] == '4' or 
                          s[2:] == '5' or s[2:] == '6' or s[2:] == '7' or s[2:] == '8' or s[2:] == '9')):
                        card = Card(s[1:])
                        l = pack.length()
                        k = 0
                        if l != 0:
                            for i in range(pack.length()):
                                if card == pack.elem(i):
                                    k = 1
                            if k == 1:
                                state = False
                            else:
                                pack.append(card)
                                state = True
                        else:
                            pack.append(card)
                            state = True                            
                    else:
                        state = False
                else:
                    state = False
            elif(s[0] == '#'):
                if len(s) == 3:
                    if ((s[1:2] == 'C' or s[1:2] == 'S' or s[1:2] == 'H' or s[1:2] == 'D') and 
                        (s[2:] == 'A' or s[2:] == 'T' or s[2:] == 'J' or s[2:] == 'Q' or 
                          s[2:] == 'K' or s[2:] == '2' or s[2:] == '3' or s[2:] == '4' or 
                          s[2:] == '5' or s[2:] == '6' or s[2:] == '7' or s[2:] == '8' or s[2:] == '9')):
                        card = Card(s[1:])
                        l = pack.length()
                        k = 0
                        if l != 0:
                            for i in range(pack.length()):
                                if card == pack.elem(i):
                                    k = 1
                            if k == 1:
                                state = False
                            else:
                                pack.add(card)
                                state = True
                        else:
                            pack.add(card)
                            state = True                            
                    else:
                        state = False
                else:
                    state = False
            else:
                state = False            
            
        if(state == False):
            break

with open('output.txt', 'w') as fout:
    if(state):
        pack.printf()
    else:
        fout.write('ERROR')