#ifndef AVL_HPP
#define AVL_HPP
#include <iostream>
#include "node.hpp"
#include "stack.hpp"
#include <cmath>
using namespace std;

class avl{
	private:
		node* root;
		int treenum; //ağaç numarası
		int avlvalue=0; //yaprakları dışında düğüm değerleri toplamı
		int height(node*);
		node* searchAndAdd(node*,int);
		node* swapWithright(node*);
		node* swapWithleft(node*);
		void delnode(node*&);
		void postorderWithLeaf(node*,stack*&);
	public:
		 avl(int);
		 bool isEmpty();
		 void add(int);
		 int height();
		 void postorderWithLeaf(stack*& );
		 int getTreenum ()const;
		 int getValue();
		~avl();
	
};
#endif
 