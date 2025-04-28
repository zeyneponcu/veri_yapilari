/*
 *@file				(avl ağacını oluşturan düğüm kodu)
 *@description		(içinde avl'nin değerini, sol ve sağ çocuğunu tutan kod)
 *@course			(2. Öğretim A Grubu)
 *@assignment		(2.ödev)
 *@date				(11.12.2023-11.12.2023)
 *@author			(Zeynep Sude Öncü /zey.su.oncu@gmail.com)
 */

#ifndef NODE_CPP
#define NODE_CPP
#include <iostream>
#include "node.hpp"
using namespace std;

		node::node(const int data,node* right,node* left){
			this->data=data;
			this-> right=right;
			this-> left=left;
		}

#endif