#include "menu.h"

extern int changeFlag;

Menu::Menu():stop(0)
{}

int askForSave()
{
		char t;
		if(changeFlag==1)
		{
				while(1)
				{
					getchar();
					cout << "\t\t\t\t\tdo you want to save?(y/n)" ;
					t=getchar();
					if(t=='n')
					{
							return 0;
					}
					else if(t=='y')
					{
							return 1;
					}
					else 
					{
							cout << "\t\t\t\t\tinput error!" << endl;
					}
				}
		}
}

void Menu::menuShow()
{	}

void Menu::writeStop()
{
		ofstream st;
		st.open("stop",ios::out);
		if(st.is_open())
		{
				st << stop;
		}
		else
				cout << "open failed!" << endl;
}

void Menu::readStop()
{
		ifstream st;
		st.open("stop",ios::in);
		while(!st.eof())
		{
				st >> stop;
				st.close();
		}
}

MenuMain::MenuMain()
{}

void MenuMain::menuShow()
{
	int flag,x;
/*	readStop();
     while(stop>0)
	{
			system("clear");
			cout << "\033[31m limit login!" << endl << "\033[31m countdown:" << "\033[37m" << stop << endl;
			stop--;
			writeStop();
			sleep(1);
	}
*/
	Person* pt;
	while(1)
	{
			system("clear");
			showTime();
//			printf("\033[5mhhhhhhhh\033[5m\n");
		cout << "\t\t\t\t\t\033[31m★★★★★★★★★★★★★★★★★★★★★★★★★★★★\033[37m\n"
			 << "\t\t\t\t\t\033[5;34m欢迎来到何朝阳の仓库管理系统!\033[37m\n"
		     << "\t\t\t\t\t\033[31m★★★★★★★★★★★★★★★★★★★★★★★★★★★★\033[37m\n"
	         << "\t\t\t\t\t▶        1:admin            ◀\n"
			 <<	"\t\t\t\t\t▶        2:inPeople         ◀\n"
			 << "\t\t\t\t\t▶        3:outPeople        ◀\n"
			 << "\t\t\t\t\t▶        4:commonPeople     ◀\n" 
			 << "\t\t\t\t\t▶        5:exit             ◀\n"
			 << "\t\t\t\t\t▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲\n"
			 << "\t\t\t\t\t☛ please input your choice(1-5):" ;
	//	flashShow();
		cin >> flag;
		pp.readPeople();
		switch(flag)
		{
			case 1://pp.readPeople();
				   x=adminLogin();
				   if(x==0)
						   break;
				   if(ps!=NULL)
				   {
						   MenuAdmin m1(ps);
						   cout << "\033[1m \t\t\t\t\twelcome admin login" << endl;
						   cout << "\033[22m";
						   sleep(1);
						   m1.menuShow();
						   delete(ps);
						   ps=NULL;
				   }
				   else
						   cout << "error" << endl;
				   break;
			case 2://pp.readPeople();
				   pt=login();
				   if(pt!=NULL)
				   {
						   cout << "\033[1m \t\t\t\t\twelcome inPeople login" << endl;
						   cout << "\033[22m";
						   sleep(1);
						   ps=new InPeople(pt);
						   MenuIn m2(ps);
						   m2.menuShow();
						   delete(ps);
						   ps=NULL;
				   }
				   break;
			case 3://pp.readPeople();
				   pt=login();
				   if(pt!=NULL)
				   {
						   cout << "\033[1m \t\t\t\t\twelcome outPeople login" << endl;
						   cout << "\033[22m";
						   sleep(1);
						   ps=new OutPeople(pt);
						   MenuOut m3(ps);
						   m3.menuShow();
						   delete(ps);
						   ps=NULL;
				   }
				   break;
			case 4://pp.readPeople();
				   pt=login();
				   if(pt!=NULL)
				   {
						   cout << "\033[1m \t\t\t\t\twelcome commonPeople login" << endl;
						   cout << "\033[22m";
						   sleep(1);
						   ps=new CommonPeople(pt);
						   MenuCommon m4(ps);
						   m4.menuShow();
						   delete(ps);
						   ps=NULL;
				   }
				   break;
			case 5:cout << "\t\t\t\t\tbye!" << endl;
				   exit(0);
			default:
				   cout << "\t\t\t\t\tinput error!" << endl;
				   break;
		}
	}
}

