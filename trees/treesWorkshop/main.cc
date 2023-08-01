#include <windows.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct Node {
	int value;
	Node* right;
	Node* left;
};

void gotoxy(int x, int y) {
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}

Node* create_node(int n) {
	Node* new_node = new Node();
	new_node->value = n;
	new_node->right = NULL;
	new_node->left = NULL;
	
	return new_node;
}

void insert_node(Node* &tree, int n) {
	if(tree == NULL) {
		tree = create_node(n);
	} else {
		if(tree->value < n) {
			insert_node(tree->right, n);
		} else {
			insert_node(tree->left, n);
		}
	}
}

void show_tree(Node* tree, int space, std::string direction) {
	if(tree == NULL) {
		return;
	} else {
		show_tree(tree->right, space + 1, "right");
		
		if(direction == "right") {
			gotoxy(60 + space * 5, space);
			std::cout << tree->value << std::endl;
		} else if(direction == "left") {
			gotoxy(60 - space* 5, space);
			std::cout << tree->value << std::endl;
		} else {
			gotoxy(60, space);
			std::cout << tree->value << std::endl;
		}	
	
		
		show_tree(tree->left, space + 1, "left");
	}
}

int main() {
	Node* tree = NULL;
	int elements, num, space = 0;
	std::cout << "Ingrese la cantidad de elementos que desea ingresar: " << std::endl;
	std::cin >> elements;
	
	for(int i = 0; i < elements; i++) {
		std::cout << "Ingrese el valor del elemento " << i + 1 << std::endl;
		std::cin >> num;
		insert_node(tree, num);
		system("cls");
		show_tree(tree, space, "center");
	}	
	
	return 0;
}