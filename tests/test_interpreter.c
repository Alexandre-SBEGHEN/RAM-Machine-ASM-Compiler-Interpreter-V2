/**
* @file test_interpreter.c
 * @brief Test des implémentations de interpreter.h / interpreter.c
 * @author Alexandre SBEGHEN
 * @date 2026-06-25
*/

#include <assert.h>
#include <stddef.h>
#include <string.h>

#include "machine.h"
#include "interpreter.h"

/**
 * @brief Test de la fonction program_create().
 *
 * Vérifie que :
 * - Le registre créé n'est pas NULL ;
 * - Sa taille est correcte ;
 * - Sa liste d'instructions n'est pas NULL ;
 * - Les op/arg des instructions sont nuls.
 *
 * @see program_create()
 */
void test_program_create() {
    for (size_t size = 1; size < 128; ++size) {
        Program* prog = program_create(size);

        assert(prog != NULL);
        assert(prog->size == size);
        assert(prog->inst != NULL);
        for (size_t i = 0; i < prog->size; ++i) {
            assert(prog->inst[i].op == 0);
            assert(prog->inst[i].arg == 0);
        }

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

/**
 * @brief Test de la fonction program_interpret().
 *
 * Exécute plusieurs programmes et vérifie les valeurs de la
 * mémoire en résultat.
 *
 * @see program_interpret()
 */
void test_program_interpret() {
    Machine* mac = machine_create(2);
    Program* prog = program_create(16);

    // Programme 1 (a = 1)
    Instruction progtest_1[3] = {
        {1, 1},
        {3, 0},
        {8, 0}
    };
    memcpy(prog->inst, progtest_1, sizeof(progtest_1));
    program_interpret(prog, mac);
    assert(mac->mem->data[0] == 1);

    // Programme 2 (a = a + 10)
    Instruction progtest_2[10] = {
        {1, -9},
        {3, 2},
        {2, 0},
        {4, 0},
        {3, 0},
        {2, 2},
        {4, 0},
        {3, 2},
        {7, 2},
        {8, 0}
    };
    memcpy(prog->inst, progtest_2, sizeof(progtest_2));
    mac->mem->data[0] = 0;
    program_interpret(prog, mac);
    assert(mac->mem->data[0] == 10);
    mac->mem->data[0] = 5;
    program_interpret(prog, mac);
    assert(mac->mem->data[0] == 15);
    mac->mem->data[0] = -5;
    program_interpret(prog, mac);
    assert(mac->mem->data[0] == 5);
    mac->mem->data[0] = -10;
    program_interpret(prog, mac);
    assert(mac->mem->data[0] == 0);

    // Programme 3 (a = |a|)
    Instruction progtest_3[16] = {
        {2, 0},
        {4, 0},
        {3, 1},
        {2, 0},
        {4, 0},
        {7, 7},
        {6, 15},
        {2, 0},
        {4, 0},
        {4, 0},
        {3, 0},
        {2, 1},
        {4, 0},
        {3, 1},
        {7, 7},
        {8, 0}
    };
    memcpy(prog->inst, progtest_3, sizeof(progtest_3));
    mac->mem->data[0] = 0;
    program_interpret(prog, mac);
    assert(mac->mem->data[0] == 0);
    mac->mem->data[0] = 5;
    program_interpret(prog, mac);
    assert(mac->mem->data[0] == 5);
    mac->mem->data[0] = -1;
    program_interpret(prog, mac);
    assert(mac->mem->data[0] == 1);
    mac->mem->data[0] = -67;
    program_interpret(prog, mac);
    assert(mac->mem->data[0] == 67);

    program_delete(&prog);
    machine_delete(&mac);
}

int main() {
    test_program_create();
    test_program_delete();
    test_program_interpret();

    return 0;
}