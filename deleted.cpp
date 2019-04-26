#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<stdlib.h>
using namespace std;

void rebuildfile(user userlist, string kind, string deleting){
	string filename=userlist.name+"-"+kind+".txt";
	ifstream dfin;
	dfin.open(filename.c_str())
	ofstream dfout;
	dfout.open("temporary.txt",ios::app)
	if (dfin.fail() || dfout.fail())
    {
        cout << "Error in delete-file opening!" << endl;
        exit(1);
    }
    else{
    	string line;
    	while(getline(dfin,line)){
    		if(deleting!=line)
    		dfout << line <<endl;
		}
		//delete old file and rename temporary.txt
		string file0="del "+filename;
		system(file0.c_str());//可以这样？ 
	    string file1="rename temporary.txt "+ filename;
	    system(file1.c_str());
	}
	dfin.close();
	dfout.close();
}

void deleted(user userlist){
	cout<<"The date of the record to be deleted: ";
	cin>>userlist.date;
	cout<<endl;
	cout<<"The amount of the record to be deleted: ";
    cin>>userlist.amount;
    cout<<endl;
    //change amount string into double type
    string number;
    stringstream ss;
    ss << userlist.amount;
    ss >> num;
    cout<<"The type of the record to be deleted: ";
    cin>>userlist.type;
    cout<<endl;
    cout<<"The account of the record to be deleted: ";
    cin>>userlist.account;
    cout<<endl;
    string d_line=userlist.date.substr(0,4) + " " + userlist.date.substr(4,2) +" "+ userlist.date.substr(6,2)+" "+ number + " " + userlist.type + " " + userlist.account; 
    
	string date_filename=userlist.name+"-date.txt";//可以这样识别？ 
	ifstream findate;
	findate.open(date_filename.c_str())
	ofstream foutdate;
	foutdate.open("temporary.txt",ios::app)
	if (findate.fail() || foutdate.fail())
    {
        cout << "Error in delete-file opening!" << endl;
        exit(1);
    }
    else{
    	string line;
    	int temd=0;
    	while(getline(findate,line)){
    		if(d_line!=line)
    		foutdate << line <<endl;
    		else
    		tem=1;	
		}
	}
	findate.close();
	fourdate.close();
	if(temd==0)
	cout<<"record not found!"<<endl;
	else{
		//delete old file and rename temporary.txt
		string file0="del "+date_filename;
		system(file0.c_str());//可以这样？ 
	    string file1="rename temporary.txt "+date_filename;
	    system(file1.c_str());
	//提交时改为Linux语言
	    rebuildfile(userlist,userlist.type,d_line);
	    rebuildfile(userlist,userlist.account,d_line);
	}
}
	
