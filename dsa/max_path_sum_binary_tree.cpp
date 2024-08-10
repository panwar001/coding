#include<bits/stdc++.h>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int sum = INT_MIN;
    int maxPath(TreeNode* root, int &sum) {
        if(root == NULL) {
            return 0;
        }
        int l = max(maxPath(root->left, sum),0);
        int r = max(maxPath(root->right, sum),0);

        sum = max(sum, l + r + root->val);
        return root->val + max(l, r);
    }
public:
    int maxPathSum(TreeNode* root) {
        int sum = INT_MIN;
        int k = maxPath(root, sum);
        return max(k,sum);
    }
};

int main(){
  Solution obj;
  struct TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    // Function Call
    cout << "Max Path sum of the given binary tree is "
         << maxPathSum(root);
  return 0;
}
