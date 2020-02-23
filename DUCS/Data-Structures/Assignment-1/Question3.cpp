#include<iostream>
#include<cstdlib>
using namespace std;

class CSLLNode{

 public:
  int info;
  CSLLNode *next;

CSLLNode(){
info=0;
next=NULL;
}

CSLLNode(int val,CSLLNode* ptr){
info=val;
next=ptr;
}

};


class CSLL{


CSLLNode* head=NULL;
CSLLNode* tail=NULL;

public:

void addtohead(){
int info;
cout<<"\nEnter the info: ";
cin>>info;
CSLLNode *node = new CSLLNode(info,NULL);
if(head==NULL)
{head=tail=node;
 tail->next=head;
}
else{
node->next=head;
head=node;
tail->next=head;
}
cout<<"\nElement added.";
traverse();
}

void addtotail(){
int info;
cout<<"\nEnter the info: ";
cin>>info;
CSLLNode *node = new CSLLNode(info,NULL);
if(tail==NULL){
head=tail=node;
tail->next=head;
}
else{
tail->next=node;
tail=node;
tail->next=head;
}
cout<<"\nElement added.";
traverse();
}

void delfromhead(){
CSLLNode* temp=head;
if(head==NULL)cout<<"\nCannot delete, List is Empty.";
else if(head==tail){
head=tail=NULL;
delete temp;
traverse();
}
else{
head=head->next;
delete temp;
tail->next=head;
traverse();
}
}

int search(int var){
CSLLNode* p=head;
int count1=0;
while(p->next!=head){
	 count1++;
	 if(p->info==var)return count1;
	 p=p->next;
}

if(tail!=NULL&&tail->info==var)return count1++;

return -1;
}

void delfromtail(){
	if(head==NULL)cout<<"\nCannot delete, List is Empty.";
	else if(head==tail){
		delete head;
		head=tail=NULL;
        traverse();
	}
	else {
		CSLLNode* pt=head;
		while(pt->next!=tail){
		pt=pt->next;
	}
	delete tail;
	tail=pt;
        tail->next=head;
	traverse();
	}

}

void traverse(){
CSLLNode* p=head;
cout<<"\nList-> ";

if(p!=NULL){

	while(p->next!=head){
	cout<<p->info<<"  ";
	p=p->next;
	}
        cout<<p->info;
}
else cout<<"List is Empty";
}

void addtopos(int);
void delfrompos(int);
};

void CSLL::addtopos(int pos){

int info,count1=0;
CSLLNode *q,*p=head;
if(p!=NULL){
while(p->next!=head){count1++; p=p->next;}
count1++;
}
if(pos>count1||pos<0)cout<<"\nIndex is not valid.";
else{
cout<<"\nEnter the info: ";
cin>>info;
CSLLNode *node = new CSLLNode(info,NULL);
p=head;
if(pos==0){
    node->next=head;
    head=node;
    tail->next=head;
}
else if(pos==count1){
tail->next=node;
tail=node;
tail->next=head;
}
else{
for(int i=0;i<pos-1;i++){
    p=p->next;
}
q=p->next;
node->next=q;
p->next=node;
}
traverse();
}
}

void CSLL::delfrompos(int pos){

CSLLNode *q,*p=head;
int count1=0;
if(p!=NULL){
while(p->next!=head){count1++; p=p->next;}
count1++;
}
if(pos>=count1||pos<0)cout<<"\nIndex is not valid.";
else if(head==NULL)cout<<"Can't delete, No element in the list.";
else {
      p=head;
      q=head;
      if(pos==0&&head==tail){
         head=tail=NULL;
         delete p;
      }
      else if(pos==0){
        head=head->next;
        delete p;
        tail->next=head;
      }
      else{
        for(int i=0;i<pos;i++){
            if(p!=q)
            q=q->next;
            p=p->next;
        }
        if(p==tail){
        q->next=NULL;
        delete p;
        tail=q;
        tail->next=head;
        }
        else{
            q->next=p->next;
            delete p;
        }
      }
    cout<<"\nElement deleted.";
    traverse();
}
}


int main(){
CSLL list;
char ch;
int ele,pos;
do{
cout<<"\n\nMENU::\n1)Add node to head.\n2)Add node to tail.\n3)Add node in a position.\n4)Delete node from head.\n";
cout<<"5)Delete node from tail.\n6)Delete node from a position.\n7)Traverse.\n8)search element.\n9)Exit.\n";
cout<<"\nEnter your choice: ";
cin>>ch;
switch(ch){
case '1':list.addtohead();
 break;
case '2':list.addtotail();
 break;
 case '3': cout<<"\nEnter the index of the new element: ";
           cin>>pos;
           list.addtopos(pos);
 break;
case '4':list.delfromhead();
 break;
case '5':list.delfromtail();
 break;
 case '6':cout<<"\nEnter the index of the element to be deleted: ";
           cin>>pos;
           list.delfrompos(pos);
 break;
case '7':list.traverse();
 break;
case '8':cout<<"\nEnter ele to search: ";
          cin>>ele;
         pos=list.search(ele);
         if(pos!=-1)cout<<"\nElement found at index: "<<pos-1<<endl;
         else cout<<"\nElement not found.\n";
 break;
case '9':exit(0);
default: cout<<"\nWrong choice!!";

}
}while(true);
return 0;
}
