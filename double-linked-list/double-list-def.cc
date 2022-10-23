#include <iostream>

struct Node {
	int value;
	Node* next;
	Node* prev;
};

Node *first = NULL;
Node *last;

// 1. Insertar elementos a la Lista
void insert_node(Node* &first, Node* &last);
// 2. Mostrar elementos de forma ascendente
void show_a(Node* &first);
// 3. Mostrar elementos de forma descendente
void show_d(Node* &last);
// 4. Eliminar un elemento de la lista
void delete_element(Node* &first, Node * &last);
// 5. Eliminar el primer elemento de la lista
void delete_first_element(Node * &first);
// 6. Eliminar ultimo elemento de la lista
void delete_last_element(Node * &last);
// 7. Ingresar elementos en orden
void insert_in_order(Node* &first, Node* &last);
// 8. Ordernar los elementos de la lista por el metodo Bubble Sort
void bubble_sort(Node * &first);
// 9. Ordenar los elementos de la lista por el método Quick Sort
Node* quick_sort(Node* list);
// 10. Eliminar lista
void delete_list(Node* &first, Node* &last);


int main() {
	int user_option;

	std::cout << std::endl;
	std::cout << "Ingrese la opcion que desea realizar: " << std::endl;
	std::cout << "1. Ingresar datos a la lista" << std::endl;
	std::cout << "2. Mostrar la lista de forma ascendente" << std::endl;
	std::cout << "3. Mostrar la lista de forma descendente" << std::endl;
	std::cout << "4. Eliminar un elemento de la lista" << std::endl;
	std::cout << "5. Eliminar el primer elemento de la lista" << std::endl;
	std::cout << "6. Eliminar el ultimo elemento de la lista" << std::endl;
	std::cout << "7. Ingresar elementos en orden" << std::endl;
	std::cout << "8. Ordenar los elementos de la lista por el método Bubble Sort" << std::endl;
	std::cout << "9. Ordenar los elementos de la lista por el método Quick Sort" << std::endl;
	std::cout << "10. Eliminar todos los elementos de la lista" << std::endl;
	std::cout << "11. Salir" << std::endl;
	std::cin >> user_option;
	std::cout << std::endl;


	switch (user_option)
	{	
		case 1:
			insert_node(first, last);
			break;
		case 2:
			show_a(first);
			break;
		case 3:
			show_d(last);
			break;
		case 4:
			delete_element(first, last);
			break;
		case 5:
			delete_first_element(first);
			break;
		case 6:
			delete_last_element(last);
			break;
		case 7:
			insert_in_order(first, last);
			break;
		case 8:
			bubble_sort(first);
			break;
		case 9:
			quick_sort(first);
			main();
			break;
		case 10:
			delete_list(first, last);
			break;
		default:
			return 0;
	}

};

// 1. Insertar elementos a la Lista
void insert_node(Node* &first, Node* &last) {
	int num_elements, current_value;	
	
	std::cout << "Ingrese cuantos elementos desea ingresar: " << std::endl;
	std::cin >> num_elements;
	
	for(int i = 0; i < num_elements; i++) {
		std::cout << "Ingrese el elemento: " << i << std::endl;
		std::cin >> current_value;
		Node *q = new Node();
		q->value = current_value;
		
		if(first == NULL) {
			first = q;
			first->next = NULL;
			first->prev = NULL;
			last = q;
		} else {
			last->next = q;
			q->next = NULL;
			q->prev = last;
			last = q;
		}
	}

	main();
}

// 2. Mostrar elementos de forma ascendente
void show_a(Node* &first) {
	std::cout << "ASCENDENTE" << std::endl;
	
	Node *aux = new Node();
	aux = first;
	
	if(aux != NULL) {
		while(aux != NULL) {
			std::cout << aux->value << std::endl;
			aux = aux->next;
		}
	} else {
		std::cout << "La lista esta vacia" << std::endl;
	}

	main();
};

// 3. Mostrar elementos de forma descendente
void show_d(Node* &last) {
	std::cout << "DESCENDENTE" << std::endl;
	
	Node *aux = new Node();
	aux = last;
	
	if(aux != NULL) {
		while(aux != NULL)	 {
			std::cout << aux->value << std::endl;
			aux = aux->prev;
		}	
	} else {
		std::cout << "La lista esta vacia" << std::endl;
	}

	main();
}

