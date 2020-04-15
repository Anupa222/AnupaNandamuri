/*Program: Finding The square and adding the squares of 'n' numbers.
  Filename:SumOfSquare.cpp
  Date:10-04-2020
  Author: N.Anupa*/
#include<iostream>
#include<string.h>
using namespace std;
//Function Name : SumOfSquares/
int SumOfSquares()
{
		int isum=0;
		int in;
		cout<<"Input	:	";
		cin>>in;
		// Formula for given expression , n(n+1)(2n+1)/6
		isum = (in * (in + 1) * (2 * in+1)) / 6;   
        cout<<"Output	:	"<<isum;	
}
int main(int argc,char* argv[])
{
	//Declaring variables ar required
   	if((argc>=2) && (strcmp(argv[1],"-h")==0))
	{               
		{
		    cout<<"  Usage Of  " <<argv[0]<<endl;
			//cout<<"Enter any integer value  "<<endl; 
		}
	}	
	else
	{
		SumOfSquares();
	}
}
