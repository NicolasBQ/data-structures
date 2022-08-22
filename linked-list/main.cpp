#include <iostream>

struct Node
{
    int data;
    Node* next;
};

void show_numbers(Node*n) {
	while(n != NULL) {
		std::cout << n->data << std::endl;
		n = n->next;
	}
}

main()
{
	Node* head = new Node();
	Node* second = new Node();
	Node* third = new Node();
	
	head->data = 1;
	head->next = second;
	second->data = 2;
	second->next = third;
	third->data = 3;
	third->next = NULL;
	
	show_numbers(head);
}
