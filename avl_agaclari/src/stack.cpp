/*
 *@file				(yığıt kodu)
 *@description		(Dizi ile gerçeklenmiş yığıt kodu. İçinde genel methodlar dışında upper isimli bir değişken ve bu değişkeni getiren ve düşüren fonk.lar var)
 *@course			(2. Öğretim A Grubu)
 *@assignment		(2.ödev)
 *@date				(11.12.2023-16.12.2023)
 *@author			(Zeynep Sude Öncü /zey.su.oncu@gmail.com)
 */
 
#ifndef STACK_CPP
#define STACK_CPP

#include <iostream>
#include "stack.hpp"

using namespace std;

		void stack::expand(int newsize){ //dizi dolunca size'ını büyüten method
			int* bigarray=new int[newsize];
			for(int i=0;i<size;i++){
				bigarray[i]=array[i];
			}
			size=newsize;
			delete [] array;
			array=bigarray;
			
		}                                                                                                                                         
		
		stack::stack(){
			top=-1;
			array= new int[size];
		}
		stack::~stack(){
			delete [] array;
		}
		void stack::push(int value){
			if(top+1!=size){
				top++;
				array[top]=value;
			}
			else{
				expand(2*size);
				top++;
				array[top]=value;
			}
		}
		void stack::equal(){ //stackleri ilk baştaki hallerine döndürüyor
			upper=top;
		}
		bool stack::isOver(){
			return (upper==-1);
		}
		void stack::pop(){
			top--;
		}
		int stack::getUpper(){
			return	array[upper];
		}
		void stack::downUpper(){
			upper--;
		}
		int stack::peek(){
			if(!isEmpty())return array[top];
			else return -1;	
		}
		bool stack::isEmpty(){
			return (top==-1);
		}
		
#endif