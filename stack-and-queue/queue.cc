#include <iostream>

// 1. Crear elemento
void create_element();
// 2. Insertar elemento
void insert_element();
// 3. Sacar elemento
void get_element();
// 4. Imprimit estructura
void print_struct();
// 5. Vaciar estructura
void emtpy_struct();
// 6. Buscar elemento 
void search_element();

int main() {
    int user_option;

    std::cout << std::endl;
    std::cout << "Ingrese la opcion que desea realizar" << std::endl;
    std::cout << "1. Crear elemento" << std::endl;
    std::cout << "2. Ingresar elemento" << std::endl;
    std::cout << "3. Sacar elemento" << std::endl;
    std::cout << "4. Imprimir la estructura" << std::endl;
    std::cout << "5. Vaciar la estructura" << std::endl;
    std::cout << "6. Buscar elemento" << std::endl;
    std::cout << "7. Salir" << std::endl;
    std::cin >> user_option;
    std::cout << std::endl;

    switch(user_option) {
        case 1:
            create_element();
            break;
        case 2:
            insert_element();
            break;
        case 3:
            get_element();
            break;
        case 4:
            print_struct();
            break;
        case 5:
            emtpy_struct();
            break;
        case 6:
            search_element();
            break;
        default:
            return;
    }
}

// 1. Crear elemento
void create_element() {
    std::cout << "Create element" << std::endl;

    main();
}

// 2. Insertar elemento
void insert_element() {
    std::cout << "Insert element" << std::endl;

    main();
}

// 3. Sacar elemento
void get_element() {
    std::cout << "Get element" << std::endl;

    main();
}

// 4. Imprimit estructura
void print_struct() {
    std::cout << "Print struct" << std::endl;

    main();
}

// 5. Vaciar estructura
void emtpy_struct() {
    std::cout << "Empty struct" << std::endl;

    main();
}

// 6. Buscar elemento 
void search_element() {
    std::cout << "Search elemet" << std::endl;

    main();
}

