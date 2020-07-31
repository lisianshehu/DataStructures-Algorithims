#include <stdlib.h>
#include <stdio.h>

class Node
{
    public:
        int data;
        Node *next = NULL;

        Node(int data)
        {
            this->data = data;
        }

        ~Node()
        {
            delete next;
        }
};

class Queue
{
    private:
        Node *head = NULL;
        Node *tail = NULL;

    public:
        Queue()
        {
           printf("Initializing Queue\n");
        }

        ~Queue()
        {
            delete head;
            delete tail;
        }

        void insert(int data);
        int deleteNode();
        bool isEmpty();
        void print();
};

void Queue::insert(int data)
{
    Node *newNode = new Node(data);

    if(head == NULL)
    {
        head = tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }

 }

 int Queue::deleteNode()
 {
     if (head == NULL)
     {
         return NULL;
     }

     Node *temp = head;

     head = head->next;
     temp->next = NULL;

     delete temp;

     if (head == NULL)
     {
         tail = NULL;
     }
 }

 void Queue::print()
{
    Node *node = head;

    while (node != NULL)
    {
        printf("%d->", node->data);
        node = node->next;
    }
    printf("%d\n", node);
    
    delete node;
}


 int main()
 {
     Queue *queue = new Queue();

     queue->insert(1);
     queue->insert(2);
     queue->insert(3);
     queue->deleteNode();
     queue->deleteNode();
     queue->deleteNode();
     queue->print();
     delete queue;
 }