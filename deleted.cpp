#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<stdlib.h>
using namespace std;


void rebuildfile(string username, string kind, string deleting){
	string filename=username+"_"+kind+".txt";
	ifstream dfin;
	dfin.open(filename.c_str());
	ofstream dfout;
	dfout.open("temporary.txt",ios::app);
	if (dfin.fail() || dfout.fail())
    {
        cout << "Error in delete_file opening!" << endl;
        exit(1);
    }
    else{
    	string line;
    	while(getline(dfin,line)){
    		if(deleting!=line)
    		dfout << line <<endl;
		}
		dfin.close();
	    dfout.close();
		//delete old file and rename temporary.txt
		string file0="rm -rf "+filename;
		system(file0.c_str()); 
	    string file1="mv temporary.txt "+ filename;
	    system(file1.c_str());
	}
}

void deleted(string username){
	string date;
    double amount;
    string type;
	string account;
	cout<<"The date of the record to be deleted: ";
	cin>>date;
	cout<<endl;
	cout<<"The amount of the record to be deleted: ";
    cin>>amount;
    cout<<endl;
    //change amount string into double type
    string number;
    stringstream ss;
    ss << amount;
    ss >> number;
    cout<<"The type of the record to be deleted: ";
    cin>>type;
    cout<<endl;
    cout<<"The account of the record to be deleted: ";
    cin>>account;
    cout<<endl;
    string d_line=date.substr(0,4) + " " + date.substr(4,2) +" "+ date.substr(6,2)+" "+ number + " " + type + " " + account; 
    //update the datefile
	string date_filename=username+"_date.txt";
	ifstream findate;
	findate.open(date_filename.c_str());
	ofstream foutdate;
	foutdate.open("temporary.txt",ios::app);
	int temd=0;
	if (findate.fail() || foutdate.fail())
    {
        cout << "Error in delete_file opening!" << endl;
        exit(1);
    }
    else{
    	string line;
    	while(getline(findate,line)){
    		if(d_line!=line)
    		foutdate << line <<endl;
    		else
    		temd=1;	
		}
	}
	findate.close();
	foutdate.close();
	if(temd==0)
	cout<<"record not found!"<<endl;
	else{
		//delete old file and rename temporary.txt
		string file0="rm -rf "+date_filename;
		system(file0.c_str()); 
	    string file1="mv temporary.txt "+date_filename;
	    system(file1.c_str());
	    rebuildfile(username,type,d_line);
	    rebuildfile(username,account,d_line);
	    cout<<"Your record has been deleted!"<<endl;
	    cout<<endl;
	}
}
	
