import numpy as np

arrList = np.array([1.0, 2.0, 3.0])

arrTuple = np.array((1.0, 2.0, 3.0))

zeroes = np.zeros((3, 4))

sequence = np.arange(0, 20, 5)

arr = np.array([[1, 2, 3, 4],
                [5, 6, 7, 8],
                [9, 10, 11, 12]])

reshapedArr = arr.reshape(2, 2, 3)

print(reshapedArr)

print(f'Matrix max is: {arr.max()}')
print(f'Matrix min is: {arr.min()}')

for i in range(arr.shape[0]):
    print(f'Row {i+1} max is: {arr[i].max()}')
    print(f'Row {i+1} min is: {arr[i].min()}')

for i in range(arr.shape[1]):
    print(f'Col {i+1} max is: {arr.T[i].max()}')
    print(f'Col {i+1} min is: {arr.T[i].min()}')

print(f'Sum of all elements of the matrix is: {arr.sum()}')