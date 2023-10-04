# String-Tomfoolery

A silly little library that explores what fun stuff you could do with strings and operators in C++...

I mean did you never want to multiply strings? This library is *exactly* this concept but taken a bit further!  
We have multiplication and division in various variations!

Now you can do all of this:

```cpp
#include "stomfoolery.hpp"

// To allow the nifty `"foobar"s` syntax that creates `std::string` objects in place
using namespace std::string_literals;

"Hello World! "s * 3; // -> "Hello World! Hello World! Hello World! "s
"Hello World! Hello World! Hello World! "s / 3; // -> "Hello World! "s

std::vector<std::string>{"Hello World!"s, "Hello Bjarne!"s} * " "s; // -> "Hello World! Hello Bjarne!"s
"Hello World! Hello Bjarne!"s / " "s; // -> std::vector<std::string> "Hello World!"s, "Hello Bjarne!"s}
```
