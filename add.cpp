#include <iostream>
#include <fstream>
using namespace std;
//this programme's function is to add record of expense or income.//
//the record will be saved in file record.txt//
//until the user type exit//
struct record
{
  string in_out;//income or expense//
  string type;//food, game,travel....//
  string account;//cash, bank card, credit card...//
  double amount;//money//
  int year,month,date;//date//
};

void add()
{ string type;

  ofstream fout("record");//open file//
  if(fout.fail())//check if opening is fail//
  {
    cout<<"fail open"<<endl;
  }
  cin>>type;
  while(type!="exit")
  {
    cin>>type;
  }
  fout.close();//close file//
  return;
}
