# 42 Porto - C++ Modules

C++ programming modules from 42 Porto curriculum, covering fundamental to advanced concepts using C++98 standard.

## About

These modules introduce C++ programming through hands-on exercises, starting from basic object-oriented programming to advanced topics like templates and STL. All code follows C++98 standard.

## Modules

**CPP00** - Introduction to C++  
Basic syntax, classes, member functions, I/O streams, namespaces

**CPP01** - Memory Management  
Stack vs heap, pointers vs references, `new`/`delete`, memory allocation

**CPP02** - Orthodox Canonical Form  
Copy constructor, copy assignment operator, destructor, operator overloading

**CPP03** - Inheritance  
Base and derived classes, constructor chaining, protected members

**CPP04** - Polymorphism  
Virtual functions, abstract classes, interfaces, deep vs shallow copy

**CPP05** - Exceptions  
Try-catch-throw, custom exceptions, exception safety

**CPP06** - Type Conversion  
C++ casts (static_cast, dynamic_cast, reinterpret_cast, const_cast)

**CPP07** - Templates  
Function templates, class templates, generic programming

**CPP08** - STL Containers  
Vector, list, stack, deque, map, iterators, algorithms

**CPP09** - Advanced Containers  
STL algorithms, performance analysis, Ford-Johnson merge-insert sort

## Compilation

Each exercise can be compiled using the provided Makefile:

```bash
cd cpp0X/exXX
make
```

All code compiles with:
```bash
c++ -Wall -Wextra -Werror -std=c++98
```

## Requirements

- C++98 standard compliance
- No memory leaks
- Orthodox Canonical Form where applicable
- Proper use of const, references, and pointers

---

Part of 42 Porto Common Core curriculum (2024-2025)