/* CFG 
S -> BABABAB
B -> 0B/ε
A -> 1/ε
*/

//Libraries
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

//Global variables
string s;
int i=0;

//Parser class containing all the necessary functions
class Parser{
public :
//Function B() represents non terminal B in the CFG
void B(){
    if(s[i]=='0'){
        i++;
        B();   
    }
}
//Function A() represents non terminal A in the CFG
void A(){
    if(s[i]=='1'){
        i++;   
    }
}
//Function S() represents non terminal S in the CFG
void S(){
    B();
    A();
    B();
    A();
    B();
    A();
    B();
}
};

int main(){
cout<<"Enter the string with $ at the end"<<endl;
cin>>s;
Parser obj;
obj.S();
int n=s.length();
if(s[i]=='$')
    cout<<"String "<<s.substr(0,n-1)<<" is accepted by this parser";
else
    cout<<"String "<<s.substr(0,n-1)<<" is not accepted by this parser";
return 0;
}
