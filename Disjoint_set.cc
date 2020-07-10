#include<bits/stdc++.h>
using namespace std;

void make_set(int i,vector<int>& par)
{
  par[i] = i;
}

int find_set(int a,vector<int>& par)
{
  if(par[a] == a) return a;
  return find_set(par[a],par);
}

void union_set(int a,int b,vector<int>& par)
{
  a = find_set(a,par);
  b = find_set(b,par);
  if(a == b)
  {
    cout<<"NO union possible !!!\n";
    return;
  }
  par[b] = a;
}

int main()
{
  int n,t;
  cin>>n>>t;
  vector<int> par(n+1);
  for(int i=1;i<=n;i++)
  {
    make_set(i,par);
  }
  while(t--)
  {
    int a,b;
    cin>>a>>b;
    union_set(a,b,par);
  }
  return 0;
}
