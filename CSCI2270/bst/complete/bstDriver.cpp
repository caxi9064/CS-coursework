#include<iostream>
#include "myBST.hpp"
using namespace std;

int main() {
    BST* T;
    T->insert(22);
    T->insert(11);
    T->insert(44);
    T->insert(33);
    T->insert(2);

    T->prettyPrint();

    cout << " ---------------------------------------" << endl;
    T->remove(22);
    T->prettyPrint();

cout << " ---------------------------------------" << endl;
    T->remove(11);
    T->prettyPrint();

    cout << " ---------------------------------------" << endl;
    T->remove(44);T->remove(33);T->remove(2);
    T->prettyPrint();

     cout << " ---------------------------------------" << endl;
       T->remove(44);T->remove(33);T->remove(2);
    T->prettyPrint();

    T->insert(22);
    T->insert(11);
    T->insert(44);
    T->insert(33);
    T->insert(2);
        T->prettyPrint();


    cout << " ---------------------------------------" << endl;

        T->inOrder();
    cout << " ---------------------------------------" << endl;
        T->preOrder();

    cout << " ---------------------------------------" << endl;
        T->postOrder();

    cout << " ---------------------------------------" << endl;

        
    return 0;
}