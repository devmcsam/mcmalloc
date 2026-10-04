# mcmalloc

- - -

## Description

Mcmalloc is a modern allocator built in C23.

---

## Portability

Mcmalloc requires the following:

- A C23 compatible version of GCC or Clang, no MSVC (yet).
- A POSIX compatible operating system (no windows yet).

---

## Goals

The main goals of Mcmalloc are to be performant and readable. A goal once the initial allocator is completed is to
have Windows and MSVC support.

---

## License

mcmalloc is licensed under the MIT license, for more info see [LICENSE](LICENSE)