#include <iostream>

struct Node {
    int value;
    Node* next;
    Node* prev;
};

Node* header = NULL;
Node* tail;

// 1. Insertar elemento
void insert_element();
// 2. Sacar elemento
void get_element(Node* header, Node* &tail);
// 3. Imprimit estructura
void print_struct();
// 4. Vaciar estructura
void emtpy_struct();
// 5. Buscar elemento 
void search_element(Node* header, Node* &tail);

int main() {
    int user_option;

    std::cout << std::endl;
    std::cout << "Ingrese la opcion que desea realizar" << std::endl;
    std::cout << "1. Ingresar elemento" << std::endl;
    std::cout << "2. Sacar elemento" << std::endl;
    std::cout << "3. Imprimir la estructura" << std::endl;
    std::cout << "4. Vaciar la estructura" << std::endl;
    std::cout << "5. Buscar elemento" << std::endl;
    std::cout << "6. Salir" << std::endl;
    std::cin >> user_option;
    std::cout << std::endl;

    switch(user_option) {
        case 1:
            insert_element();
            break;
        case 2:
            get_element(header, tail);
            break;
        case 3:
            print_struct();
            break;
        case 4:
            emtpy_struct();
            break;
        case 5:
            search_element(header, tail);
            break;
        default:
            return 0;
    }
}

// 1. Insertar elemento
void insert_element() {
    int num_elements;

    std::cout << "Ingrese la cantidad de elementos que desea anadir: " << std::endl;
    std::cin >> num_elements;

    for(int i = 0; i < num_elements; i++) {
        Node *q = new Node();
        std::cout << "Ingrese el valor del elemento " << i + 1 << std::endl;
        std::cin >> q->value;

        if(header == NULL) {
            header = q;
            q->next = NULL;
            q->prev = NULL;
            tail = q;
        } else {
            tail->next = q;
            q->next = NULL;
            q->prev = tail;
            tail = q;
        }
    }

    main();
}

// 2. Sacar elemento
void get_element(Node* header, Node* &tail) {
    if(tail == NULL) {
        std::cout << "La lista esta vacia" << std::endl;
    }

    tail = tail->prev;
    tail->next = NULL;

    main();
}

// 3. Imprimit estructura
void print_struct() {
    Node *q = header;

    if(q == NULL) {
        std::cout << "Lista Vacía" << std::endl;
    } else {
        while(q != NULL) {
            std::cout << q->value << std::endl;
            q = q->next;
        }
    }


    main();
}

// 4. Vaciar estructura
void emtpy_struct() {
    header = NULL;
    main();
}

// 6. Buscar elemento 
void search_element(Node* header, Node* &tail) {
    Node* q = new Node();
    bool found = false; 
    q = header;

    int value_to_search;

    std::cout << "Ingrese el valor que desea buscar" << std::endl;
    std::cin >> value_to_search;

    while(q != NULL) {
        if(q->value == value_to_search) {
            found = true;
        }

        q = q->next;
    }

    if(found) {
        std::cout << "Valor " << value_to_search << " encontrado!" << std::endl;
    } else {
         std::cout << "Valor " << value_to_search << " no fue encontrado" << std::endl;
    }

    main();

}







