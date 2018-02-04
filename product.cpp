#include "product.h"

int Product::productMax=0;
extern int changeFlag;
vector<int> Product::number(0);

Product::Product():name(""),type(""),price(0),id(0),logintime("NULL")
{}

Product::~Product()
{}

void Product::setId()
{
		productMax++;
		srand((unsigned)time(NULL));
		changeFlag=1;
		vector<int>::iterator it;
//		for(int i=10000;i<productMax+10000;i++)
		for(int i=0;i<productMax;i++)
		{
				it=find(number.begin(),number.end(),i);
				if(it==number.end())
				{
						while(1)
						{
						id=rand();
						for(it=number.begin();it!=number.end();it++)
						{
								if(id==(*it))
								{
										break;
								}
						}
						number.push_back(i);
						return ;
						}
				}
		}
}

void Product::setName()
{
		changeFlag=1;
		cout << "\t\t\t\t\tplease input the name:" ;
		cin >> name;
}

void Product::setType()
{
		changeFlag=1;
		int flag;
		cout << "\t\t\t\t\t1:clothes" << endl << "\t\t\t\t\t2:food" << endl << "\t\t\t\t\t3:commodity" << endl << "\t\t\t\t\t4:exit" << endl << "\t\t\t\t\tplease choice the type:" ;
		cin >> flag;
		switch(flag)
		{
				case 1://type="clothes";
					   strcpy(type,"clothes");
					   break;
				case 2://type="food";
					   strcpy(type,"food");
					   break;
				case 3://type="commodity";
					   strcpy(type,"commodity");
					   break;
				case 4:return ;
			    default:cout << "input error!" << endl;
						break;
		}
}

void Product::setPrice()
{
		changeFlag=1;
		cout << "\t\t\t\t\tplease input the price:";
		cin >> price;
}

void Product::show()
{
		cout << "name:" <<  name << "     " << "type:" << type << "    " << "price:" <<  price << "    " << "id:" << id << "     " << "time:" << logintime << endl;
}

int  Product::getId()
{
		return id;
}

void Product::setLoginTime()
{
		time_t t;
		struct tm *timeinfo;
		time(&t);
		timeinfo=localtime(&t);
		strftime(logintime,50,"%Y年%m月%d日-%H:%M:%S",timeinfo);
}

char* Product::getLoginTime()
{
		if(strcmp(logintime,"NULL")==0)
				return 0;
		else
				return logintime;
}		
char* Product::getName()
{
		return name;
}

char* Product::getType()
{
		return type;
}

float Product::getPrice()
{
		return price;
}

void Product::deleteId()
{
		vector<int>::iterator it;
		changeFlag=1;
		it=find(number.begin(),number.end(),id);
		if(it!=number.end())
		{
				number.erase(it);
				productMax--;
		}
		else
				cout << "\t\t\t\t\tdelete error!"  << endl;
}

Products::Products()
{}

int Product::getProductMax()
{
		return productMax;
}

void Products::addProduct()
{
		Product *p;
		char buf[1000];
		p=new Product;
		p->setId();
		p->setName();
		p->setType();
		p->setPrice();
		p->setLoginTime();
		push_back(p);
	//	return *p;
		sprintf(buf,"qrencode \"name=%s\ttype=%s\tprice=%f\ttime=%s\" -o %d.png",p->getName(),p->getType(),p->getPrice(),p->getLoginTime(),p->getId());
		system(buf);
}

void Products::deleteId(const int &id)
{
		vector<Product*>::iterator it;
		changeFlag=1;
		char t;
		char buf[50];
		for(it=begin();it!=end();it++)
		{
				if((*it)->getId()==id)
				{
						cout << "the product data is:" ;
						(*it)->show() ;
				//		getchar();
						cout << "do you want to delete it?(y/n)" ;
						t=getchar();
						if(t=='n')
						{
								return ;
						}
						sprintf(buf,"rm %d.png",(*it)->getId());
						system(buf);
						(*it)->deleteId();
						erase(it);
						cout << "\t\t\t\t\tdelete success!" << endl;
						return ;
				}
		}
		cout << "\t\t\t\t\tdelete error!" << endl;
}

void Products::deleteName(const char* name)
{
		vector<Product*>::iterator it;
		changeFlag=1;
		char buf[50];
		char t;
		for(it=begin();it!=end();it++)
		{
				if(strcmp((*it)->getName(),name)==0)
				{
						getchar();
						cout << "\t\t\t\t\tthe product data is:" ;
						(*it)->show() ;
						cout << "\t\t\t\t\tdo you want to delete it?(y/n)" ;
						t=getchar();
						if(t=='y')
						{
						  sprintf(buf,"rm %d.png",(*it)->getId());
						  system(buf);
						  (*it)->deleteId();
					//	 delete(*it);
						   erase(it);
						 cout << "\t\t\t\t\tdelete success!" << endl;
						 return ;
						}
						if(t='n')
						{
								continue;
						}
				}
		}
		cout << "\t\t\t\t\tdelete error!" << endl;
}

