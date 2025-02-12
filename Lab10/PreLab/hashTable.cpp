/* 
	Name: Pyung Lee
	Email ID: pkl4fr
	Date: 4/15/2020
	File Name: hashTable.cpp
*/

#include "hashTable.h"
#include "huffmanNode.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

HashTable::HashTable(){
  myHashTable = vector<huffmanNode*>(256);
}


int HashTable::hashFunction(char c) {
  return (int)c % 256;
}


void HashTable::insert(char c) {
  int index = hashFunction(c);

  if(myHashTable[index] == NULL)  {
    huffmanNode* node = new huffmanNode(c, 1);
    myHashTable[index] = node ;
  }
  else {
     int freq = myHashTable[index]->frequency; 
     freq = freq+1;
     myHashTable[index]->frequency = freq;
  }
 
}


bool HashTable::find(char c){ 
  int index = hashFunction(c);

  if(myHashTable[index] == NULL) {
    return false;
  }
  else {
    return true;
  }
}

int HashTable::getValue(char c){
  int index = hashFunction(c);
  return myHashTable[index]->frequency;

}

huffmanNode* HashTable::getNodePointer(char c){
  int index = hashFunction(c);
  return myHashTable[index];
  

}
