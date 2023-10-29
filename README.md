# String-Tomfoolery

A silly little library that explores what fun stuff you could do with strings and operators in C++...

## What you can do with it

I mean did you never want to multiply strings? This library is *exactly* this concept but taken a bit further!  
We have multiplication and division in various variations!

Now you can do all of this:

```cpp
#include "stomfoolery.hpp"

// To allow the nifty `"foobar"s` syntax that creates `std::string` objects in place
using namespace std::string_literals;

"Hello World! "s * 3; // -> "Hello World! Hello World! Hello World! "s
"Hello World! Hello World! Hello World! "s / 3; // -> std::vector<std::string>{"Hello World! "s, "Hello World! "s, "Hello World! "s}

std::vector<std::string>{"Hello World!"s, "Hello Bjarne!"s} * " "s; // -> "Hello World! Hello Bjarne!"s
"Hello World! Hello Bjarne!"s / " "s; // -> std::vector<std::string>{"Hello World!"s, "Hello Bjarne!"s}
"Hello World! \tHello Bjarne!"s / std::regex{R"(\s+)"}; // -> std::vector<std::string>{"Hello World!"s, "Hello Bjarne!"s}
```

This is really just playing around, and honestly you shouldn't be using this in production code. The idea behind is more
seeing what you can do with the language.  
The only really usable part for something like production code are the named alternatives. If you only want to use them,
set the preprocessor flag `STOMFOOLERY_DISABLE_OPERATORS`, which does in fact disable the operators.

## Using this lib

This is a CMake library, and you can use it as you would any other CMake library. See Instructions further down on how
to use it without CMake too.

### CMake

You can use the `FetchContent` module to let CMake download the lib for you:

```cmake
# Download stomfoolery
include(FetchContent)
FetchContent_Declare(
        stomfoolery
        GIT_REPOSITORY https://github.com/BrainStone/String-Tomfoolery.git
        GIT_TAG v1.0.0
)

FetchContent_MakeAvailable(stomfoolery)

# Use stomfoolery
project(${PROJECT_NAME} CXX)
target_link_libraries(${PROJECT_NAME} PRIVATE stomfoolery)
```

### Without CMake

Essentially you have two options:

- Add `$stomfoolery_base_path/src` to your include paths.
- Copy `src/stomfoolery.{hpp,inc}` into an already in use include path.

## Building

First of all there's no actual library to build. The only thing that can be build and executed are the test.  
Now this is a CMake project, so just follow standard build procedure:

```bash
# Build
cmake -B build
cmake --build build

# Run tests
cd build
ctest
```
