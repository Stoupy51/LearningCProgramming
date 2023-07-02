
#ifndef __INT_ARRAY_H__
#define __INT_ARRAY_H__

/**
 * Structure qui représente un tableau d'entiers
 * 
 * @param data		Pointeur vers un tableau d'entiers
 * @param size		Taille du tableau d'entiers
 */
typedef struct int_array_t {
	// TODO: Définir les champs de la structure (data, size)
} int_array_t;


// Prototypes de fonctions pour travailler avec des int_array_t
int int_array_init(int_array_t* array, int size);
void int_array_print(int_array_t array, int print_level);
void int_array_free(int_array_t* array);



#endif

