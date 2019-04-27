#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;
//input the year abd month in function//
//report could show the percentage of different types and monthly income and expense and amount by month//
//input the type and account you would like to view to see how much percent it takes in income/expense//
void stat(string name)
{
  string line,type,account;
  string word,a,b,c;
  double amount;
  double income=0,expense=0;
  double temp;
  int year,month,y,m,d;
  ifstream fin,fin1;

  cout<<">>>please input the year"<<endl;//input the year//
  cin>>year;
  cout<<">>>please input the month"<<endl;//input the month//
  cin>>month;

  fin.open(name+"_date.txt");//open name+date file//
  if (fin.fail())
  {
    cout<<"open fail"<<endl;// check if file is opened successfully//
    return;
  }

  while(getline(fin, line))//read until the end of file//
  {
    istringstream stream(line);//become string stream//
    stream>>y>>m>>d>>temp>>type>>account;//temp is money//
    if(y==year&&m==month)
    {

      if(temp<0)
        expense+=temp;//calculate expense//
      if(temp>0)
        income+=temp;//calculate income//
    }

  }
  amount=income+expense;
  cout<<"monthly income="<<income<<endl;//show income//
  cout<<"monthly expense="<<expense<<endl;//expense//
  cout<<"monthly amount="<<amount<<endl;//amount//
  fin.close();//close name-date.txt//

  int subamount=0;//use his variable to save amout of different types record//
  string type_input;//save the input type to compare with record's type//
  cout<<">>>input the type you would like to know or 'e' to exit"<<endl;
  cin>>type_input;

  while(type_input!="e")
  {
    fin1.open(name+"_"+type_input+".txt");//open file//
    if(fin1.fail())//dectect if file be opened successfully//
    {
      cout<<"there is no such type"<<endl;
      cout<<"input the type you would like to know or 'e' to exit"<<endl;
      cin>>type_input;
    }

    while(getline(fin1, line))//get all lines in files//
    {

      istringstream stream1(line);//become string stream//
      stream1>>y>>m>>d>>temp>>type>>account;//temp represent the money//
      if(m==month&&y==year)
      {
            subamount+=temp;
      }
      stream1.str("");
      stream1.clear();
    }

    fin1.close();//close file
    cout<<"amount of "+type_input+" is "<<subamount<<" dollar"<<endl;//show amount of specific type//

    if(subamount==0)
    {
      cout<<"no such type record this month"<<endl;
    }

    if (subamount>0)
    {

      cout<<"the percentage of "+type_input+" in monthly income is" ;
      cout<<subamount*100/income<<"%"<<endl;
    }
    if (subamount<0)
    {
      cout<<"the percentage of "+type_input+" in monthly expense is" ;
      cout<<subamount*100/expense<<"%"<<endl;
    }
    subamount=0;
    cout<<endl;
    cout<<">>>input the type you would like to know or 'e' to exit"<<endl;
    cin>>type_input;
  }
  return;

}

//int main()//
//{//
  //string name="ada";//test case//
  //report(name);//
  //return 0;//
//}
