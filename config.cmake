# Project metadata
set(PROJECT_NAME "p101_c")
set(PROJECT_VERSION "0.0.1")
set(PROJECT_DESCRIPTION "Standard C library wrapper")
set(PROJECT_LANGUAGE "C")

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

# Common compiler flags
set(STANDARD_FLAGS
        -D_POSIX_C_SOURCE=200809L
        -D_XOPEN_SOURCE=700
#        -D_GNU_SOURCE
        -D_DARWIN_C_SOURCE
        -D__BSD_VISIBLE
        -Werror
)

# Define library targets
set(LIBRARY_TARGETS p101_c)

# Source files for the library
set(p101_c_SOURCES
        src/complex.c
        src/ctype.c
        src/fenv.c
        src/inttypes.c
        src/locale.c
        src/math.c
        src/setjmp.c
        src/signal.c
        src/stdio.c
        src/stdlib.c
        src/string.c
        src/time.c
        src/wchar.c
        src/wctype.c
)

# Header files for installation
set(p101_c_HEADERS
        include/p101_c/p101_complex.h
        include/p101_c/p101_ctype.h
        include/p101_c/p101_fenv.h
        include/p101_c/p101_inttypes.h
        include/p101_c/p101_locale.h
        include/p101_c/p101_math.h
        include/p101_c/p101_setjmp.h
        include/p101_c/p101_signal.h
        include/p101_c/p101_stdio.h
        include/p101_c/p101_stdlib.h
        include/p101_c/p101_string.h
        include/p101_c/p101_time.h
        include/p101_c/p101_wchar.h
        include/p101_c/p101_wctype.h
)

# Linked libraries required for this project
set(p101_c_LINK_LIBRARIES
        p101_error
        p101_env
        m
)
