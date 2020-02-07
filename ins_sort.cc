#include<iostream>
using namespace std;


void print(int arr[], int n)
{
	cout<<"\nSorted array = ";
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl<<endl;

}

void ins_sort(int arr[], int n)
{
	for(int i = 1;i<n;i++)
	{
		int key = arr[i];
		int j=i-1;
		while(j>=0 && arr[j] > key)
		{
			arr[j+1] = arr[j];
			j = j-1;
		}
		arr[j+1] = key;
	}
	print(arr,n);
}

void sel_sort(int arr[], int n)
{
	for(int i=0;i<n;i++)
	{
		int min = i;
		for(int j=i+1;j<n;j++)
		{
			if(arr[j] < arr[min])
			{
				min = j;
			}
		}
		if(min != i)
		{
			int box = arr[i];
			arr[i] = arr[min];
			arr[min] = box;	
		}
		
	}
	print(arr,n);
}

void bub_sort(int arr[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-1-i;j++)
		{
			if(arr[j] > arr[j+1])
			{
				int box = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = box;
			}
		}
	}
	print(arr,n);
}

//////////////// Merge_sort code starts   ///////////////////////////////

void merge(int arr[],int beg,int mid,int end)
{
	int i=beg,j=mid+1,k=0;
	int tmp[end-beg+1];
	while(i<=mid && j<= end)
	{
		if(arr[i] <= arr[j])
		{
			tmp[k] = arr[i];
			i++;
			k++;
		}
		else
		{
			tmp[k] = arr[j];
			j++;
			k++;
		}
	}

	while(i<=mid)
	{
		tmp[k] = arr[i];
		i++;
		k++;
	}
	while(j<=end)
	{
		tmp[k] = arr[j];
		j++;
		k++;
	}

	for(int x = beg;x<=end;x++)
	{
		arr[x] = tmp[x-beg];
	}
}


void Merge_sort(int arr[], int beg, int end)
{
	if(beg<end)
	{
		int mid = (beg+end)/2;
		Merge_sort(arr,beg,mid);
		Merge_sort(arr,mid+1,end);
		merge(arr,beg,mid,end);
	}
}


////////////////// Merge sort code ends   ///////////////////////////////



////////////// Quick sort starts   ///////////////////////////////


int find_pivot(int arr[], int beg, int end)
{
	int pivot = arr[end];
	int i = beg-1;
	for(int j=beg;j<end;j++)
	{
		if(arr[j] < pivot)
		{
			i = i+1;
			int box = arr[i];
			arr[i] = arr[j];
			arr[j] = box;
		}
	}
	int box2 = arr[i+1];
	arr[i+1] = arr[end];
	arr[end] = box2;

	return i+1;
}


void Quick_Sort(int arr[], int p,int r)
{
	if(p<r)
	{
		int q = find_pivot(arr,p,r);
		Quick_Sort(arr,p,q-1);
		Quick_Sort(arr,q+1,r);
	}
}

//////////////// Quick sort ends   ///////////////////////////////



////////////////  Heap Sort starts   //////////////////////////////


void Build_max_heap(int arr[],int n,int i)
{
	int l = 2*i+1;
	int r = 2*i+2;
	int largest = i;
	
	if(l<n &&  arr[l] > arr[i])
		largest = l;
	else
		largest = i;
	
	if(r<n && arr[r] > arr[largest])
		largest = r;

	if(largest != i)
	{
		int tmp = arr[i];
		arr[i] = arr[largest];
		arr[largest] = tmp;

		Build_max_heap(arr,n,largest);
	}
}

void Heap_Sort(int arr[],int n)
{
	for(int i=n/2-1;i>=0;i--)
	{
		Build_max_heap(arr,n,i);
	}

	for(int i=n-1;i>=0;i--)
	{
		int box = arr[i];
		arr[i] = arr[0];
		arr[0] = box;

		Build_max_heap(arr,i,0);
	}
}
////////////////// Heap Sort ends  ///////////////////////////////


int main()
{
	int ch,n;
	cout<<"Enter size of array = ";
	cin>>n;
	int arr[n];
	cout<<"Enter elements of array = ";
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}

	cout<<"\nInsertion Sort-Press 1 || Selection Sort-Press 2 || Merge Sort-Press 3 ||\nQuick Sort - Press 4 || Heap Sort - Press 5 || Bubble Sort - Press 6 ||\n\nEnter Your Choice = ";
	cin>>ch;

	if(ch == 1)
		ins_sort(arr,n);
	else if(ch == 2)
		sel_sort(arr,n);
	else if(ch == 3)
	{
		Merge_sort(arr,0,n-1);
		print(arr,n);
	}
	else if(ch == 4)
	{
		Quick_Sort(arr,0,n-1);
		print(arr,n);
	}
	else if(ch == 5)
	{
		Heap_Sort(arr,n);
		print(arr,n);
	}
	else if(ch == 6)
		bub_sort(arr,n);
	else 
		cout<<"You've Entered Wrong Choice\n\n";


	return 0
}
