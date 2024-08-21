#include <iostream>
#include <string>

using namespace std;

bool  palindrom(string& str){
  if (str.size() == 1) return true;

  for (int i = 0, j = str.size() - 1; i < j; i++,j--)
  {
    if (str[i] != str[j]) return false;
  }

  return true;
}

int main(){
  while (1)
  {
    string in; 
    cin >> in;

    if (in == "0") break ;

    if (palindrom(in))  cout << "yes" << endl;
    else                cout << "no"  << endl;
  }
}