#include<bits/stdc++.h>
using namespace std;
#define N 100
vector<pair<int,int>> adj[N];
bool visited[N];
int nodes,edges,from,to,w;

void Dijskta(int node)
{
  int dis[nodes+1];
  for(int i=1;i<=nodes;i++) dis[i] = INT_MAX;
  dis[node] = 0;

  priority_queue<pair<int,int>> Q;
  Q.push({0,node});
  while(!Q.empty())
  {
    int curr = Q.top().second;
    Q.pop();
    if(visited[curr])continue;
    visited[curr] = true;
    for(auto i:adj[curr])
    {
      int nei = i.first, w = i.second;
      if(dis[nei] > dis[curr]+ w)
      {
          dis[nei] = dis[curr] + w;
          int min_dis = (-1)*dis[nei];
          Q.push({min_dis,nei});
      }
    }
  }

  cout<<"Shortest Distance from ["<<node<<"] = ";
  for(int i=1;i<=nodes;i++)cout<<dis[i]<<" ";
  cout<<endl;
}

int main()
{
  memset(visited,false,sizeof(visited));
  cin>>nodes>>edges;
  for(int i=0;i<edges;i++)
  {
    cin>>from>>to>>w;
    adj[from].push_back({to,w});
    adj[to].push_back({from,w});
  }

  Dijskta(3);   // traversing from node 1

  return 0;
}
