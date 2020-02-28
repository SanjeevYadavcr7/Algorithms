#include<iostream>
using namespace std;

struct node
{
  int data;
  struct node* next;
};
struct node* head;

void insert(int value)
{
  if(head == NULL)
  {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = value;
    temp->next = head;
    head = temp;
  }
  else
  {
    struct node* ptr = head;
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = value;
    temp->next = NULL;

    while(ptr->next != NULL)
    {
      ptr = ptr->next;
    }
    ptr->next = temp;
  }
}

void insert_at_loc(int loc, int value)
{
  struct node* ptr = head;
  struct node* temp = (struct node*)malloc(sizeof(struct node));
  temp->data = value;
  temp->next = NULL;
  if(loc == 1)
  {
    temp->next = head;
    head = temp;
  }
  else
  {
    while(loc-- > 2)
      ptr = ptr->next;

    temp->next = ptr->next;
    ptr->next = temp;
  }
}

void Delete(int loc)
{

  if(head == NULL)
    cout<<"\nList is alredy empty\n";
  else
  {
    if(loc == 1)
    {
      struct node* ptr = head;
      head = ptr->next;
    }
    else
    {
      struct node* ptr = head;
      while(loc > 2)
      {
        ptr = ptr->next;
        loc--;
      }
      ptr->next = ptr->next->next;
    }
  }

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
  int flag = 1;
  while(flag)
  {
    int n,ch,x;

    cout<<"Press 1 to enter in regular fashion\nPress 2 to enter at specific position\nPress 3 to Delete\nEnter your Choice = ";
    cin>>ch;
    if(ch == 1)
    {
      cout<<"Enter N = ";
      cin>>n;
      while(n-- > 0)
      {
        cout<<"\nEnter data = ";
        cin>>x;
        insert(x);
        traverse();
      }
    }
    else if(ch == 2)
    {
      int loc;
      cout<<"Enter location = ";
      cin>>loc;
      cout<<"Enter data = ";
      cin>>x;
        insert_at_loc(loc,x);
        traverse();
    }
    else if(ch == 3)
    {
      int loc;
      cout<<"\nEnter location of data to be deleted = ";
      cin>>loc;
      Delete(loc);
      traverse();
    }
    else
      cout<<"You've entered wrong choice\n";

    char ch2;
    cout<<"\nWant to Continue ?(y/n) = ";
    cin>>ch2;
    if(ch2 == 'y')
      flag = 1;
    else
      flag = 0;
  }
return 0;
}
