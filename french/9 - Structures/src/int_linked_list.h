
#ifndef __INT_LINKED_LIST_H__
#define __INT_LINKED_LIST_H__

/**
 * Structure qui représente un élément d'une liste doublement chaînée d'entiers
 * 
 * @param value		Valeur de l'élément de la liste chaînée
 * @param next		Pointeur vers l'élément suivant de la liste chaînée
 */
typedef struct int_linked_list_element_t {
	// TODO: Définir les champs de la structure (value, next, previous)
} int_linked_list_element_t;

/**
 * Structure qui représente une liste doublement chaînée d'entiers
 * 
 * @param size		Taille de la liste chaînée
 * @param head		Pointeur vers le premier élément de la liste chaînée
 * @param tail		Pointeur vers le dernier élément de la liste chaînée
 */
typedef struct int_linked_list_t {
	int size;
	int_linked_list_element_t* head;
	int_linked_list_element_t* tail;
} int_linked_list_t;

// Prototypes de fonctions pour travailler avec des int_linked_list_t
int int_linked_list_init(int_linked_list_t* list);
int_linked_list_element_t* int_linked_list_insert(int_linked_list_t* list, int value);
int_linked_list_element_t* int_linked_list_search(int_linked_list_t list, int value);
int int_linked_list_remove(int_linked_list_t* list, int_linked_list_element_t** element);
void int_linked_list_print(int_linked_list_t list, int print_level);
void int_linked_list_free(int_linked_list_t* list);

#endif

