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
    // void inorder(TreeNode* root, vector<int> &arr) {
    //     if(root == NULL) {
    //         return ;
    //     }
    //     inorder(root->left, arr);
    //     arr.push_back(root->val);
    //     inorder(root->right, arr);
    // }
    void inorder(TreeNode* root, int &count, int k, int &kLargest) {
        if(root == NULL ) {
            return ;
        }

        inorder(root->left, count, k, kLargest);
        count = count + 1;
        if(k == count) {
            kLargest = root->val;
            return;
        }
        inorder(root->right, count, k, kLargest);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> arr;
       // inorder(root, arr);
       int kLargest = 0;
       int count = 0;
       inorder(root, count, k, kLargest);
       return kLargest;
    }
};
