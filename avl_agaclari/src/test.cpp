/*
 *@file				(test kodu-main)
 *@description		(veri.txt'den sayıları alıp bunları avllere ekleyen ve stacklari oluşturan main ile silinecek avlyi bulduğum finDdel fonksiyonu burda)
 *@course			(2. Öğretim A Grubu)
 *@assignment		(2.ödev)
 *@date				(11.12.2023-19.12.2023)
 *@author			(Zeynep Sude Öncü /zey.su.oncu@gmail.com)
 */

#include "avl.hpp"
#include "stack.hpp"
#include <fstream>
#include "trees.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include "stack.hpp"
#include <windows.h> //kodu çalıştırdığımda elde ettiğim görüntü bazen çok hızlanıyordu, düzgün silip silmediği anlamak için sleep fonk. kullandım.

using namespace std;

dugum* findDel(trees* agaclar,bool sign,bool flag){
		int x=0;
		dugum* del;
		int tutucu;
		if(flag==1){
			for(dugum *itr=agaclar->ilk->next;itr!=NULL;itr=itr->next){
				itr->yigit->equal();
			}
			return del;
			
		}
		if(sign==1){
			for(dugum *itr=agaclar->ilk->next;itr!=NULL;itr=itr->next){
				tutucu=itr->yigit->getUpper();
				if(tutucu>x){
					x=tutucu;
					del=itr;
					
				}
			}
			del->yigit->downUpper();
			if(del->yigit->upper==-1)flag=1;
			sign=0;
			findDel(agaclar,sign,flag);
		}
		else{
			x=999999999;
			for(dugum *itr=agaclar->ilk->next;itr!=NULL;itr=itr->next){
				tutucu=itr->yigit->getUpper();
				if(tutucu<x){
					x=tutucu;
					del=itr;
					
				}
			}
			del->yigit->downUpper();
			if(del->yigit->upper==-1)flag=1;
			sign=1;
			findDel(agaclar,sign,flag);
		}
		if(flag==1){
			for(dugum *itr=agaclar->ilk->next;itr!=NULL;itr=itr->next){
				itr->yigit->equal();
			}
			return del;
			
		}
}


void ascii(trees* agaclar){
	char ascii;
	for(dugum *itr=agaclar->ilk->next;itr!=NULL;itr=itr->next){
		ascii=itr->avladres->getValue()%(90-65+1)+65;
		cout<<ascii;
	}
}
int main(){
	bool sign;
	bool flag;
	dugum* dele;
	trees* agaclar=new trees();
	ifstream dosya("veri.txt");
	string satir;
	int a,num=0;
	while(getline (dosya,satir)){		
		num++;
		avl* agac=new avl(num);
		stringstream okuyucu(satir);
		while(okuyucu>>a){
			agac->add(a);
		}
		agaclar->add(agac);
		
	}
	
		ascii(agaclar);
		
	
	do{
		sign=0;
		flag=0;
		dele=findDel(agaclar,sign,flag);
		agaclar->remove(dele->avladres);
		ascii(agaclar);
		//Sleep(5);//çıktıyı daha düzgün görmek için
		system("cls");
	}while(agaclar->size()!=1);
	
	for(int i=0;i<30;i++) cout<<"=";
	cout<<endl<<"|";
	for(int i=0;i<28;i++) cout<<" ";
	cout<<"|"<<endl<<"|";
	for(int i=0;i<28;i++) cout<<" ";
	cout<<"|"<<endl<<"|";
	for(int i=0;i<7;i++) cout<<" ";
	cout<<"Son Karakter: ";
	ascii(agaclar);
	for(int i=0;i<6;i++) cout<<" ";
	cout<<"|"<<endl<<"|";
	for(int i=0;i<7;i++) cout<<" ";
	cout<<"AVL NO      : ";
	cout<<agaclar->last()->getTreenum();
	for(int i=0;i<4;i++) cout<<" ";
	cout<<"|"<<endl<<"|";
	for(int i=0;i<28;i++) cout<<" ";
	cout<<"|"<<endl<<"|";
	for(int i=0;i<28;i++) cout<<" ";
	cout<<"|"<<endl;
	for(int i=0;i<30;i++) cout<<"=";
	cout<< endl;
		
}
