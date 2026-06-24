cmake_minimum_required(VERSION 4.2)
project(RAM_Machine_ASM_Compiler_Interpreter_V2 C)

set(CMAKE_C_STANDARD 11)

# Exécutable principal
add_executable(RAM_Machine_ASM_Compiler_Interpreter_V2
        src/main.c
        src/machine.c
)
target_include_directories(RAM_Machine_ASM_Compiler_Interpreter_V2 PRIVATE include/)

# Tests
enable_testing()

add_executable(test_blank tests/test_blank.c)
target_include_directories(test_blank PRIVATE include/)
add_test(NAME test_blank COMMAND test_blank)

add_executable(test_machine src/machine.c tests/test_machine.c)
target_include_directories(test_machine PRIVATE include/)
add_test(NAME test_machine COMMAND test_machine)

# Variables
add_compile_definitions(ROOT_DIR="${CMAKE_SOURCE_DIR}")