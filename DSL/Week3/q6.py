import numpy as np

arr1 = np.array([[1, 2],
                 [3, 4]])

arr2 = np.array([[1, 2],
                 [0, 1]])

res = np.dot(arr1, arr2)

print(res)