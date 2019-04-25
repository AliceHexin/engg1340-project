#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;
string line,type,account;
string word,a,b,c;
double amount;
double income=0,expense=0;
double temp;
int year,month,y,m,d;
ifstream fin;

//this function will return the sum of all historical record//
int deposite(string name)
{
  fin.open(name+"-date.txt");//open name+date file
  if (fin.fail())
  {
    cout<<"open fail"<<endl;// check if file is opened successfully
    return 0;
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
  amount=income+expense;
  
  return amount;
}

int main()
{
  int a;
  string name="ada";//test case//
  a=deposite(name);
  cout<<a;
  return 0;
}
