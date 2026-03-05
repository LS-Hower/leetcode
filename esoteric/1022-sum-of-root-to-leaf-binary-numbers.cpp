struct Solution {
    function<int(TreeNode*)> sumRootToLeaf = [](TreeNode* root) { return [](this auto self, TreeNode* root, int acc) -> int { return root == nullptr ? 0 : [self, root](int acc) { return root->left == nullptr && root->right == nullptr ? acc : self(root->left, acc) + self(root->right, acc); }((acc << 1) | root->val); }(root, 0); };
};
