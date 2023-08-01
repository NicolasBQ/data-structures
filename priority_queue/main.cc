#include <iostream>
#include <iomanip>

struct Node {
	int turn;
	int prio;
    std::string name;
	Node* next;
	Node* prev;
};

int main () {
	int numOfTurns;
	
	Node* header = new Node;
	Node* last = new Node;
	header->next = NULL;
	header->prev = NULL;
					
	std::cout << "Ingrese el numero de turnos" << std::endl;
	std::cin >> numOfTurns;
	
	for(int i = 0; i < numOfTurns; i++) {
		int prio;
        std::string name;

        std::cout << "Ingrese el nombre de la persona " << i + 1 << std::endl;
        std::cin >> name;

		std::cout << "Ingrese la prioridad de " << name << std::endl;
        std::cout << "1 -> Prioridad Alta" << std::endl;
        std::cout << "2 -> Prioridad Media" << std::endl;
        std::cout << "3 -> Prioridad Baja" << std::endl;
		std::cin >> prio;

		Node* node = new Node;
		node->turn = i + 1;
        node->name = name;
		node->prio = prio;
		
		if(header->next == NULL) {
			header->next = node;
			node->next = NULL;
			node->prev = header;
			last = node;
		} else {
			node->next = last->next;
			node->prev = last;
			node->prev->next = node;
			last = node;
		}
	}
	
	Node* headerPrio1 = new Node;
	Node* lastPrio1 = new Node;
	headerPrio1->next = NULL;
	headerPrio1->prev = NULL; 
	
	Node* prio1 = header->next;
	
	while(prio1 != NULL) {
        if(prio1->prio == 1) {
            Node* nodePrio1 = new Node;
            nodePrio1->name = prio1->name;
            nodePrio1->turn = prio1->turn;
            nodePrio1->prio = prio1->prio;

            if(headerPrio1->next == NULL) {
                headerPrio1->next = nodePrio1;
                nodePrio1->next = NULL;
                nodePrio1->prev = headerPrio1;
                lastPrio1 = nodePrio1;
            } else {
                nodePrio1->next = lastPrio1->next;
                nodePrio1->prev = lastPrio1;
                nodePrio1->prev->next = nodePrio1;
                lastPrio1 = nodePrio1;
            }
        };

        prio1 = prio1->next;
	}

    	
	Node* headerPrio2 = new Node;
	Node* lastPrio2 = new Node;
	headerPrio2->next = NULL;
	headerPrio2->prev = NULL; 
	
	Node* prio2 = header->next;
	
	while(prio2 != NULL) {
        if(prio2->prio == 2) {
            Node* nodePrio2 = new Node;
            nodePrio2->name = prio2->name;
            nodePrio2->turn = prio2->turn;
            nodePrio2->prio = prio2->prio;

            if(headerPrio2->next == NULL) {
                headerPrio2->next = nodePrio2;
                nodePrio2->next = NULL;
                nodePrio2->prev = headerPrio2;
                lastPrio2 = nodePrio2;
            } else {
                nodePrio2->next = lastPrio2->next;
                nodePrio2->prev = lastPrio2;
                nodePrio2->prev->next = nodePrio2;
                lastPrio2 = nodePrio2;
            }
        };

        prio2 = prio2->next;
	}


    Node* headerPrio3 = new Node;
	Node* lastPrio3 = new Node;
	headerPrio3->next = NULL;
	headerPrio3->prev = NULL; 

    Node* prio3 = header->next;
	
	while(prio3 != NULL) {
        if(prio3->prio == 3) {
            Node* nodePrio3 = new Node;
            nodePrio3->name = prio3->name;
            nodePrio3->turn = prio3->turn;
            nodePrio3->prio = prio3->prio;

            if(headerPrio3->next == NULL) {
                headerPrio3->next = nodePrio3;
                nodePrio3->next = NULL;
                nodePrio3->prev = headerPrio3;
                lastPrio3 = nodePrio3;
            } else {
                nodePrio3->next = lastPrio3->next;
                nodePrio3->prev = lastPrio3;
                nodePrio3->prev->next = nodePrio3;
                lastPrio3 = nodePrio3;
            }
        };

        prio3 = prio3->next;
	}

    if(headerPrio1->next == NULL) {
        if(headerPrio2->next == NULL) {
            headerPrio1->next = headerPrio3->next;
        } else {
            headerPrio1->next = headerPrio2->next;
            lastPrio2->next = headerPrio3->next;
        }
    } else {
        if(headerPrio2->next == NULL) {
            lastPrio1->next = headerPrio3->next;
        } else {
            lastPrio1->next = headerPrio2->next;
            lastPrio2->next = headerPrio3->next;
        }
    }


    Node* orderList = headerPrio1->next;

    std::cout << std::left << std::setw(10) << "Nombre" << std::left << std::setw(10) << "Turno" << std::left << std::setw(10) << "Prioridad" << std::endl;
    // std::cout << std::left << std::setw(10) << "______" << std::left << std::setw(5) << "_____" << std::left << std::setw(10) << "_________" << std::endl;
    int i = 1;
    while(orderList != NULL) {
        std::cout << std::left << std::setw(10) << orderList->name << std::left << std::setw(10) << i << std::left << std::setw(10) << orderList->prio << std::endl;
        i = i + 1;
        orderList = orderList->next;
    }



	return 0;
}

