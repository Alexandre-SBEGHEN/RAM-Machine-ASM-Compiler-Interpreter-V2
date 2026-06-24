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

Reg* register_delete(Reg** reg) {
    if (reg == NULL || *reg == NULL)
        return NULL;

    free(*reg);

    // Sauvegarder l'adresse de reg puis mettre à NULL
    Reg* addr = *reg;
    (*reg) = NULL;

    return addr;
}

Mem* memory_create() {
    return NULL;
}

Mem* memory_delete(Mem** mem) {

}