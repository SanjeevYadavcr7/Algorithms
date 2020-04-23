#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++)
    cin>>arr[i];

  int ans = INT_MIN,box=0;
  for(int i=0;i<n;i++)
  {
    box += arr[i];
    ans = max(ans,box);
    box = max(0,box);
  }

  cout<<ans<<endl;

  return 0;
}
