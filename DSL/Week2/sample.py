import numpy as np
import pandas as pd

# s = pd.Series([1, 2, 3, 4, 5])
# s.sum()
# print(s.sum())

# data = [['Dinesh', 10], ['Nithya', 12], ['Raji', 13]]
# df = pd.DataFrame(data, index = ['a', 'b', 'c'], columns=['Name', 'Age'])
# print(df)

# data = {'Name':['Kavitha', 'Sudha', 'Raju', 'Vignesh'],'Age':[28, 34, 29, 42]}
# df = pd.DataFrame(data, index=['rank1', 'rank2', 'rank3', 'rank3'])
# print(df)

# df = pd.DataFrame({'A':pd.Timestamp('20230209'), 'B':np.array([3]*4, dtype='int32'), 'C':pd.Categorical(['Male', 'Female', 'Male', 'Female'])})
# print(df)
# print(df.dtypes)
# print(df.T)

# dates = pd.date_range('20230209', periods=100)
# print(dates)

# df = pd.DataFrame(np.random.randn(100, 4))
# print(df)
# axis tells along what to sort the data, 0 = index, 1 = columns
# print(df.sort_index(axis=1, ascending=False))

# print(df.sort_values(by=0))
# [col][row]
# print(df[0][1])
# print(df[[0, 1]][:5])