/*Purpose     : Program to parse the given commandline and display the output in asked format
  File Name   : Case1.cpp
  Date        : 08-04-2020
  Author Name : N.Anupa*/
#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;

//Declaring a Function to check whether the length of the string is '1' or not
bool checkDatatype(string sStr);

//Main using command line arguments
int main(int argc,char *argv[])
{
	//if((argc==2) || (strcmp(argv[1],"-h")==0))
	if(argc==2)
		{
			//if condition to compare the input string with "-h" and displaying the usage	              
	    	{
	    		cout<<" Usage Of The File Name "<<endl;
				cout<<argv[0]<<endl<<"datatype1 datatype2 .... datatypeN "<<endl; 
	    	}
	    }
    else
    {
	    int iJ=2;
	    cout<<argv[0]<<endl;
		cout<<"        Type  "<<"\t"<<"       Value  "<<"\t"<<"       Size   "<<endl;
	    //while loop for checking the argcount
		while(iJ<argc)                                      
	    {
		    //atoi function for converting string to int
			int iA=atoi(argv[iJ]);						
		    if(iA==0)									
		    {
			    if(strlen(argv[iJ])==1)
			    {
				    cout<<endl<<"\t char";
				    cout<<"\t\t"<<argv[iJ]<<"\t\t"<<strlen(argv[iJ]);
			    }
				else
				{
				    cout<<endl<<"\t string";
				    cout<<"\t\t"<< argv[iJ]<<"\t\t"<<sizeof(argv[iJ]);
		        }
	        }
		    //else case for displaying int and float values
			else									
		    {
			    float fB=atof(argv[iJ]);
			    if(iA==fB)
			    {
				    cout<<endl<<"\t int"<<"\t\t"<<iA<<"\t\t"<<sizeof(iA);
			    }
			    else
				    cout<<endl<<"\t float"<<"\t\t"<<fB<<"\t\t"<<sizeof(fB)<<endl;
		}
		iJ++;
		}
    }
    }
    
//Defining a function to check length of string is '1' or not
bool checkDatatype(string sStr)
{
	int iLength;
	for(iLength=0;sStr.length()==1;iLength++)
	{
		return true;
	}
}
