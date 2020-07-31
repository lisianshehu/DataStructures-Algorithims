#include <stdlib.h>
#include <stdio.h>


class Node 
{
    public:
        int data;
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

class Stack
{
    private:
        Node *top = NULL;

    public:
        void push(int data);
        int pop();
        int peek();
        bool isEmpty();
        void print();

        Stack()
        {
            printf("Initializing Stack\n");
        }

        ~Stack()
        {
            delete top;
        }
};

void Stack::push(int data)
{
    Node *newNode = new Node(data);

    if (top == NULL)
    {
        top = newNode;
    }
    else
    {
        Node *temp = top;
        top = newNode;
        top->next = temp;
    }
}

int Stack::pop()
{
    if (top == NULL)
    {
        return NULL;
    }

    Node *temp = top;
    int data = top->data;
    top = top->next;
    temp->next = NULL;
    

    delete temp;
    return data;
}

void Stack::print()
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

int Stack::peek()
{   
    if ((!isEmpty()))
    {
        return top->data;
    }

    return NULL;
}

bool Stack::isEmpty()
{
    return (top == NULL);
}

int main()
{
    Stack *stack = new Stack();
    stack->push(1);
    stack->push(2);
    stack->push(3);
    stack->print();
    printf("Popped: %d\n", stack->pop());
    stack->print();
    printf("Popped: %d\n", stack->pop());
    stack->print();
    printf("Popped: %d\n", stack->pop());
    stack->print();
    printf("Peek: %d\n",stack->peek());
    delete stack;
}