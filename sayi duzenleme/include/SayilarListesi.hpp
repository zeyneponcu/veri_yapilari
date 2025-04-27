 #ifndef SAYILARLISTESI_HPP
 #define SAYILARLISTESI_HPP
 #include "dugum.hpp"
 #include "sayi.hpp"
 
 class SayilarListesi {
	public:
		dugum* ilk;
		dugum* FindByPosition(int);
	
		SayilarListesi();
		bool IsEmpty();
		int size();
		sayi* first();
		sayi* last();
		int lastInside(int );
		void add(sayi* );
		void insert(int ,sayi* );
		int getNum(int);
		void startWithOddsAll();
		void reverseDigitAll();	
		void getir(int);
		sayi* get(int index);
		int indexOf(sayi* );
		void removeAt(int );
		void remove(sayi* );
		bool find(sayi* );
		void nodePrinter();
		friend ostream& operator<<(ostream&,SayilarListesi& );
		void clear();
		~SayilarListesi(); 
		
 };	
 #endif