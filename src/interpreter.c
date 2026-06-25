/**
 * @file interpreter.c
 * @brief Implémentation de l'interpréteur.
 * @author Alexandre SBEGHEN
 * @date 2026-06-25
 */

#include "interpreter.h"
#include <stdlib.h>

/* Création dynamique d'une structure registre Register */
Program* program_create(size_t size) {
    Program* prog;

    if ((prog = malloc(sizeof(Program))) == NULL)
        return NULL;

    prog->size = size;

    if ((prog->inst = malloc(size * sizeof(Instruction))) == NULL) {
        free(prog);
        return NULL;
    }

    return prog;
}

/* Libération de mémoire d'une structure Program */
void program_delete(Program** prog) {
    if (prog == NULL || *prog == NULL)
        return;

    free((*prog)->inst);
    free(*prog);
    *prog = NULL;
}