#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<stdlib.h>
using namespace std;


void updatefile(string username, string kind, string editting, string editted){
	string filename=username+"_"+kind+".txt";
	ifstream efin;
	efin.open(filename.c_str());
	ofstream efout;
	efout.open("temporary.txt",ios::app);
	if (efin.fail() || efout.fail())
    {
        cout << "Error in edit-file opening!" << endl;
        exit(1);
    }
    else{
    	string line;
    	while(getline(efin,line)){
    		if(editting!=line)
    		efout << line <<endl;
    		else
    		efout << editted << endl;
		}
		//delete old file and rename temporary.txt
		string file0="rm -rf "+filename;
		system(file0.c_str());
	    string file1="mv temporary.txt "+ filename;
	    system(file1.c_str());
	}
	efin.close();
	efout.close();
}

void edit(string username){
	string date;
    double amount;
    string type;
	string account;
	//input the record the user want to edit
	string olddate,oldtype,oldaccount;
	double oldamount;
	cout<<"The date of the record to be editted: ";
	cin>>olddate;
	cout<<endl;
	cout<<"The amount of the record to be editted: ";
    cin>>oldamount;
    cout<<endl;
    //change amount string into double type
    string oldnumber,num;
    stringstream ss;
    ss << oldamount;
    ss >> oldnumber;
    cout<<"The type of the record to be editted: ";
    cin>>oldtype;
    cout<<endl;
    cout<<"The account of the record to be editted: ";
    cin>>oldaccount;
    cout<<endl;
    
    string old_line=olddate.substr(0,4) + " " + olddate.substr(4,2) +" "+ olddate.substr(6,2)+" "+ oldnumber + " " + oldtype + " " + oldaccount; 
    
	//find the record and edit if exists
	string date_filename=username+"_date .txt";
	string e_line;
	ifstream findate;
	findate.open(date_filename.c_str());
	ofstream foutdate;
	foutdate.open("temporary.txt",ios::app);
	int tem=0;
	if (findate.fail() || foutdate.fail())
    {
        cout << "Error in editfile opening!" << endl;
        exit(1);
    }
    else{
    	//input the editted record
        cout<<"The date of the record editted: ";
	    cin>>date;
	    cout<<endl;
    	cout<<"The amount of the record editted: ";
        cin>>amount;
        cout<<endl;
        stringstream ss;
        ss << amount;
        ss >> num;
        cout<<"The type of the record editted: ";
        cin>>type;
        cout<<endl;
        cout<<"The account of the record editted: ";
        cin>>account;
        cout<<endl;
        e_line=date.substr(0,4) + " " + date.substr(4,2) +" "+ date.substr(6,2)+" "+ num + " " + type + " " + account; 
    
    	string line;
    	while(getline(findate,line)){
    		if(old_line!=line)
    		foutdate << line <<endl;
    		else{
    			tem=1;
    			foutdate << e_line << endl;
			}	
		}
	}
	findate.close();
	foutdate.close();
	if(tem==0)
	cout<<"record not found!"<<endl;
	else{
		string file0="del "+date_filename;
	    system(file0.c_str());
	    string file1="rename temporary.txt "+date_filename;
	    system(file1.c_str());
	}
	//update file
	if(olddate!=date || oldnumber!= num){
		updatefile(username, type, old_line, e_line );
		updatefile(username, account, old_line, e_line );
	}
	if(oldtype!=type){
		updatefile(username, type, old_line, e_line );
	}
	if(oldaccount!=account){
		updatefile(username, account, old_line, e_line );
	}
}