void Menu::showTime()
{
		char showtime[50];
		time_t t;
		struct tm *timeinfo;
		time(&t);
		timeinfo=localtime(&t);
		strftime(showtime,50,"%Y年%m月%d日-%H:%M:%S",timeinfo);
		cout << "\t\t\t\t\t   " << showtime << endl;
}

#if 0
void Menu::writeTime()
{
		ofstream Time;
		char showtime[50];
		time_t t;
		struct tm *timeinfo;
		time(&t);
		timeinfo=localtime(&t);
		strftime(showtime,50,"%Y年%m月%d日-%H:%M:%S",timeinfo);
		cout << "当前时间：" << showtime << "已记录！" << endl;
		Time.open("time");
		if(Time.is_open())
		{
				Time << showtime;
				Time.close();
		}
		else
		{
				cout << "open failed!" << endl;
		}
}

void Menu::readTime()
{
		char showtime[50];
		ifstream inTime;
		inTime.open("time");
		if(inTime.is_open())
		{
				while(!inTime.eof())
				{
						inTime.getline(showtime,1000);
						cout << "上次登录时间:" << showtime << endl;
				}
		}
}
#endif

MenuAdmin::MenuAdmin(Person *ma)
{
		admin=dynamic_cast<Admin*>(ma);
}

MenuIn::MenuIn(Person *mi)
{
		inPeople=dynamic_cast<InPeople*>(mi);
}

MenuOut::MenuOut(Person *mo)
{
		outPeople=dynamic_cast<OutPeople*>(mo);
}

MenuCommon::MenuCommon(Person *mc)
{
		commonPeople=dynamic_cast<CommonPeople*>(mc);
}


void MenuAdmin::menuShow()
{
		int flag;
		system("clear");
		showTime();
		admin->writePeopleInfo();
		while(1)
		{system("clear");
		cout << "\t\t\t\t\t  ↖↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↗\n"           
			 <<	"\t\t\t\t\t  ←       1:add        →\n" 
			 << "\t\t\t\t\t  ←       2:delete     →\n" 
			 << "\t\t\t\t\t  ←       3:search     →\n"
			 << "\t\t\t\t\t  ←       4:show       →\n"
			 << "\t\t\t\t\t  ←       5:save       →\n" 
			 << "\t\t\t\t\t  ←       6:exit       →\n"
			 << "\t\t\t\t\t  ↙↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↘\n"
			 << "\t\t\t\t\tplease input your choice(1-6):" ;
		cin >> flag;
		switch(flag)
		{
				case 1:admin->addPerson();
					   sleep(1);
					   break;
				case 2:admin->deletePerson();
					   sleep(1);
					   break;
				case 3://admin->searchPerson();
					   search();
					   break;
				case 4:show();
					   break;
				case 5:admin->writePeopleInfo();
					   changeFlag=0;
					   break;
				case 6:if(askForSave())
							   admin->writePeopleInfo();
					   changeFlag=0;
					   return;
		}
		}
}
void MenuAdmin::search()
{
		int flag;
		while(1)
		{
				system("clear");
				cout << "\t\t\t\t\t1:search people\n"
					 << "\t\t\t\t\t2:search product\n"
					 << "\t\t\t\t\t3:exit\n"
					 << "\t\t\t\t\tplease input your choice(1-3):";
				cin >> flag;
				switch(flag)
				{
						case 1:admin->searchPerson();
							   system_pause();
							   break;
						case 2:admin->searchProduct();
							   system_pause();
							   break;
						case 3:return ;
					    deafault:cout << "\t\t\t\t\tinput error!" << endl;
							     break;
				}
		}
}


void MenuAdmin::show()
{
		int flag;
		while(1)
		{
				system("clear");
		cout << "\t\t\t\t\t◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇\n"
			 <<	"\t\t\t\t\t◇1:show the people   ◇\n"  
			 << "\t\t\t\t\t◇2:show the product  ◇\n" 
			 << "\t\t\t\t\t◇3:show the record   ◇\n" 
			 << "\t\t\t\t\t◇4:exit              ◇\n"
			 << "\t\t\t\t\t◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇◇\n"
			 << "\t\t\t\t\tplease input the choice(1-4):" ;
		cin >> flag;
		switch(flag)
		{
				case 1:admin->showPerson();
					   system_pause();
					   break;
				case 2:admin->showProduct();
					   system_pause();
					 //  admin->temp->showAll();
					   break;
				case 3:admin->readRecord();
					   system_pause();
					   break;
				case 4:return ;
				default:cout << "\t\t\t\t\tinput error!" << endl;
						break;
		
		}
		}
}

