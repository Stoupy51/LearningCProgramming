
#include "int_linked_list.h"
#include "universal_utils.h"

/**
 * @brief Fonction d'initialisation d'une liste doublement chaînée d'entiers
 * 
 * @param list		Pointeur vers un int_linked_list_t
 * 
 * @return int		-1 en cas d'erreur, 0 sinon
 */
int int_linked_list_init(int_linked_list_t* list) {
	// TODO: Implémenter la fonction
	return 0;
}

/**
 * @brief Fonction d'insertion d'un entier dans une liste doublement chaînée d'entiers
 * 
 * @param list		Pointeur vers un int_linked_list_t
 * @param value		Valeur à insérer dans la liste chaînée
 * 
 * @return int_linked_list_element_t*	Pointeur vers l'élément inséré dans la liste chaînée, NULL en cas d'erreur
 */
int_linked_list_element_t* int_linked_list_insert(int_linked_list_t* list, int value) {

	// Allocation de mémoire pour un nouvel élément de la liste chaînée
	int_linked_list_element_t* new_element = malloc(sizeof(int_linked_list_element_t));
	ERROR_HANDLE_PTR_RETURN_NULL(new_element, "int_linked_list_insert(): Erreur lors du malloc()\n");

	// Initialisation des valeurs de l'élément
	new_element->value = value;
	new_element->previous = NULL;
	new_element->next = NULL;
	
	// Si la liste chaînée est vide, on met à jour la tête de la liste chaînée
	if (list->size == 0) {
		list->head = new_element;
		list->tail = new_element;
	}

	// Sinon, on insère l'élément à la fin de la liste chaînée
	else {

		// L'élément précédent de l'élément à insérer est l'ancienne queue de la liste chaînée
		new_element->previous = list->tail;

		// L'élément suivant de l'ancienne queue de la liste chaînée est l'élément à insérer
		list->tail->next = new_element;

		// La nouvelle queue de la liste chaînée est l'élément à insérer		
		list->tail = new_element;
	}

	// Incrémentation du nombre d'éléments de la liste chaînée
	list->size++;

	// Retour de la fonction avec succès 
	return new_element;
}


/**
 * @brief Fonction de recherche d'un entier dans une liste doublement chaînée d'entiers
 * 
 * @param list		int_linked_list_t dans laquelle rechercher
 * @param value		Valeur à rechercher dans la liste chaînée
 * 
 * @return int_linked_list_element_t*	Pointeur vers l'élément de la liste chaînée contenant la valeur recherchée, NULL si introuvable
 */
int_linked_list_element_t* int_linked_list_search(int_linked_list_t list, int value) {

	// Variable de boucle
	int_linked_list_element_t* current_element = list.tail;

	// Parcours de la liste chaînée (tant qu'on n'est pas arrivé à la fin de la liste chaînée)
	while (current_element != NULL) {

		// Si la valeur de l'élément courant est égale à la valeur recherchée, on retourne l'élément courant
		if (current_element->value == value)
			return current_element;

		// Sinon, on passe à l'élément précédent
		current_element = current_element->previous;
	}

	// Si on arrive ici, c'est que la valeur recherchée n'a pas été trouvée dans la liste chaînée
	return NULL;
}

/**
 * @brief Fonction de suppression d'un entier dans une liste doublement chaînée d'entiers
 * 
 * @param list		Pointeur vers un int_linked_list_t
 * @param element	Pointeur vers l'élément à supprimer de la liste chaînée (passé par adresse)
 * 
 * @return int		-1 en cas d'erreur, 0 sinon
 */
int int_linked_list_remove(int_linked_list_t* list, int_linked_list_element_t** element) {

	// Si l'élément à supprimer est NULL, on retourne une erreur
	int code = element == NULL ? -1 : (*element == NULL ? -2 : 0);
	ERROR_HANDLE_INT_RETURN_INT(code, "int_linked_list_remove(): Erreur : l'élément à supprimer est NULL\n");

	// Pour simplifier l'écriture, on crée un pointeur local vers l'élément à supprimer
	int_linked_list_element_t* elt = *element;

	// Si l'élément à supprimer est la tête de liste, on met à jour la tête de liste
	if (elt == list->head)
		list->head = elt->next;
	
	// Si l'élément à supprimer est le dernier élément de la liste, on met à jour la queue de liste
	if (elt == list->tail)
		list->tail = elt->previous;
	
	// Si l'élément à supprimer a un élément précédent, on met à jour l'élément suivant de l'élément précédent
	if (elt->previous != NULL)
		elt->previous->next = elt->next;
	
	// Si l'élément à supprimer a un élément suivant, on met à jour l'élément précédent de l'élément suivant
	if (elt->next != NULL)
		elt->next->previous = elt->previous;
	
	// Libération de la mémoire allouée pour l'élément à supprimer
	free(*element);
	*element = NULL;

	// Décrémentation du nombre d'éléments de la liste chaînée
	list->size--;

	// Retour de la fonction avec succès
	return 0;
}

/**
 * @brief Fonction d'affichage d'une liste doublement chaînée d'entiers
 * 
 * @param list			int_linked_list_t à afficher
 * @param print_level	Niveau d'affichage
 * 
 * @return void
 */
void int_linked_list_print(int_linked_list_t list, int print_level) {
	
	// Variable de boucle
	int_linked_list_element_t* elt = list.head;
	
	// Affichage du préfixe de niveau d'affichage
	PREFIX_PRINT(print_level);

	// Affichage du début du tableau
	if (list.size == 0) {
		PRINTER("int_linked_list de taille 0: []\n");
	}
	else {
		PRINTER("int_linked_list de taille %d: [%d", list.size, list.head->value);
	}

	// Affichage du reste du tableau (à partir du deuxième élément)
	elt = elt == NULL ? NULL : elt->next;
	while (elt != NULL) {
		PRINTER(", %d", elt->value);
		elt = elt->next;
	}

	// Affichage de la fin du tableau
	PRINTER("]\n");
}

/**
 * @brief Fonction de libération de la mémoire allouée pour une liste doublement chaînée d'entiers
 * 
 * @param list		Pointeur vers un int_linked_list_t
 * 
 * @return void
 */
void int_linked_list_free(int_linked_list_t* list) {

	// Si la liste chaînée est vide, on retourne
	if (list->size == 0)
		return;

	// Variable de boucle
	int_linked_list_element_t* current_element = list->head;

	// Parcours de la liste chaînée (tant qu'on n'est pas arrivé à la fin de la liste chaînée)
	while (current_element != NULL) {

		// On récupère l'élément suivant
		int_linked_list_element_t* next_element = current_element->next;

		// On libère la mémoire allouée pour l'élément courant
		free(current_element);

		// On passe à l'élément suivant
		current_element = next_element;
	}

	// On met à jour les valeurs de la liste chaînée
	list->size = 0;
	list->head = NULL;
	list->tail = NULL;
}






