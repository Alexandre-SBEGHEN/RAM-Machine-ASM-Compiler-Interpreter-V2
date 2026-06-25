/**
 * @file interpreter.h
 * @brief Interpréteur du code compilé
 *
 * Allocation, suppression, interprétation
 * d'un programme assembleur compilé
 *
 * @author Alexandre SBEGHEN
 * @date 2026-06-25
 */

#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <stdint.h>
#include <stddef.h>

/* --- Alias --------------------------------------------------------------- */

typedef struct ProgramStruct Program;

/* --- Structs ------------------------------------------------------------- */

/**
 * @brief Structure du programme compilé.
 * C'est une matrice de N lignes (nb instructions)
 * et 2 colonnes (instruction/argument).
 */
struct ProgramStruct {
    int32_t** instructions; // Adresses des lignes de la matrice
    int32_t* data; // Données de la matrice (contiguës)
};

/* --- Fonctions ----------------------------------------------------------- */

/**
 * @brief Crée dynamiquement une structure programme Program.
 *
 * Valeurs de la matrice initialisées par défaut à 0.
 *
 * @param[in] number_of_instructions Nombre d'instructions du programme.
 * @return Pointeur vers la structure allouée ou NULL en cas
 * d'échec d'allocation.
 *
 * @note Penser à libérer la mémoire après utilisation.
 * @see program_delete()
 */
Program* program_create(size_t number_of_instructions);

/**
 * @brief Libération de mémoire d'une structure Program.
 *
 * Utilisation du double pointeur en paramètre pour
 * mettre automatiquement sa valeur à NULL.
 *
 * @param[in, out] prog Adresse du pointeur vers la structure.
 */
void program_delete(Program** prog);

#endif
