#include<iostream>
using namespace std;

struct node
{
  int data;
  struct node* next;
};

struct node *head;

void insert(int value)
{
  struct node* temp = (struct node*)malloc(sizeof(struct node));
  temp->data = value;
  temp->next = NULL;

  if(head == NULL)
  {
    temp->next = head;
    head = temp;
  }
  else
  {
    struct node* ptr = head;
    while(ptr->next != NULL)
      ptr = ptr->next;
    ptr->next = temp;
  }
}

void reverse()
{
    struct node* current = head;
    struct node* prev = NULL;
    struct node* new_next;

    while(current != NULL)
    {
      new_next = current->next;
      current->next = prev;
      prev = current;
      current = new_next;
    }
    head = prev;
}

void traverse()
{
    struct node* ptr = head;
    while(ptr != NULL)
    {
      cout<<"["<<ptr->data<<"] -> ";
      ptr = ptr->next;
    }
    cout<<endl;
}

int main()
{
  head = NULL;
  int y=1;
  while(y == 1)
  {
    int ch;
    cout<<"Press 1 to enter elements\nPress 2 to reverse list\nEnter your choice = ";
    cin>>ch;
    if(ch == 1)
    {
      int n,x;
      cout<<"Enter number of elemets to be inserted = ";
      cin>>n;

      for(int i=0;i<n;i++)
      {
        cin>>x;
        insert(x);
        traverse();
      }
    }
    else if(ch == 2)
    {
      reverse();
      traverse();
    }
    else
      cout<<"You've entered wrong choice";

    char ch2;
    cout<<"Want to continue ?(y/n) = ";
    cin>>ch2;
    if(ch2 == 'y')
      y = 1;
    else
      y = 0;
  }


  return 0;
}
