import numpy as np

arr1 = np.array([[1, 2],
                 [3, 4]])

arr2 = np.array([[4, 3],
                 [2, 1]])

print(arr1+arr2)

# for i in range(arr1.shape[0]):
#     for j in range(arr1.shape[1]):
#         arr1[i][j] += arr2[i][j]

# print(arr1)