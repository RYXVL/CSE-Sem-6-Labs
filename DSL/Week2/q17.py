import numpy as np
import pandas as pd

# data = {'Name':['Kavitha', 'Sudha', 'Raju', 'Vignesh'],'Height':[28, 34, 29, 42], 'Qualification': ['B.Tech', 'MBA', 'MBBS', 'BE']}
# df = pd.DataFrame(data)
# print(df)
# print('\n')
# address = ['abc', 'def', 'ghi', 'jkl']
# df.insert(3, 'Address', address)
# ['Adress'] = address
# print(df)

data1 = {'Name': ['Ram', 'Diya', 'Chandan', 'James', 'Alice']}
data2 = {'Maths': [80.0, 90.0, 77.5, 87.5, 86.5],
         'Physics': [81.0, 94.0, 74.5, 83.5, 82.5],
         'Chemistry': [91.5, 86.5, 85.5, 90.0, 91.0],
         'Biology': [82.5, 83.5, 84.5, 85.0, 93.0]}

df1 = pd.DataFrame(data1)
df2 = pd.DataFrame(data2)
print(df1)
print('\n')
print(df2)
print('\n')
newdf = pd.concat([df1, df2], axis=1)
print(newdf)
total = newdf['Maths'] + newdf['Physics'] + newdf['Chemistry'] + newdf['Biology']
# print(total)
print('\n')

newdf.insert(5, 'Total', total)
print(newdf)