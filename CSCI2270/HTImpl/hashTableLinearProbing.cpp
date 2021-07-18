#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include <math.h>

using namespace std;

struct HashNode {
  string key;
  string value;
  
  HashNode() {key = ""; value = "";}
  HashNode(string k, string v) {key = k; value = v;}
  ~HashNode() {}
};

class HashTable {
  HashNode** table;
  int size;

public:
  HashTable() {
    size = 10;
    table = new HashNode *[10];
    for (int i = 0; i < size; i++) table[i] = 0;
  }

  HashTable(int s) {
    size = s;
    table = new HashNode *[s];
    for (int i = 0; i < size; i++) table[i] = 0;
  }

  ~HashTable() {delete[] table;}

  void insert(string key, string value) {
    HashNode* node = new HashNode(key, value);
    int index = hashCode(key, size);
    
    if (table[index] == 0)  table[index] = node;
    else if (table[index]->key == key) {
      cerr << "Key in use with value:" << table[index]->value << " \n"; 
    }
    else {
      for (int i = (index+1)%size; i != index; i = (i+1)%size) {
	if (table[i] == 0) {
	  table[i] = node;
	  return;
	}
	else if (table[i]->key == key) {
	  cerr << "Key already in use with value:" << table[index]->value << " \n";
	  return;
	}
      }
      cerr << "Can not insert (" << key << ", "<< value <<")Table is full" << endl;
      return;
    } 
  }

  void remove(string key) {
    int index = hashCode(key, size);
    if (table[index] == 0) return;
    else if (table[index]->key == key) {
      delete table[index];
      table[index] = 0;
      return;
    }
    else {
      for (int i = (index+1)%size; i != index; i = (i+1)%size) {
	if (table[i] == 0)  return;
	else if (table[i]->key == key) {
	  delete table[i];
	  table[index] = 0;
	  return;
	}
      }
      return;
    }
  }
  
  HashNode* search(string key) {
    int index = hashCode(key, size);
    if (table[index] == 0)  return 0;
    else if (table[index]->key == key) return table[index];
    else {
      for (int i = (index+1)%size; i != index; i = (i+1)%size) {
	if (table[i] == 0)  return 0;
	else if (table[i]->key == key) return table[i];
      }
      return 0;
    }
  }
  
  int hashCode(string k, int table_size) {
    int hash = 0;

    for (int i = 0; i< k.length();  i++) 
      hash = hash + k[i];
    
    return hash % table_size;
  }

  /******************************************************************************
   *
   *  1. Given a key k (k is a string), generate the sum of the ASCII values
   *      for the characters in k.
   *  2. Multiply k by a constant A, where 0 < A < 1.
   *  3. Store the fractional part of kA.
   *  4. Multiply fractional part of kA by a constant, m, and take the floor of the result.”
   *
   *********************************************************************************/

  int hashCode2(string k, int table_size) {
    int hash = 0;
    double A = 13/32;
    double hA;
    int m = 1024;
    
    for (int i = 0; i< k.length();  i++) 
      hash = hash + k[i];
    
    hA = hash * A;

    double fractpart, intpart;
    //get the fractional part of hash 
    fractpart = modf (hA , &intpart);

    fractpart = fractpart*m;
    hash = floor(fractpart);
    return hash % table_size;
  }


  void printHashTable() {
    for (int i = 0; i < size; i++) {
      if (table[i] != 0) {
	cout << "[" << i << "] -> Key: " << table[i]->key << " (#" << hashCode(table[i]->key, size)<< ") Value: " << table[i]->value<< endl; 
      }
      else {
	cout << "[" << i << "] -> Empty" << endl;
      }
    }
  }
};

int main(int argc, char* argv[]) {

  if (argc != 2) return 0;
  
  HashTable HT(20);
  
  ifstream file(argv[1]);
  string line; 

  while(getline(file,line))
    {
      stringstream  linestream(line);
      string key;
      string value;
      
      getline(linestream, key,',');
      getline(linestream, value, '\n');

      HT.insert(key, value);
    }
  

  //  HT.remove("Ashutosh Trivedi");
  
  string name1= "Prathyusha Gayam";
    
  if (HT.search(name1) == 0) cout << name1 << ": Key not found" << endl;
  else cout << "Key: " << name1 << " has value:" << HT.search(name1)->value;

  name1= "Ashutosh Trivedi";
    
  if (HT.search(name1) == 0) cout << name1 << "key not found" << endl;
  else cout << "Key: " << name1 << " has value:" << HT.search(name1)->value << endl;
  
    
  HT.printHashTable();
  
  return 0;
}
