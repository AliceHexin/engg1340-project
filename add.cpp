#include<iostream>
#include<string>
#include<fstream>
using namespace std;

//write different kind of information into files
void appendfile(string filename, user userlist){
	ofstream fout;
	fout.open(filename,ios::app);
	if (fout.fail())
    {
        cout << "Error in ",filename," opening!" << endl;
        exit(1);
    }
    else
    fout << userlist.date.substr(0,4) << " " << userlist.date.substr(4,2) <<" "<< userlist.date.substr(6,2)<<" "<< userlist.amount << " " << userlist.type << " " << userlist.account<<endl; 
    fout.close();
}

void add(user userlist){
	//read-in the information the user add
	//add user's date into the datelist
	cout<<"date: ";
	cin>>userlist.date;
	cout<<endl;
	//add user's deposit amount into amountlist
	cout<<"amount: ";
	cin>>userlist.amount;
	cout<<endl;
	//add user's deposit type into typelist
	cout<<"type: ";
	cin>>userlist.type;
	cout<<endl;
	//add user's deposit account into accountlist
	cout<<"account: ";
	cin>>userlist.account;
	cout<<endl;
	//write user's deposits into datefile
	string date_filename=userlist.name+"-date.txt";
	appendfile(date_filename, userlist[n]);
	//write user's deposit type into different typefiles
	string type_filename=userlist.name+"-"+userlist.type+".txt";
	appendfile(type_filename, userlist);
	//write user's deposit account into different accountfiles
	string account_filename=userlist.name+"-"+userlist.account+".txt";
	appendfile(account_filename, userlist);
}

