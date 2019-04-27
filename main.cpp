//include all the function files
#include<iostream>
#include<string>
#include"add.cpp"
#include"deleted.cpp"
#include"edit.cpp"
#include"view.cpp"
#include"stat.cpp"
#include"budget.cpp"
#include"wonderlist.cpp"
using namespace std;
const int maxuser=100; //The largest number of users

int main(){
	string userlist[maxuser];
	int i=0,num;
	while(1){
		cout<<"Do you want to enter your accounting system or quit? ";
		string choice;
		cin >> choice;
		cout << endl;
		if(choice=="quit"){
			cout<<"Goodbye!"<<endl;
			break;
		}
		else if(choice=="enter"){
			int k=0;
			while(i<maxuser){
				num=i;
			    //input user's name
		        string username;
		        cout<<"Please input your name: ";
		        cin >> username;
		        cout<<endl;
		        if(i==0){
		        	cout<<"Hello "<<username<<", your accounting system has been built!"<<endl;
							cout<<endl;
		        	userlist[i]=username;
				}
				//search through the userlist to check whether the user has already existed
		        else{
		        	int tem=0;
		        	for(int j=0;j<i;j++){
		        	    if(userlist[j]==username){
				            cout<<"Hello "<<username<<", welcome back to your accounting system!"<<endl;
										cout<<endl;
				            break;
			            }
			            else{
			        	    tem+=1;
					    }
			        }
				    //add new user to the userlist when it's not filled
		            if(tem==i && i<maxuser-1){
			            userlist[i]=username;
			            cout<<"Hello "<<username<<", your accounting system has been built!"<<endl;
									cout<< endl;
		            }
		            //show an alert when the userlist will be full
		            else if(tem==i && i==maxuser-1){
			            userlist[i]=username;
			            cout<<"Hello "<<username<<", your accounting system has been built!"<<endl;
			            cout<<"The accounting system is full! No more new users!"<<endl;
									cout<<endl;
	            	}
	            }
		        //input user's request
	            string command="begin";
	            cout<<"structure:"<<endl;
	        	  cout<<"quit: exit the system"<<endl;
	            cout<<"add: add your accounting record"<<endl;
	       	    cout<<"delete: delete your accounting record"<<endl;
	       	    cout<<"edit: edit your accounting record"<<endl;
	       	    cout<<"view: view your accounting record"<<endl;
	       	    cout<<"stat: show the summary of your record"<<endl;
	       	    cout<<"budget: set a budget"<<endl;
	       	    cout<<"wonderlist: set a target amount of income"<<endl;
							cout<<endl;
	            while(command!="quit"){
	        	    cout<<"Please input your request: ";
	                cin >> command;
	                cout<<endl;
	                int check=1;
		            if(command== "add"){
			                add(username);
			                check=0;
			                budget(username,check);
			                //wonderlist(username,check)
				         
		                }
		            else if(command=="delete"){
			                deleted(username);
			                check=0;
			                //budget(username,check);
			                //wonderlist(username,check);
			                
	    	            }
		            else if(command=="edit"){
			                edit(username);
			                check=0;
			                //budget(username,check);
			                //wonderlist(username,check);
			                
		                }
		            else if(command=="view"){
		    	            view(username);
		    	            
		            	}
		            else if(command=="stat"){
		    	            stat(username);
		    	            
		                }
		            else if(command=="budget"){
			                budget(username,check);
			                
		                }
		            else if(command=="wonderlist"){
			                wonderlist(username,check);
			                
		                }
	                }
	              if(command=="quit"){
	            	k=1;
	            	break;
				        }
	              i++;
	              if(k==1)
			      break;
		    }
	    }
	}
	return 0;
}
