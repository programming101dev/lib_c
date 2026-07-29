# lib_c Repository Guide

`lib_c` is the standard C-library wrapper layer in the Programming 101
collection. It makes fallible calls report through `p101_error`, and makes
wrapper activity observable through `p101_env`.

## **Table of Contents**

1. [Cloning the Repository](#cloning-the-repository)
2. [Prerequisites](#prerequisites)
3. [Configuring the Build](#configuring-the-build)
4. [Building](#building)
5. [Testing](#testing)
6. [Wrapper contract](#wrapper-contract)
7. [Deliberate omissions and limits](#deliberate-omissions-and-limits)
8. [Installing](#installing)
9. [Adding or Removing Files](#adding-or-removing-files)

## **Cloning the Repository**

Clone the repository using the following command:

```bash
git clone https://github.com/programming101dev/lib_c.git
```

Navigate to the cloned directory:

```bash
cd lib_c
```

Ensure the scripts are executable:

```bash
chmod +x *.sh
```

## **Prerequisites**

To ensure you have all of the required tools installed, run:

```bash
./check-env.sh
```

If you are missing tools follow these [instructions](https://docs.google.com/document/d/1ZPqlPD1mie5iwJ2XAcNGz7WeA86dTLerFXs9sAuwCco/edit?usp=drive_link). If something still looks wrong, `./doctor.sh` reports what actually works on this machine for this project.

## **Configuring the Build**

Tell CMake which compiler you want to use:

```bash
./change-compiler.sh -c <compiler>
```

To see the list of possible compilers:

```bash
cat supported_c_compilers.txt
```

Run it again any time to switch compilers; each compiler configures into its own build directory (e.g. `build-clang`, `build-gcc-15`).

## **Building**

To build the library run:

```bash
./build.sh
```

This compiles through the strict analysis pipeline: the clang-format check, clang-tidy, cppcheck, the Clang static analyzer, and hundreds of warnings under `-Werror`. `./build.sh -f` applies the formatter and tidy fixes in place.

## **Testing**

`./check.sh` is the one command to run before you submit: the format check, the strict build, the tests, and a short fuzz smoke run, with a single PASS/FAIL at the end.

The unit suite checks wrapper error contracts, allocation and descriptor
events, fault injection, balanced enter/exit tracing, and C/C++ header
compatibility. The fuzz target compiles the wrappers with ASan and UBSan and
exercises numeric, allocation, formatting, multibyte, and ownership paths.

## **Wrapper contract**

- A fallible wrapper accepts `p101_error` and reports a real error code. A
  successful call does not manufacture an error from an ambiguous sentinel
  such as `0`, `EOF`, or `(time_t)-1`.
- Fault injection uses the underlying C function name (`malloc`, `fopen`,
  `strtol`, and so on). Every wrapper emits a matching exit event, including an
  injected or validated failure.
- `fopen`, `freopen`, `tmpfile`, and `fclose` emit descriptor lifecycle events.
  Allocators emit allocation lifecycle events.
- `p101_strerror` returns a newly allocated string on success. Release it with
  `p101_free`.
- `p101_malloc`, `p101_calloc`, and `p101_aligned_alloc` reject zero-sized
  allocations with `EINVAL`. `p101_realloc(ptr, 0)` also returns `NULL` with
  `EINVAL` and leaves `ptr` owned by the caller.
- Checked division and absolute-value wrappers report `EDOM` for a zero
  denominator and `ERANGE` for the otherwise undefined minimum-value cases.

## **Deliberate omissions and limits**

The library does not wrap APIs whose safer replacement should be taught
instead: `gets`, `sprintf`/`vsprintf`, `strcpy`, `strcat`, `strtok`,
`atoi`/`atol`, `rand`, `rewind`, and `setbuf`. Existing bounded functions such
as `strncpy` still have their standard C semantics; the `p101_` prefix does not
turn them into safer string-building APIs.

`setjmp` and `sigsetjmp` must be invoked directly because the jump-capture site
has to be in the stack frame that receives `longjmp`. Only `longjmp` has a
normal wrapper.

C complex declarations are intentionally hidden from C++ consumers because C
complex types do not have a portable C++ ABI. The long-double complex
hyperbolic/trigonometric subset and `<uchar.h>` conversion APIs are omitted
because they are not exposed consistently by all supported macOS, Linux, and
FreeBSD toolchains. The atomic API deliberately provides flags, fences, and a
complete `atomic_uint` operation set rather than pretending C's generic atomic
macros can be reproduced as ordinary functions for every atomic type.

These wrappers observe only calls routed through `p101_*`; direct libc calls,
third-party code, and libc internals remain outside the event stream.

## **Installing**

To install the library run:

```bash
./install.sh
```

You may need to run it via sudo, or give the user account access to the install directories. `./uninstall.sh` removes it again.

## **Adding or Removing Files**

The `CMakeLists.txt` is fixed and shared across every repository — do not edit it. When you add or remove a source or header, edit the lists in `config.cmake` (`p101_c_SOURCES`, `p101_c_HEADERS`, and `p101_c_LINK_LIBRARIES`), then re-configure and build:

```bash
./change-compiler.sh -c <compiler>
./build.sh
```
