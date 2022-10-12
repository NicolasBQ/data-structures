#include <iostream>


struct Node
{
    int value;
    Node *next;
};

Node *header = NULL;


// 1. Ingresar elementos a la lista
void insertNode(Node *&list);
// 2. Mostar la lista
void show_list(Node *list);
// 3. Mostar el elemento mas grande de la lista
void max_list(Node *list);
// 4. Mostrar el elemento mas pequeno de la lista
void min_list(Node *list);
// 5. Mostrar el promedio de la lista
void mean_list(Node *list);
// 6. Anadir un elemento al inicio de la lista
void add_initial_element(Node *&list);
// 7. Anadir un elemento al final de la lista
void add_final_element(Node *&list);
// 8. Eliminar un elemento de la lista
void delete_element(Node *&list);
// 9. Eliminar el primer elemento de la lista
void delete_first_element(Node *&list);
// 10. Eliminar el ultimo elemento de la lista
void delete_last_element(Node *&list);
// 11. Ordenar la lista por el metodo Bubble Sort
void bubble_sort(Node *&list);
// 12. Ordenar la lista por el metodo Quick Sort
Node* quick_sort(Node* list);
// 13. Eliminar lista
void delete_list(Node* &list);


// Stop or Continue Program
void continue_program();

int main()
{
    int user_selection;

    std::cout << std::endl;
    std::cout << "Ingrese la opcion que desea realizar: " << std::endl;
    std::cout << "1. Ingresar elementos a la lista" << std::endl;
    std::cout << "2. Mostrar la lista" << std::endl;
    std::cout << "3. Mostar el elemento mas grande de la lista" << std::endl;
    std::cout << "4. Mostar el elemento mas pequeno de la lista" << std::endl;
    std::cout << "5. Mostar el promedio de la lista" << std::endl;
    std::cout << "6. Anadir un elemento al inicio de la lista" << std::endl;
    std::cout << "7. Anadir un elemento al final de la lista" << std::endl;
    std::cout << "8. Eliminar un elemento de la lista" << std::endl;
    std::cout << "9. Eliminar el primer elemento de la lista" << std::endl;
    std::cout << "10. Elimnar el ultimo elemento de la lista" << std::endl;
    std::cout << "11. Ordenar la lista por el metodo Bubble Sort" << std::endl;
    std::cout << "12. Ordenar la lista por el metodo Quick Sort" << std::endl;
    std::cout << "13. Eliminar la lista" << std::endl;
    std::cout << "14. Salir" << std::endl;
    std::cin >> user_selection;
    std::cout << std::endl;

    switch(user_selection) {
        case 1:
            insertNode(header);
            break;
        case 2:
            show_list(header);
            break;
        case 3:
            max_list(header);
            break;
        case 4:
            min_list(header);
            break;
        case 5:
            mean_list(header);
            break;
        case 6:
            add_initial_element(header);
            break;
        case 7:
            add_final_element(header);
            break;
        case 8:
            delete_element(header);
            break;
        case 9:
            delete_first_element(header);
            break;
        case 10:
            delete_last_element(header);
            break;
        case 11:
            bubble_sort(header);
            break;
        case 12:
            quick_sort(header);
            continue_program();
            break;
        case 13:
            delete_list(header);
            break;
        default:
            return 0;
    }

};

// 1. Ingresar elementos a la lista
void insertNode(Node *&list)
{
    int current_value, value;
    Node *q;

    std::cout << "Ingrese el numero de elementos que desea ingresar: " << std::endl;
    std::cin >> value;

    for (int i = 0; i < value; i++)
    {
        std::cout << "Ingrese el valor " << i << std::endl;
        std::cin >> current_value;
        q = new Node();
        q->value = current_value;
        q->next = list;
        list = q;
    }

    continue_program();
};

// 2. Mostar la lista
void show_list(Node *list)
{
    if (list == NULL)
    {
        std::cout << "No hay valores en la lista" << std::endl;
    }
    else
    {
        while (list != NULL)
        {
            std::cout << list->value << std::endl;
            list = list->next;
        }
    }

    continue_program();
}

