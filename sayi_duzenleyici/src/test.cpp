/*
 *@file(Test kodu)
 *@description(Main'i içeren dosya.İçerisinde txt dosyasından sayıları alan, ekrana sayıların çıktısını veren,satırda bulunan en büyük sayıyı silen kodlar var )
 *@course(2. Öğretim A Grubu)
 *@assignment(1.ödev)
 *@date(11.11.2023-26.11.2023)
 *@author(Zeynep Sude Öncü /zey.su.oncu@gmail.com)
 */
#include "sayi.hpp"
#include "SayilarListesi.hpp"
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
using namespace std;

int adresSize(sayi* ptr){
	stringstream translate;
	translate<<hex<<ptr;
	string k= translate.str();
	int a=k.length();
	return a;
}
void print(sayi* yeni,SayilarListesi *liste,int a,int adresuzunlugu){
		
		yeni->drawLine(adresuzunlugu);
		cout<<endl<<"#"<<yeni<<"#";
		yeni->adresLine(adresuzunlugu);
		cout<<endl;
		yeni->drawLine2(adresuzunlugu);
		cout<<endl<<"#";
		for(int i=0;i<(adresuzunlugu-(yeni->size()));i++)
			cout<<" ";
		liste->getir(a);
		cout<<"#";
		yeni->basamakLine();
		cout<<endl;
		yeni->drawLine(adresuzunlugu);
		cout<<endl<<endl;
				
		
 } 
 void delBig(SayilarListesi *liste){
	 int big=0,index=0;
	 int num=0;
	 for(int i=0;i<liste->size();i++){
		 num=liste->getNum(i);
		 
		 if(big<num){
			big=num;
			index=i;
		 }
		 
	 }
	 
	 liste->removeAt(index);
	 
 }
int main(){
	
	ifstream dosya("sayilar.txt");
	string satir;
	int a,b,adresuzunlugu;
	int gosterici,secilen;
	
	
	while(getline (dosya,satir))
		{	
			SayilarListesi *liste=new SayilarListesi();
			sayi* ptr;
			adresuzunlugu=adresSize(ptr);
			stringstream okuyucu(satir);
			while(okuyucu>>a){
				sayi *yeni=new sayi();
				int bas=1;
				
				while(a/bas>0){
					b=(a/bas)%10;
					yeni->insert(0,b);
					bas*=10;				
				}
				liste->add(yeni);
				
					
			}
			int i=0,j=0,k=0,l=0;
			for(dugum *itr=liste->ilk->next;itr!=NULL;itr=itr->next,i++){
						print(itr->sayiadres,liste,i,adresuzunlugu);
					}
			do{
			cout<<"1. Tek Basamaklari Basa Al"<<endl;
			cout<<"2. Basamaklari Tersle"<<endl;
			cout<<"3. En Buyuk Cikar"<<endl;
			cout<<"4. Cikis"<<endl;
			cin>>secilen;
			
			switch(secilen){
				case 1:
					liste->startWithOddsAll();
					for(dugum *itr=liste->ilk->next;itr!=NULL;itr=itr->next,j++){
						print(itr->sayiadres,liste,j,adresuzunlugu);
					}
				break;
				case 2:
					liste->reverseDigitAll();
					for(dugum *itr=liste->ilk->next;itr!=NULL;itr=itr->next,k++){
						print(itr->sayiadres,liste,k,adresuzunlugu);
					}
				break;
				case 3:
					delBig(liste);
					for(dugum *itr=liste->ilk->next;itr!=NULL;itr=itr->next,l++){
						print(itr->sayiadres,liste,l,adresuzunlugu);
					}
				break;
				case 4:
					for(dugum *itr=liste->ilk->next;itr!=NULL;itr=itr->next){
						itr->sayiadres->~sayi();
						
					}
					liste->clear();
					delete liste;
				break;
				default:
					cout<<"hatali secim"<<endl;
				break;	
			}
			}
			while(secilen!=4);
		}	
}
	                                                                                                                                          