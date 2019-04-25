#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream>

using namespace std;

void view(string name)
{
  string type;
  string filename;
  string line;
  std::cout << "/* please choose to view by date/food/game/salary  */" << '\n';// choose type
  cin >> type;
  filename=name+"-"+type+".txt";//the filename to open
  ifstream fin;
  fin.open(filename);//open "filename" file

  if (fin.fail())
  {
    cout<<"open fail"<<endl;// check if file is opened successfully
    return;
  }
  while(getline(fin, line))
  {
    cout<<line<<endl;
  }
  fin.close();
  return;
}

int main()
{
  string name="ada";//test case//
  view(name);
  return 0;
}
