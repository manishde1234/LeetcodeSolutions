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
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int preStart , int preEnd,int &idx){
        if(preStart > preEnd){
            return NULL;
        }
        int rootval = preorder[idx];
        TreeNode* root = new TreeNode(rootval);
        

        //find root in inorder
        int j = preStart;
        while(inorder[j] != rootval){
            j++;
        }
        idx++;
        
        //call recursion on both half
        root -> left = solve(preorder, inorder, preStart, j-1,idx);
        root -> right = solve(preorder, inorder, j+1, preEnd, idx );

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        int idx = 0;
        return solve(preorder, inorder,0, n-1, idx);
    }
};