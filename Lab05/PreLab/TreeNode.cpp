/* 
	Name: Pyung Lee
	Email ID: pkl4fr
	Date: 2/25/2020
	File Name: TreeNode.cpp
*/
// TreeNode.cpp:  Tree Node method implementations
// CS 2150: Lab 5

#include "TreeNode.h"

// Default Constructor - left and right are NULL, value '?'
TreeNode::TreeNode() {
    value = "?";
    left = NULL;
    right = NULL;
}

// Constructor - sets value to val
TreeNode::TreeNode(const string& val) {
    value = val;
    left = NULL;
    right = NULL;
}
