/*
filename: access specifiers.cpp
details: Program to demonstrate access specifiers
author: Badari vinay
date: 11/04/2020
*/
#include <iostream>
#include<string.h>
using namespace std;
class Base
{
 	private:
        int IM;
 	protected:
 	    int IN;
 	public:
 	    int IP;
	// Default constructor
 	Base() 
 	{
 	   IM = 1;
 	   IN = 2;
 	   IP = 3;
 	}
};
class Derive: private Base
{
 	public:
 	    void showdata()
 	    {
 	           cout <<  "   Using Accessmode as Private   " << endl;
               	   cout <<  "   M is not Accessible because we declared it as Private " << endl;             
               	   cout <<  "   Value of N is   " << IN << endl;
                   cout <<  "   Value of P is   " << IP << endl;
 	    }
};
class DeriveA: protected Base
{
 	public:
 	    void showdata()
 	    {
 	           cout<<   "   Using Accessmode as Protected  " << endl;
 	           cout <<  "   M is not Accessible because we declared it as Private " << endl;
               	   cout <<  "   Value of N is   " << IN << endl;
                   cout <<  "   Value of P is    " << IP << endl;
 	    }
};
class DeriveB: public Base
{
 	public:
 	    void showdata()
 	    {
 	           cout<<   "   Using Accessmode as Public  " << endl;;
 	           cout <<  "   M is not Accessible because we declared it as Private " << endl;
                   cout <<  "   Value of N is   " << IN << endl;
                   cout <<  "   Value of P is   " << IP << endl;
 	    }
};
int main(int argc,char *argv[])
{
	if(argc==2) 
	{
		// help command
		if(strcmp(argv[1],"-h")==0)     
        	{
			cout<<"\n Usage of file --> \n"
					"\t filename.exe & enter"<<endl<<
					" Program is used to demonstrate different access specifiers "<<endl;
		}	
	}
	else
	{
     Derive A;
     DeriveA B;
     DeriveB C;
     A.showdata();
     B.showdata();
     C.showdata();
     return 0;
	} 
}
