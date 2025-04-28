#ifndef DUGUM_HPP
#define DUGUM_HPP
#include <iostream>
#include "sayi.hpp"
using namespace std;

class dugum{

	public:
		sayi* sayiadres;
		dugum *next;
		
		dugum(sayi*,dugum*);
			
		
};
#endif