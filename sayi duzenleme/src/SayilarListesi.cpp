 /*
 *@file(Sayılar listesi)
 *@description(sayilar.txt dosyasında bulunan satırdaki sayıları tutan sayı listelerinin adreslerini tutan bağlı liste)
 *@course(2. Öğretim A Grubu)
 *@assignment(1.ödev)
 *@date(11.11.2023-26.11.2023)
 *@author(Zeynep Sude Öncü /zey.su.oncu@gmail.com)
 */
 #ifndef SAYILARLISTESI_CPP
 #define SAYILARLISTESI_CPP
 #include "dugum.hpp"
 #include "sayi.hpp"
 #include "SayilarListesi.hpp"
 
		dugum* SayilarListesi::FindByPosition(int position){
			if (position<0||position>size())throw "girilen sayi yanlis";
			int index=0;
			dugum *itr=ilk;
			for(;itr!=NULL;itr=itr->next,index++){
				if(position==index)return itr;
			}
			return NULL;
		}
		SayilarListesi::SayilarListesi(){
			ilk= new dugum(0,NULL);
		}
		bool SayilarListesi::IsEmpty(){
			return ilk->next==NULL;
		}
		int SayilarListesi::size(){
			int lenght=0;
			for(dugum *itr=ilk->next;itr!=NULL;itr=itr->next){
				lenght++;
			}
			return lenght;
		}
		
		sayi* SayilarListesi::first(){
			if(IsEmpty())throw "Liste bos1";
			return ilk->next->sayiadres;
		}
		sayi* SayilarListesi::last(){
			if(IsEmpty())throw "Liste bos2";
			return FindByPosition(size())->sayiadres;
		}
		int SayilarListesi::lastInside(int k){
			if(IsEmpty())throw "Liste bos2";
			return last()->getWithindex(k);
		}
		void SayilarListesi::add(sayi* sayiadres){
			insert(size(),sayiadres);
		}
		void SayilarListesi::insert(int index,sayi* sayiadres){
			if(index==0)ilk->next=new dugum(sayiadres,ilk->next);
			else{
				dugum *prev=FindByPosition(index);
				prev->next= new dugum(sayiadres,prev->next);
			}
		}
		int SayilarListesi::getNum(int k){
			sayi* str=get(k);
			int a=str->size()-1;
			int toplam=0,sayac=0;
			for(basamak* itr=str->head->next;a>=0;itr=itr->next){
				toplam+=itr->deger*(10^a);
				a--;
			}
			return toplam;
		}
		void SayilarListesi::startWithOddsAll(){
			for(dugum *itr=ilk->next;itr!=NULL;itr=itr->next){
				itr->sayiadres->startWithOdds();
			}
		}
		void SayilarListesi::reverseDigitAll(){
			for(dugum *itr=ilk->next;itr!=NULL;itr=itr->next){
				itr->sayiadres->reverseDigit();
			}
		}
		void SayilarListesi::getir(int a){
			get(a)->nodePrinter();
		}
		sayi* SayilarListesi::get(int index){
			int a=0;
			dugum* itr=ilk->next;
			for(int a=0;a!=index;a++)
				itr=itr->next;
			return itr->sayiadres;
		}
		int SayilarListesi::indexOf(sayi* sayiadres){
			int index=0;
			for(dugum *itr=ilk->next;itr!=NULL;itr=itr->next,index++)
				if (itr->sayiadres==sayiadres) return index;
			throw "Out of range";
		}
		void SayilarListesi::removeAt(int index){
			if(IsEmpty())throw "Liste bos";
			dugum *prev= FindByPosition(index);
			dugum *del;
			del=prev->next;
			prev->next=prev->next->next;
			delete del;
		}
		void SayilarListesi::remove(sayi* sayiadres){
			int position=indexOf(sayiadres);
			removeAt(position);
		}
		bool SayilarListesi::find(sayi* sayiadres){
			for(dugum *itr=ilk->next;itr!=NULL;itr=itr->next)
				if (itr->sayiadres==sayiadres) return true;
			return false;
		}
		void SayilarListesi::nodePrinter(){
			for(dugum *itr=ilk;itr!=NULL;itr=itr->next){
				cout<<itr->next->sayiadres<<" ";
			}
		}
		ostream& operator<<(ostream& ekran,SayilarListesi& sag){
			if(sag.IsEmpty()) ekran<< "Liste bos";
			else{
				for(dugum *itr=sag.ilk->next;itr!=NULL;itr=itr->next){
					ekran<<itr->sayiadres<<" ";
				}
				cout<<endl;
			}
			return ekran;
		}
		void SayilarListesi::clear(){
			while (!IsEmpty())
				removeAt(0);
		}
		SayilarListesi::~SayilarListesi() {
			clear();
			delete ilk;
		}	
		
 #endif