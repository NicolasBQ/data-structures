#include <iostream>

struct Node {
    int value;
    Node* next;
};

Node* main_list = NULL;

int count_digits(int number);

int main() {
    int num_elements;
    int max_digits = 0;

    std::cout << "Ingrese la cantidad de elementos de la lista: " << std::endl;
    std::cin >> num_elements;

    for(int i = 0; i < num_elements; i++) {
        Node* q = new Node();
        std::cout << "Ingrese el valor del elemento " << i + 1 << std::endl;
        std::cin >> q->value;
        q->next = main_list;
        main_list = q;
    }

    Node* aux = main_list;

    while(aux != NULL) {
        int current_value = count_digits(aux->value);
        if(current_value > max_digits) {
            max_digits = current_value;
        }

        aux = aux->next;
    }

    aux = main_list;
    Node* storage[max_digits];

    for(int i = 0; i < max_digits; i++) {
        storage[i] = NULL;
    }

    for(int i = 0; i < max_digits; i++) {
        while(aux != NULL) {
            int current_value = count_digits(aux->value);
            if(current_value == i + 1) {
                Node* q = new Node();
                q->value = aux->value;
                q->next = storage[i];
                storage[i] = q;

            }

            aux = aux->next;
        }

        aux = main_list;
    }

    for(int i = 0; i < max_digits; i++) {
        std::cout << "DIGITOS " << i + 1 << std::endl;
        while(storage[i] != NULL) {
            std::cout << storage[i]->value << std::endl;
            storage[i] = storage[i]->next;
        }
    }

    return 0;
}



int count_digits(int number) {
    int digits = 0;
    while(number) {
        number /= 10;
        digits++;
    }

    return digits;
}


