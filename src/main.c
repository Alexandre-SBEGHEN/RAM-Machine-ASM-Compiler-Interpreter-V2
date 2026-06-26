/**
 * @file main.c
 * @brief Point d'entrée du programme
 * @author Alexandre SBEGHEN
 * @date 2026-06-24
 */

#include <stdio.h>
#include <string.h>

#include "machine.h"
#include "compiler.h"
#include "interpreter.h"

int main(void) {
    char* str = "# commentaire";

    string_clean(str);

    printf("length : ");
    printf("%lu\n", strlen(str));
    printf("|%s|\n", str);



    return 0;
}