"""Module: to understand two dimension Numpy"""

import numpy as np

# the number of lists the list contains does not have to do
# with the dimension but the shape of the list
a = [[11, 12, 13], [21, 22, 23], [31, 32, 33]]
A = np.array(a)

print("A", A)
print("A.ndim", A.ndim)
print("A.shape", A.shape)
print("A.size", A.size)

print("A[0:2, 2]", A[0:2, 2])

# adding matrix
x = [[1, 2], [3, 4]]
y = [[5, 6], [7, 8]]
add_z = np.array(x) + np.array(y)

# hadamard product
mul_z = np.array(x) * np.array(y)
scalar_z = 2 * np.array(x)
print("add_z", add_z)
print("mul_z", mul_z)
print("scalar_z", scalar_z)

# matrix multiplication

A = [[0, 1, 1], [1, 0, 1]]
B = [[1, 1], [1, 1], [-1, 1]]
C = np.dot(np.array(A), np.array(B))

print("C.shape", C.shape)
print("Dot C:\n", C)
