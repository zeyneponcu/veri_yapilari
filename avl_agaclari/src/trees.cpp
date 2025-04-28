/*
 *@file				(ağaçlar bağlı listesi)
 *@description		(İçinde her satırda oluşturulan avl ağaçlarını ve stacklerini tutan bağlı liste. 
					 Genel bağlı liste methodları var sadece kodda ihtiyacım olduğu için first ve last düğümün içindeki avlnin adresini döndürüyor)
 *@course			(2. Öğretim A Grubu)
 *@assignment		(2.ödev)
 *@date				(15.12.2023-16.12.2023)
 *@author			(Zeynep Sude Öncü /zey.su.oncu@gmail.com)
 */

 #ifndef TREES_CPP
 #define TREES_CPP
 #include "dugum.hpp"
 #include "trees.hpp"
 
		dugum* trees::FindByPosition(int position){
			if (position<0||position>size())throw "girilen sayi yanlis";
			int index=0;
			dugum *itr=ilk;
			for(;itr!=NULL;itr=itr->next,index++){
				if(position==index)return itr;
			}
			return NULL;
		}
		trees::trees(){
			ilk= new dugum(0,NULL);
		}
		bool trees::IsEmpty(){
			return ilk->next==NULL;
		}
		int trees::size(){
			int lenght=0;
			for(dugum *itr=ilk->next;itr!=NULL;itr=itr->next){
				lenght++;
			}
			return lenght;
		}
		avl* trees::first(){
			if(IsEmpty())throw "Liste bos";
			return ilk->next->avladres;
		}
		avl* trees::last(){
			if(IsEmpty())throw "Liste bos";
			return FindByPosition(size())->avladres;
		}
		void trees::add(avl* avladres){
			insert(size(),avladres);
		}
		void trees::insert(int index,avl* avladres){
			if(index==0)ilk->next=new dugum(avladres,ilk->next);
			else{
				dugum *prev=FindByPosition(index);
				prev->next= new dugum(avladres,prev->next);
			}
		}
		int trees::indexOf(avl* avladres){
			int index=0;
			for(dugum *itr=ilk->next;itr!=NULL;itr=itr->next,index++)
				if (itr->avladres==avladres) return index;
			throw "Out of range";
		}
		void trees::removeAt(int index){
			if(IsEmpty())throw "Liste bos";
			dugum *prev= FindByPosition(index);
			dugum *del;
			del=prev->next;
			prev->next=prev->next->next;
			delete del;
		}
		void trees::remove(avl* avladres){
			int position=indexOf(avladres);
			removeAt(position);
		}
		bool trees::find(avl* avladres){
			for(dugum *itr=ilk->next;itr!=NULL;itr=itr->next)
				if (itr->avladres==avladres) return true;
			return false;
		}
		ostream& operator<<(ostream& ekran,trees& sag){
			if(sag.IsEmpty()) ekran<< "Liste bos";
			else{
				for(dugum *itr=sag.ilk->next;itr!=NULL;itr=itr->next){
					ekran<<itr->avladres<<" ";
				}
				cout<<endl;
			}
			return ekran;
		}
		void trees::clear(){
			while (!IsEmpty())
				removeAt(0);
		}
		trees::~trees() {
			clear();
			delete ilk;
		}	
 #endif