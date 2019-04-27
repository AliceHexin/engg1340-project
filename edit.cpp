#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<stdlib.h>

using namespace std;

//send the editted information into files
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
		efin.close();
	    efout.close();
		//delete old file and rename temporary.txt
		string file0="rm -rf "+filename;
		system(file0.c_str());
	    string file1="mv temporary.txt "+ filename;
	    system(file1.c_str());

	}
}

//delete the information that no longer belong to the file
void delfile(string username, string kind, string editting){
	string filename=username+"_"+kind+".txt";
	ifstream dfin;
	dfin.open(filename.c_str());
	ofstream dfout;
	dfout.open("temporary.txt",ios::app);
	if (dfin.fail() || dfout.fail())
    {
        cout << "Error in delfile opening!" << endl;
        exit(1);
    }
    else{
    	string line;
    	while(getline(dfin,line)){
    		if(editting!=line)
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

//transform the editted information into other files
void tranfile(string username, string kind, string editted){
	string filename=username+"_"+kind+".txt";
	ofstream efout;
	efout.open(filename.c_str());
	if (efout.fail())
    {
        cout << "Error in edit-file opening!" << endl;
        exit(1);
    }
    else{
    	efout<<editted<<endl;
    }
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
	string date_filename=username+"_date.txt";
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
		string file0="rm -rf "+date_filename;
	    system(file0.c_str());
	    string file1="mv temporary.txt "+date_filename;
	    system(file1.c_str());
	}
	//update file
	if(olddate!=date || oldnumber!= num){
		if(oldtype==type)
		updatefile(username, oldtype, old_line, e_line );
		if(oldaccount==account)
		updatefile(username, oldaccount, old_line, e_line );
	}
	if(oldtype!=type){
		tranfile(username, type, e_line );
		delfile(username, oldtype, old_line);
	}
	if(oldaccount!=account){
		tranfile(username, account, e_line );
		delfile(username, oldaccount, old_line);
	}
	cout<<"Your record has been editted!"<<endl;
	cout<<endl;
}
