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
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        
        // Sanitation, if empty, just create and return new node
        if (root == nullptr)
        {
            return new TreeNode(val);
        }





        // Keep going until we find the bottom of the tree, going left/right as we need to
        if ( (val < root->val) && root->left != nullptr)
        {
            insertIntoBST(root->left, val);
            return root;
        }

        if (val > root->val && root->right != nullptr)
        {
            insertIntoBST(root->right, val);
            return root;
        }

        // At this point, we have reached the bottom of tree (right and left == null ptr)
        // Check if we make this new node the left or right child

        if (val < root->val)
        {
            root->left = new TreeNode(val);
        }

        else
        {
            root->right = new TreeNode(val);
        }

        return root;

    }
};