void Products::deleteAll()
{
		int flag,id;
		string scan;
		cout << "\t\t\t\t\tplease scan the qrencode!" << endl;
		cin >> scan;
		char name[32];
		cout << "\t\t\t\t\t1:by the id." << endl << "\t\t\t\t\t2:by the name." << endl << "\t\t\t\t\t3:exit" << endl << "\t\t\t\t\tplease the delete way:" ;
		cin >> flag;
		switch(flag)
		{
				case 1:
		            //   cout << "\t\t\t\t\tplease scan the qrencode!" << endl;
		            //   cin >> scan;
						cout << "\t\t\t\t\tplease input the id:" ;
						cin >> id;
						deleteId(id);
						sleep(1);
						break;
				case 2:
						cout << "\t\t\t\t\tplease input the name:" ;
						cin >> name;
						deleteName(name);
						sleep(1);
						break;
				case 3:return ;
				default:
						cout << "\t\t\t\t\tinput error!" << endl;
						break;
		}
}


Product* Products::searchId(const int &id)
{
		vector<Product*>::iterator it;
		for(it=begin();it!=end();it++)
		{
				if((*it)->getId()==id)
				{
						return (*it);
				}
		}
		return NULL;
}

Product* Products::searchName(const char* name)
{
		vector<Product*>::iterator it;
		for(it=begin();it!=end();it++)
		{
				if(strcmp((*it)->getName(),name)==0)
				{
						return (*it);
				}
		}
		return NULL;
}

Products Products::searchType(const char* Type)
{
		vector<Product*>::iterator it;
		Products pts;
		for(it=begin();it!=end();it++)
		{
				if(strcmp((*it)->getType(),Type)==0)
				{
					pts.push_back(*it);	
				}
		}
		return pts;
}


void  Products::commonSearch()
{
		int id;
		Products s;
		Product *p;
		cout << "\t\t\t\t\tplease input the number:" ;
		cin >> id;
		p=searchId(id);
		if(p!=NULL)
		{	
				p->show();
	   }
		else
		{
				cout << "\t\t\t\t\tit is not in the warehouse!" << endl;
		}
}

void Products::search()
{
		int flag,id,flag1;
		char name[32];
		char type[32];
		Products s;
		Product *p;
		cout << "\t\t\t\t\t1:by the name." << endl << "\t\t\t\t\t2:by the id." << endl << "\t\t\t\t\t3:by the type." << endl << "\t\t\t\t\t4:exit." << endl << "\t\t\t\t\tplease choice the search way:" ;
		cin >> flag;
		switch(flag)
		{
				case 1:cout << "\t\t\t\t\tpleae input the name:" ;
					   cin >> name;
					   p=searchName(name);
					   if(p!=NULL)
					   {
							   p->show();
							   break;
					   }
					   else
					   {
							   cout << "\t\t\t\t\twithout the name!" << endl;
							   break;
					   }
				case 2:cout << "\t\t\t\t\tplease input the id:" ;
					   cin >> id;
					   p=searchId(id);
					   if(p!=NULL)
					   {
							   p->show();
							   break;
					   }
					   else
					   {
							   cout << "\t\t\t\t\twithout the id!" << endl;
							   break;
					   }
				case 3:cout << "\t\t\t\t\t1:food" << endl << "\t\t\t\t\t2:clothes" << endl << "\t\t\t\t\t3:commodity" << endl << "\t\t\t\t\t4:exit" << endl << "\t\t\t\t\tplease choice the type:" ;
					   cin >> flag1;
					   switch(flag)
					   {
							   case 1:strcpy(type,"food");
									  s=searchType(type);
									  s.showAll();
									  break;
							   case 2:strcpy(type,"clothes");
									  s=searchType(type);
									  s.showAll();
									  break;
							   case 3:strcpy(type,"commodity");
									  s=searchType(type);
									  s.showAll();
									  break;
							   case 4:break;
							   default:cout << "\t\t\t\t\tinput error!" << endl;
									   break;
					   }
					   break;
				case 4:return ;
				default:
					   cout << "\t\t\t\t\tinput error!" << endl;
					   break;
		}
}

void Products::showAll()
{
		vector<Product*>::iterator it;
		if(this->size()==0)
		{
				cout << "\t\t\t\t\tno product!" << endl;
				return ;
		}
		else
				for(it=begin();it!=end();it++)
						(*it)->show();
}
									  
void Products::delAll()
{
		this->clear();
}

void Products::readProduct()
{
		ifstream in("product",ios::binary);
		if(!in)
		{
				cout << "\t\t\t\t\topen failed" << endl ;
				return ;
		}
		else
		{
		    delAll();
			Product *p;
			vector<Product*>::iterator it;
			it=begin();
			while(1)
			{
					p=new Product;
					in.read((char*)(p),sizeof(Product));
					if(!in.eof())
					{
							this->push_back(p);
							p->number.push_back(p->getId());
					}
					else
					{
							delete(p);
							break;
					}
			}
			(*it)->productMax=this->size();
		}
		in.close();
}


void Products::writeProduct()
{
		ofstream out("product",ios::binary);
		if(!out)
		{
				cout << "\t\t\t\t\topen failed" << endl;
				return ;
		}
		else
		{
				vector<Product*>::iterator it;
				for(it=begin();it!=end();it++)
				{
						out.write((char*)(*it),sizeof(Product));
				}
		}
		out.close();
}



















