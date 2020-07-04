#include<bits/stdc++.h>
using namespace std;
#define d 256
const int q = 5381;

bool robinKarp(string base,string sub)
{
  int base_len = base.length();
  int sub_len = sub.length();
  int hash_base=0,hash_sub=0;
  int h=1;

  for(int i=0;i<sub_len-1;i++)
    h = (h*d)%q;

  for(int i=0;i<sub_len;i++)
  {
    hash_base = (d*hash_base + base[i])%q;
    hash_sub = (d*hash_sub + sub[i])%q;
  }

  for(int i=0;i<=base_len - sub_len;i++)
  {
    if(hash_sub == hash_base)
    {
      int j;
      for(j=0;j<sub_len;j++)
      {
        if(base[i+j] != sub[j])break;
      }
      if(j == sub_len)return true;
    }

    if(i<base_len-sub_len)
    {
      hash_base = (d*(hash_base - base[i]*h) + base[i+sub_len])%q;
      if(hash_base < 0)
        hash_base = hash_base+q;
    }
  }
  return false;
}

int main()
{
  string base,sub;
  cin>>base;
  cin>>sub;
  if(robinKarp(base,sub))
    cout<<"True\n";
  else
    cout<<"False\n";

  return 0;
}
