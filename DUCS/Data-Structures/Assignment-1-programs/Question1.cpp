#include<iostream>
#include<cstdlib>
using namespace std;

template <typename T>
class SLLNode{

 public:
  T info;
  SLLNode<T> *next;

SLLNode(){
  next=NULL;
}

SLLNode(T val,SLLNode<T>* ptr){
  info=val;
  next=ptr;
}

};

template <typename T>
class SLL{
 

SLLNode<T>* head=NULL;
SLLNode<T>* tail=NULL;

public:

void addtohead(){
  
  int info;
  cout<<"\nEnter the info: ";
  cin>>info;
  SLLNode<T> *node = new SLLNode<T>(info,NULL);
  
  if(head==NULL)
  	head=tail=node;
  else{
	node->next=head;
	head=node;
  }

cout<<"\nElement added.";
traverse();
}

void addtotail(){
int info;
cout<<"\nEnter the info: ";
cin>>info;
SLLNode<T> *node = new SLLNode<T>(info,NULL);

if(tail==NULL)
	head=tail=node;
else{
	tail->next=node;
	tail=node;
}
cout<<"\nElement added.";
traverse();
}

void delfromhead(){

SLLNode<T>* temp=head;

if(head==NULL)cout<<"\nCannot delete, List is Empty.";

else if(head==tail){
	head=tail=NULL;
	delete temp;
	traverse();
}
else if(head!=NULL){
	head=head->next;
	delete temp;
	traverse();
}

}

int searchAndSwap(T var){

SLLNode<T>* p=head;
int count1=1;
T temp;
if(p->info==var) return count1;
while(p->next!=NULL){
  count1++;
	if(p->next->info==var){
    temp = p->info;
    p->info = p->next->info;
    p->next->info = temp;
    return count1;
  };
	p=p->next;
}
return -1;
}

void delfromtail(){

if(head==NULL)cout<<"\nCannot delete, List is Empty.";

else if(head==tail){
	delete head;
	head=tail=NULL;
	traverse();
}
else{
	
	SLLNode<T>* pt=head;
	while(pt->next!=tail){
	pt=pt->next;
	}
	
	delete tail;
	tail=pt;
	pt->next=NULL;
	traverse();
}

}

void traverse(){

SLLNode<T>* p=head;
cout<<"\nLinked list: ";

if(p!=NULL){
	while(p!=NULL){
	cout<<p->info<<" -> ";
	p=p->next;
	}
    cout<<" NULL";
}
else cout<<"Empty";

}

void reverse(){

SLLNode<T> *q, *s, *p=head;

if(p->next!=NULL){
    s=p->next;
    while(s!=NULL){
      q=s->next;
      s->next = p;
      p=s;
      s=q;
    }

    p=head;
    head=tail;
    tail=p;

    tail->next=NULL;
}


}

void addtopos(int);
void delfrompos(int);
};


template <typename T>
void SLL<T>::addtopos(int pos){

int info,count1=0;
SLLNode<T> *q,*p=head;
while(p!=NULL){
    count1++; 
    p=p->next;
}
if(pos>count1||pos<0)cout<<"\nIndex is not valid.";
else{
cout<<"\nEnter the info: ";
cin>>info;
SLLNode<T> *node = new SLLNode<T>(info,NULL);
p=head;
if(pos==0){
    node->next=head;
    head=node;
    if(count1==0){
        tail=head;
    }
}
else if(pos==count1){
    tail->next=node;
    tail=node;
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

template <typename T>
void SLL<T>::delfrompos(int pos){

SLLNode<T> *q,*p=head;
int count1=0;
while(p!=NULL){count1++; p=p->next;}
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
SLL<int> list;
char ch;
int ele;
int pos;
do{
cout<<"\n\nMENU::\n1)Add ele to head.\n2)Add ele to tail.\n3)Add ele in a position.\n4)Delete ele from head.\n";
cout<<"5)Delete ele from tail.\n6)Delete ele from a position.\n7)Reverse list.\n8)Search element and Swap.\n9)Exit.\n";
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
case '7':list.reverse();
         cout<<"\nList is reversed.";
         list.traverse();
 break;
case '8':cout<<"\nEnter ele to search: ";
          cin>>ele;
         pos=list.searchAndSwap(ele);
         if(pos!=-1)cout<<"\nElement found at index "<<pos-1<<" is swapped with its previous element."<<endl;
         else cout<<"\nElement not found.\n";
         list.traverse();
 break;
case '9':exit(0);
default: cout<<"\nWrong choice!!";

}
}while(true);
return 0;
}
