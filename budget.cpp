#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdio>
#include <stdio.h>

using namespace std;

bool check_file(string filename)
{
  std::ifstream ifile(filename.c_str());
  return (bool)ifile;
}
//int input==1 means user call it by command "budget", user could input 1 budget here, 0 when call function to check if budget is achieved) //
//int input==0,means this function is just called to check if budget is achieved//
void budget(string name,int input)//when input==1 when user set budget, otherwise input==0//

{
  string line,type,account;
  string word,a,b,c;
  double income=0,expense=0;
  double temp;
  int y,m,d;
  ifstream fin;
  int flag;

  fin.open(name+"_date.txt");
  while(getline(fin, line))//read until the end of file
  {
    istringstream stream(line);//become string stream
    stream>>y>>m>>d>>temp>>type>>account;//temp is money

    if(temp<0)
      expense-=temp;//calculate expense
    if(temp>0)
      income+=temp;//calculate income
  }

  fin.close();


  ifstream fin1;
  ofstream fout,fout1,fout2;
  double origin=0,budget=0;
  string filename=name+"_budget.txt";

  if(input==1)//at the begining
  {
    fout.open(filename);
    cout<<"set a budget over here";
    cin>>budget;
    fout<<budget<<" "<<origin;

    fout.close();
  }

  else
  {

    flag=check_file(filename);
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

    fin1.open(filename);
    if (fin1.fail())
    {
      cout<<"open fail fin1"<<endl;
      exit(1);
    }

    fin1>>budget>>origin;
    fin1.close();


    if ((expense-origin)>budget&&budget>0)//budget is achieved
    {
      cout<<"***budget alert: expense achieved "<<budget<<" now***"<<endl;
      budget=-1;
      origin=expense;
      fout1.open(name+"_budget.txt");
      fout1<<budget<<" "<<origin;
      fout1.close();

    }

  }

}
