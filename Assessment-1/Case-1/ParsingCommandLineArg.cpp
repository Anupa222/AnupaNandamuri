/*Purpose     : Program to parse the given commandline and display the output in asked format
  File Name   : parsecommand.cpp
  Date        : 08-04-2020
  Author Name : N.Anupa*/
  
#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;

//Declaring a Function to check the datatype of arguments
string checkDatatype(char *input)
{
	//check for single char which is not digit
	if(strlen(input)==1 && !isdigit(input[0]))
	{
			return("Char");
	}
	else
	{
		//checking number of dots in input
		int dotCount = 0;		
	  	for (int i = 0; i < strlen(input); i++) 
		  {
      	  	if(i==0 && input[i]=='-')
				{
       				continue;
				}
			if (isdigit(input[i]) == false)
       		{
       			if(input[i]=='.')
				{
				   dotCount++;
				   if(dotCount>=2)
				   {
				   		//more than 2 dots in input string
				   		return("String");
				   }
				}
				if(input[i]!='.')
				{
					//Other than digits in input
      			return ("String");
      			}
       		}
       	}
       	//No dots integer
       	if(dotCount<=0)
		{
			return("Integer");
		}
		else
		{
			//One Dot Float or Double
			return ("Float/Double");
		}
	}
}
int findSizeOf(string input)
{
	if(input == "Char")
	{
		return(sizeof(char));
	}
	else if(input == "String")
	{
		return(sizeof(input));
	}
	else if(input == "Integer")
	{
		return(sizeof(int));
	}
	else if(input == "Float/Double")
	{
		return(sizeof(float));
	}
}
	
//Main using command line arguments
int main(int argc,char *argv[])
{
	if(argc<2)
		{
				//If No arguments are provided
	    		cout<<" Please pass atleast one argument! see below for example : "<<endl;
				cout<<argv[0]<<" 1 a sss 4.5643"<<endl; 
	    }
    else
    {
    	if(argc==2)
		{
    		//if condition to compare the input string with "-h" and displaying the usage
    		if(strcmp(argv[1],"-h")==0)
			{
    			cout<<"Help: This program accepts command line arguments as input and prints their datatype and size in memory, see usage and example below:"<<endl;
    			cout<<argv[0]<<" datatype1 datatype2 datatype3 .... datatypeN"<<endl; 
    			cout<<"Example : "<<argv[0]<<" 1 a sss 4.5643"<<endl;
    			return 0;
			}
    		
		}
        cout<<"\n\tType\t\t\t\tValue\t\t\t\tSize"<<endl;
        for(int i=1;i<argc;++i)
		{

            cout<<"\t"<<checkDatatype(argv[i])<<"\t\t\t\t"<<argv[i]<<"\t\t\t\t"<<findSizeOf(checkDatatype(argv[i]))<<endl;
        }
	}
		return 0;
}

