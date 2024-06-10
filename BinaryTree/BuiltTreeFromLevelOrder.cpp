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

void *create(Node *&root)
{
    queue<Node *> q;
    int data;

    cout << "Enter the data for the node : ";
    cin >> data;

    root = new Node(data);
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        int leftData;
        cout << "Enter the data for left of " << temp->data << " : " << endl;
        cin >> leftData;

        if (leftData != -1)
        {
            temp->left = new Node(leftData);
            q.push(temp->left);
        }

        int rightData;
        cout << "Enter the data for right of " << temp->data << " : " << endl;
        cin >> rightData;

        if (rightData != -1)
        {
            temp->right = new Node(rightData);
            q.push(temp->right);
        }
    }
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

    create(root);
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