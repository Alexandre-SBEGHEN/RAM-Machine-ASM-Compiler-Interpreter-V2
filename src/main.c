/**
 * @file main.c
 * @brief Point d'entrée du programme
 * @author Alexandre SBEGHEN
 * @date 2026-06-24
 */

#include <stdio.h>
#include "machine.h"
#include "interpreter.h"

int main(void) {
    Program* prog = file_bin_to_program(PROJECT_ROOT "/tests/testdata/test_a_equals_abs_of_a.bin");

    if (prog == NULL)
        printf("erreur\n");
    else
        printf("reussi\n");



    program_delete(&prog);
    return 0;
}