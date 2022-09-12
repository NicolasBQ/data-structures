#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


struct Node {
	int value;
	Node* next;
};

void insertNode(Node* &list, int value);
void show_list(Node* list);
void max_list(Node* list);
void min_list(Node* list);
void mean_list(Node* list);

int main() {
	int value;
	Node* header;
	header= NULL;
	std::cout << "Ingrese el numero de elementos que desea ingresar: " << std::endl;
	std::cin >> value;
	
	insertNode(header, value);
	show_list(header);
	max_list(header);
	min_list(header);
	mean_list(header);
};

void insertNode(Node* &list, int value) {
	int current_value;
	Node* q;
	
	for(int i = 0; i < value; i++) {
		std::cout << "Ingrese el valor " << i << std::endl;
		std::cin >> current_value;
		q = new Node();
		q->value = current_value;
		q->next = list;
		list = q;
	}
};

void show_list(Node* list) {
	if(list == NULL ) {
		std::cout << "No hay valores en la lista" << std::endl;
	} else {
		while(list != NULL) {
			std::cout << list->value << std::endl;
			list = list->next;
		}
	}
}

void max_list(Node* list) {
	int max = list->value;	
	while(list != NULL) {
		if(list->value > max) {
			max = list->value;
		}
		
		list = list->next;
	}
	
	std::cout << "El numero mayor de la lista es " << max << std::endl;
}

void min_list(Node* list) {
	int min = list->value;
	while(list != NULL) {
		if(list->value < min) {
			min = list->value;
		}
		
		list = list->next;
	}
	
	std::cout << "El numero menor de la lista es " << min << std::endl;
}

void mean_list(Node* list) {
	int sum = 0;
	int mean;
	int counter = 0;
	
	while(list != NULL) {
		sum += list->value;
		counter++;
		list = list->next;
	};
	
	mean = sum / counter;
	
	std::cout << "El promedio de la lista es " << mean << std::endl;
	
}









