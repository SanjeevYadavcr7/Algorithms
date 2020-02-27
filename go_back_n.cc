#include<iostream>
#include<stdlib.h>
using namespace std;

int main()
{
  int n,ws,tr=0;
  // tr -> total nuber of transmissions

  cout<<"Enter number of frames to be transmitted = ";
  cin>>n;
  cout<<"Enter sender window size = ";
  cin>>ws;

  int i=1;
  while(i<=n)
  {
    int x = 0;
    // send frames from current frame to (current frame + window size)
    for(int j=i;j<i+ws && j<=n;j++)
    {
      cout<<"Sent Frame ["<<j<<"]\n";
      tr++;
    }

    for(int j=i;j<i+ws && j<=n;j++)
    {
        int flag = rand()%2;
        if(flag != 0)
        {
          cout<<"Ack for Frame["<<j<<"]\n";
          x++;
        }
        else
        {
          cout<<"Frame["<<j<<"] not received\n\n";
          cout<<"Retransmitting Window\n";
          break;
        }
    }
    cout<<endl;
    i = i+x;
  }
  cout<<"Total number of transmissions = "<<tr<<endl;

  return 0;
}
