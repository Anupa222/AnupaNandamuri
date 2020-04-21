/*Purpose:Program to describe about Varible scopes,modifier types,Storage classes 
  Filename:VariableModifierStorageclass.cpp
  Date:10-04-2020
  Author: N.Anupa*/
// C++ program to show that we can access a global  
// there is a local variable with same name  
#include<iostream>  
using namespace std; 
   
// Global Variable x   
int x = 0;   


void staticSC() {    
   //static variable
   static int i = 11;    
   int j=22; 
   i++;    
   j++;    
   cout<<"Static :  i=" << i<<" and Non Static : j=" <<j<<endl;    
}  

class Student {
	//Without mutable this implementation is not possible
       mutable int id;
      
    public : Student(int id)  {
		Student::id = id;
    }
    void setID(int id) const {
        Student::id = id;
    }

    int getID() const {
        return Student::id;
    }
};


    
int main() 
{ 
  // Local Variable x     
  int x = 10;  
// variable using scope resolution operator :: when   
  cout << "Value of global x is " << ::x<<endl; 
  cout<< "Value of local x is " << x<<endl; 

// long, unsigned, signed and short can be used as modifiers 
long int a= 50;
short int b = 28;
unsigned int c= 74;
signed int d = 69;
cout<< "long : Value of a is " << a << " , Size of a is : "<< sizeof(a)<<endl; 
cout<< "short: Value of b is " << b<< " , Size of b is : "<< sizeof(b)<<endl; 
cout<< "unsigned : Value of c is " << c << " , Size of c is : "<< sizeof(c)<<endl; 
cout<< "signed : Value of d is " << d << " , Size of d is : "<< sizeof(d)<<endl; 

//Auto is default storage class for all local variables.
auto int i;  
float f= 3.45;

//Registered variables are created in RAM for faster access
register int r = 10;  
cout<< "Registered : Value of r is " << r << " , Address of r is : "<< &r <<endl;


//Static Storage Class is demonstrated by static keyword before variable
staticSC();
staticSC();
staticSC();

//if a variable is residing in external file that is shared between multiple programs extern is used
extern const int max;   

//Mutable
 	Student s(18);
    cout << "Student ID " << s.getID()<<endl;
    s.setID(25);
    cout << "Student modified ID " << s.getID()<<endl;
 
  return 0; 
}

