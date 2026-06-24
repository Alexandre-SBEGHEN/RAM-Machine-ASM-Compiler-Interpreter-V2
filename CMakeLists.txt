cmake_minimum_required(VERSION 4.2)
project(RAM_Machine_ASM_Compiler_Interpreter_V2 C)

set(CMAKE_C_STANDARD 11)

add_executable(RAM_Machine_ASM_Compiler_Interpreter_V2 src/main.c)
target_include_directories(RAM_Machine_ASM_Compiler_Interpreter_V2 PRIVATE include/)

add_compile_definitions(ROOT_DIR="${CMAKE_SOURCE_DIR}")