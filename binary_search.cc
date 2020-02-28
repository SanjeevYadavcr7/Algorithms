#include<iostream>
using namespace std;

int main()
{
  int n;
  cout<<"Enter size of array = ";
  cin>>n;
  int arr[n];
  cout<<"Enter elements of array in sorted order = ";
  for(int i=0;i<n;i++)
    cin>>arr[i];

  int item,flag=0;
  cout<<"Enter element to be searched = ";
  cin>>item;

  int beg = 0,end = n-1;
  while(beg <= end)
  {
    int mid = (beg+end)/2;
    if(arr[mid] == item)
    {
      flag = 1;
      break;
    }
    else if(arr[mid] < item)
      beg = mid+1;
    else
      end = mid-1;
  }
  if(flag == 1)
    cout<<"Element found\n";
  else
    cout<<"Element not found\n";

 return 0;
}
