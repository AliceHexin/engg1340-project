#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<stdlib.h>
using namespace std;

void updatefile(user userlist, string kind, string editting, string editted){
	string filename=userlist.name+"-"+kind+".txt";
	ifstream efin;
	efin.open(filename.c_str())
	ofstream efout;
	efout.open("temporary.txt",ios::app)
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
		string file0="del "+filename;
		system(file0.c_str());//���������� 
	    string file1="rename temporary.txt "+ filename;
	    system(file1.c_str());
	}
	efin.close();
	efout.close();
}

void edit(user userlist){
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
    string oldnumber;
    stringstream ss;
    ss << userlist.amount;
    ss >> oldnumber;
    cout<<"The type of the record to be editted: ";
    cin>>oldtype;
    cout<<endl;
    cout<<"The account of the record to be editted: ";
    cin>>oldaccount;
    cout<<endl;
    
    string old_line=olddate.substr(0,4) + " " + olddate.substr(4,2) +" "+ olddate.substr(6,2)+" "+ oldnumber + " " + oldtype + " " + oldaccount; 
    
	//find the record and edit if exists
	string date_filename=userlist.name+"-date .txt";
	ifstream findate;
	findate.open(date_filename.c_str())
	ofstream foutdate;
	foutdate.open("temporary.txt",ios::app)
	if (findate.fail() || foutdate.fail())
    {
        cout << "Error in editfile opening!" << endl;
        exit(1);
    }
    else{
    	//input the editted record
        cout<<"The date of the record editted: ";
	    cin>>userlist.date;
	    cout<<endl;
    	cout<<"The amount of the record editted: ";
        cin>>userlist.amount;
        cout<<endl;
        string num;
        stringstream ss;
        ss << userlist.amount;
        ss >> num;
        cout<<"The type of the record editted: ";
        cin>>userlist.type;
        cout<<endl;
        cout<<"The account of the record editted: ";
        cin>>userlist.account;
        cout<<endl;
        string e_line=userlist.date.substr(0,4) + " " + userlist.date.substr(4,2) +" "+ userlist.date.substr(6,2)+" "+ num + " " + userlist.type + " " + userlist.account; 
    
    	string line;
    	int tem=0;
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
	if(olddate!=userlist.date || oldnumber!=num){
		updated(userlist, userlist.type, old_line, e_line );
		updated(userlist, userlist.account, old_line, e_line );
	}
	if(oldtype!=userlist.type){
		updated(userlist, userlist.type, old_line, e_line );
	}
	if(oldaccount!=userlist.account){
		updated(userlist, userlist.account, old_line, e_line );
	}
}