void MenuIn::menuShow()
{
		int flag;
		Product *p;
		pp.readPeople();
		system("clear");
		showTime();
		inPeople->pp->writePeople();
		while(1)
		{
				system("clear");
		cout << "\t\t\t\t\t✚✚✚✚✚✚✚✚✚✚✚✚✚✚✚✚✚✚✚✚✚✚✚✚✚✚✚✚\n"
			 << "\t\t\t\t\t✚      1:add product       ✚\n"
			 << "\t\t\t\t\t✚      2:show information  ✚\n"
			 << "\t\t\t\t\t✚      3:change passwd     ✚\n"
			 << "\t\t\t\t\t✚      4:save              ✚\n"
			 << "\t\t\t\t\t✚      5:exit              ✚\n"
			 << "\t\t\t\t\t✚✚✚✚✚✚✚✚✚✚✚✚✚✚✚✚✚✚✚✚✚✚✚✚✚✚✚✚\n"
			 << "\t\t\t\t\tplease input your choice(1-5):" ;
		cin >> flag;
		switch(flag)
		{
				case 1:inPeople->addProduct();
					   cout << "add success!" << endl;
					   sleep(1);
				//	   inPeople->pt=p;
				//	   inPeople->writeRecord(2);
					   break;
				case 2:inPeople->show();
				//	   getchar();
					   system_pause();
					   break;
				case 3:inPeople->setPasswd();
					   break;
				case 4:inPeople->pp->writePeople();
					   inPeople->writeProductInfo();
					   changeFlag=0;
					   break;
				case 5:if(askForSave())
					   {
							   inPeople->pp->writePeople();
							   inPeople->writeProductInfo();
							   changeFlag=0;
					   }
					   return ;
				default:cout << "input error!" << endl;
						break;
		}
		}
}

void MenuOut::menuShow()
{
		int flag;
		pp.readPeople();
		system("clear");
		showTime();
		outPeople->pp->writePeople();
		while(1)
		{
				system("clear");
		cout << "\t\t\t\t\t◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎\n"
			 <<	"\t\t\t\t\t◎ 1:delete Product    ◎\n"
			 << "\t\t\t\t\t◎ 2:show information  ◎\n"
			 << "\t\t\t\t\t◎ 3:change passwd     ◎\n"
			 << "\t\t\t\t\t◎ 4:save              ◎\n"
			 << "\t\t\t\t\t◎ 5:exit              ◎\n"
			 << "\t\t\t\t\t◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎◎\n"
			 << "\t\t\t\t\tplease input your choice(1-5):" ;
		cin >> flag;
		switch(flag)
		{
				case 1:outPeople->deleteProduct();
					   break;
				case 2:outPeople->show();
					   system_pause();
					   break;
				case 3:outPeople->setPasswd();
					   break;
				case 4:outPeople->pp->writePeople();
					   outPeople->writeProductInfo();
					   changeFlag=0;
					   break;
				case 5:if(askForSave())
					   {
							   outPeople->pp->writePeople();
							   outPeople->writeProductInfo();
							   changeFlag=0;
					   }
					   return ;
				default:cout << "input error!" << endl;
						break;
		}
		}
}

void MenuCommon::menuShow()
{
		int flag;
		pp.readPeople();
		system("clear");
		showTime();
		commonPeople->pp->writePeople();
		while(1)
		{
				system("clear");
		cout   << "\t\t\t\t\t✪✪✪✪✪✪✪✪✪✪✪✪✪✪✪✪✪✪✪✪✪✪✪✪✪✪✪✪✪\n"
			   << "\t\t\t\t\t✪      1:search             ✪\n"
	//		   << "\t\t\t\t\t✪      2:show product       ✪\n"
			   << "\t\t\t\t\t✪      2:change passwd      ✪\n"
			   << "\t\t\t\t\t✪      3:show information   ✪\n"
			   << "\t\t\t\t\t✪      4:save               ✪\n"
			   << "\t\t\t\t\t✪      5:exit               ✪\n"
			   << "\t\t\t\t\t✪✪✪✪✪✪✪✪✪✪✪✪✪✪✪✪✪✪✪✪✪✪✪✪✪✪✪✪✪\n"
			   << "\t\t\t\t\tplease input your choice(1-5):";
		cin >> flag;
		switch(flag)
		{
				case 1:commonPeople->searchProduct();
					   system_pause();
					   break;
		//		case 2:commonPeople->showProduct();
		//			   system_pause();
		//			   break;
				case 2:commonPeople->setPasswd();
					   break;
				case 3:commonPeople->show();
					   system_pause();
					   break;
				case 4:commonPeople->pp->writePeople();
					   commonPeople->writeProductInfo();
					   changeFlag=0;
					   break;
				case 5:if(askForSave())
					   {
							   commonPeople->pp->writePeople();
							   commonPeople->writeProductInfo();
							   changeFlag=0;
					   }
					   return ;
				default:cout << "\t\t\t\t\tinput error!" << endl ;
						break;
		}
		}
}

