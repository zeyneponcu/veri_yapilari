/*
 *@file(Basamak düğümü)
 *@description(sayilar.txt dosyasında bulunan sayıların rakamlarını tutuyor)
 *@course(2. Öğretim A Grubu)
 *@assignment(1.ödev)
 *@date(11.11.2023-11.11.2023)
 *@author(Zeynep Sude Öncü /zey.su.oncu@gmail.com)
 */

#ifndef BASAMAK_CPP
#define BASAMAK_CPP
#include "basamak.hpp"
#include <iostream>
using namespace std;

		basamak::basamak(int deger=0,basamak *next=NULL){
			this->deger=deger;
			this->next=next;
			
		}
		


#endif