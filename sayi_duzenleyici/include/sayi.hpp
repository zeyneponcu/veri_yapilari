 #ifndef SAYI_HPP
 #define SAYI_HPP
 #include "basamak.hpp"
 #include <sstream>
 
 class sayi {
	public:
		basamak* head;
		basamak* FindByPosition(int);
		sayi();
		bool IsEmpty();
		int size();
		void drawLine(int );
		void drawLine2(int );
		void adresLine(int );
		void basamakLine();
		string lastThree(const void*);
		basamak* first();
		basamak* last();
		void add(int);
		void insert(int ,int );
		int indexOf(int);
		void removeAt(int);
		void remove(int );
		bool find(int );
		void reverseDigit();
		void startWithOdds();
		void nodePrinter();
		int getWithindex(int );
		void get();
		void clear();
		~sayi();
		
 };	
 #endif