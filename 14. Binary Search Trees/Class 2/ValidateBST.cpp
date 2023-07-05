/*

*/

bool flag = true;
    void solve(TreeNode* root, long long int a, long long int b){
        if(root == NULL)
            return;
        
        if(flag == false)
            return;
        
        if(root->val< b && root->val >a){
        }
        else{
            flag = false;
        }
        solve(root->left, a, root->val);
        solve(root->right, root->val, b);

        
    }
    bool isValidBST(TreeNode* root) {
        long long int a = -4294967296;
        long long int b = 4294967296;
        solve(root, a, b);
        return flag;
    }