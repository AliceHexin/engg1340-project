#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdio>
#include <stdio.h>
using namespace std;
//todo 将record放入file

void budget(string name,int input)//when input==1 when user set budget, otherwise input==0
{
  string line,type,account;
  string word,a,b,c;
  double income=0,expense=0;
  double temp;
  int y,m,d;
  ifstream fin;
  fin.open(name+"-date.txt");//open name+date file
  if (fin.fail())
  {
    cout<<"open fail"<<endl;// check if file is opened successfully
    return;
  }

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
  ofstream fout,fout1;
  double origin=0,budget=0;
  string filename=name+"-budget.txt";
  fin1.open(filename);
  if(fin1.fail())
    exit(1);

  fin1>>budget>>origin;

  cout<<origin<<" "<<expense<<" "<<budget<<endl;// print out the amount when budget is seted current amount and budget

  if(input==1)//at the begining
  {
    fin1.close();
    fout.open(filename);
    cout<<"set budget"<<endl;
    cin>>budget;
    origin=expense;

    fout<<budget<<" "<<origin;

    fout.close();
  }

  else
  {
    fin1>>budget>>origin;
    fin1.close();

    if ((expense-origin)>budget&&budget>0)
    {
      origin=expense;
      cout<<"***budget alert：expense achieved "<<budget<<"now***"<<endl;
      budget=-1;

      origin=expense;
      fout1.open(name+"-budget.txt");
      fout1<<budget<<" "<<origin;
      fout1.close();

    }

  }
  return ;//haven satisfied the budget
}

int main()
{
  string name="ada";//test case//
  budget(name,0);

  return 0;
}
