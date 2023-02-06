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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
     vector<vector<int>> v;
map<int , map<int,multiset<int>>> store; 
      queue<pair<TreeNode *,pair<int ,int>>> qu;
      qu.push({root,{0,0}});
      while(!qu.empty())
      {
          TreeNode *node=qu.front().first;
          int vertical=qu.front().second.first;
          int level =qu.front().second.second; 
 qu.pop(); 
          store[vertical][level].insert(node->val);
            
             if(node->left)
             {
               qu.push({node->left , {vertical-1, level+1}});
             }
             if(node->right)
             { 
qu.push({node->right, {vertical+1,level+1}});
             }

      }
          
          for(auto it:store)
          {
            vector<int> s;
            for(auto it1 :it.second)
            {
               s.insert(s.end(),it1.second.begin(),it1.second.end());
            }
            v.push_back(s);
          }
return v;
         
    }
};