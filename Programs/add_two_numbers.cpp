//C++ Program to add 2 numbers using a singly linked list
#include <iostream>

class Node {
public:
    int val;
    Node* next;

    Node(int value) : val(value), next(NULL) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(NULL) {}

    void add(int value) 
    {
        Node* node = new Node(value);
        if (head == NULL) 
        {
            head = node;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) 
        {
            temp = temp->next;
        }
        temp->next = node;
        node->next = NULL;
    }

    static LinkedList addTwoNumbers(LinkedList list1, LinkedList list2) 
    {
        LinkedList result;
        Node* l1 = list1.head;
        Node* l2 = list2.head;
        int carry = 0;

        while (l1 != NULL || l2 != NULL || carry) 
        {
            int sum = 0;
            if(l1 != NULL)
            {
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2 != NULL)
            {
                sum += l2->val;
                l2 = l2->next;
            }
            sum += carry;
            carry = sum / 10;

            result.add(sum % 10);
        }
        return result;
    }

    void printList() {
        Node* temp = head;
        while (temp != NULL) 
        {
            std::cout<<temp->val<<" ";
            temp = temp->next;
        }
    }


};

int main() 
{
    // Create two linked lists
    LinkedList list1;
    LinkedList list2;

    // Add to list1 : 321
    list1.add(1);
    list1.add(2);
    list1.add(3);

    // Add to list2: 765
    list2.add(5);
    list2.add(6);
    list2.add(7);

    // Add the two lists
    LinkedList result;
    result = LinkedList::addTwoNumbers(list1, list2);

    // Display the result
    std::cout<<"Sum: ";
    result.printList();

    return 0;
}
