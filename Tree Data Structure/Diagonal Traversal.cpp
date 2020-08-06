----------------Using Map----------------------

/*void print(TreeNode * root,int d ,map<int, vector<int>>&diagonal)
{
    if(!root)
        return ;
    
    diagonal[d].push_back(root->val);
    print(root->left,d+1,diagonal);
    print(root->right,d,diagonal);
}
vector<int> Solution::solve(TreeNode* A) 
{
    vector<int>res;
     map<int, vector<int>>diagonal; 
     
     print(A,0,diagonal);
     
      for(auto it =diagonal.begin() ;it!=diagonal.end();it++) 
        { 
            for(auto itr = it->second.begin();itr != it->second.end(); ++itr) 
                res.push_back(*itr); 
        } 
    return res;
}*/

------------------------Using queue--------------------------
vector<int> Solution::solve(TreeNode* root) 
{
    
    if(!root)
        return {};
    queue<TreeNode* >q;
    vector<int>res;
    TreeNode* cur;
    q.push(root);
    while(!q.empty())
    {
        cur=q.front();
        q.pop();
        
        while(cur)
        {
            if(cur->left)
                q.push(cur->left);
             res.push_back(cur->val);
             cur=cur->right;
        }
    }
   return res;
}