// 4. Eliminar un elemento de la lista
void delete_element(Node* &first, Node* &last) {
	Node *head = first;
	Node *node_to_delete;
	int value_to_delete;
	
	std::cout << "Ingrese el valor que desea eliminar: " << std::endl;
	std::cin >> value_to_delete;
	
	
	while(head != NULL) {
		if(head->value == value_to_delete) {
			node_to_delete = head;
		}
		
		head = head->next;
	}
	
	if(node_to_delete->next != NULL) {
		node_to_delete->next->prev = node_to_delete->prev;
	} else {
		last = node_to_delete->prev;
	} 
	
	
	if(node_to_delete->prev != NULL) {
		node_to_delete->prev->next = node_to_delete->next;
	} else {
		first = node_to_delete->next;
	}

	main();
}

// 5. Eliminar el primer elemento de la lista
void delete_first_element(Node * &first) {
	first = first->next;
	first->prev = NULL;

	main();
}

// 6. Eliminar ultimo elemento de la lista
void delete_last_element(Node * &last) {
	last = last->prev;
	last->next = NULL;

	main();
}

// 7. Ingresar elementos en orden
void insert_in_order(Node* &first, Node* &last) {
	int num_elements;

	std::cout << "Ingrese el numero de elementos que desea ingresar: " << std::endl;
	std::cin >> num_elements;

	for(int i = 0; i < num_elements; i++) {
		Node* q = new Node();
		std::cout << "Ingrese el valor del elemento " << i + 1 << std::endl;	
		std::cin >> q->value;

		if(first == NULL ){
			first = q;
			last = q;
			q->next = NULL;
			q->prev = NULL;
			show_a(first);
		} else {
			Node* aux = first;
			Node* first_node = first;
			while(aux != NULL ) {
				if(q->value < aux->value) {
					if(aux->prev == NULL) {
						q->prev = NULL;
						q->next = first;
						first->prev = q;
						first = q;
						break;
					} else {
						aux->prev->next = q;
						q->prev = aux->prev;
						aux->prev = q;
						q->next = aux;
						first = first_node;
						break;
					}
				}

				if(aux->next == NULL && q->value > aux->value) {
					q->prev = last;
					q->next = NULL;
					last->next = q;
					last = q;
					break;
				}	

				aux = aux->next;
			}
		}
	}

	main();	
};

// 8. Ordernar los elementos de la lista por el metodo Bubble Sort
void bubble_sort(Node* &first) {
	Node* current_node = first;
	Node* next_node = current_node->next;
	Node* end_pointer = NULL;
	int point_value;

	while(current_node->next != end_pointer) {
		while(current_node->next != end_pointer) {
			if(next_node->value < current_node->value) {
				point_value = next_node->value;
				next_node->value = current_node->value;
				current_node->value = point_value;
			}

			current_node = current_node->next;
			next_node = current_node->next;
		}

		end_pointer = current_node;
		current_node = first;
		next_node = current_node->next;
	}

	first = current_node;

	main();
};

// 9. Ordenar los elementos de la lista por el método Quick Sort
Node* quick_sort(Node* list) {
	   if(list == NULL || list->next == NULL) {
        return list;
    } 

    Node *pivot = list;
    Node *right_list = NULL;
    Node *left_list = NULL;
    Node *aux_right;
    Node *aux_left;


    while(list != NULL) {

        if(pivot->value > list->value) {
            aux_left = new Node();
            aux_left->value = list->value;
            aux_left->next = left_list;
            left_list = aux_left;
        }else if(pivot->value < list->value) {
            aux_right = new Node();
            aux_right->value = list->value;
            aux_right->next = right_list;
            right_list = aux_right;
        } 	
        
        list = list->next;
    }

    left_list = quick_sort(left_list);
    right_list = quick_sort(right_list);
	
	
	Node *last_left_list;
	Node *head_left = left_list;
	Node *head_right = right_list;
	
	while(left_list != NULL) {
		if(left_list->next == NULL) {
			last_left_list = left_list;
		}
		
		left_list = left_list->next;
	};

	while(right_list != NULL) {
		if(right_list->next == NULL) {
			last = right_list;
		}
			
		right_list = right_list->next;
	};
	
	left_list = head_left;
	right_list = head_right;
	
	first = left_list;
	last_left_list->next = pivot;	
	pivot->next = right_list;


	while(first->next != NULL) {
		first->next->prev = first;
		first = first->next;
	}

	first = left_list;

    return first;
};

// 10. Eliminar lista
void delete_list(Node* &first, Node* &last) {
	first, last = NULL;
}









