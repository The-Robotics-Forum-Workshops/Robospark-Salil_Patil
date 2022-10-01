#include <iostream>

using namespace std;


struct Node {  
    int data;  
    Node *left;  
    Node *right;  
};  
Node* create(int item)  
{  
    Node* node = new Node;  
    node->data = item;  
    node->left = node->right = NULL;  
    return node;  
}  
/*Inorder traversal of the tree formed*/  
void inorder(Node *root)  
{  
    if (root == NULL)  
        return;  
    inorder(root->left); //traverse left subtree  
    cout<< root->data << "   "; //traverse root node  
    inorder(root->right); //traverse right subtree  
}  
Node* findMinimum(Node* cur) /*To find the inorder successor*/  
{  
    while(cur->left != NULL) {  
        cur = cur->left;  
    }  
    return cur;  
}  

Node* insertion(Node* root, int item) /*Insert a node*/  
{  
    if (root == NULL)  
        return create(item); /*return new node if tree is empty*/  
    if (item < root->data)  
        root->left = insertion(root->left, item);  
    else  
        root->right = insertion(root->right, item);  
    return root;  
}  
void search(Node* &cur, int item, Node* &parent)  
{  
    while (cur != NULL && cur->data != item)  
    {  
        parent = cur;  
        if (item < cur->data)  
            cur = cur->left;  
        else  
            cur = cur->right;  
    }  
} 

int main()
{

  Node* root = NULL;  
  root = insertion(root, 10);  
  root = insertion(root, 33);  
  root = insertion(root, 24);  
  root = insertion(root, 77);  
  root = insertion(root, 66);  
  root = insertion(root, 15);  
  root = insertion(root, 9);  
  root = insertion(root, 89);  
  printf("The inorder traversal of the given binary tree is - \n");  
  inorder(root);

    return 0;
}

