/**
* @file test_machine.c
 * @brief Test des implémentations de machine.h / machine.c
 * @author Alexandre SBEGHEN
 * @date 2026-06-24
*/

#include <stddef.h>
#include <assert.h>
#include "machine.h"
#include "stdio.h"

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
    for (size_t size = 0; size < 128; ++size) {
        Mem* mem = memory_create(size);

        assert(mem != NULL);
        for (size_t i = 0; i < size; i++)
            assert(mem->data[i] == 0);

        memory_delete(&mem);
    }
}

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