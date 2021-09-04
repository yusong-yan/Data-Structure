#ifndef TRIES
#define TRIES

class BST{
public:
    ~BST();
    bool search(int key);
    int successor(int key);
    int predecessor(int key);
    void insert (int key);
    void deleteNode (int key);
    
    

private:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };
    TreeNode* insert(TreeNode* root, int val);
    TreeNode* search(TreeNode* root, int val);
    TreeNode* successor(TreeNode* root, TreeNode* target);
    TreeNode* predecessor(TreeNode* root,TreeNode* target);
    TreeNode* deleteNode(TreeNode* root, int key);
    void deleteAll(TreeNode* root);
    TreeNode* r = nullptr;

};



#endif 