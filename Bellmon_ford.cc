#include<bits/stdc++.h>
using namespace std;
#define N 100
vector<tuple<int,int,int>> edges;
int dis[N] = {0};
int n,m;

void bellFord(int x)
{
  for(int i=1;i<=n;i++) dis[i] = INT_MAX;
  dis[x] = 0;
  for(int i=1;i<=n-1;i++)
  {
    for(auto e:edges)
    {
      int a,b,w;
      tie(a,b,w) = e;
      dis[b] = min(dis[b],dis[a]+w);
      cout<<"From = "<<a<<" | To = "<<b<<" | Weight = "<<w<<" | Min Dis = "<<dis[b]<<endl;
    }
  }
  cout<<"Path[] = ";for(int i=1;i<=n;i++)cout<<dis[i]<<" ";
}

int main()
{
  cin>>n>>m;
  for(int i=0;i<m;i++)
  {
    int a,b,w;
    cin>>a>>b>>w;
    edges.push_back({a,b,w});
  }
  bellFord(1);

  return 0;
}
