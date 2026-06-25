/**
* @file test_machine.c
 * @brief Test des implémentations de machine.h / machine.c
 * @author Alexandre SBEGHEN
 * @date 2026-06-24
*/

#include <stddef.h>
#include <assert.h>
#include <string.h>
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
    Register* reg = register_create();

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
    Register* reg = register_create();
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
    for (size_t size = 1; size < 128; ++size) {
        Memory* mem = memory_create(size);

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
        Memory* mem = memory_create(size);
        memory_delete(&mem);

        assert(mem == NULL);
    }
}

/**
 * @brief Test de la fonction ram_load_direct().
 *
 * Vérifie que :
 * - La valeur chargée dans le registre est la bonne.
 *
 * @see ram_load_direct()
 */
void test_ram_load_direct() {
    Register* reg = register_create();
    for (int32_t i = -128; i < 128; ++i) {
        ram_load_direct(reg, i);
        assert(reg->val == i);
    }
    register_delete(&reg);
}

/**
 * @brief Test de la fonction ram_load_from().
 *
 * Vérifie que :
 * - La valeur chargée dans le registre est la bonne.
 *
 * @see ram_load_from()
 */
void test_ram_load_from() {
    Register* reg = register_create();
    Memory* mem = memory_create(8);

    // Mettre des valeurs dans la mémoire
    const int32_t test_values[] = {0, 1, 3, 2, -4, -5, 127, -67};
    memcpy(mem->data, test_values, sizeof(test_values));

    // Tester les valeurs du registre
    for (int32_t i = 0; i < 8; ++i) {
        assert(mem->data[i] == test_values[i]);
        ram_load_from(reg, mem, i);
        assert(reg->val == mem->data[i]);
    }

    memory_delete(&mem);
    register_delete(&reg);
}

/**
 * @brief Test de la fonction ram_store_to().
 *
 * Vérifie que :
 * - La valeur enregistrée dans la mémoire est la bonne.
 *
 * @see ram_store_to()
 */
void test_ram_store_to() {
    Register* reg = register_create();
    Memory* mem = memory_create(8);

    // Valeurs à ranger dans la mémoire
    const int32_t test_values[] = {0, 1, 3, 2, -4, -5, 127, -67};

    for (int32_t i = 0; i < 8; ++i) {
        reg->val = test_values[i];
        ram_store_to(reg, mem, i);
        assert(mem->data[i] == test_values[i]);
    }
}

/**
 * @brief Test de la fonction register_increment().
 *
 * Vérifie que :
 * - La valeur enregistrée dans le registre est la bonne.
 *
 * @see register_increment()
 */
void test_register_increment() {
    Register* reg = register_create();

    register_increment(reg);
    assert(reg->val == 1);
    register_increment(reg);
    register_increment(reg);
    assert(reg->val == 3);
    register_increment(reg);
    register_increment(reg);
    register_increment(reg);
    register_increment(reg);
    assert(reg->val == 7);
    register_increment(reg);
    register_increment(reg);
    register_increment(reg);
    assert(reg->val == 10);
}

/**
 * @brief Test de la fonction register_decrement().
 *
 * Vérifie que :
 * - La valeur enregistrée dans le registre est la bonne.
 *
 * @see register_decrement()
 */
void test_register_decrement() {
    Register* reg = register_create();

    register_decrement(reg);
    assert(reg->val == -1);
    register_decrement(reg);
    register_decrement(reg);
    assert(reg->val == -3);
    register_decrement(reg);
    register_decrement(reg);
    register_decrement(reg);
    register_decrement(reg);
    assert(reg->val == -7);
    register_decrement(reg);
    register_decrement(reg);
    register_decrement(reg);
    assert(reg->val == -10);
}

int main() {
    test_register_create();
    test_register_delete();
    test_memory_create();
    test_memory_delete();

    test_ram_load_direct();
    test_ram_load_from();
    test_ram_store_to();
    test_register_increment();
    test_register_decrement();

    return 0;
}