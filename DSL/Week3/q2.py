import numpy as np

matrix = np.array([[1, 2, 3],
          [4, 5, 6],
          [7, 8, 9]])

print('Col sum:-')
print(matrix.sum(axis=0))

print('Row sum:-')
print(matrix.sum(axis=1))