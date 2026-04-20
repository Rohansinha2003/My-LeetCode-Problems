class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Case 1: both null
        if (p == NULL && q == NULL) return true;
        
        // Case 2: one null or values different
        if (p == NULL || q == NULL || p->val != q->val) return false;
        
        // Case 3: check left and right subtree
        return isSameTree(p->left, q->left) && 
               isSameTree(p->right, q->right);
    }
};