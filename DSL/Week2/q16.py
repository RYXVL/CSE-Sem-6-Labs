import numpy as np
import pandas as pd

data = {'Name':['Kavitha', 'Sudha', 'Raju', 'Vignesh'],'Height':[28, 34, 29, 42], 'Qualification': ['B.Tech', 'MBA', 'MBBS', 'BE']}
df = pd.DataFrame(data)
print(df)
print('\n')
address = ['abc', 'def', 'ghi', 'jkl']
df.insert(3, 'Address', address)
# ['Adress'] = address
print(df)