#include<iostream>
#include "string.h"
using namespace std;

int main()
{
  string str;
  cout<<"Enter String to be checked = ";
  getline(cin,str);

  int size = str.length();
  int flag = 0;
  for(int i=0;i<=size/2;i++)
  {
    if(str[i] == str[size-1-i])
      flag = 1;
    else
      flag = 0;
      break;
  }

  if(flag == 1)
    cout<<"Palindrome\n";
  else
    cout<<"Non-Palindrome\n";


  return 0;
}
