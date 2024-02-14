"""
Module: to understand one dimension Numpy

- library for scientific computing
- advantages in speed and memory
- numpy array or ND array is similar to list
- usually fixed in size and each element is of the same type
"""

import numpy as np
import matplotlib.pyplot as plt
import termplotlib as tpl

a = np.array([0, 1, 2, 3, 4])

print("a:", a)
print("type(a):", type(a))
print("a.dtype:", a.dtype)
print("a.size", a.size)

# no of dimension
print("a.ndim", a.ndim)
# tuple indicating size in each dimension
print("a.shape", a.shape)

a[3:5] = 300, 400
print(a)

# classic method (vector addition)
u = [1, 0]
v = [0, 1]
add_z = []

for n, m in zip(u, v):
    add_z.append(n + m)

print("classic: add_z", add_z)

# numpy method (vector addition)
u = np.array([1, 2])
v = np.array([2, 2])

add_z = u + v
sub_z = u - v
mul_z = u * v
dot_product_z = np.dot(u, v)
print("numpy add_z:", add_z)
print("numpy sub_z:", sub_z)
print("numpy mul_z:", mul_z)
print("numpy dot_product_z:", dot_product_z)

# classic method (scalar multiplication)
y = [1, 2]
z = []

for n in y:
    z.append(n * 2)

print("classic z:", z)

# numpy method (scalar multiplication)
y = np.array([1, 2])
z = 2 * y
print("numpy z:", z)

# numpy broadcasting (adding constant)
u = np.array([1, 2, 3, -1])
z = u + 1
print("broadcasting z", z)

# numpy universal functions

a = np.array([1, -1, 1, -1, 5])
mean_a = a.mean()
max_a = a.max()
print("mean_a", mean_a)
print("max_a", max_a)

x = np.array([0, np.pi / 2, np.pi])
y = np.sin(x)
print("y", y)

# numpy linspace, plotting mathematical functions is line space
# linspace returns evenly spaced numbers over specified interval

a = np.linspace(-2, 2, num=9)
print("a", a)  # 9 evenly spaced array

# plotting mathematical functions

print("ploting sin wave")

x = np.linspace(0, 2 * np.pi, 100)
y = np.sin(x)
fig = tpl.figure()
fig.plot(x, y)
fig.show()

# output = plt.plot(x, y)
# print(output)
