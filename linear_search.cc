#include<iostream>
using namespace std;

int main()
{
  int n;
  cout<<"Enter size of array = ";
  cin>>n;
  int arr[n];
  cout<<"Enter elements of array = ";
  for(int i=0;i<n;i++)
    cin>>arr[i];

  int item,flag=1;
  cout<<"Enter element to be searched = ";
  cin>>item;
  for(int i=0;i<n;i++)
  {
    if(arr[i] == item)
    {
      flag = 1;
      break;
    }
    else
      flag = 0;
  }
  if(flag == 1)
    cout<<"Element found\n";
  else
  cout<<"Element not found\n";

 return 0;
}
