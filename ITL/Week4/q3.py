class Power:
    def __init__(self, nm, pw):
        self.num = nm
        self.pow = pw
    def calculate(self):
        result = 1
        while self.pow > 0:
            result *= self.num
            self.pow = self.pow - 1
        return result

nm = int(input('Enter number: '))
pw = int(input('Enter power: '))
print(Power(nm, pw).calculate())
