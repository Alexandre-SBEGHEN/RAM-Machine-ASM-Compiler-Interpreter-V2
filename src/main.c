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
    const char* str = "Bonjour tout le monde !\nCeci est un paragraphe simple,\ntrès très simple...\nHihihi";
    char** array = string_to_array(str);

    char strtest_1[4][50] = {
        "Bonjour tout le monde !",
        "Ceci est un paragraphe simple,",
        "très très simple...",
        "Hihihi"
    };

    for (size_t i = 0; i < 4; ++i) {
        printf("%s\t\t%s\t\t%d\n", array[i], strtest_1[i], strcmp(array[i], strtest_1[i]));
    }



    return 0;
}