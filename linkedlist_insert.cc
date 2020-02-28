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

  while(loc-- > 2)
    ptr = ptr->next;

  temp->next = ptr->next;
  ptr->next = temp;

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

    cout<<"Press 1 to enter in regular fashion\nPress 2 to enter at specific position\nEnter your Choice = ";
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
