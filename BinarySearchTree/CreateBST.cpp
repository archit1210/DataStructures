#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *create(Node *root, int data)
{
    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }
    else if (data > root->data)
    {
        root->right = create(root->right, data);
    }
    else
    {
        root->left = create(root->left, data);
    }

    return root;
}

void takeInput(Node *&root) // Pass root by reference
{
    int data;
    cout << "Enter the data : " << endl;
    cin >> data;

    while (data != -1)
    {
        root = create(root, data); // Assign returned root to the root
        cin >> data;
    }
}

vector<int> levelOrder(Node *root)
{
    vector<int> res;
    if (root == NULL)
        return res; // Check if root is NULL to avoid processing an empty tree

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        res.push_back(it->data);

        if (it->left)
        {
            q.push(it->left);
        }
        if (it->right)
        {
            q.push(it->right);
        }
    }

    return res;
}

void preorder(Node *&root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node *&root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(Node *&root)
{
    if (root == NULL)
    {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main()
{
    Node *root = NULL;

    takeInput(root); // Pass root by reference
    vector<int> ans = levelOrder(root);

    cout << endl
         << "Level Order Traversal" << endl;

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    cout << endl
         << "Pre Order Traversal" << endl;

    preorder(root);
    cout << endl
         << "In Order Traversal" << endl;

    inorder(root);
    cout << endl
         << "Post Order Traversal" << endl;
    postorder(root);
    return 0;
}

/*
Enter the data :
40
35
25
10
45
50
60
-1

Level Order Traversal
40 35 45 25 50 10 60
Pre Order Traversal
40 35 25 10 45 50 60
In Order Traversal
10 25 35 40 45 50 60
Post Order Traversal
10 25 35 60 50 45 40
*/