int MenuMain::adminLogin()
{
		int limit=0,login=2,x;
		Person *lg;
		char passwd[32];
		char name[32];
		cout << "\t\t\t\t\tplease input the username:" ;
		cin >> name;
	//	lg=pp.searchName(name);
		if(strcmp(name,"admin")!=0)
		{
				cout << "username error!" << endl;
				sleep(1);
				return 0;
		}//	lg=pp.searchName(name);
		lg=pp.searchName(name);
		if(lg!=NULL)
				{  
				    lg->readStop();
	        		while(lg->getStop()>0)
					{ 	
						system("clear");
						cout << "\033[31m limit login!" << endl << "\033[31m countdown:" << "\033[37m" << lg->getStop() << endl;
						lg->subStop();
					    lg->writeStop();	
						sleep(1);
						if(lg->getStop()==0)
								return 0;
					}
						while(1)
						{
					        if(limit==3)
							{
									lg->setStop10();
									while(lg->getStop()>0)
									{
											system("clear");
											cout << "\033[31m limit login!" << endl << "\033[31m countdown:" << "\033[37m" << lg->getStop() << endl;
											lg->subStop();
											lg->writeStop();
											sleep(1);
									}
									return 0;
							}
							cout << "\t\t\t\t\tplease input the passwd:\033[08m" ;
							cin >> passwd;
							cout << "\033[28m";
							cout << "\033[37m";
				//			cout << "passwd:" << lg->getPasswd()  << endl;
							if(strcmp(passwd,lg->getPasswd())==0)
							{
									lg->pp=&pp;
									pd.readProduct();
				          		    lg->temp=&pd;
									ps=new Admin(lg);
								//	while(login>=0)
							//		{
							 			if(lg->getTime()!=0)
												cout << "\t\t\t\t\t上次登录时间:" << lg->getTime() << endl;
										else
												cout << "\t\t\t\t\twelcome new user!" << endl;
							//	        if(login==0)
							//			{
								//		    lg->readRecord();
											lg->setTime();
											lg->writeRecord();
							//				cout << "时间已记录!" << endl;
							//			}
										cout << "\t\t\t\t\t当前时间:" << lg->getTime() << "   已记录!" << endl<< endl;;
								//		cout << "当前时间:";
								//		showTime();
										srand((unsigned)time(NULL));
										while(login>0)
										{
												x=rand()%6;
										if(x==0)
										{
											 cout << "\033[1A";
											 cout << "\033[K";
											 cout << "\t\t\t\t\t\033[31m请稍候:" << login << endl;
								    		 login--;
											 sleep(1);
										}
										if(x==1)
										{
											cout << "\033[1A";
											cout << "\033[K";
											cout << "\t\t\t\t\t\033[32m请稍候:" << login << endl;
											sleep(1);
											login--;
										}
										if(x==2)
										{
											cout << "\033[1A";
											cout << "\033[K";
											cout << "\t\t\t\t\t\033[33m请稍候:" << login << endl;
											sleep(1);
											login--;
										}
										if(x==3)
										{
											cout << "\33[1A";
											cout << "\33[K";
											cout << "\t\t\t\t\t\033[34m请稍候:" << login << endl;
											sleep(1);
											login--;
										}
										if(x==4)
										{
											cout << "\33[1A";
											cout << "\33[K";
											cout << "\t\t\t\t\t\033[35m请稍候:" << login << endl;
											sleep(1);
											login--;
										}
										if(x==5)
										{
											cout << "\33[1A";
											cout << "\33[K";
											cout << "\t\t\t\t\t\033[36m请稍候:" << login << endl;
											sleep(1);
											login--;
										}
										}
										cout << "\33[1A";
										cout << "\033[K";
									    cout << "\t\t\t\t\t\033[37m请稍候:" << login << endl;
										sleep(1);
								//		system("clear");
									//	}
									//	cout << "welcome admin login in system" << endl;
										return 1;
							}
				
							else
							{
									cout << "\033[28m";
									cout << "\t\t\t\t\tpasswd error!" << endl;
									limit++;
							}
						}
				}

				
				else
				{
				//		cout << "11111" << endl;
						ps=new Admin;
				//		cout << "333333" << endl;
						ps->pp=&pp;
						ps->pp->push_back(ps);
						pd.readProduct();
						ps->temp=&pd;
						ps->setTime();
						return 1;
				}		
}


