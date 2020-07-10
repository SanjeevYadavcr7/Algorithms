#include<bits/stdc++.h>
using namespace std;

unordered_map<int,int> par,size;

void make_set(int i)
{
  par[i] = i;
  size[i] = 1;
}

int find_par(int v)
{
  if(par[v] == v)return v;
  return par[v] = find_par(par[v]);
}

void union_set(int st,int end)
{
  if(size[st] < size[end])
    swap(st,end);
  par[end] = st;
  size[st] += size[end];
}


int main()
{
  int nodes,edges;
  cin>>nodes>>edges;
  for(int i=1;i<=nodes;i++)
  {
    make_set(i);
  }
  pair<int, pair<int,int> > v[edges+1];
  for(int i=1;i<=edges;i++)
  {
    int from,to,w;
    cin>>from>>to>>w;
    v[i] = {w,{from,to}};
  }
  sort(v,v+edges+1);

  int min_cost = 0;
  for(int i=1;i<=edges;i++)
  {
    int st,end,w;
    w = v[i].first;
    st = v[i].second.first;
    end = v[i].second.second;
    st = find_par(st);
    end = find_par(end);
    if(st != end)
    {
      min_cost += w;
      union_set(st,end);
    }
  }
  cout<<min_cost<<endl;
  return 0;
}
