#include "people.h"

int Person::peopleMax=0;
//static int productMax=0;
int changeFlag=0;


#if 0
InPerson::InPerson(string a="",string b="",string c="",int d=0)
{
		name=a;
		passwd=b;
		department=c;
		number=d;
}
#endif

//Person::Person():name(""),passwd(""),department(""),id(0)
//{}

Person::Person():department("NULL"),pp(NULL),name(""),temp(NULL),loginTime("NULL"),stop(0)
{}

Person::~Person()
{}

Person::Person(char* name1):department("NULL"),pp(NULL),temp(NULL),loginTime("NULL"),stop(0)
{
		strcpy(name,name1);
}

Person::Person(Person *ps)
{
		//passwd=ps->getPasswd();
		strcpy(passwd,ps->getPasswd());
		id=ps->getNumber();
		stop=ps->getStop();
//		name=ps->getName();
		strcpy(name,ps->getName());
		if(ps->pp!=NULL)
				pp=ps->pp;
		if(ps->temp!=NULL)
				temp=ps->temp;
}

vector<int> Person::number(0);
void Person::setNumber()
{
		peopleMax++;
		changeFlag=1;
		vector<int>::iterator it;
		for(int i=1;i<peopleMax+1;i++)
		{
				it=find(number.begin(),number.end(),i);
				if(it==number.end())
				{
						id=i;
						number.push_back(i);
						return;
				}
		}
}

void Person::deleteId()
{
		vector<int>::iterator it;
		it=find(number.begin(),number.end(),id);
		if(it!=number.end())
		{
				number.erase(it);
				peopleMax--;
		}
		else
		{
				cout << "\t\t\t\t\tdelete error!" << endl;
		}
}

People::People()
{}
void Person::setName()
{
		changeFlag=1;
		cout << "\t\t\t\t\tplease input the name:" ;
		cin >> name;
}

void Person::setTime()
{
		time_t t;
		struct tm *timeinfo;
		time(&t);
		timeinfo=localtime(&t);
		strftime(loginTime,50,"%Y年%m月%d日-%H:%M:%S",timeinfo);
}

char* Person::getTime()
{
		if(strcmp(loginTime,"NULL")==0)
				return 0;
		else
				return loginTime;
}

void Person::setPasswd()
{
		changeFlag=1;
		cout << "\t\t\t\t\tplease input the passwd:" ;
		cin >> passwd;
}

char* Person::getName()
{
		return name;
}

char* Person::getPasswd()
{
		return passwd;
}

int Person::getNumber()
{
		return id;
}

void Person::insert()
{
		setName();
		setPasswd();
}


void Person::changeInfo()
{
		int flag;
		cout << "\t\t\t\t\t1:change the name." << endl << "\t\t\t\t\t2:change the Number." << endl << "\t\t\t\t\t3:exit." << endl <<  "\t\t\t\t\tplease choice:" ;
		cin >> flag;
		switch(flag)
		{
				case 1: setName();
						break;
				case 2:	setNumber();
						break;
				case 3: return ;
				default:cout << "\t\t\t\t\tinput error!" << endl;
						break;
		}
}

void Person::show()
{
	cout << "name:" << name << "     " << "id:" << id << "      " <<  "department:" << department << endl;
}

void People::add()
{
		Person *p;
		int flag;
		while(1)
		{
			cout << "\t\t\t\t\t1:inPeople" << endl << "\t\t\t\t\t2:outPeople" << endl << "\t\t\t\t\t3:commonPeople" << endl << "\t\t\t\t\t4:exit" << endl << "\t\t\t\t\tplease input the your choice:" ;
			cin >> flag;
			switch(flag)
			{
				case 1:p=new InPeople;
					   break;
				case 2:p=new OutPeople;
					   break;
				case 3:p=new CommonPeople;
					   break;
				case 4:return ;
				default:p=NULL;
						cout << "\t\t\t\t\tinput error!" << endl;
						break;
			}
			if(p!=NULL)
			{
	//			cout << "123213" << endl;
				p->setNumber();
				p->setName();
				p->setPasswd();
				p->setStop();
				this->push_back(p);
				break;
			}
		}
		return ;
}

