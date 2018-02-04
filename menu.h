#ifndef __MENU_H__
#define __MENU_H__

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
//#include <termio.h>
//#include <thread>
#include "people.h"
#include "product.h"

using namespace std;

class Menu
{
		public:
				Menu();
				void run();
				virtual void menuShow();
				void showTime();
				void system_pause(void);
			//	void readTime();
			//	void writeTime();
				void writeStop();
				void readStop();
		protected:
				int stop;
};

class MenuMain:public Menu
{
		public:
				    MenuMain();
					Person* login();
					virtual void menuShow();
					int adminLogin();
			//		static void  runMain();
					void flashShow();
					People pp;
					Products pd;
					Person* ps;
					Product pdt;
};

class MenuAdmin:public Menu
{
		public:
			MenuAdmin(Person *ma);
			virtual  void menuShow();
			void show();
			void search();
		protected:
			Admin* admin;
			People pp;
};

class MenuIn:public Menu
{
		public:
				MenuIn(Person *mi);
				virtual  void menuShow();
		protected:
				InPeople* inPeople;
				People pp;
};

class MenuOut:public Menu
{
		public:
				MenuOut(Person *mo);
				virtual  void menuShow();
		protected:
				OutPeople* outPeople;
				People pp;
};

class MenuCommon:public Menu
{
		public:
				MenuCommon(Person *mc);
				virtual  void menuShow();
		protected:
				CommonPeople* commonPeople;
				People pp;
};





#endif
