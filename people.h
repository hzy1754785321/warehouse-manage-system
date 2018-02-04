#ifndef __PEOPLE_H__
#define __PEOPLE_H__

//#define title "name		number 		department\n"	

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include "product.h"


class People;
class Admin;
class InPeople;
class OutPeople;
class CommonPeople;
using namespace std;

class Person
{
		protected:
				char name[32];
				char passwd[32];
				char department[32];
				int id;
				int stop;
				char loginTime[50];
		public:
				Person();
				Person(char* name);
				Person(Person *ps);
				virtual ~Person();
				void setStop10();
				void setStop();
				void subStop();
				int getStop();
				static int peopleMax;
				static vector<int> number;
				Products*  temp;
				void setNumber();
				void setName();
				void setTime();
				void setPasswd();
				void changeInfo();
				char* getName();
				char* getPasswd();
				char* getType();
				char* getTime();
				void writestop();
				void readstop();
				int getNumber();
				void deleteId();
				void show();
				void insert();
				People *pp;
//				Product* pt;
	//			void readProductInfo();
				void writeProductInfo();
				void writeRecord();
				void readRecord();
				void writeStop();
				void readStop();
};

class People:public vector<Person*>
{
		public:
				People();
				void add();
				void deleteNumber(const int &id);
				void deleteName(const char* name);
				void deletePeople();
				Person* searchNumber(const int &id);
				Person* searchName(const char* name);
				People  searchType(const char* type);
				friend class Admin;
				void writePeople();
				void readPeople();
				void search();
				void showAll();
				void delAll();
};

class Admin:public Person
{
		public:
				Admin();
				virtual ~Admin();
				Admin(Person* ps);
				void showProduct();
				void addPerson();
				void deletePerson();
				void searchPerson();
				void showPerson();
				void writePeopleInfo();
				void readPeopleInfo();
				void searchProduct();
};

class InPeople:public Person
{
		public:
				InPeople();
				virtual ~InPeople();
				InPeople(Person *in);
				void addProduct();
};

class OutPeople:public Person
{
		public:
				OutPeople();
				virtual ~OutPeople();
				OutPeople(Person *ps);
				void deleteProduct();
};

class CommonPeople:public Person
{
		public:
				CommonPeople();
				virtual ~CommonPeople();
				CommonPeople(Person *cp);
				void searchProduct();
             	void showProduct();
};



#endif
