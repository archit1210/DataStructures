#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        this->data = value;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *create(Node *root)
{
    int data;
    cout << "Enter the data for the node : " << endl;
    cin >> data;

    if (data == -1)
    {
        return NULL;
    }

    root = new Node(data);

    cout << "Enter the data for left of " << root->data << " : " << endl;
    root->left = create(root->left);

    cout << "Enter the data for right of " << root->data << " : " << endl;
    root->right = create(root->right);

    return root;
}

void Inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
}

int main()
{
    Node *root;

    root = create(root);
    Inorder(root);

    return 0;
}