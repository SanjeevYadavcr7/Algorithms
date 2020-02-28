#include<iostream>
using namespace std;

int main()
{
  int n,m;
  cout<<"Enter number of processes = ";
  cin>>n;
  cout<<"Enter number of type of resources = ";
  cin>>m;

  cout<<"Enter already allocated resources by each process =\n";
  int alloc[n][m];
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
      cin>>alloc[i][j];
  }

  cout<<"Enter maximum needed resources by each process = \n";
  int max[n][m];
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
      cin>>max[i][j];
  }

  cout<<"Enter available instance of resources = ";
  int avail[m];
  for(int i=0;i<m;i++)
  {
    cin>>avail[i];
  }

  // Calculation of Needed_resource[]
  int need[n][m];
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      need[i][j] = max[i][j] - alloc[i][j];
    }
  }

  // safe[n] -> for storing safe sequence of processes
  // count   -> for counting safe processes
  // executed[] -> for checking if process has executed
  int safe[n],count=0,executed[n];

  // initially no process has executed so it holds 0
  for(int i=0;i<n;i++)
    executed[i] = 0;

  // actual processing starts
  for(int i=0;i<n;i++)
  {
    for(int j=0;j,n;j++)
    {
      // if process hasn't executed
      if(executed[j] == 0)
      {
          int flag = 0;
          for(int k=0;k<m;k++)
          {
            if(need[j][k] > avail[k])
            {
              // if needed resource is more than available resource
              flag = 1;
              break;
            }
          }

          if(flag == 0)
          {
            safe[count++] = j;
            executed[j] = 1;
            for(int k=0;k<m;k++)
              avail[k] += alloc[j][k];
          }
      }
    }
  }

  if(count == n)
  {
    cout<<"System is safe\nSafe sequence is = [";
    for(int i=0;i<n;i++)
    {
      cout<<"P["<<safe[i]<<"] ";
      if(i != n-1)
      cout<<"->";
    }
  }
  else
    cout<<"ERROR : deadlock has occurred !!!!\n";

  cout<<endl;


  return 0;
}
