#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Data{
    String name,address,disease,gender,description;
    int specialRoomNo,age;
}
struct Node
{
    Data data;
    Node* next;
};
Node* insertFront(Node* head, Data data)
{
    Node* temp = new Node;
    temp->data = data;
    temp->next = head;
    head=temp;
    return head;
}
Node* append(Node* head,Data data)
{
    Node* temp = new Node;
    temp->data=data;
    temp->next=NULL;
    if(head==NULL)
    {
        head = temp;
        return head;
    }
    Node* last = head;
    while(last->next!=NULL)
    {
        last=last->next;
    }
    last->next=temp;
    printf("\nAppend completed\n");
    return head;
}
void changeNode(Node* head,Data data,Data newData)
{
    while(head!=NULL)
    {
        if(head->data.name==data.name)
        {
            head->data=newData;
            break;
        }
        head = head->next;
    }
}
void changeNode(Node* head,string data,string newData)
{
    while(head!=NULL)
    {
        if(head->data.name==data)
        {
            head->data.name=newData;
        }
        head=head->next;
    }
}
void PrintLinkedList(Node* head)
{
    if(head==NULL)
    {
        printf("\nHead is null\n");
        return;
    }
    while(head->next!=NULL)
    {
        printf("\nName:%s",head->data.name);
        printf("\nAddress:%s",head->data.address);
        printf("\nGender:%s",head->data.gender);
        printf("\nDisease:%s",head->data.disease);
        printf("\nDescription:%s",head->data.description);
        printf("\nAge:%s",head->data.age);
        printf("\nSpecialist room no:%s",head->data.specialRoomNo);
        head=head->next;
    }
    printf("\nName:%s",head->data.name);
        printf("\nAddress:%s",head->data.address);
        printf("\nGender:%s",head->data.gender);
        printf("\nDisease:%s",head->data.disease);
        printf("\nDescription:%s",head->data.description);
        printf("\nAge:%s",head->data.age);
        printf("\nSpecialist room no:%s",head->data.specialRoomNo);
}
int listLength(Node* head){
    int temp=0;
    if(head==NULL)
    {
        printf("\nNode is empty\n");
        return 0;
    }
    while(head->next!=NULL)
    {
        ++temp;
        head=head->next;
    }
    return temp+1;
}
void delelement(Node* head,int loc)
{
    Node* temp=new Node;
    temp=head;
    if(head==NULL)
    {
        printf("\nNode is null");
        return;
    }
    for(int i=1;i<=loc;++i)
    {
        temp=temp->next;
        if(i<loc){
            head=head->next;
        }
    }
    head->next=temp->next;
}
Node* searchList(Node* head,Data v){
    if(head==NULL)
    {
        printf("\nNode is empty returning null");
        return NuLL;
    }
    int l=1;
    while(head->next!=NuLL && head->data.name!=v.name)
    {
       head=head->next;
       ++l;
    }
    printf("\nElement found at location:%d",l);
    return head;
}
Node* searchList(Node* head,string v){
    if(head==NULL)
    {
        printf("\nNode is empty returning null");
        return NULL;
    }
    int l=1;
    while(head->next!=NULL && head->data.name!=v)
    {
        head=head->next;
        ++l;
    }
    printf("\nElement found at location:%d",l);
    return head;
}
Data inputPatients()
{
    string name,address,disease,gender,description;
    int specialRoomNo,age;
    Data p;
    printf("\nEnter patient name:");
    cin.ignore();//clearing buffer
    gets(cin,name);
    printf("\nEnter patient address:");
    gets(cin,address);
    printf("\nEnter patient disease:");
    gets(cin,disease);
    printf("\nEnter patient gender:");
    gets(cin,gender);
    printf("\nEnter disease description:");
    gets(cin,description);
    printf("\nEnter patient special room no:%d",specialRoomNo);
    printf("\nEnter patient age:%d",age);
    p.name=name;
    p.address=address;
    p.gender=gender;
    p.description=description;
    p.specialRoomNo=specialRoomNo;
    p.age=age;
    printf("\nCompleted input operation\n");
    return p;
}
int main()
{
    Node* head=NULL;
    Data patient;
    string nameToSearch;
    string oldName,newName;
    int op;
      printf("\n1.Add patient\n2.Del patient\n3.Search by name\n4.List length\n5.Print list\n6.Change patient name\n7.Insert new at front\n");
      while(cin>op){
          switch (op)
          {
            case 1:
                  printf("\nEnter patient details below\n");
                  patient = inputPatients();
                  head=append(head,patient);
                  break;
            case 2:
                  if(listLength(head)<2)
                  {
                      printf("\nLength is less than two.\nTerminating program\n");
                      exit(1);
                  }
                  else{
                      printf("\nEnter location where you want to delete a patient,at least three patient must be in a list\n");
                      int l;
                      cin >> 1;
                      delElement(head,l);
                    }
                    break;
            case 3: 
                    printf("\nEnter name to search patient:\n");
                    cin.ignore();
                    gets(cin,nameToSearch);
                    searchList(head,nametoSearch);
                    break;
            case 4:
                    printf("\nYou have:%d",listLength(head));
                    printf("patients in your hosital\n");
                    break;
            case 5:
                   printLinkedList(head);
                   break;
            case 6: 
                   cin.ignore();
                   printf("\nEnter old name:");
                   gets(cin,oldName);
                   printf("\nEnter new name:");
                   gets(cin, newName);
                   changeNode(head,oldName,newName);
                   break;
            case 7:
                   patient=inputPatients();
                   head=insertFront(head,patient);
                   break;
            default:
                    printf("\nWrong option selected\n");
          }
          printf("\n1.Add patient\n2.Del patient\n3.Search by name\n4.List length\n5.Print list\n6.Change patient name\n7.Insert new at front\n");

      }

}