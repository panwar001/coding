class Solution {
    int diameter(TreeNode* root, int &d) {
        if(root == NULL) {
            return 0;
        }
        int l = diameter(root->left, d);
        int r = diameter(root->right, d);

        d = max(d, l+r);
        return 1 + max(l,r);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {

        int d = 0;
        diameter(root, d);
        return d;
        
    }
};
