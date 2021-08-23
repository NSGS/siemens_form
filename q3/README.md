# Question 3

This C++ program that performs two types of operations on this string:
1. Concat a lowercase character from the Portuguese alphabet at the end of the string.
2. Remove the last character from the string. If the string is empty, it will remain empty.

Given an integer k and two strings s and t, if you can convert s to t using exactly k operations described above on s the program prints 'yes', otherwise it prints 'no'.

# Code Comments

The ConcatRemove function is implemented calculating the number of minimum moves necessary to convert s to t. After that, some analysis indicates if s can be converted to t using exactly k moves. There are 3 situtations where the function returns true:

1.If k is equal to the minimum moves moves necessary, the conversion is possible.

2.If k is equal to or greater than s and t size together, the conversion is possible (remove all characters from s and add all from t).

3.If k minus the minimum moves is even, the conversion is possible. Example:

```
S= Tab, T=Tab, K=3

1: S=Ta
2: S=T
3: S=Ta

Conversion is not possible.
```

The user can test the code by typing string s,t and the value of k directly from the terminal.

# Building

To code can be built with CMake. To do that, run the following commands:

```
mkdir build && cd build
cmake ..
make
./q3_siemens
```

The code can also be tested on https://www.onlinegdb.com/
