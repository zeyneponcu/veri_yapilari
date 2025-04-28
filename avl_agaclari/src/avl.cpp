/*
 *@file				(avl ağacı)
 *@description		(Genel avl methodları dışında yaprakları postorder dolaşan fonksiyon,ağacın numarasını ve değerini döndüren fonksiyon var)
 *@course			(2. Öğretim A Grubu)
 *@assignment		(2.ödev)
 *@date				(11.12.2023-16.12.2023)
 *@author			(Zeynep Sude Öncü /zey.su.oncu@gmail.com)
 */
 
#ifndef AVL_CPP
#define AVL_CPP
#include <iostream>
#include "node.hpp"
#include "stack.hpp"
#include "avl.hpp"
#include <cmath>

using namespace std;

		int avl::height(node* itr){
			if(itr==NULL) return -1;
			return 1+ max(height(itr->left),height(itr->right));
		}
		node* avl::searchAndAdd(node* itr,int data){
			if(itr==NULL) {
				itr=new node(data);
				avlvalue+=data;
				}	
			else if(data<itr->data){
				itr->left=searchAndAdd(itr->left,data);
				
				if(height(itr->left)==height(itr->right)+2){
					if(data<itr->left->data)
						itr=swapWithleft(itr);
					else{
						itr->left=swapWithright(itr->left);
						itr=swapWithleft(itr);
					}
				}
			}
			else if(data>itr->data){
				itr->right=searchAndAdd(itr->right,data);
				if(height(itr->right)==height(itr->left)+2){
					if(data>itr->right->data)
						itr=swapWithright(itr);
					else{
						itr->right=swapWithleft(itr->right);
						itr=swapWithright(itr);
					}
				}
			}
			return itr;
		}
		node* avl::swapWithright(node* itr){
			node* ptr=itr->right;
			itr->right=ptr->left;
			ptr->left=itr;	 
		}
		node* avl::swapWithleft(node* itr){
			node* ptr=itr->left;
			itr->left=ptr->right;
			ptr->right=itr;
		}
		
		void avl::delnode(node*& itr){
			node* dnode=itr;
			if(itr->right==NULL) itr =itr->left;
			else if(itr->left==NULL) itr=itr->right;
			else{
				dnode=itr->left;
				node* parent=itr;
				while(dnode->right!=NULL){
					parent=dnode;
					dnode=dnode->right;
				}
				itr->data=dnode->data;
				if(parent==itr)itr->left=dnode->left;
				else parent->right=dnode->left;
			}
			delete dnode;
		} 
		void avl::postorderWithLeaf(node* itr,stack*& yigit){
			if(itr!=NULL)
			{
				postorderWithLeaf(itr->left,yigit);
				postorderWithLeaf(itr->right,yigit);
				if(itr->left==NULL&&itr->right==NULL){
					yigit->push(itr->data);
					avlvalue=avlvalue-(itr->data);
				}
			}	
		}
		 avl::avl(int num){
			 root=NULL;
			 treenum=num;
		 }
		 bool avl::isEmpty(){
			 return root==NULL;
		 }
		 void avl::add(int data){
			 root= searchAndAdd(root,data);
		 }
		 int avl::height(){
			 return height(root);
		 }
		 void avl::postorderWithLeaf(stack*& yigit){
			postorderWithLeaf(root,yigit);
		 }
		 int avl::getTreenum ()const{ //ağaç numarası
			 return treenum;
		 }
		 int avl::getValue(){ //yaprakları dışında düğüm değerleri toplamı
			 return avlvalue;
		 }
		avl::~avl(){
			while(!isEmpty()) delnode(root);
		}

#endif
 