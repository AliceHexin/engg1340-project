#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;


//this function will return the sum of all historical record//
double deposite(string name)
{
  string line,type,account;
  string word,a,b,c;
  double amount;
  double income=0,expense=0;
  double temp;
  int y,m,d;
  ifstream fin;
  fin.open(name+"-date.txt");//open name+date file
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
  return amount;//return the sum of all record
}

int main()
{
  string name="ada";//test case//
  double a=deposite(name);
  cout<<a<<endl;
  return 0;
}
