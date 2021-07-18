#include <iostream>
#include "myBST.hpp"
#define COUNT 10 

using namespace std;

void _insert(TreeNode* &T, int key);
void _destructBST(TreeNode *T);
TreeNode* _search(TreeNode* T, int key);
void _remove(TreeNode* &T, int key);
void _prettyPrint(TreeNode* T, int space);
TreeNode* _searchMin(TreeNode* T);
void _inOrder(TreeNode* T);
void _preOrder(TreeNode* T);
void _postOrder(TreeNode* T);


BST::BST() {
    root = 0;
}

void _destructBST(TreeNode *T) {
  if (T == 0) return;
    else {
        _destructBST(T->left);
        _destructBST(T->right);
        delete T;
    }
}

BST::~BST() {
    _destructBST(root);
}


void _insert(TreeNode* &T, int key) {
    if (T == 0) {
        T = new TreeNode();
        T->key = key;
        T->left = 0;
        T->right = 0;
    } 
    else if (key < T->key) _insert(T->left, key);
    else _insert(T->right, key);
}

void BST::insert(int key) {
    _insert(root, key);
}

TreeNode* _search(TreeNode* T, int key) {
    if (T == 0) return 0;
    else if (key == T->key) return T;
    else if (key < T->key) return _search(T->left, key);
    else return _search(T->right, key);
}

TreeNode* BST::search(int key) {
    return _search(root, key);
}

void _remove(TreeNode* &T, int key) {
    if (T == 0) return;
    else if (key < T->key) _remove(T->left, key);
    else if (key > T->key) _remove(T->right, key);
    else {
        if (T->left == 0  && T->right == 0) {
            delete T;
            T = 0;
        }
        else if (T-> left == 0 && T->right != 0) {
            TreeNode* child = T->right;
            delete T;
            T = child;
        }
        else if (T-> left != 0 && T->right == 0) {
            TreeNode* child = T->left;
            delete T;
            T = child;
        }
        else {
            T->key = _searchMin(T->right)->key;
            _remove(T->right, T->key);
        }
    }
}

void BST::remove(int key) {
    _remove(root, key);
}

void _prettyPrint(TreeNode* T, int space)                                                                                                                                         
{                                                                                                                                                                                 
  // Base case                                                                                                                                                                    
  if (T == 0) return;                                                                                                                                                             
                                                                                                                                                                                  
    // Increase distance between levels                                                                                                                                           
  space += COUNT;                                                                                                                                                                 
                                                                                                                                                                                  
  // Process right child first                                                                                                                                                    
  _prettyPrint(T->right, space);                                                                                                                                                   
                                                                                                                                                                                  
  // Print current node after space                                                                                                                                               
  // count                                                                                                                                                                        
  printf("\n");                                                                                                                                                                   
  for (int i = COUNT; i < space; i++)                                                                                                                                             
    printf(" ");                                                                                                                                                                  
  printf("%d\n", T->key);                                                                                                                                                         
                                                                                                                                                                                  
  // Process left child                                                                                                                                                           
  _prettyPrint(T->left, space);                                                                                                                                                    
}                                                                                                                                                                                 
                                                                                                                                                                                  
void BST::prettyPrint()                                                                                                                                                           
{                                                                                                                                                                                 
  _prettyPrint(root, 1);                                                                                                                                                           
}  

TreeNode* _searchMin(TreeNode* T) {
    if (T == 0) return 0;
    else if (T->left == 0) return T;
    else return _searchMin(T->left);
}

TreeNode* BST::searchMin() {
    return _searchMin(root);
}

void _inOrder(TreeNode* T) {
    if (T == 0) {
        return;
    }
    else {
        _inOrder(T->left);
        cout << T->key << " ";
        _inOrder(T->right);
    }
}

void BST::inOrder() {
    _inOrder(root);
}

void _preOrder(TreeNode* T) {
    if (T == 0) {
        return;
    }
    else {
        cout << T->key << " ";
        _preOrder(T->left);
        _preOrder(T->right);
    }
}

void BST::preOrder() {
    _preOrder(root);
}


void _postOrder(TreeNode* T) {
    if (T == 0) {
        return;
    }
    else {
        _postOrder(T->left);
        _postOrder(T->right);
         cout << T->key << " ";
    }
}

void BST::postOrder() {
    _postOrder(root);
}
