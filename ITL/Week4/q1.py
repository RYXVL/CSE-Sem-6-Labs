class Subsets:
    resultList = []
    def __init__(self, inplst):
        self.lst = inplst
    def find(self, current, sset):
        if sset:
            return self.find(current, sset[1:]) + self.find(current + [sset[0]], sset[1:])
        return [current]

inplst = [ int(x) for x in input('Enter distinct elements of list : ').split() ]
print(Subsets(inplst).find([], sorted(inplst)))
