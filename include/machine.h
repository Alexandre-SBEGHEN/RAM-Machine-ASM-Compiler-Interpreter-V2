/**
* @file machine.h
 * @brief Machine RAM
 *
 * Allocation, suppression, gestion d'une
 * machine RAM avec son registre.
 *
 * @author Alexandre SBEGHEN
 * @date 2026-06-24
 */

#ifndef MACHINE_H
#define MACHINE_H

#include <stdint.h>

/* --- Alias ---------------------------------------------------- */

typedef struct RegStruct Reg;
typedef struct MemStruct Mem;

/* --- Structs -------------------------------------------------- */

/**
 * @brief Structure du registre.
 * Contient son unique valeur de type int32_t.
 */
struct RegStruct {
    int32_t val;
};

/**
 * @brief Structure de la mémoire.
 * Contient un tableau d'entiers de type int32_t.
 */
struct MemStruct {
    size_t size;
    int32_t* data;
};

/* --- Fonctions ------------------------------------------------ */

/**
 * @brief Crée dynamiquement une structure registre Reg.
 *
 * Valeur initialisée par défaut à 0.
 *
 * @return Pointeur vers la structure allouée ou NULL en cas
 * d'échec d'allocation.
 *
 * @note Penser à libérer la mémoire après utilisation.
 * @see register_delete()
 */
Reg* register_create();

/**
 * @brief Libération de mémoire d'une structure Reg.
 *
 * Utilisation du double pointeur en paramètre pour
 * mettre automatiquement sa valeur à NULL.
 *
 * @param[in, out] reg Pointeur vers la structure.
 */
void register_delete(Reg** reg);

/**
 * @brief Crée dynamiquement une structure mémoire Mem.
 *
 * Valeurs initialisées à 0.
 *
 * @param[in] size Taille de la mémoire.
 * @return Pointeur vers la structure allouée ou NULL en cas
 * d'échec d'allocation.
 *
 * @note Penser à libérer la mémoire après utilisation.
 * @see memory_delete()
 */
Mem* memory_create(size_t size);

/**
 * @brief Libération de mémoire d'une structure Mem.
 *
 * Utilisation du double pointeur en paramètre pour
 * mettre automatiquement sa valeur à NULL.
 *
 * @param[in, out] mem Pointeur vers la structure.
 */
void memory_delete(Mem** mem);

#endif