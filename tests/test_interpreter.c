/**
* @file test_interpreter.c
 * @brief Test des implémentations de interpreter.h / interpreter.c
 * @author Alexandre SBEGHEN
 * @date 2026-06-25
*/

#include <assert.h>
#include <stddef.h>
#include "interpreter.h"

/**
 * @brief Test de la fonction program_create().
 *
 * Vérifie que :
 * - Le registre créé n'est pas NULL ;
 * - Ses champs ne sont pas NULL ;
 * - Les valeurs de la matrice sont initialisées à 0.
 *
 * @see program_create()
 */
void test_program_create() {
    for (size_t size = 1; size < 128; ++size) {
        Program* prog = program_create(size);

        assert(prog != NULL);
        assert(prog->instructions != NULL);
        assert(prog->data != NULL);
        for (size_t i = 0; i < size; ++i)
            assert(
                prog->instructions[i][0] == 0 &&
                prog->instructions[i][1] == 0
            );

        program_delete(&prog);
    }
}

/**
 * @brief Test de la fonction program_delete().
 *
 * Vérifie que :
 * - Le pointeur est défini à NULL.
 *
 * @see program_delete()
 */
void test_program_delete() {
    for (size_t size = 0; size < 128; ++size) {
        Program* prog = program_create(size);
        program_delete(&prog);

        assert(prog == NULL);
    }
}

int main() {
    test_program_create();
    test_program_delete();

    return 0;
}