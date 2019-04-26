#include<iostream>
#include<string>
#include"add.cpp"
#include"deleted.cpp"
#include"edit.cpp"
#include"stat.cpp"
#include"budget.cpp"
#include"wonoderlist.cpp"
//include all the function files
using namespace std;
const int max=10; //The largest number of users

int main(){
	struct user {
		string name;
		int date;
		double amount;
		string type;
		string account;
	};
	user userlist[max];
	for(int i=0;i<10;i++){
		string username;
		cin >> username;
		int tem=0;
		for(int j=0;j<i;j++){
			if(userlist[j]==username){
				cout<<"Hello "<<username<<", welcome back to your accounting system!"<<endl;
				break;
			}
			else
			tem+=1;
		}
		//search through the userlist to check whether the user already exists
		if(tem=i){
			userlist[i].name=username;
			cout<<"Hello "<<username<<", your accounting system has been built!"<<endl;
		}
		//add new user to the userlist when it's not filled
	}
	string command;
	cin >> command;
	switch(command){
		case "add" :{
			add(userlist);
			break;
		}
		case "delete":{
			deleted(username);
			break;
		}
		case "edit":{
			edit(username);
			break;
		}
		case "stat":{
			stat(username);
			break;
		}
		case "budget":{
			budget(username);
			break;
		}
		case "wonderlist":{
			wonderlist(username);
			break;
		}
			
	}
}
