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

void test_memory_create() {
    Mem* mem = memory_create();

    assert(mem != NULL);
    for (size_t i = 0; i < mem->size; ++i)
        assert(mem->data[i] == 0);

    memory_delete(&mem);
}

int main() {
    test_register_create();

    return 0;
}