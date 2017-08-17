# Description
A library for very large integer arithmetics. 

# How to use?
include the `bigint.hpp` in your cpp file and see the examples below:

## Example
```
#include "bigint.hpp"

// Initialization
bigint a = "123123123123123123123";
bigint b("123123");
bigint d = "-9999";

// Operations
++a;
bigint c = a + b;
c = a - b;
cout << c * "123456789";
if(b > "200") cout << "greater than 200";
```
