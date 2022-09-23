#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct Node
{
    int value;
    Node *next;
};

void insertNode(Node *&list, int value);
void show_list(Node *list);
void max_list(Node *list);
void min_list(Node *list);
void mean_list(Node *list);
void add_initial_element(Node *&list);
void add_final_element(Node *&list);
void delete_element(Node *&list);
void delete_first_element(Node *&list);
void delete_last_element(Node *&list);
void bubble_sort(Node *&list);
void quick_sort(Node *&list);

int main()
{
    int value;
    int user_selection;
    Node *header;
    header = NULL;
    std::cout << "Ingrese el numero de elementos que desea ingresar: " << std::endl;
    std::cin >> value;

    insertNode(header, value);
    // show_list(header);
    // delete_element(header);
    // delete_first_element(header);
    // delete_last_element(header);
    //bubble_sort(header);
    //show_list(header);
    quick_sort(header);
    show_list(header);

    // std::cout << "Ingrese la opcion que necesite" << std::endl;
    // std::cout << "1. Para ingresar datos a la lista" << std::endl;
    // std::cout << "2. Para mostrar los datos de la lista" << std::endl;
    // std::cout << "3. Para agregar un elemento al inicio de la lista" << std::endl;
    // std::cout << "4. Para agregar un elemento al final de la lista" << std::endl;
    // std::cout << "5. Para eliminar un elemento" << std::endl;
    // std::cout << "6. Para mostrar el elemento mayor de la lista" << std::endl;
    // std::cout << "7. Para mostrar el elemento menor de la lista" << std::endl;
    // std::cout << "8. Para mostrar la media de todos los elementos de la lista" << std::endl;
    // std::cin >> user_selection;

    // switch (user_selection)
    // {
    // case 1:
    // 	insertNode(header, value);
    // 	break;
    // case 2:
    // 	show_list(header);
    // 	break;
    // case 3:
    // 	add_initial_element(header);
    // 	break;
    // case 4:
    // 	add_final_element(header);
    // 	break;
    // case 5:
    // 	delete_element(header);
    // 	break;
    // case 6:
    // 	max_list(header);
    // 	break;
    // case 7:
    // 	min_list(header);
    // 	break;
    // case 8:
    // 	mean_list(header);
    // 	break;
    // default:
    // 	std::cout << "Opcion no disponible";
    // }
};

void insertNode(Node *&list, int value)
{
    int current_value;
    Node *q;

    for (int i = 0; i < value; i++)
    {
        std::cout << "Ingrese el valor " << i << std::endl;
        std::cin >> current_value;
        q = new Node();
        q->value = current_value;
        q->next = list;
        list = q;
    }
};

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
}

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
}

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
}

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
}

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
}

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
};

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
}

void delete_first_element(Node *&list)
{
    list = list->next;
};

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
}

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
};

void quick_sort(Node* &list)
{
    Node *pivot = list;
    Node *right_list = NULL;
    Node *left_list = NULL;
    Node *aux_right;
    Node *aux_left;

        
    while(list != NULL) {
    	if(pivot == list) {
    		
		} else {
			if(pivot->value > list->value) {
				aux_left = new Node();
				aux_left->value = list->value;
				aux_left->next = left_list;
				left_list = aux_left;
			}else {
				aux_right = new Node();
				aux_right->value = list->value;
				aux_right->next = right_list;
				right_list = aux_right;
			} 	
		}
		
		
		list = list->next;
	}
	
	Node *last_left_list;
	Node *head_left = left_list;
	
	while(left_list != NULL) {
		if(left_list->next == NULL) {
			last_left_list = left_list;
		}
		
		left_list = left_list->next;
	};
	
	left_list = head_left;
	
	list = left_list;
	last_left_list->next = pivot;	
	pivot->next = right_list;

}
