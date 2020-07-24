#include <stdlib.h>
#include <stdio.h>
#include <unordered_set>
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
    private:
        Node *head = NULL;
        Node *tail = NULL;

    public:
        void headInsert(int data);
        void tailInsert(int data);
        int headDelete();
        int tailDelete();
        void searchNode(int data);
        bool isEmpty();
        void removeDups();
        void removeDupsBuffer();
        void deleteMiddleNode();
        Node * findKthToLast(Node *n, int k, int &count);
        Node * findKthToLast(int k);
        int length();
        void print();

    LinkedList()
    {
        printf("Initializing linked list\n");
    }

    ~LinkedList()
    {
        delete head;
        delete tail;
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

    Node *temp = tail;

    int temp_data = temp->data;

    if (head == tail)
    {
        head = tail = NULL;
    }
    else
    {
        Node *n = head;
        while(n->next != tail)
        {   
            n = n->next;
        }

        tail = n;
        tail->next = NULL;
    }

    delete temp;   

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

void LinkedList::removeDups()
{
    Node *curr = head;

    while (curr != NULL)
    {
        Node *runner = curr;
        while (runner->next != NULL)
        {
            if (curr->data == runner->next->data)
            {
                runner->next = runner->next->next;
            }
            else
            {
                runner = runner->next;
            }
        }
        
        curr = curr->next;

    }
}


void LinkedList::removeDupsBuffer()
{
    unordered_set<int> dupsSet;

    Node *prev = NULL;
    Node *curr = head;

    while (curr != NULL)
    {
        if (dupsSet.find(curr->data) != dupsSet.end())
        {
            prev->next = curr->next;
        }
        else
        {
            dupsSet.insert(curr->data);
            prev = curr;
        }
        curr = curr->next;
    }
}

Node * LinkedList::findKthToLastIter(int k)
{
    
}
Node * LinkedList::findKthToLast(Node *n, int k, int &count)
{   
    // base case
    if (n == NULL)
    {
        return NULL;
    }

    Node *nd = findKthToLast(n->next, k, count);
    count++;

    if (count == k)
    {
        return n;
    }

    return nd;
}

Node * LinkedList::findKthToLast(int k)
{
    int count = 0;

    return findKthToLast(head, k, count);
}

void LinkedList::deleteMiddleNode()
{
    Node *curr = head;
    Node *n = head->next;
    while (curr->next != n)
    {
        curr = curr->next;
    }

    curr->next = n->next;
    delete n;
}

int LinkedList::length()
{
    Node *n = head;
    int length = 0;

    while (n != NULL)
    {
        n = n->next;
        length++;
    }

    return length;
}

bool LinkedList::isEmpty()
{
    return (head==NULL);
}

int main()
{
    LinkedList *list = new LinkedList();
    list->tailInsert(1);
    list->tailInsert(2);
    list->tailInsert(3);
    list->tailInsert(4);
    list->tailInsert(5);
    list->print();
    printf("Length of list: %d\n", list->length());
    printf("Found kth to last %d\n", list->findKthToLast(2)->data);
    // list->removeDupsBuffer();
    // list->print();
    // printf("NO BUFFER SOLUTION!");
    // while(list->isEmpty() == 0)
    // {
    //     list->headDelete();
    // }
    // list->tailInsert(2);
    // list->tailInsert(4);
    // list->tailInsert(2);
    // list->tailInsert(4);
    // list->tailInsert(3);
    // list->print();
    // list->removeDups();
    // list->print();


    // printf("%d\n", list->isEmpty());
    // list->headDelete();
    // list->headDelete();
    // list->print();
    // list->tailDelete();
    // list->tailDelete();
    // printf("%d\n", list->isEmpty());
    // list->print();
    // list->tailDelete();
    // list->print();
    // printf("%d\n", list->isEmpty());
    // delete list;
}