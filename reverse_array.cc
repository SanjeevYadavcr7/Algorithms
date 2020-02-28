#include<iostream>
using namespace std;

int main()
{
  int n;
  cout<<"Enter size of array = ";
  cin>>n;
  cout<<"Enter array = ";
  int arr[n];
  for(int i=0;i<n;i++)
    cin>>arr[i];

  for(int i=0;i<n/2;i++)
  {
    int box = arr[i];
    arr[i] = arr[n-1-i];
    arr[n-1-i] = box;
  }

  cout<<"reversed array = ";
  for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";

  cout<<endl;

  return 0;
}
