# Question 2

This is a C++ program that prints each number from 1 to 100 on a new line.

For each multiple of 3, print "Foo" instead of the number.
For each multiple of 5, print "Baa" instead of the number.
For multiple numbers simultaneously of 3 and 5, print "FooBaa", instead of the number.

# Code Comments

The code implements a static function called "printer" that prints "Foo", "Baa", "FooBaa" or a number according to the problem description.
The main function uses the printer function with values from 1 to 100.

# Building


To code can be built with CMake. To do that, run the following commands:

```
mkdir build && cd build
cmake ..
make
./q2_siemens
```

The code can also be tested on https://www.onlinegdb.com/
