#include<iostream>
#include<string>
#include<fstream>

using namespace std;

//write different kind of information into files
void appendfile(string filename, string date, double amount, string type, string account){
	ofstream fout;
	fout.open(filename,ios::app);
	if (fout.fail())
    {
        cout<<"Error in ";
		cout<<filename;
		cout<<" opening!" << endl;
        exit(1);
    }
    else
    fout << date.substr(0,4) << " " << date.substr(4,2) <<" "<< date.substr(6,2)<<" "<< amount << " " << type << " " << account<<endl; 
    fout.close();
}

void add(string username){
    string date;
    double amount;
    string type;
	string account;
	//read-in the information the user add
	//add user's date into the datelist
	cout<<"date: ";
	cin>>date;
	cout<<endl;
	//add user's deposit amount into amountlist
	cout<<"amount: ";
	cin>>amount;
	cout<<endl;
	//add user's deposit type into typelist
	cout<<"type: ";
	cin>>type;
	cout<<endl;
	//add user's deposit account into accountlist
	cout<<"account: ";
	cin>>account;
	cout<<endl;
	//write user's deposits into datefile
	string date_filename=username+"_date.txt";
	appendfile(date_filename, date, amount, type, account);
	//write user's deposit type into different typefiles
	string type_filename=username+"_"+type+".txt";
	appendfile(type_filename, date, amount, type, account);
	//write user's deposit account into different accountfiles
	string account_filename=username+"_"+account+".txt";
	appendfile(account_filename, date, amount, type, account);
	cout<<"Your record has been added!"<<endl;
	cout<<endl;
}


