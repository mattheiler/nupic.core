# nupic.core-redux
Nupic.Core C++ Extraction Redux.

### Setup (CMake)

path/to/repo/src  
path/to/repo/build

## Considerations

Add find_package?

* Will it be easy to integrate with vcpkg and apt-get?
* What about packages that aren't available via the package manager?

Flatten the file structure? 

* Should internal and external sources be separate?
* There should probably be a CMakeLists.txt in the root, regardless.

```
\nupic.core
  \nupic.core
  CMakeLists.txt
```

A project per existing subfolder?

* No redundant, matching filters.
* More modular.
* Many libraries.

```
\nupic.core
  \nupic.algorithms
    \bindings
      Foo.i
    \include
      Foo.hpp
    \src
      Foo.cpp
    \tests
    CMakeLists.txt
  \nupic.encoders
    \bindings
      Bar.i
    \include
      Bar.hpp
    \src
      Bar.cpp
      Qux.cpp
      Qux.hpp
    \tests
    CMakeLists.txt
  ...
  CMakeLists.txt
```
