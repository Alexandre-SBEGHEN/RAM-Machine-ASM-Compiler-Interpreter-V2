/**
 * @file test_compiler.c
 * @brief Test des implémentations de compiler.h / compiler.c
 * @author Alexandre SBEGHEN
 * @date 2026-06-26
 */

#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "compiler.h"

/**
 * @brief Test de la fonction file_to_string().
 *
 * Exécute la fonction sur différents cas et vérifie
 * les strings en résultat.
 *
 * @see file_to_string()
 */
void test_file_to_string() {
    // Premier fichier (paragraphe simple)
    char* strfile_1 = file_to_string(PROJECT_ROOT "/tests/testdata/test_compiler/test_file_to_string/simple_paragraph"
                                                  ".txt");
    assert(strfile_1 != NULL);
    char* strtest_1 = "Bonjour tout le monde !\nCeci est un paragraphe simple,\ntrès très simple...\nHihihi";
    assert(strcmp(strfile_1, strtest_1) == 0);
    free(strfile_1);

    // Second fichier (code asm simple)
    char* strfile_2 = file_to_string(PROJECT_ROOT "/tests/testdata/test_compiler/test_file_to_string/simple_asm_code.asm");
    assert(strfile_2 != NULL);
    char* strtest_2 = "# Petit code asm tranquilou\nmain:\n    LOAD #1;\n    HALT;";
    assert(strcmp(strfile_2, strtest_2) == 0);
    free(strfile_2);
}

/**
 * @brief Test de la fonction string_to_array().
 *
 * Exécute la fonction sur différents cas et vérifie
 * les tableaux en résultat.
 *
 * @see string_to_array()
 */
void test_string_to_array() {
    // Première string (paragraphe simple)
    char** str_1 = string_to_array(
        "Bonjour tout le monde !\nCeci est un paragraphe simple,\ntrès très simple...\nHihihi"
    );
    assert(str_1 != NULL);
    char strtest_1[4][50] = {
        "Bonjour tout le monde !",
        "Ceci est un paragraphe simple,",
        "très très simple...",
        "Hihihi"
    };
    for (int i = 0; i < 4; ++i)
        assert(strcmp(str_1 [i], strtest_1[i]) == 0);
    free(str_1);

    // Seconde string (code asm simple)
    char** str_2 = string_to_array("# Petit code asm tranquilou\nmain:\n    LOAD #1;\n    HALT;");
    assert(str_2 != NULL);
    char strtest_2[4][50] = {
        "# Petit code asm tranquilou",
        "main:",
        "    LOAD #1;",
        "    HALT;"
    };
    for (int i = 0; i < 4; ++i)
        assert(strcmp(str_2 [i], strtest_2[i]) == 0);
    free(str_2);
}

/**
 * @brief Test de la fonction string_clean().
 *
 * Exécute la fonction sur différents cas et vérifie
 * les strings en résultat.
 *
 * @see string_clean()
 */
void test_string_clean() {
    char* str_1 = string_clean("# commentaire");
    char* str_2 = string_clean("     # espace et commentaire");
    char* str_3 = string_clean("etiquette: #commentaire");
    char* str_4 = string_clean("   HALT;      ");
    char* str_5 = string_clean("   STORE @0;      # commentaire");
    char* str_6 = string_clean("    ");
    char* str_7 = string_clean("");
    char* str_8 = string_clean(" # ");
    char* str_9 = string_clean("   #");
    char* str_10 = string_clean("#     ");
    char* str_11 = string_clean("  STORE #-67;   # commentaire");
    char* str_12 = string_clean("  ####    z");
    assert(strcmp(str_1, "") == 0);
    assert(strcmp(str_2, "") == 0);
    assert(strcmp(str_3, "etiquette:") == 0);
    assert(strcmp(str_4, "HALT;") == 0);
    assert(strcmp(str_5, "STORE @0;") == 0);
    assert(strcmp(str_6, "") == 0);
    assert(strcmp(str_7, "") == 0);
    assert(strcmp(str_8, "") == 0);
    assert(strcmp(str_9, "") == 0);
    assert(strcmp(str_10, "") == 0);
    assert(strcmp(str_11, "STORE #-67;") == 0);
    assert(strcmp(str_12, "") == 0);
}

int main() {
    test_file_to_string();
    test_string_to_array();
    test_string_clean();

    return 0;
}