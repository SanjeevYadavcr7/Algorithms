#include<bits/stdc++.h>
using namespace std;

void make_set(int i,vector<int>& par,vector<int>& size)
{
  par[i] = i;
  size[i] = 1;
}

int find_set(int v,vector<int>& par)
{
    if(par[v] == v)return v;
    return par[v] = find_set(par[v],par);
}

void unoin(int a, int b,vector<int>& par,vector<int>& size)
{
  a = find_set(a,par);
  b = find_set(b,par);
  if(a != b)
  {
    if(size[a] < size[b])
      swap(a,b);
    par[b] = a;
    size[a] += size[b];
  }
  else
    cout<<"already joined !!!\n";
}

int main()
{
  int n,t;
  cin>>n;
  vector<int> par(n+1),size(n+1);
  for(int i=1;i<=n;i++)
    make_set(i,par,size);

  cin>>t;
  while(t--)
  {
    int a,b;
    cin>>a>>b;
    unoin(a,b,par,size);
  }

  return 0;
}
