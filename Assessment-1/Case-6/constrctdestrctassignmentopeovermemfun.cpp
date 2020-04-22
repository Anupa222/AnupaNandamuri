/*
Given a class has a two private member vairables int* and char[20]. 
Complete the class declaration and definition with all the necessary constructors/destructor/operator overloading/member functions. 
Write a method display() which will display the int and char variables for the given object. 
Note: Think on what compiler add when we create a class and try to implement.

Purpose :To write a program using constructor,destructor,operator overloading and member functions and print the output using display() function
Filename:constrctdestrctassignmentopeovermemfun.cpp
Author 	:N.Anupa
Date   	:19/04/2020 
*/ 

#include<iostream>
#include<string.h>
using namespace std;
//creating a class called CopyConstructor
class CopyConstructor
{
   //Taking two private member variables
    char *s_copy;
    int *ptr;
    public:
	CopyConstructor(int m)
	{
		*ptr=m;
	}
    CopyConstructor(const char *str,int p)
    {
    	//Dynamically Allocating Memory
        s_copy = new char[strlen(str)+1];
        strcpy(s_copy, str);
		ptr=new int;
		*ptr=p;
    }

 CopyConstructor(CopyConstructor &s,CopyConstructor &p)
    {
		cout<<"deepcopy"<<endl;
		s_copy=new char[strlen(s.s_copy)+1];
        strcpy(s_copy, s.s_copy);
		ptr=new int;
		*ptr=p.getx();
    }
	int getx()
	{
		return *ptr;
	}
    // concatenate method
    void concatenate(const char *str,int m)
    {
    	//Concatenation Of two strings
        strcpy(s_copy, str);
		*ptr=m;
    }
    /* destructor */
   ~CopyConstructor ()
    {

    } 
    //Assignment operator overloading
    void operator =(CopyConstructor &C)
	{
		
		*ptr=C.getx();
		s_copy = C.s_copy;
	}		
    void display()
    {
        cout<<s_copy<<endl;
		cout<<*ptr<<endl;
    }
    void display1()
    {
		cout<<*ptr<<endl;
    }
};
/* main function */
int main(int argc,char *argv[])
{
		//Help command to print the usage of the file
    if(argc==2) 
	{
		if(strcmp(argv[1],"-h")==0)     
        {
			cout<<"\n Usage of file --> \n\t filename.exe & enter"<<endl<<"Program used to demonstrate class declaration and definition with all the necessary constructors/destructor/operator overloading/member functions. "<<endl;
		}	
	}
	else
	{
    CopyConstructor c1("Copy",9);
   		//Copy constructor
    	CopyConstructor c2=c1;
    	c1.display();
    	c2.display();
    	cout<<"operator overloading"<<endl;

    CopyConstructor c3(20);
        c3.display1();
		c3=c2;
		c3.display1();
    	//c1 is invoking concatenate()
		c1.concatenate("Constructor",8);
    	c1.display();
    	c2.display();
	}
    return 0;
}
