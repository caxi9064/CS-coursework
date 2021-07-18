#include "MovieTree.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

// Helper function: Create new node using provided args
MovieNode* getMovieNode(int rank, string t, int y, float r) {
    MovieNode* nn = new MovieNode;
    nn->title = t;
    nn->ranking = rank;
    nn->year = y;
    nn->rating = r;
    return nn;
}

MovieTree::MovieTree() {
  root = NULL;
}


void traverseInOrder(MovieNode*node)
{
  if (node == NULL)
  {
    return;
  }
  else
  {
    traverseInOrder(node->left);
    cout << "Movie: " << node->title << " (" << node->rating << ")" << endl;//print title
    traverseInOrder(node->right);

  }
}
void MovieTree::printMovieInventory() {
  MovieNode* temp = root;
  if (temp == NULL)
  {
    cout << "Tree is empty. Cannot print. " << endl;
    return;
  }
  else
  {
    //traverse entire tree
    //get movie title
    traverseInOrder(root);
  }
}
void add(MovieNode* &node, int ranking, string title, int year, float rating)
{
  if (node == NULL)
  {
    node = getMovieNode(ranking, title, year, rating);
  }
  //if new title is smaller then it is in the left subtree
  //else if it is greater then in right subtree 
  else if (title < node->title)
  {
    add(node->left, ranking, title, year, rating);
  }
  else
  {
    add(node->right, ranking, title, year, rating);
  }
}
void MovieTree::addMovieNode(int ranking, string title, int year, float rating) {
  add(root, ranking, title, year, rating);
}

void find(MovieNode* node, string title)
{
  if (node == NULL)
  {
    cout << "Movie not found. " << endl;
  }
  else if (title == node->title)//base case
  {
    cout << "Movie Info:" << endl << "==================" << endl << "Ranking:" << node->ranking << endl << "Title  :" << node->title << endl << "Year   :" << node->year << endl << "Rating :" << node->rating << endl;
  }
  else if (title < node->title)//search in left subtree if smaller
  {
    find(node->left, title);
  }
  else 
  {
    find(node->right, title);
  }
}
void MovieTree::findMovie(string title) {
  find(root, title);
}


void query(MovieNode* node, float rating, int year)
{
  if (node == NULL)
  {
    return;
  }
  else 
  {
    //traverse in preorder 
    if (node->year > year && node->rating >= rating)
    {
      cout << node->title << " (" << node->year << ") " << node->rating << endl;
    }
    query(node->left, rating, year);
    query(node->right, rating, year);

  }
}
void MovieTree::queryMovies(float rating, int year) {
  if (root == NULL)
  {
    cout << "Tree is Empty. Cannot query Movies. " << endl;
  }
  else
  {
    cout << "Movies that came out after " << year << " with rating at least " << rating << ":" << endl;
    query(root, rating, year);
  }
  
}
void traversePostOrder(MovieNode* node, float &sum, float &count)
{
  if (node == NULL)
  {
    return;
  }
  else
  {
    traversePostOrder(node->left, sum, count);
    traversePostOrder(node->right, sum, count);
    sum += node->rating;
    count++;
  } 
}
void MovieTree::averageRating() {
  float sum,count = 0;
  if (root == NULL)
  {
    cout << "Average rating:0.0" << endl;
    return;
  }
  traversePostOrder(root, sum, count);
  cout << "Average rating:" << sum/count << endl;
}

void findHeight(MovieNode* node, int level, int &count)
{
  //note: recursion in binary trees, several copies of countNode is being executed in each subtree and adding to total count
  if (node == NULL)
  {
    return;
  }
  else
  { 
    count++;
    findHeight(node->left, level, count);
  }
}
void printLevel(MovieNode*node, int level, int temp)
{
  if (node == NULL)
  {
    return;
  }
  else if (level == temp)
  {
    cout << "Movie: " << node->title << " (" << node->rating << ")" << endl;
  }
  else
  {
    temp++;
    printLevel(node->left, level, temp);
    printLevel(node->right, level, temp);
  }

}
void MovieTree::printLevelNodes(int level){
  //find max of each tree
  int count, temp = 0; //count root node
  findHeight(root, level, count);  
  if(level > count)
  {
    return;
  }
  else
    printLevel(root, level, temp);
}


