#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdio>
#include <stdio.h>
using namespace std;

// int input==1 will let user input the item and target number of money to file, up to 10 items(indeed could be much more )//
//int input==0 will check if items' target numbers are satisfied, if yes, print alert, renew file//
void wonderlist(string name,int input)//when input==1 means user insert wonder item
{
  string line,type,account;
  string word,a,b,c;
  double amount;
  double income=0,expense=0;
  double temp;
  double original=0;
  int y,m,d;
  ifstream fin;


  fin.open(name+"_date.txt");//open name+date file
  if (fin.fail())
  {
    cout<<"open fail"<<endl;// check if file is opened successfully
    exit(1);
  }

  while(getline(fin, line))//read until the end of file
  {
    istringstream stream(line);//become string stream
    stream>>y>>m>>d>>temp>>type>>account;//temp is money

    if(temp<0)
      expense+=temp;//calculate expense
    if(temp>0)
      income+=temp;//calculate income
  }
  fin.close();

  amount=income+expense;

  ifstream fin1;
  ofstream fout,fout1,fout2;
  double money=0;
  string filename=name+"_wonderlist.txt";
  string item="";
  int flag;





  if(input==1)//at the begining
  {

    fout.open(filename,ios::app);
    cout<<"set an target in your wonderlist. ";
    cout<<endl;
    cin>>item;
    cout<<"set the amount. ";
    cin>>money;
    fout<<item<<" "<<money<<endl;
    fout.close();
    return;
  }

  else
  {

    flag=check_file(filename);//check if file exsited, if not , creat one
    if(flag==0)
    {
      fout2.open(filename);
      if(fout2.fail())
      {
        cout<<"fout open fail"<<endl;
        exit(1);
      }
      fout2.close();
    }

    fin1.open(filename);//open file name_wonderlist.txt
    if(fin1.fail())
    {
      cout<<"open fail"<<endl;
      exit(1);
    }

    fout2.open("temporary.txt",ios::app);//creat a new file to save records

    while(fin1>>item>>money>>original)
    {

      if(amount-original>money&&money>0)//when target is achieved
      {
        cout<<"***wonderlist: "+item+" is now available!***"<<endl;
        cout<<endl;
      }
      else
      {
        fout2<<item<<" "<<money<<" "<<original<<endl;//send to temporary.txt
      }
    }

    fin1.close();
    fout2.close();
    remove( filename.c_str() );//delete original file
    rename("temporary.txt",filename.c_str());//rename temporaray file as the original one
  }
  return;
}
