#include <iostream>

//Node class contains a data field and next, pointing to next node
class Node 
{
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(NULL) {}
};

class LinkedList 
{
private:
    //for each LinkedList object, head points to starting node
    Node* head;

public:
    LinkedList() : head(NULL) {}

    //insert a node at the end of the list
    void insert(int value) 
    {
	Node* temp = head;
	Node* node = new Node(value);
	if(head == NULL)
	{
	    head = node;
	    node->next = NULL;
	    return;
	}
	while(temp->next)
	{
	    temp = temp->next;
	}
	temp->next = node;
	node->next = NULL;

    }

    //reverse the linked list
    void reverse() 
    {
        if (head == NULL || head->next == NULL)
            return;

        Node* prev = NULL;
        Node* current = head;

        while (current != NULL) 
	{
            Node* nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }

        head = prev;
    }

    //print the linked list
    void display() 
    {
        Node* temp = head;
        while (temp != NULL) 
	{
	    std::cout << temp->data << " ";
            temp = temp->next;
        }
    }

};

int main() {
    LinkedList list;

    int n; 
    std::cout<<"Enter the number of elements: ";
    std::cin>>n;

    std::cout<<"Enter the elements: ";
    for (int i = 0; i < n; i++) 
    {
        int value;
	std::cin >> value;
        list.insert(value);
    }

    list.reverse();

    std::cout<<"Reversed linked list: "<<std::endl;
    list.display();

    return 0;
}
