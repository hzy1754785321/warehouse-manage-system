#ifndef __PRODUCT_H__
#define __PRODUCT_H__

#define title1  "name	type 	price   	number\n"

#include <iostream>
#include <vector>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <unistd.h>

using namespace std;

class Product
{
		protected:
				char name[32];
				char type[32];
				float price;
			//	int quantity;
				int id;  //快递单号
			    char logintime[50];
		public:
				Product();
			    ~Product();
				static vector<int> number;
				static int productMax;
				void setId();
				void setName();
				void setType();
				void setLoginTime();
				void setPrice();
				void show();
				int  getId();
				char* getLoginTime();
				char*  getName();
				char* getType();
				float getPrice();
				int getProductMax();
				void deleteId();
};


class Products:public vector<Product*>
{
		public:
			Products();
		//	Product *pdt;
			void showAll();
			void addProduct();
			void deleteId(const int &id);
			void deleteName(const char* name);
			void deleteAll();
			Product* searchId(const int &id);
			Products searchType(const char* Type);
			Product* searchName(const char* Name);
			void commonSearch();
			void search();
			void readProduct();
			void writeProduct();
			void delAll();
};




#endif
