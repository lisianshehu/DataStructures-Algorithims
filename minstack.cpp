#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
using namespace std;

class Node
{
    public:
        int data;
        int minVal;
        Node * next = NULL;

        Node(int data)
        {
            this->data = data;
        }

        ~Node()
        {
            delete next;
        }
};

class MinStack
{
    private:
        Node *top = NULL;
    
    public:

        MinStack()
        {
            printf("Initializing MinStack\n");
        }

        ~MinStack()
        {
            delete top;
        }

        void push(int data);
        int pop();
        Node * peek();
        int getMin();
        void print();
};

void MinStack::push(int data)
{
    Node *newNode = new Node(data);

    if (top == NULL)
    {
        top = newNode;
        top->minVal = newNode->data;
        printf("Base min value: %d\n", top->minVal);
    }
    else
    {
        Node *temp = top;
        int curMin = temp->minVal;
        top = newNode;
        top->next = temp;
        top->minVal = min(top->data, curMin);
        printf("New nodes min value: %d\n", top->minVal);
    }
}

int MinStack::pop()
{
    if (top == NULL)
    {
        return NULL;
    }

    Node * temp = top;
    int tempData = temp->data;
    top = top->next;
    temp->next = NULL;

    delete temp;

    return tempData;

}

int MinStack::getMin()
{
    if (top == NULL)
    {
        return NULL;
    }
    
    return peek()->minVal;
}

Node * MinStack::peek()
{
    return top;
}

void MinStack::print()
{
    Node *n = top;
    
    while (n != NULL)
    {
        printf("%d->", n->data);
        n = n->next;
    }

    printf("%d", n);
    printf("\n");
}

int main()
{
    MinStack *minStack = new MinStack();

    minStack->push(2);
    minStack->push(3);
    minStack->push(1);
    minStack->print();
    printf("Get min: %d\n", minStack->getMin());
    minStack->pop();
    printf("Get min: %d\n", minStack->getMin());
    minStack->print();
    minStack->pop();
    printf("Get min: %d\n", minStack->getMin());
    minStack->print();
    minStack->pop();
    printf("Get min: %d\n", minStack->getMin());
    minStack->print();
    minStack->pop();
    printf("Get min: %d\n", minStack->getMin());
    minStack->print();

}