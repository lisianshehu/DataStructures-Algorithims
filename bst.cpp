#include <stdio.h>
#include <stdlib.h>

class Node
{
    public:
        int data;
        Node *left = NULL;
        Node *right = NULL;

        Node(int data)
        {
            this->data = data;
        }

        ~Node()
        {
            delete left;
            delete right;
        }
};

class BST
{
    private:
        Node *root;
    
    public:
        void insertNode(int data);
        void deleteNode(int data);
        bool searchNode(int data);
        Node *preorder();
        Node *postorder();
        Node *inorder();

        BST()
        {
            printf("Initializing BST\n");
        }

        ~BST()
        {
            delete root;
        }

    private:
        Node *insertNode(Node *root, int data);
        Node *deleteNode(Node *root, int data);
        bool searchNode(Node *root, int data);
        int findMax(Node * root);
        Node *preorder(Node *root);
        Node *postorder(Node *root);
        Node *inorder(Node *root);
};


void BST::insertNode(int data)
{
    root = insertNode(root, data);
}

Node *BST::insertNode(Node *root, int data)
{
    // base case 
    if (root == NULL)
    {
        printf("Inserting: %d\n", data);
        return new Node(data);
    }

    if (data > root->data)
    {
        printf("Traversing root->right\n");
        root->right = insertNode(root->right, data);
    }
    else if (data < root->data)
    {
        printf("Traversing root->left\n");
        root->left = insertNode(root->left, data);
    }

    printf("Returning root: %d\n", root->data);
    return root; 
}

void BST::deleteNode(int data)
{   
    root = deleteNode(root, data);
    printf("Root assigned to %d\n", root->data);

}

Node *BST::deleteNode(Node *root, int data)
{
    // 3 cases:
    // Case 1. Delete leaf
    // Case 2. One child
    // Case 3. Two children

    // first traverse to the node we want to delete recursively
    if (root == NULL)
    {
        return NULL;
    }
    else if (root->data > data)
    {
        root->left = deleteNode(root->left, data);
    }
    else if (root->data < data)
    {
        root->right = deleteNode(root->right, data);
    }
    else
    {
        // Case 1
        if (!root->left && !root->right)
        {
            printf("DELETING LEAF\n");
            delete root;
            root = NULL;
            return root;
        }
        // Case 2
        else if (!root->left)
        {
            printf("RETURNING RIGHT CHILD\n");
            printf("Returning root->right: %d\n", root->right->data);
            return root->right;
        }
        else if (!root->right)
        {
            printf("RETURNING LEFT CHILD\n");
            printf("Returning root->left: %d\n", root->left->data);
            return root->left;
        }
        // Case 3
        else
        {
            // find max node in left subtree, replace and delete
            printf("FINDING MAX and replacing root with max node in left subtree\n");
            root->data = findMax(root->left);
            printf("FOUND MAX TO BE %d\n", root->data);
            root->left = deleteNode(root->left, root->data);
        }
    }

    printf("Returning root: %d\n", root->data);
    return root;
}

bool BST::searchNode(int data)
{
    return searchNode(root, data);
}

bool BST::searchNode(Node *root, int data)
{
    if (root == NULL)
    {
        return false;
    }
    else if (root->data > data)
    {
        return searchNode(root->left, data);
    }
    else if (root->data < data)
    {
        return searchNode(root->right, data);
    }
    else
    {
        return true;
    }
}

Node * BST::preorder(Node *root)
{
    if (!root)
    {
        return NULL;
    }
    printf("%d->", root->data);
    preorder(root->left);
    preorder(root->right);
}

Node *BST::preorder()
{
    return preorder(root);
}

// find the largest node in the left subtree to replace
int BST::findMax(Node *root)
{
    while (root->right != NULL)
    {
        root = root->right;
    }

    return root->data;
}

int main()
{
    BST *bst = new BST();
    printf("INSERTING NEW NODE\n");
    printf("-----------------------\n");
    bst->insertNode(4);
    printf("-----------------------\n");
    printf("INSERTING NEW NODE\n");
    printf("-----------------------\n");
    bst->insertNode(2);
    printf("-----------------------\n");
    printf("INSERTING NEW NODE\n");
    printf("-----------------------\n");
    bst->insertNode(5);
    printf("-----------------------\n");
    printf("INSERTING NEW NODE\n");
    printf("-----------------------\n");
    bst->insertNode(7);
    printf("-----------------------\n");
    printf("INSERTING NEW NODE\n");
    printf("-----------------------\n");
    bst->insertNode(6);
    printf("-----------------------\n");
    printf("INSERTING NEW NODE\n");
    printf("-----------------------\n");
    bst->insertNode(3);
    printf("INSERTING NODE\n");
    printf("-----------------------\n");
    bst->insertNode(1);
    printf("-----------------------\n");
    printf("INSERTING NODE\n");
    printf("-----------------------\n");
    bst->preorder();
    printf("Deleting NODE\n");
    printf("-----------------------\n");
    bst->deleteNode(2);
    printf("-----------------------\n");
    bst->preorder();
    bool flag = bst->searchNode(5);
    printf("\nContains 5: %d\n", flag);
    bool flag2 = bst->searchNode(2);
    printf("Contains 2: %d\n", flag2);

}