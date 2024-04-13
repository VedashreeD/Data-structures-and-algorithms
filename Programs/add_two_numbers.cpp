//C++ Program to add 2 numbers using a singly linked list
#include <iostream>

struct ListNode 
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* addTwoNumbers(ListNode* list1, ListNode* list2) 
{
     ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;
        int carry = 0;
        while(list1 || list2 || carry)
        {
            int sum = 0;
            if(list1 != NULL)
            {
                sum += list1->val;
                list1 = list1->next;
            }
            if(list2 != NULL)
            {
                sum += list2->val;
                list2=list2->next;
            }
            sum += carry;
            carry = sum/10;
            ListNode* newnode = new ListNode(sum % 10);
            temp->next = newnode;
            temp = temp->next;
        }
        return dummy->next;
}

void printList(ListNode* head) 
{
    ListNode* current = head;
    while (current != NULL) 
    {
	std::cout<<current->val<<" -> ";
        current = current->next;
    }
    std::cout<<"NULL"<<std::endl;
}

int main() 
{
    // Create two linked lists representing numbers
    ListNode* list1 = new ListNode(2);
    list1->next = new ListNode(4);
    list1->next->next = new ListNode(3);

    ListNode* list2 = new ListNode(5);
    list2->next = new ListNode(6);
    list2->next->next = new ListNode(4);

    // Add the numbers represented by the linked lists
    ListNode* result = addTwoNumbers(list1, list2);

    // Print the result
    printList(result);

    return 0;
}