Person* MenuMain::login()
{
		int id,limit=0,login=2,x,i=0;
		char passwd[32];
		Person* lg;
		cout << "\t\t\t\t\tplease input your username:" ;
		cin >> id;
		lg=pp.searchNumber(id);
		if(lg!=NULL)
		{
			//	    lg->pp=&pp;
			//		pp.readPeople();
				    lg->readstop();
	        		while(lg->getStop()>0)
					{ 	
						system("clear");
						cout << "\033[31m limit login!" << endl << "\033[31m countdown:" << "\033[37m" << lg->getStop() << endl;
						lg->subStop();
						lg->writestop();
						sleep(1);
						if(lg->getStop()==0)
						{
								lg=NULL;
								return lg;
						}
					}
				while(1)
				{
						if(limit==3)
						{
								lg->setStop10();
									while(lg->getStop()>0)
									{
											system("clear");
											cout << "\033[31m limit login!" << endl << "\033[31m countdown:" << "\033[37m" << lg->getStop() << endl;
									     	lg->subStop();
											lg->writestop();
											sleep(1);
									}
									lg=NULL;
									return lg;
						}

					cout << "\t\t\t\t\tplease input your passwd:\033[08m" ;
					cin >> passwd;
					cout << "\033[28m" ;
					cout << "\033[37m" ;
		//			cout << "3333333" << endl;
					if(strcmp(passwd,lg->getPasswd())==0)
					{
							cout << "\033[28m";
							lg->pp=&pp;
							pd.readProduct();
							lg->temp=&pd;
								//	while(login>=0)
								//	{
							 			if(lg->getTime()!=0)
												cout << "\t\t\t\t\t上次登录时间:" << lg->getTime() << endl;
										else
												cout << "\t\t\t\t\twelcome new user!" << endl;
								  //      if(login==0)
									//	{
											lg->setTime();
											lg->writeRecord();
									//		cout << "时间已记录!" << endl;
									//	}
										cout << "\t\t\t\t\t当前时间:" << lg->getTime() << "   已记录!" << endl << endl;
									//	cout << "当前时间:";
									//	showTime();
									//	while(login>0)
									//	{
										srand((unsigned)time(NULL));
										while(login>0)
										{
												x=rand()%6;
										if(x==0)
										{
											 cout << "\033[1A";
											 cout << "\033[K";
											 cout << "\t\t\t\t\t\033[31m请稍候:" << login << endl;
								    		 login--;
											 sleep(1);
										}
										if(x==1)
										{
											cout << "\033[1A";
											cout << "\033[K";
											cout << "\t\t\t\t\t\033[32m请稍候:" << login << endl;
											sleep(1);
											login--;
										}
										if(x==2)
										{
											cout << "\033[1A";
											cout << "\033[K";
											cout << "\t\t\t\t\t\033[33m请稍候:" << login << endl;
											sleep(1);
											login--;
										}
										if(x==3)
										{
											cout << "\33[1A";
											cout << "\33[K";
											cout << "\t\t\t\t\t\033[34m请稍候:" << login << endl;
											sleep(1);
											login--;
										}
										if(x==4)
										{
											cout << "\33[1A";
											cout << "\33[K";
											cout << "\t\t\t\t\t\033[35m请稍候:" << login << endl;
											sleep(1);
											login--;
										}
										if(x==5)
										{
											cout << "\33[1A";
											cout << "\33[K";
											cout << "\t\t\t\t\t\033[36m请稍候:" << login << endl;
											sleep(1);
											login--;
										}
										}
										cout << "\33[1A";
										cout << "\033[K";
									    cout << "\t\t\t\t\t\033[37m请稍候:" << login << endl;
										sleep(1);
									//			cout << "\033[1A";
									//			cout << "\033[K";
									//			cout << "\t\t\t\t\t请稍候:" << login << endl;
									//			login--;
									//			sleep(1);
								//		}
									//	system("clear");
						//	if(lg->getTime()!=0)
							   //  	cout << "上次登录时间:" << lg->getTime() << endl;
					//		else
					//				cout << "welcome new user!" << endl;
					//		lg->setTime();
					//		cout << "当前时间:" << lg->getTime() << "   已记录!" << endl;				
					//		sleep(5);
							return lg;
					}
					else
					{
							cout << "\t\t\t\t\t\033[28mpasswd error!" << endl;
							limit++;
					}
				}
		}
		else
		{
				cout << "username is NULL!" << endl;
				sleep(1);
				return lg;
		}
}

