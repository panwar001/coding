#include<bits/stdc++.h>
using namespace std;

// Structure of a Binary Tree Node
struct Node {
    int data;
    struct Node *left, *right;
    Node(int v)
    {
        data = v;
        left = right = NULL;
    }
};

// pre-order traversal
class Solution {

    void preorder(Node* root, vector<int>& res) {
        if (root ==  NULL) {
            return ;
        }
        res.push_back(root->data);
        cout << root->data << " " ;
        preorder(root->left, res);
        preorder(root->right, res);
    }
public:
    vector<int> preorderTraversal(Node* root) {
        vector<int> res;
        preorder(root, res);
        return res;
    }
};

// Driver code
int main()
{
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    Solution obj;
    
    // Function call
    cout << "Preorder traversal of binary tree is: \n";
    obj.preorderTraversal(root);

    return 0;
}
