#include <iostream>
using namespace std;

struct Node {
   int data;
   struct Node* next;
   };
 
Node* deleteFirstNode(struct Node* head)
{
   if (head == NULL)
   return NULL;
 
   Node* tempNode = head;
   head = head->next;
   delete tempNode;
 
   return head;
}

Node* removeLastNode(struct Node* head)
{
   if (head == NULL)
   return NULL;
 
   if (head->next == NULL) {
      delete head;
      return NULL;
   }

Node* second_last = head;
while (second_last->next->next != NULL)
second_last = second_last->next;

delete (second_last->next);
 
second_last->next = NULL;
 
return head;
}
 
void push(struct Node** head, int new_data)
{
   struct Node* newNode = new Node;
   newNode->data = new_data;
   newNode->next = (*head);
   (*head) = newNode;
}
 
int main()
{
   Node* head = NULL;
   push(&head, 2);
   push(&head, 4);
   push(&head, 6);
   push(&head, 8);
   push(&head, 10);
 
         Node* temp;
 
   cout<<"Linked list dibuat "<<endl; for (temp = head; temp != NULL; temp = temp->next)
   cout << temp->data << "-->";
   if(temp == NULL)
   cout<<"NULL"<<endl;
 
   head = deleteFirstNode(head);
   cout<<"Linked list setelah menghapus head node"<<endl; for (temp = head; temp != NULL; temp = temp->next)
   cout << temp->data << "-->";
   if(temp == NULL)
   cout<<"NULL"<<endl;
 
   head = removeLastNode(head);
   cout<<"Linked list setelah menghapus last node"<<endl; for (temp = head; temp != NULL; temp = temp->next)
   cout << temp->data << "-->";
   if(temp == NULL)
   cout<<"NULL";
 
   return 0;
}
