/*
 *@file(Sayıları tutan düğüm)
 *@description(sayilar.txt dosyasında bulunan sayıları tutan 'sayi' bağlı listesinin adreslerini tutuyor)
 *@course(2. Öğretim A Grubu)
 *@assignment(1.ödev)
 *@date(11.11.2023-11.11.2023)
 *@author(Zeynep Sude Öncü /zey.su.oncu@gmail.com)
 */

#ifndef DUGUM_CPP
#define DUGUM_CPP
#include <iostream>
#include "sayi.hpp"
#include "dugum.hpp"
using namespace std;

		
		 dugum::dugum(sayi* sayiadres=0,dugum* next=NULL){
			this->sayiadres=sayiadres;
			this->next=next;
			
		}
		

#endif