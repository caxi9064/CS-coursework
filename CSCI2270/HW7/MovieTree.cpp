#include <iostream>
#include <fstream>
#include "MovieTree.hpp"

using namespace std;

/* ------------------------------------------------------ */

LLMovieNode* getLLMovieNode(int r, std::string t, int y, float q)
{
	LLMovieNode* lmn =new LLMovieNode();
	lmn->ranking = r;
	lmn->title=t;
	lmn->year =y;
	lmn->rating =q;
	lmn->next =NULL;
	return lmn;
}

/* ------------------------------------------------------ */
MovieTree::MovieTree()
{
	root = NULL;
}

void destruct(TreeNode* t)
{
	if (t != NULL)
	{
    	destruct(t->leftChild);
    	destruct(t->rightChild);
    	
    	LLMovieNode* tmp = t->head;
        LLMovieNode* tmp1 = NULL;
        while(tmp != NULL)
        {
            tmp1 = tmp;
            delete tmp1;
            tmp = tmp->next;
        }
        
    	t->head = NULL;
    	delete t;//deleting node on tree
    }
}
MovieTree::~MovieTree()//destructor
{
	destruct(root);
}
/* ------------------------------------------------------ */
void inorderTraversalHelper(TreeNode * root) 
{
	if (root == NULL) {
		return;
	}

	inorderTraversalHelper(root->leftChild);
	cout << root->titleChar << " ";
	inorderTraversalHelper(root->rightChild);
}

void MovieTree::inorderTraversal() {
	inorderTraversalHelper(root);
	cout << endl;
}

/* ------------------------------------------------------ */
TreeNode* searchCharHelper(TreeNode* curr, char key)
{
    if (curr == NULL)
        return curr;
    else if(curr->titleChar == key)
        return curr;
    else if (curr->titleChar > key)
        return searchCharHelper(curr->leftChild, key);
    else
        return searchCharHelper(curr->rightChild, key);
}

TreeNode* MovieTree::searchCharNode(char key)
{
    return searchCharHelper(root, key);
}
void showMovieInOrder(TreeNode* t)
{
	if (t == NULL)
	{
		return;
	}
	else
	{
		LLMovieNode* n = t->head;
		showMovieInOrder(t->leftChild);
		if (n != NULL)
		{
		    cout << "Movies starting with letter: " << t->titleChar << endl;
		}
		while(n != NULL)//print all movies in linked list
		{
			cout << " >> " << n->title << " " << n->rating << endl;
			n = n->next;
		}
		showMovieInOrder(t->rightChild);
	}
}
void MovieTree::showMovieCollection()
{
    if (root == NULL)
    {
        return;
    }
	showMovieInOrder(root);
}

void insert(TreeNode* &t, char c, TreeNode* p, LLMovieNode* movieNode)
{
	if (t == NULL)
	{
		t = new TreeNode();
		t->leftChild = NULL;
		t->rightChild = NULL;
		t->titleChar = c;
		t->parent = p;//setting parent pointer
		t->head = movieNode;//setting head to new node in linked list
		movieNode->next = NULL;
	}
	else if (c > t->titleChar)
	{
		insert(t->rightChild, c, t, movieNode);
	}
	else if (c < t->titleChar)
	{
		insert(t->leftChild, c,t, movieNode);
	}
}

void MovieTree::insertMovie(int ranking, string title, int year, float rating)
{
	TreeNode* foundNode = searchCharNode(title[0]); //find correct title
	LLMovieNode* movieNode = getLLMovieNode(ranking, title, year, rating); //create movie node
	
	if (foundNode == NULL) //if no tree node exists, create a new tree node and set parent pointer
	{
	    TreeNode* parentNode = NULL;
		insert(root, title[0], parentNode, movieNode);
	}
	else
	{	   
		LLMovieNode* temp = foundNode->head;
		if (temp->next == NULL)//only one node in linked list
        {
            if (title > temp->title)
            {
                temp->next = movieNode;
                movieNode->next = NULL;
            }
            else
            {
                movieNode->next = temp;
                temp->next = NULL;
                foundNode->head = movieNode;
            }
        }
        else
        {
            LLMovieNode* prev = NULL;
            while(temp != NULL)
    		{
    		    if (title > temp->title)
    			{
    			    prev = temp;
    				temp = temp->next;
    			}
    			else break;
            }
            if (temp->title > title)//inserting at beginning
    		{
    		    movieNode->next = temp;//adding to LL
    		    foundNode->head = movieNode;
    		}
    		else if (temp == NULL) //inserting at end
    		{
    		    prev->next = movieNode;
    		    movieNode->next = NULL;
    		}
    		else //if inserting at middle
    		{
                prev->next = movieNode;
                movieNode->next = temp;
    		}
                
        }
	}
	
}
void MovieTree::removeMovieRecord(std::string title)
{
	TreeNode* foundNode = searchCharNode(title[0]);
	if (foundNode == NULL)
	{
		cout << "Movie not found." << endl;
	}
	else
	{
		LLMovieNode* curr = foundNode->head;
		LLMovieNode* prev = NULL;
		while(curr != NULL && curr->title != title)
		{
			prev = curr;
			curr = curr->next;
		}

		if (curr->title == title)
		{
			if (curr == foundNode->head)
			{
			    if (curr->next == NULL)//results in empty list
				{
				    foundNode->head = NULL;
				    delete curr;
				}
				else
				{
				    foundNode->head = curr->next;//next node is the head
				    delete curr;
				}
			}
			else 
			{
				prev->next = curr->next;
				delete curr;
			}
		}
		else 
		{
			cout << "Movie not found." << endl;
		}
	}
}     
void MovieTree::leftRotation(TreeNode* curr)
{
    if (curr == 0)//empty tree
	{
		return;
	}
	else if (curr->rightChild == NULL)//no right child
	{
		return;
	}
	else if (curr->parent == NULL)//root node
	{   
		TreeNode* rightNode = curr->rightChild;
		TreeNode* rightNodeLeft = rightNode->leftChild;
		
		curr->parent = rightNode;//setting parent pointer
		rightNode->leftChild = curr; //left child of parent is now curr
		curr->rightChild = rightNodeLeft;
		
		if (rightNodeLeft != NULL)
		{
		    rightNodeLeft->parent = curr;
		}
		root = rightNode;
		rightNode->parent = NULL;//setting parent pointer of rightNode
	}
	else
	{
	    TreeNode* rightCurr = curr->rightChild;
		TreeNode* rightCurrLeft = rightCurr->leftChild;
		
		rightCurr->parent = curr->parent;//setting parent pointers 
		curr->parent = rightCurr;
		curr->rightChild = rightCurrLeft; 
		rightCurr->leftChild = curr;
		
		rightCurr->parent->rightChild = rightCurr;//setting parent pointer right child
	}
}