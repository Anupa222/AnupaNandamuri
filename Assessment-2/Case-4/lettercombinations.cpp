/*Purpose : To write a program to print all the possible letter combinations based on the input given by the user
  Filename	:lettercombinations.cpp
  Author 	:N.Anupa
  Date   	:15/05/2020 
*/
#include<iostream>
#include<string.h>
#include <cstdlib>
using namespace std;
//To check that what is there in the position of the input given by the user
string dial(int key)
{
    string m[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    return m[key];
}
void phoneKey(int num,string out)
{
	//	cout<<"Out = "<<out<<" | Num = "<<num<<endl;
    if(num==0)
	{
        cout<<out<<endl;
        return ;
    }
    string pd=dial(num%10);
    //cout<<"PD = "<<pd<<" | PD.SIZE "<<pd.size()<<endl;
    for(int i=0;i<pd.size();i++)
	{
    //	cout<<"I = "<<i<<" | num/10 = "<<num/10<<" | pd["<<i<<"]+"<<out<<" ="<<pd[i]+out<<endl;
    //calls phonekey function
        phoneKey(num/10,pd[i]+out);
    }
}
void phone(char *input)
{
	//To check whether the input is an integer or not
	for(int index = 0; index <strlen(input);index++)
	{
	//if the given input is having alphabets or any spacial characters this message will print	
		if(!isdigit(input[index]))
		{		
			cout<<"Input should be between 2 and 9 only!: Alphabets or symbols entered"<<endl;
				return;
		}
		//if 0 or 1 is entered by the user then this else case will execute
		else if(input[index]==48 ||input[index]==49)
		{
			cout<<"Input should be between 2 and 9 only!: 0 or 1 entered"<<endl;
			return;
		}
	}
	//calls phonekey and converts the input data into integer type
	phoneKey(atoi(input),"");	
}
int main(int argc, char *argv[])
{
	if(argc==2)
	{
		//if condition to compare the input string with "-h" and displaying the usage
    	if(strcmp(argv[1],"-h")==0)
    	{
    		cout<<"Help: This program accepts the input from the user and prints the number of possible letter combinations :"<<endl;
		}
		else
		{		
		//calls phone function
			phone(argv[1]);
		}
	}
	else
	{
		cout<<"Wrong usage : please use lettercombinations.exe, -h for help"<<endl;
	}	
	return 0;
}
