/*
Filename: Case3(2)-ModifierType.cpp
Details: Program to demonstrate Modifier types
Author: N.Anupa
date: 12/04/2020
*/
#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;

// main function
int main(int argc,char *argv[])
{
	int iNumb;
	short int a;		// declaring varible as short integer
	long int b;			// declaring varible as long integer 
	unsigned short c;	// declaring varible as unsigned short 
	signed short d;		// declaring varible as signed short
	
    	if(argc==2) 
	{
		if(strcmp(argv[1],"-h")==0)     //created a help command
        	{
			cout<<"\n Usage of file --> \n"
					"\t filename.exe & enter"<<endl<<
					" Program used to demonstrate Modifier types "<<endl;
		}	
	}
	else
	{		
		cout << "enter value: ";
		cin>>iNumb;
		a=c=d=b=iNumb;    //value of a, b, c and d is assigned same 
		
		cout << " short int = " << a << endl;        //outputs of the values based on modifiers
		cout << " long int = " << b << endl;
		cout << " unsigned short = " << c << endl;
		cout << " signed short = " << d << endl;
		
		return 0;
	} 
}
