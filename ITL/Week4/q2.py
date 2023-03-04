class Pair:
    result = []
    def __init__(self, inplst):
        self.lst = inplst
    def find(self, target):
        for i in range(len(self.lst)-1):
            for j in range(len(self.lst)):
                if self.lst[i]+self.lst[j] == target:
                    self.result.append(i)
                    self.result.append(j)
                    break
            if len(self.result) == 2:
                break
        return self.result



inplst = [ int(x) for x in input('Enter distinct elements of list : ').split() ]
target = int(input('Enter the target number: '))
print(Pair(inplst).find(target))
