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
    int maxD = 0;
    map<int,int>mp;

    void dep(TreeNode* root, int depth){
        if(root == NULL){
            return;
        }
        maxD = max(maxD, depth);
        mp[root -> val] = depth;
        dep(root -> left, depth+1);
        dep(root -> right, depth+1);
    }

    TreeNode* solve(TreeNode* root){
        if(root == NULL){
            return NULL;
        }
        if(mp[root -> val] == maxD){
            //last node
            return root;
        }

        TreeNode* leftside = solve(root -> left);
        TreeNode* rightside = solve(root -> right);

        if(leftside != NULL && rightside != NULL){
            return root;
        }
        if(leftside != NULL){
            return leftside;
        }
        return rightside;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        //find the depth
        dep(root,0);

        //function with lca
        return solve(root);

    }
};