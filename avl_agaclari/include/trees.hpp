 #ifndef TREES_HPP
 #define TREES_HPP
 #include "dugum.hpp"
 
 class trees{
	public:
		dugum* ilk;
		dugum* FindByPosition(int);
		trees();
		bool IsEmpty();
		int size();
		avl* first();
		avl* last();
		void add(avl*);
		void insert(int,avl*);
		int indexOf(avl*);
		void removeAt(int);	
		void remove(avl*);
		bool find(avl*);
		friend ostream& operator<<(ostream&,trees&);
		void clear();
		~trees() ;
 };	
 #endif