void Person::subStop()
{
		stop--;
}

void Person::setStop()
{
		stop=0;
}

void Person::setStop10()
{
		stop=10;
}

int Person::getStop()
{
		return stop;
}

void Person::writeStop()
{
		ofstream st;
		st.open("stop",ios::out);
		if(st.is_open())
		{
				st << stop;
		}
		else
				cout << "open failed!" << endl;
		st.close();
}

void Person::readStop()
{
		ifstream st;
		st.open("stop",ios::in);
		while(!st.eof())
		{
				st >> stop;
				st.close();
		}
}


void Person::writestop()
{
		ofstream st;
		st.open("stop1",ios::out);
		if(st.is_open())
		{
				st << stop;
		}
		else
				cout << "open failed!" << endl;
		st.close();
}

void Person::readstop()
{
		ifstream st;
		st.open("stop1",ios::in);
		while(!st.eof())
		{
				st >> stop;
				st.close();
		}
}
void People::showAll()
{
	//	cout << "test 169" << endl;
		vector<Person*>::iterator it;
		for(it=begin();it!=end();it++)
		{
				(*it)->show();
		}
}

void People::deleteNumber(const int &id)
{
		vector<Person*>::iterator it;
		changeFlag=1;
		char t;
	 	for(it=begin();it!=end();it++)
		{
				if((*it)->getNumber()==id)
				{
						cout << "\t\t\t\t\tthe person data is:" ;
						(*it)->show() ; 
						getchar();
						cout << "\t\t\t\t\tdo you want to delete it?(y/n)" ;
						t=getchar();
						if(t=='n')
						{
								return ;
						}
						(*it)->deleteId();
		  //               cout << "test 187" << endl;
				//		delete(*it);
		    //             cout << "test 189" << endl;
						erase(it);
				
				cout << "\t\t\t\t\tdelete success!" << endl;
				return ;
				}
		}
		cout << "\t\t\t\t\tdelete error!" << endl;
}

void People::deleteName(const char* name)
{
		vector<Person*>::iterator it;
		changeFlag=1;
		char t;
		for(it=begin();it!=end();it++)
		{
				if(strcmp((*it)->getName(),name)==0)
				{
						getchar();
						cout << "\t\t\t\t\tthe person data is:";
						(*it)->show();
						cout << "\t\t\t\t\tdo you want to delete it?(y/n)";
						t=getchar();
						if(t=='y')
						{
						(*it)->deleteId();
		//				delete(*it);
						erase(it);
				        cout << "\t\t\t\t\tdelete success!" << endl;
				         return ;
						}
						if(t=='n')
						{
								continue;
						}
				}
		}
						cout << "\t\t\t\t\tdelete error!" << endl;
}

void People::deletePeople()
{
		int flag,id;
		char name[32];
		while(1)
		{
			cout << "\t\t\t\t\t1:by the name." << endl << "\t\t\t\t\t2:by the id." << endl << "\t\t\t\t\t3:exit." << endl << "\t\t\t\t\tplease choice the delete way:" ;
			cin >> flag;
			switch(flag)
			{
					case 1:
						   cout << "\t\t\t\t\tplease input the name:";
						   cin >> name;
					   	deleteName(name);
					   	break;
			    	case 2:
						   cout << "\t\t\t\t\tplease input the number:";
					   	   cin >> id;
					  	   deleteNumber(id);
					  	   break;
					case 3:return ;
					default:
						   cout << "\t\t\t\t\tinput error!" << endl;
					   	   break;
			}
		}
}

Person* People::searchNumber(const int &id)
{
	//	cout << "111111" << endl;
		vector<Person*>::iterator it;
		for(it=begin();it!=end();it++)
		{
				if((*it)->getNumber()==id)
				{
						return (*it);
				}
		}
		return NULL;
}

