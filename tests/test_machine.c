/**
 * @file test_machine.c
 * @brief Test des implémentations de machine.h / machine.c
 * @author Alexandre SBEGHEN
 * @date 2026-06-24
*/

#include <stddef.h>
#include <assert.h>
#include "machine.h"

void test_register_create() {
    Reg* reg = register_create();

    assert(reg != NULL);
    assert(reg->val == 0);

    register_delete(&reg);
}

void test_register_delete() {
    Reg* reg = register_create();
    register_delete(&reg);

    assert(reg == NULL);
}

int main() {
    test_register_create();

    return 0;
}