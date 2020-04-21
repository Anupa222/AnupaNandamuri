/*what is the purpose and difference in public, private and protected access specifiers.  Illustrate a design example with this. 
Filename: AccessSpecifier.cpp
Purpose : Program to demonstrate Access Specifiers
Author  : N.Anupa
Date    : 11/04/2020
*/
#include <iostream>
#include<string.h>
using namespace std;
//creating a base class constructor
class Base
{
	//declaring variables in public,protected and private mode
 	private:
        int IM;
 	protected:
 	    int IN;
 	public:
 	    int IP;
	// Default constructor
 	Base() 
 	{
 	//Assigning values to the variables declared in base class
 	   IM = 1;
 	   IN = -2;
 	   IP = -4+1;
 	}
};
//Inheriting the properties of base class in Private mode to Derived class
class Derive: private Base
{
 	public:
 	    void showdata()
 	    {
 	        		cout <<  " \n ****&&&& Using Accessmode as PRIVATE &&&&****  " << endl;
               	   	cout <<  " \n  M is not Accessible because we declared it as Private " << endl;             
               	   	cout <<  " \n  Value of N is   " << IN << endl;
                   	cout <<  " \n  Value of P is   " << IP << endl;
 	    }
};
//Inheriting the properties of base class in Protected mode to Derived Class A
class DeriveA: protected Base
{
 	public:
 	    void showdata()
 	    {
 	           	cout<<   "   \n          Using Accessmode as PROTECTED          " << endl;
 	           	cout <<  "   \n M is not Accessible because we declared it as Private " << endl;
            	cout <<  "   \n Value of N is   " << IN << endl;
                cout <<  "   \n Value of P is    " << IP << endl;
 	    }
};
//Inheriting The properties of Base class in Public mode to Derived class B
class DeriveB: public Base
{
 	public:
 	    void showdata()
 	    {
 	           	cout<<   "   \n           Using Accessmode as PUBLIC          " << endl;;
 	           	cout <<  "   \n M is not Accessible because we declared it as Private " << endl;
            	cout <<  "   \n Value of N is   " << IN << endl;
                cout <<  "   \n Value of P is   " << IP << endl;
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
					" This Program is to demonstrate different access specifiers "<<endl;
		}	
	}
	else
	{
	//creating objects for the derived classes and printing the output using showdata function
     Derive A;
     DeriveA B;
     DeriveB C;
     A.showdata();
     B.showdata();
     C.showdata();
     return 0;
	} 
}
