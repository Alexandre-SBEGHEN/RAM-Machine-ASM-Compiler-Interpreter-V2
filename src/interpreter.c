/**
 * @file interpreter.c
 * @brief Implémentation de l'interpréteur.
 * @author Alexandre SBEGHEN
 * @date 2026-06-25
 */

#include "interpreter.h"
#include <stdlib.h>

/* Création dynamique d'une structure registre Register */
Program* program_create(size_t size) {
    Program* prog;

    if ((prog = malloc(sizeof(Program))) == NULL)
        return NULL;

    prog->size = size;

    if ((prog->inst = malloc(size * sizeof(Instruction))) == NULL) {
        free(prog);
        return NULL;
    }

    return prog;
}

/* Libération de mémoire d'une structure Program */
void program_delete(Program** prog) {
    if (prog == NULL || *prog == NULL)
        return;

    free((*prog)->inst);
    free(*prog);
    *prog = NULL;
}

/* Exécution d'un programme compilé */
int program_interpret(const Program* prog, Machine* mac) {
    size_t inst_index = 0;

    // Boucle du programme
    while (1) {
        // Index en dehors du programme (erreur 1)
        if (inst_index >= prog->size)
            return 1;

        // Obtenir la paire opération / argument
        int32_t op = prog->inst[inst_index].op;
        int32_t arg = prog->inst[inst_index].arg;

        // Action selon l'instruction
        switch (op) {
            // Ne rien faire
            case 0:
                break;
            // LOAD #?
            case 1:
                ram_load_direct(mac, arg);
                break;
            // LOAD @?
            case 2:
                ram_load_from(mac, arg);
            // STORE @?
            case 3:
                ram_store_to(mac, arg);
                break;
            // INCR
            case 4:
                ram_increment(mac);
                break;
            // DECR
            case 5:
                ram_decrement(mac);
                break;
            // JUMP ?
            case 6:
                // Gérer l'overflow (erreur 1)
                if (arg < 0)
                    return 1;
                inst_index = arg;
                continue;
            // JZ ?
            case 7:
                // Gérer l'overflow (erreur 1)
                if (arg < 0)
                    return 1;
                if (mac->reg->val <= 0) {
                    inst_index = arg;
                    continue;
                }
                break;
            // HALT
            case 8:
                return 0;
            // Instruction inconnue (erreur 2)
            default:
                return 2;
        }

        // Instruction suivante
        ++inst_index;
    }
}

/* Création d'un programme à partir d'un fichier .bin */
Program* file_bin_to_program(const char* filename) {
    return NULL;
}