class GetPrintString:
    def getString(self):
        inpstr = input('Enter the string: ')
        self.str = inpstr
    def printString(self):
        print(self.str.upper())

gps = GetPrintString()
gps.getString()
gps.printString()
