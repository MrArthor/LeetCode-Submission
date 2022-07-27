class Solution {
public:
    void flatten(TreeNode* root) {
        if (root == NULL || root->left == NULL && root->right == NULL)
        return;
    if (root->left != NULL) {
        flatten(root->left);
        struct TreeNode* tmpRight = root->right;
        root->right = root->left;
        root->left = NULL;
        struct TreeNode* t = root->right;
        while (t->right != NULL) 
            t = t->right;
        t->right = tmpRight;
    }
    flatten(root->right);
    }
};