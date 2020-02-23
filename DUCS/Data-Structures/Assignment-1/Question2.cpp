#include<iostream>
#include<stdlib.h>
using namespace std;
class IntDLLNode
  {	public:
	int info;
	static int count;
	IntDLLNode *next, *prev;
	IntDLLNode ()
	   {	count++;
		info=0;
		next=NULL;
		prev=NULL;
	   }
	~IntDLLNode()
	   {
		count--;
	    }
  };
int IntDLLNode::count=0;
class DLList
 {	public:
	IntDLLNode *head, *tail, *p;
	DLList()
	 {
		head=tail=p=NULL;
	  }
	void add_to_head(int val)
	 {
		IntDLLNode *newNode= new IntDLLNode();
		newNode->info=val;
		if(head==NULL)
	 	   {
			head=newNode;
			tail=newNode;
		   }
		else
		   {
			head->prev=newNode;
			newNode->next=head;
			head=newNode;
		   }
	   }
	void add_to_tail(int val)
	   {
		IntDLLNode *newNode=new IntDLLNode();
		newNode->info=val;
		if(tail==NULL)
		   {
			head=newNode;
			tail=newNode;
		    }
		else
		   {
			tail->next=newNode;
			newNode->prev=tail;
			tail=newNode;
		    }
	   }
	void traverse()
	  {
		p=head;
		if(head==NULL)
		   {
			cout<<"List is empty\n";
			return;
		    }
		while(p!=NULL)
		  {
			cout<<p->info<<" ";
			p=p->next;
		   }
	   }
	void traverse_reverse()
	   {
		p=tail;
		if(tail==NULL)
		   {
			cout<<"List is empty\n";
			return;
		    }
		while(p!=NULL)
		  {
			cout<<p->info<<" ";
			p=p->prev;
		   }
	   }
	void search(int val)
	   {
		p=head;
		if(tail==NULL)
		   {
			cout<<"List is empty\n";
			return;
		    }
		else
		   {
			while(p!=NULL)
			   {
				if(p->info==val)
				  {
					cout<<"Element found\n";
					return;
				   }
				p=p->next;
			   }
			cout<<"Element not found\n";
			return;
		    }
	   }
	void delete_from_head()
	  {
		if(head==NULL)
		  {
			cout<<"List is empty\n";
			return;
		   }
		else if(head==tail)
		   {
			delete head;
			head=tail=NULL;
			return;
		    }
		else
		  {
			p=head;
			head=head->next;
			delete p;
			head->prev=NULL;
		   }
	   }
	void delete_from_tail()
	   {
		if(head==NULL)
		   {
			cout<<"List is empty\n";
			return;
		    }
		else if(head==tail)
		   {
			delete head;
			head=tail=NULL;
			return;
		   }
		else
		   {
			p=tail;
			tail=tail->prev;
			delete p;
			tail->next=NULL;
		   }
	    }
	
	void delete_from_pos(int pos)
	  {
		if(pos<1 || pos>IntDLLNode::count)
		  {
			cout<<"This position does not exist\n";
			return;
		   }
		else if(pos==1)
		   delete_from_head();
		else if(pos==IntDLLNode::count)
		    delete_from_tail();
		else
		  {
			p=head;
			for(int i=0;i<pos-1;i++)
			   p=p->next;
			p->prev->next=p->next;
			p->next->prev=p->prev;
			delete p;
			p=NULL;
		   }
	    }
	void delete_node(int val)
	   {
		p=head;
		if(tail==NULL)
		  {
			cout<<"List is empty\n";
			return;
		   }
		else
		   {
			while(p!=NULL)
			   {
				if(p->info==val)
				   {
					if(p==head)
					  {
						delete_from_head();
						return;
					  }
					if(p==tail)
					   {
						delete_from_tail();
						return;
					   }
					else
					   {
						p->prev->next=p->next;
						p->next->prev=p->prev;
						delete p;
						p=NULL;
						return;
					    }
				
				   }
				p=p->next;
			    }
			cout<<"Element not found\n";
		   }
	   }
	void add_at_pos(int pos,int val)
	  {
		p=head;
		if(pos==1)
		  {
			add_to_head(val);
			return;
		   }
		if(pos==IntDLLNode::count)
		   {
			add_to_tail(val);
			return;
		    }
		else
		   {
			IntDLLNode *newNode = new IntDLLNode();
			newNode->info=val;
			for(int i=0;i<pos-2;i++)
			     p=p->next;
			newNode->next=p->next;
			p->next=newNode;
			p=p->next;
			newNode->prev=p->prev;
			p->prev=newNode;
			

		   }
	  }	
							




};
int main()
{
DLList List1;
int ch,val,pos;
const std::string colour("\033[0;36m");
const std::string reset("\033[0m");
while(true) {
	cout<<colour<<"\nProgram for Unordered Double Linked List\n";
	cout<<"MAIN MENU\n";
	cout<<"1. Add to node to head			2. Add a node to tail\n";
	cout<<"3. Print the list 			4. Print the list in reverse\n";
	cout<<"5. Search for an element		6. Delete a node from head\n";
	cout<<"7. Delete a node from tail		8. Delete a node from a position\n";
	cout<<"9. Delete a node with a given value	10. Add a node at a given position\n";
	cout<<"11. Exit\n";
	cout<<"Enter your choice\n"<<reset;
	cin>>ch;
	switch(ch)
	  {
		case 1: cout<<"Enter the value to be added\n";
			cin>>val;
			List1.add_to_head(val);
			cout<<"The updated list is\n";
			List1.traverse();
			break;
		case 2: cout<<"Enter the value to be added\n";
			cin>>val;
			List1.add_to_tail(val);
			cout<<"The updated list is\n";
			List1.traverse();
			break;
		case 3: cout<<"The elements in the list are\n";
			List1.traverse();
			break;
		case 4: cout<<"The elements of the list in reverse order are\n";
			List1.traverse_reverse();
			break;
		case 5: cout<<"Enter the element to search\n";
			cin>>val;
			List1.search(val);
			break;
		case 6: List1.delete_from_head();
			cout<<"Element deleted from head\n";
			cout<<"The updated list is\n";
			List1.traverse();
			break;
		case 7: List1.delete_from_tail();
			cout<<"Element deleted from tail\n";
			cout<<"The updated list is\n";
			List1.traverse();
			break;
		case 8: cout<<"Enter the position from where element is to be deleted\n";
			cin>>pos;
			List1.delete_from_pos(pos);
			cout<<"The updated list is\n";
			List1.traverse();
			break;
		case 9: cout<<"Enter the value of the node to be deleted\n";
			cin>>val;
			List1.delete_node(val);
			cout<<"The updated list is\n";
			List1.traverse();
			break;
		case 10:cout<<"Enter the value to be added\n";
			cin>>val;
			cout<<"Enter the position of the new node\n";
			cin>>pos;
			List1.add_at_pos(pos,val);
			cout<<"The updated list is\n";
			List1.traverse();
			break;
		case 11:exit(0);	
   }
}

}
