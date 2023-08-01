#include <iostream>


struct Node {
    int value;
    Node* left;
    Node* rigth;
};

Node* createNode(int value ) {
    Node* newNode = new Node();
    newNode->value = value;
    newNode->left = newNode->rigth = NULL;
    return newNode;
}


int main() {
    Node* root = createNode(1);
    root->left = createNode(3);
    root->rigth = createNode(2);
    root->left->left = createNode(4);

    return 0;   
}