#include <iostream>
#include <queue>
using namespace std;

// Define TreeNode structure
struct TreeNode 
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to implement preorder DFS
void preorder(TreeNode* node) 
{
    if (node == NULL) 
    {
        return;
    }

    std::cout<<node->val<<" ";
    preorder(node->left);
    preorder(node->right);
}

// Function to implement inorder DFS
void inorder(TreeNode* node) 
{
    if (node == NULL) 
    {
        return;
    }

    inorder(node->left);
    std::cout<<node->val<<" ";
    inorder(node->right);
}

// Function to implement postorder DFS
void postorder(TreeNode* node) 
{
    if (node == NULL) 
    {
        return;
    }

    postorder(node->left);
    postorder(node->right);
    std::cout<<node->val<<" ";
}


TreeNode* buildTree() 
{
    // Ex, Build binary tree:
    //       1
    //      / \
    //     2   3
    //    / \
    //   4   5

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    return root;
}

int main() 
{
    TreeNode* root = buildTree();

    std::cout<<"Preorder traversal: ";
    preorder(root);
    std::cout<<std::endl;

    std::cout<<"Inorder traversal: ";
    inorder(root);
    std::cout<<std::endl;

    std::cout<<"Postorder traversal: ";
    postorder(root);
    std::cout<<endl;

    return 0;
}

