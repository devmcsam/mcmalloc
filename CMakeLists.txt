cmake_minimum_required(VERSION 3.21...4.4)

project(mcmalloc
        VERSION 0.1.0
        LANGUAGES C
)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if (NOT CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")
    message(FATAL_ERROR
            "mcmalloc requires GCC or Clang; found '${CMAKE_C_COMPILER_ID}'"
    )
endif ()

add_library(${PROJECT_NAME} STATIC
        src/mcmalloc.c
        src/internal/data.h
        src/internal/free.h
        src/internal/block.h
        src/internal/defs.h
)

target_include_directories(${PROJECT_NAME}
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
        PRIVATE
        src/internal
)

set_target_properties(${PROJECT_NAME} PROPERTIES
        C_STANDARD 23
        C_STANDARD_REQUIRED ON
        C_EXTENSIONS OFF
)

find_program(CCACHE_PROGRAM ccache)

if (CCACHE_PROGRAM)
    set_property(TARGET ${PROJECT_NAME} PROPERTY
            C_COMPILER_LAUNCHER "${CCACHE_PROGRAM}"
    )
endif ()

set(COMMON_WARNINGS
        -Wall
        -Wextra
        -Wpedantic
        -Wshadow
        -Wcast-align
        -Wconversion
        -Wsign-conversion
        -Wfloat-equal
        -Wpointer-arith
        -Wundef
        -Wformat=2
)

target_compile_options(${PROJECT_NAME}
        PRIVATE
        ${COMMON_WARNINGS}
)

set(RELEASE_CFLAGS
        -O3
        -fno-strict-aliasing
        -fno-unsafe-math-optimizations
        -fno-math-errno
)

target_compile_options(${PROJECT_NAME}
        PRIVATE
        $<$<CONFIG:Release>:${RELEASE_CFLAGS}>
)

set(DEBUG_CFLAGS
        -Og
        -g
        -fno-omit-frame-pointer
        -fno-optimize-sibling-calls
)

set(DEBUG_SANITIZERS
        -fsanitize=address,undefined,leak
)

target_compile_options(${PROJECT_NAME}
        PRIVATE
        $<$<CONFIG:Debug>:${DEBUG_CFLAGS}>
        $<$<CONFIG:Debug>:${DEBUG_SANITIZERS}>
)

target_link_options(${PROJECT_NAME}
        PRIVATE
        $<$<CONFIG:Debug>:${DEBUG_SANITIZERS}>
)

set(RELWITHDEBINFO_CFLAGS
        -O2
        -g
        ${RELEASE_CFLAGS}
)

target_compile_options(${PROJECT_NAME}
        PRIVATE
        $<$<CONFIG:RelWithDebInfo>:${RELWITHDEBINFO_CFLAGS}>
)

include(CheckIPOSupported)

check_ipo_supported(
        RESULT ipo_supported
        OUTPUT ipo_error
        LANGUAGES C
)

if (ipo_supported)
    set_property(TARGET ${PROJECT_NAME} PROPERTY
            INTERPROCEDURAL_OPTIMIZATION_RELEASE TRUE
    )

    set_property(TARGET ${PROJECT_NAME} PROPERTY
            INTERPROCEDURAL_OPTIMIZATION_RELWITHDEBINFO TRUE
    )
else ()
    message(STATUS
            "IPO/LTO is not supported: ${ipo_error}"
    )
endif ()

target_compile_definitions(${PROJECT_NAME}
        PRIVATE
        $<$<CONFIG:Debug>:DEBUG>
)