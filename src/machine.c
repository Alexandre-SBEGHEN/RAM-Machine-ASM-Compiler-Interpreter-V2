/**
 * @file machine.c
 * @brief Implémentation de la machine RAM et ses opérations.
 * @author Alexandre SBEGHEN
 * @date 2026-06-24
 */

#include "machine.h"
#include <stdlib.h>

/* Création dynamique d'une structure registre Register */
Register* register_create() {
    Register* reg;

    // Allocation, return NULL si échec
    if ((reg = malloc(sizeof(Register))) == NULL)
        return NULL;

    // Valeur 0 par défaut
    reg->val = 0;

    return reg;
}

/* Libération de mémoire d'une structure Register */
void register_delete(Register** reg) {
    if (reg == NULL || *reg == NULL)
        return;

    free(*reg);
    (*reg) = NULL;
}

/* Création dynamique d'une structure mémoire Memory */
Memory* memory_create(const size_t size) {
    Memory* mem;

    // Allocation, return NULL si échec
    if ((mem = malloc(sizeof(Memory))) == NULL)
        return NULL;

    mem->size = size;

    // Allocation des données, echec -> free reg puis return NULL
    if ((mem->data = calloc(size, sizeof(int32_t))) == NULL) {
        free(mem);
        return NULL;
    }

    return mem;
}

/* Libération de mémoire d'une structure Memory */
void memory_delete(Memory** mem) {
    if (mem == NULL || *mem == NULL)
        return;

    free(*mem);
    (*mem) = NULL;
}

/* Chargement direct du registre */
void ram_load_direct(Register* reg, const int32_t val) {
    if (reg != NULL)
        reg->val = val;
}

/* Chargement du registre depuis la mémoire */
void ram_load_from(Register* reg, const Memory* mem, const size_t index) {
    if (reg != NULL && mem != NULL)
        reg->val = mem->data[index];
}

/* Rangement du registre vers la mémoire */
void ram_store_to(const Register* reg, Memory* mem, const size_t index) {
    if (reg != NULL && mem != NULL)
        mem->data[index] = reg->val;
}

/* Incrémentation du registre */
void register_increment(Register* reg) {
    reg->val += 1;
}

/* Décrémentation du registre */
void register_decrement(Register* reg) {
    reg->val -= 1;
}