Person* People::searchName(const char* name)
{
//		cout << "1111111" <<endl
		vector<Person*>::iterator it;
	//	it=begin();
	//	string name1;
	//	name1=(*it)->getName();
	//	cout << name1 <<endl;
	//	cout << "22222" << endl;
		for(it=begin();it!=end();it++)
		{
			if(strcmp((*it)->getName(),name)==0)
						return (*it);
		}
		cout << "\t\t\t\t\tNULL" << endl;
		return NULL;
}

void People::writePeople()
{
		ofstream out("people",ios::binary);
		if(!out)
		{
				cout << "\t\t\t\t\topen failed!" << endl;
				return ;
		}
		else
		{
				vector<Person*>::iterator it;
				for(it=begin();it!=end();it++)
				{
						out.write((char*)(*it),sizeof(Person));
				}
		}
		out.close();
		//cout << "\t\t\t\t\twrite success!" << endl;
}

void People::delAll()
{
		this->clear();
}

void People::readPeople()
{
		ifstream in("people",ios::binary);
		if(!in)
		{
				cout << "\t\t\t\t\topen failed!" << endl;
				return ;
		}
		else
		{
				delAll();
				vector<Person*>::iterator it;
				it=begin();
				(*it)->number.clear();
				(*it)->peopleMax=0;
				Person *pe;
				while(1)
				{
						pe=new Person;
						in.read((char*)(pe),sizeof(Person));
						if(!in.eof())
						{
								this->push_back(pe);
								pe->number.push_back(pe->getNumber());
						}
						else
						{
								delete(pe);
								break;
						}
						(*it)->peopleMax=this->size();
				}
				in.close();
		}
}

void Person::writeRecord()
{
		ofstream record;
	//	int gn;
	//	char gt[50];
	//	gn=getNumber();
	//	gt=getTime();
		record.open("record",ios::app);
		if(record.is_open())
		{
					record << "Id:"  << getNumber() << "   time:" << getTime() << "  login in the system!\n"  ;
			/*	if(i==2)
				{
						record << "Id:" << getNumber() << "   time:" << pt->getLoginTime() << "   incoming:" << pt->getId() << "\n" ; 
				}
				if(i==3)
				{
						record << "Id:" << getNumber() << "   time:" << pt->getLoginTime() << "   outcoming:" << pt->getId() << "\n" ;
				}*/
		}
		else
				cout <<"open failed!" << endl;
		record.close();
}

void Person::readRecord()
{
		ifstream record;
		char rec[500];
		record.open("record",ios::in);
		if(record.is_open())
		{
				while(!record.eof())
				{
					record.getline(rec,sizeof(rec));
					cout << rec << endl;
				}
				cout << "\033[1A" ;
				cout << "\033[K";
//				cout << endl;
		}
		record.close();
}


void Admin::writePeopleInfo()
{
		pp->writePeople();
}

void Admin::readPeopleInfo()
{
		pp->readPeople();
}

char* Person::getType()
{
		return department;
}

People People::searchType(const char* type)
{
		vector<Person*>::iterator it;
		People p2;
		for(it=begin();it!=end();it++)
		{
				if((*it)->getType()==type)
						p2.push_back(*it);
		}
		return p2;
}

