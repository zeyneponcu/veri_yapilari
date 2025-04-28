/*
 *@file(Sayı listesi)
 *@description(sayilar.txt dosyasında bulunan sayıları tutan bağlı liste)
 *@course(2. Öğretim A Grubu)
 *@assignment(1.ödev)
 *@date(11.11.2023-25.11.2023)
 *@author(Zeynep Sude Öncü /zey.su.oncu@gmail.com)
 */
 #ifndef SAYI_CPP
 #define SAYI_CPP
 #include "basamak.hpp"
 #include <sstream>
 #include "sayi.hpp"
 
		basamak* sayi::FindByPosition(int position){
			if (position<0||position>size()) throw "girilen sayi yanlis";
			int index=0;
			basamak* itr=head;
			for(;itr!=NULL;itr=itr->next,index++){
				if(position == index) return itr;
			}
			return NULL;
		}
		
		sayi::sayi(){
			head= new basamak(0,NULL);
			
			
		}
		
		bool sayi::IsEmpty(){
			return head->next==NULL;
		}
		int sayi::size(){
			int lenght=0;
			for(basamak *itr=head->next;itr!=NULL;itr=itr->next){
				lenght++;
			}
			return lenght;
		}
		void sayi::drawLine(int l){
			for(int z=0;z<l+2;z++)
				cout<<"#";
			for(int i=0;i<size();i++){
				cout<<"   ";
				for(int j=0;j<7;j++)
					cout<<"*";
			}
		}
		void sayi::drawLine2(int l){
			cout<<"#";
			for(int z=0;z<l;z++)
				cout<<"-";
			cout<<"#";
			for(int i=0;i<size();i++){
				cout<<"   ";
				for(int j=0;j<7;j++)
					cout<<"*";
			}
		}
		void sayi::adresLine(int k){
			basamak *itr=head;
			for(int i=0;i<size();i++){
				itr=itr->next;
				cout<<"   "<<"* ";
				cout<<lastThree(itr)<<" *";
			}
		}
		void sayi::basamakLine(){
			basamak *itr=head;
			for(int i=0;i<size();i++){
				itr=itr->next;
				cout<<"   "<<"*  ";
				cout<<itr->deger<<"  *";
			}
		}
		string sayi::lastThree(const void* itr){
			stringstream translate;
			translate<<hex<<itr;
			string hold= translate.str();
			return hold.substr(6);
		} 
		
		basamak* sayi::first(){
			if(IsEmpty()) throw "Liste bos";
			return head->next;
		}
		basamak* sayi::last(){
			if(IsEmpty())throw "Liste bos";
			return FindByPosition(size());
		}
		void sayi::add(int deger){
			insert(size(),deger);
		}
		void sayi::insert(int index,int deger){
			basamak *prev=FindByPosition(index);
			prev->next= new basamak(deger,prev->next);
		}
		int sayi::indexOf(int deger){
			int index=0;
			for(basamak *itr=head->next;itr!=NULL;itr=itr->next,index++)
				if (itr->deger==deger) return index;
			throw "Dogru index degil";
		}
		void sayi::removeAt(int index){
			if(IsEmpty())throw "Liste bos";
			basamak *prev= FindByPosition(index);
			basamak *del;
			del=prev->next;
			prev->next=prev->next->next;
			delete del;
		}
		void sayi::remove(int deger){
			int position=indexOf(deger);
			removeAt(position);
		}
		bool sayi::find(int deger){
			for(basamak *itr=head->next;itr!=NULL;itr=itr->next)
				if (itr->deger==deger) return true;
			return false;
		}
		
		void sayi::reverseDigit(){
			int a=size();
			if(a==1) 
				head->next->next=NULL;
			else if(a==2){
				basamak* itr=head->next->next;
				itr->next=head->next;
				head->next->next=NULL;
				head->next=itr;
			}
			else{
					basamak* ptr=head->next;
					basamak* itr=ptr->next;
					ptr->next=NULL;
					ptr=itr;
					itr=itr->next;
					ptr->next=head->next;
					head->next=ptr;
				for (int i=1;i<a-1;i++){
					ptr=itr;
					itr=itr->next;
					ptr->next=head->next;
					head->next=ptr;
				}	
			}
			
			
		}
		void sayi::startWithOdds(){
			basamak* itr=head->next;
			basamak* ptr=head;
			basamak* ktr;
			basamak* str=head;
			if(size()==1);
			else{
				for(int i=1;i<=size();i++){
					if(head==ptr&&itr->deger%2==0){
						head->next=itr->next;
						ptr=itr;
						itr=itr->next;
						last()->next=ptr;
						ptr->next=NULL;
						ptr=head;
			
					}
					else if(i==1&&itr->deger%2==1){
						ptr=itr;
						itr=itr->next;
					}
					else if(i<=size()&&itr->deger%2==0){
			 				ptr->next=itr->next;
							last()->next=itr;
							itr->next=NULL;
							itr=ptr->next;
						}
					else if(i<=size()&&itr->deger%2==1){
							ptr=itr;
							itr=itr->next;
						}
				}
			}
		}
			
		void sayi::nodePrinter(){
			for(basamak *itr=head->next;itr!=NULL;itr=itr->next){
				cout<<itr->deger;
			}
		}
		int sayi::getWithindex(int index){
			
			if(IsEmpty()) throw;
			if(index>size()-1) throw;
			int a=0;
			basamak* itr=head;
			do{
				itr=itr->next;
				a++;
				
			}while(index==a);
			return itr->deger;
		}
		void sayi::get(){
			if(IsEmpty()) throw;
			for(basamak *itr=head->next;itr!=NULL;itr=itr->next){
				cout<<itr->deger;
			}
		}
		ostream& operator<<(ostream& ekran,sayi& sag){
			if(sag.IsEmpty()) ekran<< "Liste bos";
			else{
				for(basamak *itr=sag.head->next;itr!=NULL;itr=itr->next)
					ekran<<itr->deger<<" ";
			}
		}
		
		void sayi::clear(){
			while (!IsEmpty())
				removeAt(0);
		}
		sayi::~sayi() {
			clear();
			delete head;
		}
		

 #endif