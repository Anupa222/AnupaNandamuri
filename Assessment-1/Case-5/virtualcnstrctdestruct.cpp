/*
  Write your own program that explains the 
	Different way to initialize the private member variables in a class. 
	Order of the construction and destruction of objects with and without virtual. 
Purpose : To Initialize the private member variables in different ways and also to construct and destruct the objects with and with out virtual
Filename:virtualcnstrctdestruct.cpp
Author 	:N.Anupa
Date   	:19/04/2020 
*/ 

#include <iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;

class Width;

class Rectangle 
{
    private:
      	 // declaring int l as Private variable.
		  int l,w; 
    public:
    	//constructor for class
      	Rectangle()
		{ 
			cout<<"Class Length constructor called"<<endl; 
			//initializing in constructor
			l = 5;
			w = 10;
			cout<<" Value of L is "<<l<<" . Value of W is "<<w<<endl; 
	  	}
	  	void setLW(int a, int b){
	  		l = a;
	  		w = b;
		  }
		// destructorclass for class Length with virtual keyword
	  	virtual ~Rectangle() 
		{
	  		cout<<"Class Rectangle destructor called"<<endl;
		}
		
      // friend function declaration
      friend class Area;
};
class Area{
	public: 
    getArea(Rectangle& l,Rectangle& w) 
    { 
        // Since Area is friend of Rectangle, it can access 
        // private members of Rectangle 
        return (l.l*w.w);
    } 
    ~Area(){
    	cout<<"Area Destructor is called"<<endl;
	}
};

class Base 
{ 
public: 
    virtual ~Base()=0; // Pure virtual destructor 	
};
Base::~Base() { 
    	cout << "Pure virtual destructor is called"<<endl; 
	}
  
class Derived : public Base 
{ 
public: 
    ~Derived() 
    { 
        cout << "Derived destructor is executed\n"<<endl; 
    } 
};

int main(int argc,char *argv[])
{
	//Help command to print the usage of the file
    if(argc==2) 
	{
		if(strcmp(argv[1],"-h")==0)     
        	{
			cout<<"\n Usage of file --> \n\t filename.exe & enter"<<endl<<"Program used to demonstrate different access specifiers "<<endl;
		}	
	}
	else
	{
		Rectangle r;
		Area a;
		r.setLW(10,20);
		int area = a.getArea(r,r);
    	cout<<"Area of Rectangle is: "<< area << " Sq units"<<endl;
    	
    	//Pure virtual destructor
    	Base *b = new Derived();
    	delete b;
	}
	return 0;
}
