#ifndef NODE_HPP
#define NODE_HPP
#include <iostream>

using namespace std;

class node{

	public:
		int data;
		node* right;
		node* left;
		node(const int,node*right=NULL,node* left=NULL);
};
#endif