#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdio>
#include <stdio.h>
using namespace std;

void wonderlist(string name)
{
  string line,type,account;
  string word,a,b,c;
  double amount;
  double income=0,expense=0;
  double temp;
  int year,month,y,m,d;
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

  amount=income+expense;

  ifstream fin1;
  ofstream fout,fout1;
  double origin=0,money=0;
  string filename=name+"-wonderlist.txt";
  string item="";


  fin1.open(filename);
  if(fin1.fail())
    exit(1);

  fin1>>item>>amount;
  cout<<item<<" "<<money<<endl;

  if(item=="")//at the begining
  {
    fin1.close();
    fout.open(filename);
    cout<<"set item"<<endl;
    cin>>item;
    cout<<"set amount"<<endl;
    cin>>money;
    fout<<item<<" "<<money<<endl;
    fout.close();
  }

  else
  {
    fin1>>item>>money;
    fin1.close();

    if (amount>money)
    {

      cout<<item+"finish do you want to set budget again."<<endl;
      cout<<"enter budget"<<endl;
      cin>>item;
      cin>>money;

      fout1.open(filename);
      fout1<<item<<" "<<money;
      fout1.close();
    }
  }



}

int main()
{

  string name="ada";//test case//
  wonderlist(name);
  return 0;
}
