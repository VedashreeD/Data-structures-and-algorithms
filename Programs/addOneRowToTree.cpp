//C++ Program using queues to insert a value into the mentioned depth, connecting the depth-1 nodes to new_node
//and new node to the child subtrees.
#include<iostream>
#include<queue>

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BinaryTree {
public:
    TreeNode* constructBinaryTree()
    {
        int value;
        std::cout<<"Enter the value for the root node: "<<std::endl;
        std::cin >> value;
        TreeNode* root = new TreeNode(value);

        std::queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) 
        {
            TreeNode* x = q.front();
            q.pop();

            int left_value, right_value;
            std::cout<<"Enter the left child value of "<< x->val << " (or type '-1' if no left child): ";
            std::cin >> left_value;
            if (left_value != -1) 
            {
                x->left = new TreeNode(left_value);
                q.push(x->left);
            }

            std::cout << "Enter the right child value of " << x->val << " (or type '-1' if no right child): ";
            std::cin >> right_value;
            if (right_value != -1) 
            {
                x->right = new TreeNode(right_value);
                q.push(x->right);
            }
        }
        return root;
    }

    TreeNode* addOneRow(TreeNode* root, int value, int depth) 
    {
        //store the child into new_node
        //store new_node into parent
        if(depth == 1)
        {
            TreeNode* new_node = new TreeNode(value);
            new_node->left = root;
            return new_node;
        }
        std::queue<TreeNode*> q;
        q.push(root);
        int d = 1;
        while(!q.empty())
        {
            //if we are one level above the depth level, store the child and new_node 
            if(depth == d + 1)
            {
                //get size of queue
                int s = q.size();
                //for each node in the queue
                for(int i = 0; i < s; i++)
                {
                    //get the node
                    TreeNode* x = q.front();
                    q.pop();
                    TreeNode* new_node_left = new TreeNode(value);
                    new_node_left->left = x->left;
                    x->left = new_node_left;

                    TreeNode* new_node_right = new TreeNode(value);
                    new_node_right->right = x->right;
                    x->right = new_node_right;
                    
                }
                return root;

            }
            //if d is not depth-1, add the left and right subtrees
            d++;
            int s = q.size();
            for(int i = 0; i < s; i++)
            {
                TreeNode* x = q.front();
                q.pop();
                
                if(x->left)
                {
                    q.push(x->left);
                }
                if(x->right)
                {
                    q.push(x->right);
                }  
            }
        }
        return root;
        
    }
    // Function to print the binary tree in a visual format
    void printTree(TreeNode* root, int space = 0, int count = 10)
    {
	//todo:visually print the binary tree
    }
};

int main()
{
    BinaryTree bt;
    int value = 0, depth = 1;
    TreeNode* root = bt.constructBinaryTree();
    bt.printTree(root);
    std::cout<<"Enter the value to be inserted :"<<std::endl;
    std::cin>>value;
    std::cout<<"Enter the depth to insert the value(root starts at depth = 1) :"<<std::endl;
    std::cin>>depth;
    TreeNode* new_root = bt.addOneRow(root, value, depth);
    std::cout<<"New values inserted!"<<std::endl;
    bt.printTree(new_root);

}
