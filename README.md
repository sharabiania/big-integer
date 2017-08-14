# Description
A library for very large integer arithmetics. 

# Example
```
#include "bigint.hpp"

bigint a = "123123123123123123123";
bigint b("123123");
bigint d = "-9999";

++a;
bigint c = a + b;
c = a - b;
```
