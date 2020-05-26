/*Purpose : To Write a program to encrypt and decrypt the data stored in the source file by setting a key to open that file
  Filename	:encryptdecrypt.cpp
  Author 	:N.Anupa
  Date   	:09/05/2020 
*/
#include<iostream>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<fstream>
#include<algorithm>
#include <streambuf>
#include <sstream>
#define SPACE_REPLACE '*'
#define SPACE_REPLACE2 '$'
using namespace std;
//Encrypt function to encode the message
void encrypt(char *ifile, string key)
{
	//To read file
	ifstream t(ifile);
	if(!t)
	{
		cout<<"File Doesnt Exists! Please check file name and location";
		return;
	}
	string text,output,temp, file;
	stringstream buffer;
	buffer << t.rdbuf();
	text = buffer.str();
	output ="";
	temp="";
	text+="\n";
	//For loop to check for the letters 
	for (int letter = 0; letter<text.length();letter++)
	{
		//if case to check whether there is any space is present in between the words of the statement or not
		if(text[letter] != ' ')
		{
			// if no space is present then print the next letter
			if(text[letter] == '\n' )
			{
				reverse(temp.begin(), temp.end());
				output+=temp+text[letter];
				temp="";
			}
			else if(text[letter]==SPACE_REPLACE)
			{
				temp+=SPACE_REPLACE2;
			}
			else
			{
				temp+=text[letter];
			}
		} 
		//else if any space is present then it will replace the space
		else
		{
			if(text[letter] == ' ')
			{
				text[letter] = SPACE_REPLACE;
				reverse(temp.begin(), temp.end());
				temp+=text[letter];
				output+=temp;
				temp="";
			}
		}
	}
	output+=temp;
	//this for loop is to take the key from the user and encrypt it
	for(int letter = 0; letter<key.length();letter++)
	{
		if(key[letter]>25 && key[letter]<240)
			key[letter] = key[letter]+2;
	}
	reverse(key.begin(), key.end());
	output = "key=\""+key+"\"\n"+output;
	cout<<"This is encoded text : "<<endl<<output;
	file = ifile;
	file.replace(file.find("."),1,"_encode.");
	ofstream ofile(file.c_str());
	ofile << output;
}
//decrypt function to decode the message stored in the source file
void decrypt(char *ifile, string key)
{
	//To read file
	ifstream t(ifile);
	if(!t)
	{
		cout<<"File Doesnt Exists! Please check file name and location";
		return;
	}
	string text,output,temp, file, fkey;
	stringstream buffer;
	buffer << t.rdbuf();
	text = buffer.str();
	output ="";
	temp="";
	fkey="";
	
	int count=0;
	for (int letter = 0; letter<text.length();letter++)
	{
		if(text[letter] == '\n' || count > 1)
			break;
		else if(text[letter]!='"')
		{
			if(text[letter]>27&&text[letter]<242)
				fkey+=text[letter]-2;
		}
		else if(text[letter]=='"'&& count==0)
		{
			fkey="";
			count++;
		}
	}
	reverse(fkey.begin(), fkey.end());
	//if case to check whether the key used to encrypt the data is same as the key used to decrypt the data
	if(fkey != key)
	{
		cout<<" Key did not match! Please enter correct key!!"<<endl;
		return;		
	}
	text = text.substr(text.find("\n"));	
	for (int letter =1; letter<text.length();letter++)
	{
		if(text[letter] == SPACE_REPLACE || text[letter] == SPACE_REPLACE2 )
		{
			if(text[letter] == SPACE_REPLACE2)
			{		
				text[letter] = SPACE_REPLACE;
				temp+=text[letter];
			}
			else
			{
				text[letter] = ' ';
				reverse(temp.begin(), temp.end());
				temp+=text[letter];
				output+=temp;
				temp="";			
			}
		}
		else
		{
			if(text[letter] == '\n' )
			{
				reverse(temp.begin(), temp.end());
				output+=temp+text[letter];
				temp="";
			}
			else
			{
				temp+=text[letter];
			}
			
		}
	}
	reverse(temp.begin(), temp.end());
	output+=temp;
	cout<<"This is decoded text : "<<endl<<output;
}

int encryptdecrypt(int argc, char *argv[])
{
	string file="", key="", mode="";
	if(argc==6) //encryptdecrypt.exe -d/-e -f fname -k key
	{
		for(int arg=1;arg<=6;arg++)	
		{
			if(strcmp(argv[arg],"-d")==0)
				if(mode.empty())
					mode = "-d";
				else
				cout<<"Wrong usage : please use encryptdecrypt.exe -h for help"<<endl;
			else if(strcmp(argv[arg],"-e")==0)
				if(mode.empty())
					mode = "-e";
				else
					cout<<"Wrong usage : please use encryptdecrypt.exe -h for help"<<endl;
			else if(strcmp(argv[arg],"-f")==0)
				if(file.empty())
				{				
					arg+=1;
					file = argv[arg];
				}
				else
					cout<<"Wrong usage : please use encryptdecrypt.exe -h for help"<<endl;
			else if(strcmp(argv[arg],"-k")==0)
				if(key.empty())
				{
					arg+=1;
					key = argv[arg];
				}
				else
					cout<<"Wrong usage : please use encryptdecrypt.exe -h for help"<<endl;
				else
				cout<<"Wrong usage : please use encryptdecrypt.exe -h for help"<<endl;

			if(arg == 5)
			{
				char *ifile = strdup(file.c_str());
				if(mode=="-e")
					encrypt(ifile,key);
				else
					decrypt(ifile,key);
			}
		}
	}
	//Usage of the Program
	else if(argc==2 && strcmp(argv[1],"-h")==0)
	{
		cout<<" This -h command is to print the Usage Of The Program \n\n In this program the arguements are passed through the commandline"<<endl;
		cout<<"\n Those arguements are -e for encode -d for decode -f for file name -k for key"<<endl;
		cout<<"\n A key and a text message should be stored in a source file"<<endl;
		cout<<"\n User has to provide the same key that stored in the source file to view the decoded text message"<<endl;
		cout<<"\n If the key provided by the user doesn't match with the key stored in the source file then an error message will print"<<endl;
	}
	else
	{
		cout<<"Wrong usage : please use encryptdecrypt.exe -h for help"<<endl;
	}	
	return 0;
}
