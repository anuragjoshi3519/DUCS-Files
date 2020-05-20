#include<iostream>
#include<cstdlib>
using namespace std;

template <typename T>
class CSLLNode{

 public:
  T info;
  CSLLNode *next;

CSLLNode(){
next=NULL;
}

CSLLNode(T val,CSLLNode<T>* ptr){
info=val;
next=ptr;
}

};

template <typename T>
class CSLL{

private:

CSLLNode<T>* cursor=NULL;

bool isEmpty(){ return (cursor==NULL); }

public:

void front(){
  if(isEmpty()) cout<<"\nList is empty"; 
  else cout<< "\nFront element is "<<cursor->next->info;
}

int back(){
  if(isEmpty()) cout<<"\nList is empty"; 
  else cout<< "\nBack element is "<<cursor->info;
}

void add(){
  T info;
  cout<<"\nEnter the info: ";
  cin>>info;
  CSLLNode<T> *node = new CSLLNode<T>(info,NULL);
  if(isEmpty()){
    node->next=node;
    cursor = node;
  }
  else{
    node->next=cursor->next;
    cursor->next=node;
  }
  traverse();
}

void remove(){
  if(isEmpty())cout<<"\nCannot remove, List is Empty.";
  else{
    CSLLNode<T>* temp=cursor->next;
    if(cursor==cursor->next) cursor=NULL;
    else cursor->next = temp->next;

    delete temp;
    traverse();
  }
}

void advance(){
  if(isEmpty()) cout<<"\nCan't move cursor. List is Empty.";
  else{
    cursor=cursor->next;
    traverse();
  }
}

void traverse(){
  if(isEmpty()) cout<<"\nList is Empty.";
  else{
    CSLLNode<T>* p=cursor->next;
    cout<<"\nCircular List-> ";
    while(p!=cursor){
      cout<<p->info<<"  ";
      p=p->next;
    }
    cout<<p->info;
  }

}

};


int main(){

  CSLL<int> list;
  char ch;

  do{
    cout<<"\n\nMENU::\n1)Add node\n2)Remove node\n3)Print Front\n4)Print Back\n";
    cout<<"5)Advance\n6)Traverse list\n7)Exit.\n";
    cout<<"\nEnter your choice: ";
    cin>>ch;
    switch(ch){
      case '1':list.add();
      break;
      case '2':list.remove();
      break;
      case '3':list.front();
      break;
      case '4':list.back();
      break;
      case '5':list.advance();
      break;
      case '6':list.traverse();
      break;
      case '7':exit(0);
      
      default: cout<<"\nWrong choice!!";
    }
  }while(true);

  return 0;
}
