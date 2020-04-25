#include<iostream>
using namespace std;

int main()
{
  int n;
  cin>>n;
  int arr[n];
  int min=0,max=0,min2=0;
  for(int i=0;i<n;i++)
  {
    cin>>arr[i];
    if(min > arr[i])
      min = arr[i];
  }
  for(int i=0;i<n;i++)
      arr[i] = arr[i]+abs(min);
  for(int i=0;i<n;i++)
  {
    if(max < arr[i])
      max = arr[i];
    if(min2 > arr[i])
      min2 = arr[i];
  }
  int range = max-min2+1;
  int count[range] = {0};

  for(int i=0;i<n;i++)
    count[arr[i]]++;

  for(int i=1;i<range;i++)
    count[i] += count[i-1];

  int b[n]={0};
  for(int i=n-1;i>=0;i--)
  {
    int item = arr[i];
    count[arr[i]]--;
    int index = count[arr[i]];
    b[index] = item;
  }
  for(int i=0;i<n;i++)
    arr[i] = b[i]-abs(min);

  for(int i=0;i<n;i++)
      cout<<arr[i]<<" ";
    cout<<endl;


  return 0;
}
