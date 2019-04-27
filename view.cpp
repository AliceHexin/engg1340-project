#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <list>

using namespace std;

void view(string name)
{
  string type;
  string filename;
  string line;
  std::cout << "/* please choose to view by date/food/game/salary/income/expense */" << '\n';// choose type
  cin >> type;
  filename=name+"_"+type+".txt";//the filename to open
  ifstream fin;
  ofstream fout;
  fin.open(filename);//open "filename" file

  if (fin.fail())
  {
    cout<<"open fail"<<endl;// check if file is opened successfully
    return;
  }

  list<string> book;
  while(getline(fin, line))
  {
    book.push_back(line);
  }
  book.sort();
  for (auto it = book.begin(); it != book.end(); ++it)
        cout << *it<<endl;
  fin.close();

  return;
}

//int main()
//{
  //string name="ada";//test case//
  //view(name);
  //return 0//;
//}