// 3. Mostar el elemento mas grande de la lista
void max_list(Node *list)
{
    int max = list->value;
    while (list != NULL)
    {
        if (list->value > max)
        {
            max = list->value;
        }

        list = list->next;
    }

    std::cout << "El numero mayor de la lista es " << max << std::endl;

    continue_program();
}


// 4. Mostrar el elemento mas pequeno de la lista
void min_list(Node *list)
{
    int min = list->value;
    while (list != NULL)
    {
        if (list->value < min)
        {
            min = list->value;
        }

        list = list->next;
    }

    std::cout << "El numero menor de la lista es " << min << std::endl;

    continue_program();
}

// 5. Mostrar el promedio de la lista
void mean_list(Node *list)
{
    int sum = 0;
    int mean;
    int counter = 0;

    while (list != NULL)
    {
        sum += list->value;
        counter++;
        list = list->next;
    };

    mean = sum / counter;

    std::cout << "El promedio de la lista es " << mean << std::endl;

    continue_program();
}

// 6. Anadir un elemento al inicio de la lista
void add_initial_element(Node *&list)
{
    int new_value;
    Node *q;

    std::cout << "Ingrese el valor para agregar al inicio de la lista: " << std::endl;
    std::cin >> new_value;
    q = new Node();
    q->value = new_value;
    q->next = list;
    list = q;

    continue_program();
}

// 7. Anadir un elemento al final de la lista
void add_final_element(Node *&list)
{
    int new_value;
    Node *head_node = list;
    Node *last_node;
    Node *q;
    std::cout << "Ingrese el valor para agregar al final de la lista: " << std::endl;
    std::cin >> new_value;
    q = new Node();
    q->value = new_value;

    while (list != NULL)
    {
        if (list->next == NULL)
        {
            last_node = list;
        }

        list = list->next;
    }

    list = head_node;
    last_node->next = q;
    q->next = NULL;

    continue_program();
};

// 8. Eliminar un elemento de la lista
void delete_element(Node *&list)
{
    int value_to_delete;
    Node *head = list;
    std::cout << "Ingrese el valor que quiere eliminar: " << std::endl;
    std::cin >> value_to_delete;

    if (head->value == value_to_delete)
    {
        head = head->next;
    }
    else
    {
        while (list != NULL)
        {
            if (list->next->value == value_to_delete)
            {
                list->next = list->next->next;
                break;
            };

            list = list->next;
        }
    };

    list = head;

    continue_program();
}

// 9. Eliminar el primer elemento de la lista
void delete_first_element(Node *&list)
{
    list = list->next;

    main();
};

// 10. Eliminar el ultimo elemento de la lista
void delete_last_element(Node *&list)
{
    Node *head = list;
    while (list != NULL)
    {
        if (list->next->next == NULL)
        {
            list->next = NULL;
        }
        list = list->next;
    }

    list = head;

    continue_program();
}

// 11. Ordenar la lista por el metodo Bubble Sort
void bubble_sort(Node *&list)
{
    Node *p = list;
    Node *q = p->next;
    Node *end_pointer = NULL;
    int point_value;

    while (p->next != end_pointer)
    {
        while (p->next != end_pointer)
        {
            if (q->value < p->value)
            {
                point_value = p->value;
                p->value = q->value;
                q->value = point_value;
            }

            p = p->next;
            q = p->next;
        };
        end_pointer = p;
        p = list;
        q = p->next;
    }

    list = p;

    continue_program();
};

// 12. Ordenar la lista por el metodo Quick Sort
Node* quick_sort(Node* list)
{     
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
	
	while(left_list != NULL) {
		if(left_list->next == NULL) {
			last_left_list = left_list;
		}
		
		left_list = left_list->next;
	};
	
	left_list = head_left;
	
	header = left_list;
	last_left_list->next = pivot;	
	pivot->next = right_list;

    return header;
}

// 13. Eliminar lista
void delete_list(Node* &list) {
    list = NULL;
    continue_program();
}


void continue_program() {
    int user_option;

    std::cout << std::endl;
    std::cout << "Desea continuar?" << std::endl;
    std::cout << "Marque 1 para continuar" << std::endl;
    std::cout << "Marque 2 para salir" << std::endl;
    std::cout << std::endl;
    std::cin >> user_option;

    if(user_option == 1) {
        main();
    } 
}