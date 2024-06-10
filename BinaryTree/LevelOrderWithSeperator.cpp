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
        this->left = nullptr;
        this->right = nullptr;
    }
};

Node *create(Node *root)
{
    int data;

    cout << endl;

    cout << "Enter the data for the node : ";
    cin >> data;

    if (data == -1)
    {
        return nullptr;
    }

    root = new Node(data);

    cout << "Enter the data for the left of " << root->data << " : ";
    root->left = create(root->left);

    cout << endl;

    cout << "Enter the data for the right of " << root->data << " : ";
    root->right = create(root->right);

    return root;
}

void LevelOrder(Node *root)
{
    queue<Node *> q;

    q.push(root);
    q.push(nullptr);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(nullptr);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }

            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}
int main()
{
    Node *root;

    root = create(root);

    LevelOrder(root);

    return 0;
}

/*
          1
        /   \
      2       3
     / \     / \
    4   5   6   7
   / \ / \ / \ / \
  8  9 10 11 12 13 14 15

Expected Output
1
2 3
4 5 6 7
8 9 10 11 12 13 14 15

*/