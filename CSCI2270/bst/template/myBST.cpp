#include <iostream>
#include "myBST.hpp"
#define COUNT 10 

using namespace std;


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

BST::BST() {

}

BST::~BST() {

}

void BST::insert(int key) {

}

TreeNode* BST::search(int key) {
    return 0;
}

void BST::remove(int key) {

}


TreeNode* BST::searchMin() {
    return 0;
}

void BST::inOrder() {
}

void BST::preOrder() {
}

void BST::postOrder() {
}
