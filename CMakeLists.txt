cmake_minimum_required(VERSION 3.13.4)
project(cprogramming)
include_directories(include)
file(GLOB_RECURSE INCLUDE_FILES ${CMAKE_SOURCE_DIR}/include/*.h)
file(GLOB_RECURSE SOURCE_FILES_NO_MAIN ${CMAKE_SOURCE_DIR}/src/*.c)
list(REMOVE_ITEM SOURCE_FILES_NO_MAIN ${CMAKE_SOURCE_DIR}/src/main.c)
set(SOURCE_FILES ${SOURCE_FILES_NO_MAIN} ${CMAKE_SOURCE_DIR}/src/main.c)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fno-common -fno-omit-frame-pointer \
-fstrict-aliasing \
-ggdb3 \
-O0 \
-pedantic \
-std=c17 \
-Wall \
-Wbad-function-cast \
-Wcast-align -Wcast-qual \
-Werror \
-Wextra \
-Wfloat-equal \
-Wformat=2 \
-Winit-self \
-Winline \
-Wmissing-prototypes \
-Wnested-externs \
-Wno-missing-braces -Wno-missing-field-initializers \
-Wmissing-declarations -Wmissing-include-dirs -Wmissing-prototypes \
-Wold-style-definition \
-Wpointer-arith \
-Wredundant-decls \
-Wshadow \
-Wstrict-aliasing=2 -Wstrict-overflow=5 -Wstrict-prototypes \
-Wswitch-default -Wswitch-enum \
-Wundef \
-Wunreachable-code \
-Wno-unused-parameter \
-Wuninitialized \
-Wwrite-strings")
include(${CMAKE_SOURCE_DIR}/cmake/clang_tools.cmake)
add_executable(${PROJECT_NAME} ${INCLUDE_FILES} ${SOURCE_FILES_NO_MAIN} ${SOURCE_FILES})