void Menu::system_pause()
{
		getchar();
		puts("Press any key to continue...");
		system("stty raw");
		getchar();
		system("stty cooked");
}
/*
int Menu::getch(void)
{
		struct termios tm,tm_old;
		int fd=0,ch;
		if(tcgetattr(fd,&tm)<0)
		{
				return -1;
		}
		tm_old=tm;
		cfmakeraw(&tm);
		if(tcsetattr(fd,TCSANOW,&tm)<0)
		{
				return -1;
		}
		ch=getchar();
		if(tcsetattr(fd,TCSANOW,&tm_old)<0)
		{
				return -1;
		}
		return ch;
}
*/				
						


/*void Menu::run()
{
		//cout << title;
		  menuShow();
}*/

/*void flashMenu()
{
		for(int i=0;i<5;i++)
		{
		cout << "hello,thread!" << endl;
		sleep(1);
		}
}
*/
//void MenuMain::runMain()
//{
//		menuShow();
//}


int main()
{
		MenuMain mm;
		mm.menuShow();
	//  thread task01(flashMenu);
//		thread task02(mm.runMain);
		//task02.detach();
//		mm.menuShow();
		return 0;
}

#if 0
void MenuMain::flashShow()
{
        int i=10;
		printf("\033[s");
		printf("\033[?25l");
		while(i>0)
		{
		 if(i==10)
		printf("\033[8A");
		printf("\033[K");
		printf("\t\t\t\t\t\033[30m欢迎来到何朝阳の仓库管理系统!\033[37m\n");
    //  printf("\033[30m hello,world!i\033[37m");
	//	if(getch()!='@')
		sleep(1);
		printf("\033[1A");
		printf("\033[K");
		printf("\t\t\t\t\t\033[31m欢迎来到何朝阳の仓库管理系统!\033[37m\n");
	//	printf("\033[31m hello,world!i\033[37m\n");
		sleep(1);
		printf("\033[1A");
		printf("\t\t\t\t\t\033[32m欢迎来到何朝阳の仓库管理系统!\033[37m\n");
	//	printf("\033[32m hello,world!i\033[37m\n");
		sleep(1);
		printf("\033[1A");
		printf("\033[K");
		printf("\t\t\t\t\t\033[33m欢迎来到何朝阳の仓库管理系统!\033[37m\n");
	//	printf("\033[33m hello,world!i\033[37m\n");
		sleep(1);
		printf("\033[1A");
		printf("\033[K");
		printf("\t\t\t\t\t\033[34m欢迎来到何朝阳の仓库管理系统!\033[37m\n");
	  //  printf("\033[34m hello,world!i\033[37m\n");
		sleep(1);
		printf("\033[1A");
		printf("\033[K");
		printf("\t\t\t\t\t\033[35m欢迎来到何朝阳の仓库管理系统!\033[37m\n");
	//	printf("\033[35m hello,world!i\033[37m\n");
		sleep(1);
		printf("\033[1A");
		printf("\033[K");
		printf("\t\t\t\t\t\033[36m欢迎来到何朝阳の仓库管理系统!\033[37m\n");
	//	printf("\033[36m hello,world!i\033[37m\n");
		sleep(1);
		printf("\033[1A");
		printf("\033[K");
		printf("\t\t\t\t\t\033[37m欢迎来到何朝阳の仓库管理系统!\033[37m\n");
	//	printf("\033[37m hello,world!i\033[37m\n");
		sleep(1);
		printf("\033[1A");
		printf("\033[K");
		i--;
		}
		return ;
}
#endif



