#pragma once
#include<iostream>
using namespace std; 

struct TreeNode {
    int key;
    TreeNode* left;
    TreeNode* right;
};

class BST {
    private:
        TreeNode* root;

    public:
        BST();
        ~BST();
        
        void insert(int key);
        TreeNode* search(int key);
        void remove(int key);

        TreeNode* searchMin();
        
        void inOrder();
        void preOrder();
        void postOrder();

        void prettyPrint(); 
};
