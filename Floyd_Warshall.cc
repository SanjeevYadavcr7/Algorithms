#include<bits/stdc++.h>
using namespace std;

void FloydWarshall(int nodes,int edges)
{
  int adj[100][100];
  int from,to,w;
  for(int i=0;i<edges;i++)
  {
    cin>>from>>to>>w;
    adj[from][to] = w;
    adj[to][from] = w;
  }
  long long int n = nodes,dis[n][n];

  for(int i=1;i<=n;i++)      //  initializing distance[][] matrix
  {
    for(int j=1;j<=n;j++)
    {
      if(i == j)dis[i][j] = 0;
      else if(adj[i][j]) dis[i][j] = adj[i][j];
      else dis[i][j] = INT_MAX;
    }
  }

  for(int k=1;k<=n;k++){
    for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
        dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
      }
    }
  }

  cout<<"\nResultant Dis[] = \n";
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)cout<<dis[i][j]<<" ";
    cout<<endl;
  }
}


int main()
{
  int nodes,edges;
  cin>>nodes>>edges;
  FloydWarshall(nodes,edges);

  return 0;
}
