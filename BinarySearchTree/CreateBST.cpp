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

int main()
{
    Node *root = NULL;

    takeInput(root); // Pass root by reference
    vector<int> ans = levelOrder(root);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}
