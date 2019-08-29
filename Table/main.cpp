#include<iostream>
#include<fstream>
#include<limits>
#include<vector>
#include<string>
#include"employee.h"
using namespace std;
int main()
{
	vector<Employee*> database;
	bool quit=false;
	ofstream outFile("out.txt");
	//Employee* emp[50];
	int input,select1,j=0,sal,vac,meet,exp;
	string firstName;string lastName;string school;string topic;string knowCPP;string trade;string search;
	while(!quit)
	{
		cout<<"Database size:"<<database.size()<<endl;
		cout<<"Database contains:"<<endl;
		for(int k=0;k<database.size();k++)
		{
			database[k]->printStats();
			cout<<endl<<endl;
		}
		
		cout<<"\n1.Add an employee 2.Delete an employee 3.save 4. Exit ";
		cin>>select1;
		cout<<endl;
		switch(select1)
		{
		case 1:
			cout<<"\n1.Add a manager 2. Add an engineer 3.Add a researcher ";
			cin>>input;
			cin.ignore();
			switch(input)
			{
			case 1:
				cout<<"\nEnter first name:";
				getline(cin,firstName);
				cout<<"\nEnter last name:";
				getline(cin,lastName);
				cout<<"\nEnter salary:";
				cin>>sal;
				cout<<"\nEnter number of meetings in an year:";
				cin>>meet;
				cout<<"\nEnter number of vacations in year:";
				cin>>vac;
				//emp[j]=new Manager(firstName,lastName,sal,meet,vac);
				database.push_back(new Manager(firstName,lastName,sal,meet,vac));
				//emp[j]->save(outFile);
				//j++;
				break;
			case 2:
				cout<<"\nEnter first name:";
				getline(cin,firstName);
				cout<<"\nEnter last name:";
				getline(cin,lastName);
				cout<<"\nEnter salary:";
				cin>>sal;
				cout<<"\nEnter whether know c++ y/n:";
				cin>>knowCPP;
				cout<<"\nEnter trade:";
				cin>>trade;
				cout<<"\nEnter years of experience:";
				cin>>exp;
				//emp[j]= new Engineer(firstName,lastName,sal,knowCPP,exp,trade);
				database.push_back(new Engineer(firstName,lastName,sal,knowCPP,exp,trade));
				//emp[j]->save(outFile);
				//j++;
				break;
			case 3:
				cout<<"\nEnter first name:";
				getline(cin,firstName);
				cout<<"\nEnter last name:";
				getline(cin,lastName);
				cout<<"\nEnter salary:";
				cin>>sal;
				cin.ignore();
				cout<<"\nEnter the name of school of Phd.:";
				getline(cin,school);
				cout<<"\nEnter the topic pf Phd.:";
				getline(cin,topic);
				//emp[j]=new Researcher(firstName,lastName,sal,school,topic);
				database.push_back(new Researcher(firstName,lastName,sal,school,topic));
				//emp[j]->save(outFile);
				//j++;
				break;
			}
			break;
		case 2:
			cout<<"enter last name of employee to be deleted:";
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
			getline(cin,search);
			for(int l=0;l<database.size();l++)
			{
				if(database[l]->getLastName()==search)
				{
					database.erase(database.begin()+l);
					break;
				}
					
			}
		case 3:
			for(int i=0;i<database.size();i++)
			{
				database[i]->save(outFile);
				cout<<endl;
			}
			break;
		case 4:
			cout<<"\nExiting............";
			quit=true;
			break;
		}
	}
}