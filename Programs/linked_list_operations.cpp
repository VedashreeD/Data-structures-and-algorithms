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

    //Remove Nth node from the end of the list
    void removeNthFromEnd(int remove_node) 
    {
        Node *fast = head;
        Node *slow = head;
        for (int i = 0; i < remove_node; i++) //fast goes to nth ele from starting index.
        {
            fast = fast->next;
        }    
        if (!fast) //if fast = NULL, return head+1 ele.
        {
            head = head->next;
	    return;
        }
        while (fast->next) //traverse fast to 2nd last ele, and slow to n-1th ele from end.
        {
            fast = fast->next, slow = slow->next;
        } 
        slow->next = slow->next->next;
        
         

    }

    //print the linked list
    void display() 
    {
        Node* temp = head;
	std::cout<<"HEAD -> ";
        while (temp != NULL) 
	{
	    std::cout<< temp->data << " -> ";
            temp = temp->next;
        }
	std::cout<<"NULL"<<std::endl;
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
	std::cin>>value;
        list.insert(value);
    }

    list.reverse();

    std::cout<<"Reversed linked list: "<<std::endl;
    list.display();

    int remove_node = 0;
    std::cout<<"Enter a position(starting from 0) within the linked list to be removed : "<<std::endl;
    std::cin>>remove_node;
    list.removeNthFromEnd(remove_node);
    list.display();

    return 0;
}
