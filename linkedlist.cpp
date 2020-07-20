#include <stdlib.h>
#include <stdio.h>
using namespace std;
class Node
{
    public:
        int data;
        Node *next = NULL;

        Node(int data)
        {
            printf("Creating node %d\n", data);
            this->data = data;
        }

        Node(){}
};

class LinkedList
{
    public:
        Node *head = NULL;
        Node *tail = NULL;

        void headInsert(int data);
        void tailInsert(int data);
        int headDelete();
        int tailDelete();
        void searchNode(int data);
        void print();

    LinkedList()
    {
        printf("Initializing linked list\n");
    }
};

void LinkedList::tailInsert(int data)
{
    Node *newNode = new Node(data);

    if (head == NULL && tail == NULL)
    {
        head = tail = newNode;
    }
    else
    {
        // link new element to the end list and move tail reference forward to point to newly added node
        tail->next = newNode;
        tail = tail->next;
    }
}

void LinkedList::headInsert(int data)
{
    Node *newNode = new Node(data);

    // if we have yet to assign a tail then we should assign it to the first node that gets passed in 
    if (tail == NULL)
    {
        tail = newNode;
    }

    // will insert node at the beginning of linked list and update head
    newNode->next = head;
    head = newNode;
    
   
}

int LinkedList::headDelete()
{
    if (head == NULL)
    {
        return NULL;
    }

    Node *temp = head;
    int head_data = temp->data;
    head = head->next;

    if (head == NULL)
    {
        tail = NULL;
    }

    delete temp;

    return head_data;

}

int LinkedList::tailDelete()
{
    if (tail == NULL)
    {
        return NULL;
    }

    Node *temp = new Node();
    temp = tail;
    int temp_data = temp->data;

    if (head == tail)
    {
        head = tail = NULL;
    }
    else
    {
        Node *n = new Node();
        n = head;

        while(n->next != tail)
        {   
            n = n->next;
        }

        tail = n;
        tail->next = NULL;
    }

    delete temp;   
    delete n;
    
    return temp_data;
}

void LinkedList::print()
{
    Node *node = head;

    while (node != NULL)
    {
        printf("%d->", node->data);
        node = node->next;
    }
    printf("Null\n");
    
    delete node;
}

int main()
{
    LinkedList *list = new LinkedList();
    list->tailInsert(1);
    list->tailInsert(2);
    list->headInsert(3);
    list->headInsert(4);
    list->headInsert(5);
    // list->print();
    // list->headDelete();
    // list->headDelete();
    list->print();
    list->tailDelete();
    list->tailDelete();
    list->tailDelete();
    list->tailDelete();
    list->tailDelete();

    list->print();
}