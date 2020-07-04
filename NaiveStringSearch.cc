#include<bits/stdc++.h>
using namespace std;

bool findSub(string base, string sub)
{
  int base_len = base.length(),sub_len = sub.length();
  int j=0;
  for(int i=0;i<=base_len-sub_len;i++)
  {
      int flag = 0;

      if(base[i] == sub[j])
      {
        for(int j=0;j<sub_len;j++){
          if(base[i+j] == sub[j])
            flag = 1;
          else{
            flag = 0;
            break;}}
      }
      if(flag)
        return true;
      else
        j=0;
  }
return false;
}

int main()
{
  string base,sub;
  cout<<"Enter Base array = ";
  cin>>base;
  cout<<"Enter Sub array = ";
  cin>>sub;
  if(findSub(base,sub))
    cout<<"True\n";
  else
    cout<<"False\n";

  return 0;
}
