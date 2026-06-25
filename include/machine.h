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

#include <stddef.h>
#include <stdint.h>

/* --- Alias --------------------------------------------------------------- */

typedef struct RegisterStruct Register;
typedef struct MemoryStruct Memory;

/* --- Structs ------------------------------------------------------------- */

/**
 * @brief Structure du registre.
 * Contient son unique valeur de type int32_t.
 */
struct RegisterStruct {
    int32_t val;
};

/**
 * @brief Structure de la mémoire.
 * Contient un tableau d'entiers de type int32_t.
 */
struct MemoryStruct {
    size_t size;
    int32_t* data;
};

/* --- Fonctions ----------------------------------------------------------- */

/**
 * @brief Crée dynamiquement une structure registre Register.
 *
 * Valeur initialisée par défaut à 0.
 *
 * @return Pointeur vers la structure allouée ou NULL en cas
 * d'échec d'allocation.
 *
 * @note Penser à libérer la mémoire après utilisation.
 * @see register_delete()
 */
Register* register_create();

/**
 * @brief Libération de mémoire d'une structure Register.
 *
 * Utilisation du double pointeur en paramètre pour
 * mettre automatiquement sa valeur à NULL.
 *
 * @param[in, out] reg Adresse du pointeur vers la structure.
 */
void register_delete(Register** reg);

/**
 * @brief Crée dynamiquement une structure mémoire Memory.
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
Memory* memory_create(size_t size);

/**
 * @brief Libération de mémoire d'une structure Memory.
 *
 * Utilisation du double pointeur en paramètre pour
 * mettre automatiquement sa valeur à NULL.
 *
 * @param[in, out] mem Adresse du pointeur vers la structure.
 */
void memory_delete(Memory** mem);

/**
 * @brief Chargement direct du registre.
 *
 * @param[out] reg Pointeur vers la structure Register.
 * @param[in] val Valeur à charger dans le registre.
 */
void ram_load_direct(Register* reg, int32_t val);

/**
 * @brief Chargement du registre depuis la mémoire.
 *
 * @param[out] reg Pointeur vers la structure Register.
 * @param[in] mem Pointeur vers la structure Memory.
 * @param[in] index Indice de la case mémoire.
 */
void ram_load_from(Register* reg, const Memory* mem, size_t index);

/**
 * @brief Rangement du registre vers la mémoire.
 *
 * @param[in] reg Pointeur vers la structure Register.
 * @param[out] mem Pointeur vers la structure Memory.
 * @param[in] index Indice de la case mémoire.
 */
void ram_store_to(const Register* reg, Memory* mem, size_t index);

/**
 * @brief Incrémente de 1 la valeur du registre Register.
 *
 * @param[out] reg Pointeur vers la structure Register.
 */
void register_increment(Register* reg);

/**
 * @brief Décrémente de 1 la valeur du registre Register.
 *
 * @param[out] reg Pointeur vers la structure Register.
 */
void register_decrement(Register* reg);

#endif