/*Purpose : To Write a program which will do the list of operations in the file.  
  Filename	:experiment7.cpp
  Author 	:N.Anupa
  Date   	:23/04/2020 
*/
#include<iostream>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<fstream>
using namespace std;

class ManageConfig
{
	
		 string key;
         string value;
		void addConfig()
		{                
            cout<<"Enter Config Key : "<<endl;
            cin.clear();
            cin.sync();
            getline (cin,key);                  
            cout<<"Enter Config Value : "<<endl;
            cin.clear();
            cin.sync();
            getline (cin,value);
            FILE  *file;
            file= fopen("notes.ini","a");
            fprintf(file,"%s = %s\n",key.c_str(),value.c_str());
            fclose(file);
            cout<<"New Config pair is added";
        }
		void listConfig()
		{
               
            cout<<"Here is the content of Config file : "<<endl; 
            ifstream f("notes.ini");
    		if (f.is_open())
        	cout << f.rdbuf();
			f.close();
                cout<<endl;
        }
 		
 		void editConfig()
		{
                 string fkey;
                cout<<"Enter key to find value : "<<endl;
                cin.clear();
                cin.sync();
                getline (cin,fkey);
                 string rvalue;
                cout<<"\nEnter value for key : "<<endl;
                cin.clear();
                cin.sync();
                getline (cin,rvalue);
                string config="";
                FILE *file;
                file= fopen("notes.ini", "r");
                while(fscanf(file,"%s = %s\n", &key[0], &value[0])!= EOF)
				{
                        if(strcmp(fkey.c_str(), key.c_str())==0)
						{
                                config += fkey+" = "+rvalue+"\n";
                        }
                        else
						{
                                config += key +" = "+ value+"\n";
                        }
                }
                fclose(file);
                ofstream out("notes.ini");
    			out << config;
    			out.close();
    			cout<<"Config edited"<<endl;
        }

        void deleteConfig()
		{
    			 string fkey;
                cout<<"Enter key to find value : ";
                cin.clear();
                cin.sync();
                getline (cin,fkey);
                
				string config="";
                FILE *file;
                file= fopen("notes.ini", "r");
                while(fscanf(file,"%s = %s\n", &key[0], &value[0])!= EOF)
				{ 
                        if(strcmp(fkey.c_str(), key.c_str())!=0)
						{
                                config += key +" = "+ value+"\n";
                    	}
                    	else
						{
                    		cout<<"Config Deleted"<<endl;
						}
                }
                fclose(file);
                ofstream out("notes.ini");
    			out << config;
    			out.close();
        }
        public: ~ManageConfig()
		{
			FILE *file;
            file= fopen("notes.ini", "r");
            string config="";
                while(fscanf(file,"%s = %s\n", &key[0], &value[0])!= EOF)
				{
                	config+=key+" = "+value+"\n";                  
				}
            	    fclose(file);
                	if(strcmp(config.c_str(),"")==0)
					{
                		remove("notes.ini");
                		cout<<endl<<"File Deleted"<<endl;
					}
		}
		
public:
		   void choices()
		   {
                while(true)
				{

                        cout<<" \n Manage Config file : "<<endl;
                        cout<<"   1:   AddConfig"<<endl;
                        cout<<"   2:   listconfig"<<endl;
                        cout<<"   3:   editConfig"<<endl;
                        cout<<"   4:   deleteConfig"<<endl;
                        cout<<"   5:   To Exit     "<<endl;
                        cout<<"   Please Enter Your Choice : ";

                        int option;
                        cin>>option;

                        switch (option) 
						{

                                case 1:
                                        addConfig();
                                        break;
                                case 2:
                                		listConfig();
                                		break;
                                case 3:
                                		editConfig();
                                		break;
                                case 4: 
                                		deleteConfig();
                                		break;
                                case 5:
                                        cout<<endl<<"Good bye!";
                                        return;
                                default:
                                        cout<<" Please try again! Invalid option!!! \n";
                                        break;
                        }
                }
        }
};
        
int main(int argc, char *argv[])
{
	if(argc==2) 
	{
		if(strcmp(argv[1],"-h")==0)     //created a help command
        {
			cout<<"\n Usage of file --> \n"
					"\t filename.exe & enter"<<endl<<
					"\t -Program to perform filehandling in 'notes.ini' file. "<<endl<<
					"\t -select an option from the list "<<endl<<
					"\t -submit data based on the requirement "<<endl<<
					"Note: please don't give any spaces as input of the code maybe fall into infinite loop."<<endl;
		}	
	}
	else
	{
        ManageConfig obj;
        obj.choices();
	}
	return 0;
}
