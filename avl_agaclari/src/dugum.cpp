/*
 *@file				(bağlı listenin düğüm kodu)
 *@description		(içinde mainde oluşturulan avl ağaçlarının adreslerini ve o avl ağaçlarının yığıt yapılarını tutan düğüm. 
					 Düğüm silindiğinde avlnin ve yığıtın yıkıcı fonk.larını çağıran yıkıcı fonksiyonu var)
 *@course			(2. Öğretim A Grubu)
 *@assignment		(2.ödev)
 *@date				(15.12.2023-16.12.2023)
 *@author			(Zeynep Sude Öncü /zey.su.oncu@gmail.com)
 */

#ifndef DUGUM_CPP
#define DUGUM_CPP
#include <iostream>
#include "avl.hpp"
#include "dugum.hpp"
using namespace std;

		dugum::dugum(avl* avladres,dugum* next){
			this->avladres=avladres;
			this->next=next;
			if(avladres!=0){
				yigit=new stack();
				avladres->postorderWithLeaf(yigit);
				yigit->upper=yigit->top;
			}		
		}
		dugum::~dugum(){
			yigit->~stack();
			avladres->~avl();
		}
#endif