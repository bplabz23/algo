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
    TreeNode* searchBST(TreeNode* root, int val) {
        
        TreeNode *left_result = nullptr;
        TreeNode *right_result = nullptr;

        cout << root->val << " ";

        // If this node has our value
        if (root->val == val)
        {
            return root;        // Return this node
        }


        // Otherwise, we need to search our left and right children until we get to the bottom of this tree

        if (root->left != nullptr)
        {
            // If we are not at left-most value, keep going, search the left subtree
            left_result = searchBST(root->left, val);  
        }

        if (root->right != nullptr)
        {
            // If we are not at right-most child keep going, search the right subtree
            right_result = searchBST(root->right, val);    
        }


        // If our search of the left or right subtree finds a match, return it
        if (left_result != nullptr)
        {
            return left_result;
        }

        if (right_result != nullptr)
        {
            return right_result;
        }

        // otherwise, return null
        return nullptr;
    }
};
