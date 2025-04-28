#ifndef DUGUM_HPP
#define DUGUM_HPP
#include <iostream>
#include "avl.hpp"
using namespace std;

class dugum{		 
	public:
		avl* avladres;
		stack* yigit;
		dugum *next;
		dugum(avl* avladres=0,dugum* next=NULL);
		~dugum();
};
#endif