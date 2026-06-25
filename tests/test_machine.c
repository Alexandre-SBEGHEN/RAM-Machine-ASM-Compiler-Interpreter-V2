/**
* @file test_machine.c
 * @brief Test des implémentations de machine.h / machine.c
 * @author Alexandre SBEGHEN
 * @date 2026-06-24
*/

#include <stddef.h>
#include <assert.h>
#include "machine.h"

/**
 * @brief Test de la fonction register_create().
 *
 * Vérifie que :
 * - Le registre créé n'est pas NULL ;
 * - Sa valeur est initialisée à 0.
 *
 * @see register_create()
 */
void test_register_create() {
    Reg* reg = register_create();

    assert(reg != NULL);
    assert(reg->val == 0);

    register_delete(&reg);
}

/**
 * @brief Test de la fonction register_delete().
 *
 * Vérifie que :
 * - Le pointeur est défini à NULL.
 *
 * @see register_delete()
 */
void test_register_delete() {
    Reg* reg = register_create();
    register_delete(&reg);

    assert(reg == NULL);
}

/**
 * @brief Test de la fonction memory_create().
 *
 * Vérifie que :
 * - La mémoire créée n'est pas NULL ;
 * - Son champ size est correct ;
 * - Toutes ses données sont initalisées à 0.
 *
 * @see memory_create()
 */
void test_memory_create() {
    for (size_t size = 0; size < 128; ++size) {
        Mem* mem = memory_create(size);

        assert(mem != NULL);
        assert(mem->size == size);
        for (size_t i = 0; i < size; i++)
            assert(mem->data[i] == 0);

        memory_delete(&mem);
    }
}

/**
 * @brief Test de la fonction memory_delete().
 *
 * Vérifie que :
 * - Le pointeur est défini à NULL.
 *
 * @see memory_delete()
 */
void test_memory_delete() {
    for (size_t size = 0; size < 128; ++size) {
        Mem* mem = memory_create(18);
        memory_delete(&mem);

        assert(mem == NULL);
    }
}


int main() {
    test_register_create();
    test_register_delete();
    test_memory_create();
    test_memory_delete();

    return 0;
}