void People::search()
{
		Person *p;
		People p1;
		char t;
		char name[32];
		char type[32];
		int id,flag;
		while(1)
		{
				cout << "\t\t\t\t\t1:by the name." << endl << "\t\t\t\t\t2:by the number." << endl << "\t\t\t\t\t3:search the type" << endl << "\t\t\t\t\t4:exit" << endl << "\t\t\t\t\tplease choice the search way:" ;
				cin >> flag;
				switch(flag)
				{
						case 1:
								cout << "\t\t\t\t\tplease input the name:" ;
								cin >> name;
								p=searchName(name);
								if(p==NULL)
								{
										cout << "\t\t\t\t\tsearch failed" << endl ;
										break;
								}
								else
								{
										cout << "\t\t\t\t\tsearch success!" << endl;
										p->show();
										getchar();
										cout << "\t\t\t\t\tdo you want to change it?(y/n)";
										t=getchar();
										if(t=='n')
												return ;
										else
												p->changeInfo();
												break;
								}
						case 2:
								cout << "\t\t\t\t\tplease input the id:" ;
								cin >> id;
								p=searchNumber(id);
								if(p==NULL)
								{
										cout << "\t\t\t\t\tsearch failed!" << endl;
										break;
								}
								else
								{
										cout << "\t\t\t\t\tsearch success!" << endl;
										p->show();
										getchar();
										cout << "\t\t\t\t\tdo you want to change it?(y/n)";
										t=getchar();
										if(t=='n')
												return ;
										else
												p->changeInfo();
												break;
								}
						case 3:
								cout << "\t\t\t\t\t1:admin" << endl << "\t\t\t\t\t2:inpeople" << endl << "\t\t\t\t\t3:outpeople" << endl << "\t\t\t\t\t4:commonpeople" << endl << "\t\t\t\t\t5:exit" << endl << "\t\t\t\t\tplease input your choice:" ;
								cin >> flag;
								switch(flag)
								{
										case 1://type="Admin";
											   strcpy(type,"admin");
											   p1=searchType(type);
											   p1.showAll();
											   break;
										case 2://type="InPeople";
											   strcpy(type,"InPeople");
											   p1=searchType(type);
											   p1.showAll();
											   break;
										case 3://type="OutPeople";
											   strcpy(type,"OutPeople");
											   p1=searchType(type);
											   p1.showAll();
											   break;
										case 4://type="CommonPeople";
											   strcpy(type,"CommonPeople");
											   p1=searchType(type);
											   p1.showAll();
											   break;
										case 5:break;
										default:cout << "\t\t\t\t\tinput error!" << endl;
												break;
								}break;
						case 4:return ;

						default:
								cout << "\t\t\t\t\tinput error!" << endl;
								break;
				}		
		/*		cout << "continue?(y/n)" ;
				getchar();
				if((getchar())=='n')
						return ;    */
		}
}

InPeople::InPeople(Person *in):Person(in)
{
	//	department="InPeople";
		strcpy(department,"InPeople");
}

OutPeople::OutPeople(Person *ps):Person(ps)
{
//		department="OutPeople";
		strcpy(department,"OutPeople");
}

CommonPeople::CommonPeople(Person *cp):Person(cp)
{
//		department="CommonPeople";
		strcpy(department,"CommonPeople");
}

InPeople::InPeople()
{
//		department="InPeople";
		strcpy(department,"InPeople");
}

OutPeople::OutPeople()
{
//		department="OutPeople";
		strcpy(department,"OutPeople");
}

CommonPeople::CommonPeople()
{
//		department="CommonPeople";
		strcpy(department,"CommonPeople");
}

void InPeople::addProduct()
{
		temp->addProduct();
}

void OutPeople::deleteProduct()
{
		temp->deleteAll();
}

void CommonPeople::searchProduct()
{
		temp->commonSearch();
}

void CommonPeople::showProduct()
{
		temp->showAll();
}

Admin::Admin():Person((char*)("admin"))
{
		strcpy(department,"admin");
		setPasswd();
		setNumber();
		//setStop();
}

Admin::Admin(Person* ps):Person(ps)
{
	//	cout << "test " << endl;
		strcpy(department,"admin");
		strcpy(name,"admin");
		strcpy(passwd,"1997");
		//stop=0;
}

void Admin::showProduct()
{
		temp->showAll();
}

void Admin::addPerson()
{
		pp->add();
}

void Admin::deletePerson()
{
		pp->deletePeople();
}

void Admin::searchPerson()
{
		pp->search();
}
void Admin::showPerson()
{
		pp->showAll();
}

Admin::~Admin()
{}

InPeople::~InPeople()
{}

OutPeople::~OutPeople()
{}

CommonPeople::~CommonPeople()
{}

/*void Person::readProductInfo()
{
		temp->readProduct();
}*/

void Person::writeProductInfo()
{
		temp->writeProduct();
}

void Admin::searchProduct()
{
		temp->search();
}
