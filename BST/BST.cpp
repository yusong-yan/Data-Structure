#include "BST.hpp"
#include <iostream>

using namespace std;
//private
BST::TreeNode* BST::insert(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (root->val > val){
        if (root->left)
            insert(root->left, val);
        else
            root->left = new TreeNode(val);
    }else if (root->val < val){
        if (root->right)
            insert(root->right, val);
        else
            root->right = new TreeNode(val);
    }
    return root;
}

BST::TreeNode* BST::search(TreeNode* root, int val){
    if (!root)
        return nullptr;
    if (root->val > val)
        return search(root->left, val);
    if (root->val)
        return search(root->right, val);
    return root;
}

BST::TreeNode* BST::successor(TreeNode* root, TreeNode* p) {
    int pval = p->val;
    TreeNode* cur = root;
    TreeNode* prev = nullptr;
    while(cur){
        if (cur->val > pval){
            prev = cur;
            cur= cur->left;
        }else if (cur->val <= pval){
            cur= cur->right;
        }
    }
    return prev;
}

BST::TreeNode* BST::predecessor(TreeNode* root, TreeNode* p) {
    int pval = p->val;
    TreeNode* cur = root;
    TreeNode* prev = nullptr;
    while(cur){
        if (cur->val >= pval){
            cur= cur->left;
        }else if (cur->val < pval){
            prev = cur;
            cur= cur->right;
        }
    }
    return prev;
}

void BST::deleteAll(TreeNode* root){
    if (!root) return;
    deleteAll(root->left);
    deleteAll(root->right);
    delete root;
}

BST::TreeNode* BST::deleteNode(TreeNode* root, int key) {
    if (!root) return nullptr;
    if (root->val > key) {
        root->left = deleteNode(root->left, key);
    }else if (root->val < key){ 
        root->right =deleteNode(root->right,key);
    }else if (root->left && root->right){
        TreeNode* pre = predecessor(root, root);
        root->val = pre->val;
        root->left = deleteNode(root->left, root->val); 
    }else{
        TreeNode* temp = root;
        if (root->left && !root->right)
            root = root->left;
        else if (root->right && !root->left)
            root = root->right;
        else
            root = nullptr;
        delete temp; 
    }
    return root; 
}



void BST::deleteNode (int key){
    deleteNode(this->r, key);
}
//public
bool BST::search(int key){
    if (!search(this->r, key))
        return false;
    return true;
}

void BST::insert (int key){
    if (!this->r) this->r = new TreeNode(key);
    else insert(this->r, key);
}

int BST::successor(int key){
    TreeNode* target = search(this->r, key);
    if (!target)
        return INT_MIN;
    else
        return successor(this->r, target)->val;
}
int BST::predecessor(int key){
    TreeNode* target = search(this->r, key);
    if (!target)
        return INT_MAX;
    else
        return predecessor(this->r, target)->val;
}

BST::~BST(){
    deleteAll(this->r);
}



