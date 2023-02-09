import numpy as np
import pandas as pd

data = {'Name': ['Annie', 'Diya', 'Charles', 'James', 'Emily'],
        'Quiz_1/10': [8.0, 9.0, 7.5, 8.5, 6.5],
        'In-Sem_1/15': [11.0, 14.0, 14.5, 13.0, 12.5],
        'Quiz_2/10': [9.5, 6.5, 8.5, 9.0, 9.0],
        'In-Sem_2/15': [12.5, 13.5, 14.5, 15.0, 13.0]}

df = pd.DataFrame(data)
# print(df)
total = df['Quiz_1/10'] + df['In-Sem_1/15'] + df['Quiz_2/10'] + df['In-Sem_2/15']
df.insert(5, 'Total', total)
# .loc is used to access a particular row or a col
# df[row, col] returns that particular element
df.loc['mean'] = df.mean()
# above line creates a row with index 'mean' and puts the means
# of each col in them
print(df)