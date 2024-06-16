#include<iostream>
#include<vector>

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution 
{
public:
    void solve(TreeNode* root, int targetSum, int &count,std::vector<int> path)
    {
        if(root==NULL)
            return;
        //add current value to path
        path.push_back(root->val);
	//traverse from parent to child nodes
        solve(root->left,targetSum,count,path);
        solve(root->right,targetSum,count,path);
        //get current path size
        int size=path.size();
        long sum=0;
        //get the sum of the current path from root to leaf
        for(int i=size-1;i>=0;i--)
        {
            sum+=path[i];
            if(sum==targetSum)
            {
                count++;
            }
        }
        //remove the path and move to next path
        path.pop_back();
    }
    
    int pathSum(TreeNode* root, int targetSum) 
    {
        std::vector<int> path;
        int count = 0;
        solve(root, targetSum, count, path);
        return count;
    }
    
    TreeNode* buildTreeDFS() 
    {
        int val;
        std::cout<<"Enter current node value or -1 for no node: ";
        std::cin >> val;
        
        if (val == -1) 
        {
            return nullptr;
        }
        //create new node with given value
        TreeNode* root = new TreeNode(val);
        
        std::cout<<"Enter left child of "<<val<<":"<<std::endl;
        root->left = buildTreeDFS();
        
        std::cout<<"Enter right child of "<<val<<":"<<std::endl;
        root->right = buildTreeDFS();
        
        return root;
    }
};

int main()
{
    Solution s;
    TreeNode* root = s.buildTreeDFS();
    int targetSum = 0;
    std::cout<<"Enter the required target sum from paths : "<<std::endl;
    std::cin>>targetSum;
    std::cout<<"The number of paths where target sum is found :"<<s.pathSum(root, targetSum)<<std::endl; 
    return 0;
}
