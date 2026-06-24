/**
 * @file machine.c
 * @brief Implémentation de la machine RAM et ses opérations.
 * @author Alexandre SBEGHEN
 * @date 2026-06-24
 */

#include <stdlib.h>
#include "machine.h"

Reg* register_create() {
    Reg* reg;

    // Allocation, return NULL si échec
    if ((reg = malloc(sizeof(Reg))) == NULL)
        return NULL;

    // Valeur 0 par défaut
    reg->val = 0;

    return reg;
}

void register_delete(Reg** reg) {
    if (reg == NULL || *reg == NULL)
        return;

    free(*reg);
    (*reg) = NULL;
}

Mem* memory_create() {
    return NULL;
}

void memory_delete(Mem** mem) {

}