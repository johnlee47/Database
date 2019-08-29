#ifndef EMPLYOEE_H
#define EMPLOYEE_H
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class Employee
{
public:
	Employee(string firstName,string lastName,int salary)
	{mFirstName=firstName;mLastName=lastName;mSalary=salary;}
	virtual void printStats()
	{
		cout<<"First name:"<<mFirstName<<endl;
		cout<<"Last name:"<<mLastName<<endl;
		cout<<"Salary:"<<mSalary<<endl;
	} 
	virtual void save(ofstream& outFile)
	{
		outFile<<"First name:"<<mFirstName<<endl;
		outFile<<"Last name:"<<mLastName<<endl;
		outFile<<"Salary:"<<mSalary<<endl;
	}
	string getLastName()
	{ return mLastName;}
protected:
	string mFirstName;
	string mLastName;
	int mSalary;
};
class Engineer: public Employee
{
public:
	Engineer(string firstName,string lastName,int salary,string knowCPP,int yearsExp,string trade):Employee(firstName,lastName,salary)
	{
		mKnowCPP=knowCPP;mYearsExp=yearsExp;mtrade=trade;}
	void Save(ofstream& outFile)
	{
		Employee::save(outFile);
		outFile<<"know c++:"<<mKnowCPP<<endl;
		outFile<<"Years of exp:"<<mYearsExp<<endl;
		outFile<<"trade:"<<mtrade<<endl;
	}
	void PrintStats()
	{
		Employee::printStats();
		cout<<"know c++:"<<mKnowCPP<<endl;
		cout<<"Years of exp:"<<mYearsExp<<endl;
		cout<<"trade:"<<mtrade<<endl;
	}
protected:
	string mFirstName;
	string mLastName;
	int mSalary;
	string mKnowCPP;
	int mYearsExp;
	string mtrade;
};
class Manager: public Employee
{
public:
	Manager(string firstName,string lastName,int salary,int meet,int vac):Employee(firstName,lastName,salary)
	{mMeet=meet;mVac=vac;}
	void Save(ofstream& outFile)
	{
		Employee::save(outFile);
		outFile<<"Number of meetings:"<<mMeet<<endl;
		outFile<<"Number of holidays:"<<mVac<<endl;
	}
	void printStats()
	{
		Employee::printStats();
		cout<<"Number of meetings:"<<mMeet<<endl;
		cout<<"Number of holidays:"<<mVac<<endl;
	}
protected:
	int mMeet;
	int mVac;
};
class Researcher:public Employee
{
public:
	Researcher(string firstName,string lastName,int salary,string schoolPhd,string PhdTopic):Employee(firstName,lastName,salary)
	{mSchoolPhd=schoolPhd;mPhdTopic=PhdTopic;}
	void save(ofstream& outFile)
	{
		Employee::save(outFile);
		outFile<<"School of Phd.:"<<mSchoolPhd<<endl;
		outFile<<"Phd. topic:"<<mPhdTopic<<endl;
	}
protected:
	string mSchoolPhd;
	string mPhdTopic;
};

#endif 