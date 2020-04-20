/*Program: Finding The square and adding the squares of 'n' numbers.
  Filename:SumofSquare.cpp
  Date:10-04-2020
  Author: N.Anupa*/
  
#include<iostream>
#include<string.h>
#include <cstdlib> 
using namespace std;
void SumOfSquares(int in)
{
		int isum=0;
		if(in>=0)
		{
		// Formula for given expression , n(n+1)(2n+1)/6
		isum = (in * (in + 1) * (2 * in+1)) / 6;   
        cout<<"Sum Of The Squares Of Given Positive Integer series Is " <<isum;
		}
		else
		{
			cout<<"The entered value is a negative number please give a valid positive number";
		}
}

//Main using command line arguments
int main(int argc,char *argv[])
{
	
	if(argc<2 || argc>2)
	{
			//If No arguments are provided
	    	cout<<" Please pass the correct argument! use -h for help "<<endl;
	}
    else
    {
    	if(argc==2)
		{
    		//if condition to compare the input string with "-h" and displaying the usage
    		if(argv[1]=="-h")
    		{
    			cout<<"Help: This program accepts command line arguments as input and prints the sum of square of number, see usage and example below:"<<endl;
    			cout<<argv[0]<<" n"<<endl; 
    			cout<<"Example : "<<argv[0]<<"4"<<endl;
			}
    		else
			{
    			SumOfSquares(atoi(argv[1]));
			}
		}
	}
	return(0);
}

