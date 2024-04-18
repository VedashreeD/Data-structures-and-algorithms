//Program to print the lexicographically smallest string that starts at a leaf of this tree and ends at the root, using queue to insert and dfs algorithm.
#include<iostream>
#include<string>
#include<queue>
#include<algorithm>

struct TreeNode 
{
    std::string val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(std::string x) : val(x), left(nullptr), right(nullptr) {}
 };

class StringTree 
{
private:
	std::vector<std::string> res;
public:
    TreeNode* constructStringTree()
    {
	std::string value;
        std::cout<<"Enter the value for the root node: "<<std::endl;
        std::cin >> value;
        TreeNode* root = new TreeNode(value);

        std::queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) 
        {
            TreeNode* x = q.front();
            q.pop();

	    std::string left_value, right_value;
            std::cout<<"Enter the left child value of "<< x->val << " (or type \"None\" if no left child): ";
            std::cin >> left_value;
            if (left_value != "None") 
            {
                x->left = new TreeNode(left_value);
                q.push(x->left);
            }

            std::cout << "Enter the right child value of " << x->val << " (or type \"None\" if no right child): ";
            std::cin >> right_value;
            if (right_value != "None") 
            {
                x->right = new TreeNode(right_value);
                q.push(x->right);
            }
        }
        return root;
    }

    void stringCheck(TreeNode* root, std::string ans)
    {
        //base case
        if(root == NULL)
        {
            return;
        }
        //end case
        if(root->left == NULL && root->right == NULL)
        {
            //convert to string
            ans += root->val;
            //convert to leaf to root->node values
	    std::reverse(ans.begin(), ans.end());
            res.push_back(ans);
            return;
        }
        //logic and traversal
        ans += root->val;
        stringCheck(root->left, ans);
        stringCheck(root->right, ans);

    }

    std::string smallestFromLeaf(TreeNode* root) 
    {
	std::string ans;
        stringCheck(root, ans);
        sort(res.begin(), res.end());
        return res[0];
        
    }
    void printTree(TreeNode* root)
    {
	//todo: add visual print for tree	
    }
};

int main()
{
    StringTree stree;
    TreeNode* root = stree.constructStringTree();
    stree.printTree(root);
    std::string result = stree.smallestFromLeaf(root);
    std::cout<<"The lexicographically smallest string in the tree : "<<result<<std::endl;
    return 0;
}
