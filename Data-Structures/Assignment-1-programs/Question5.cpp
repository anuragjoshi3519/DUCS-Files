#include<iostream>
#include<cstring>
using namespace std;

void reverseString(string &s,int l){

int f=s.length()-l-1;

if( f>=l )return;
char temp;
temp=s[f];
s[f]=s[l];
s[l]=temp;
reverseString(s,l-1);

}

int main(){

string s;
cout<<"\nEnter the string: ";
getline(cin,s); 
reverseString(s,s.length()-1);
cout<<"\nReversed String: "<<s;
cout<<"\n\n";
}