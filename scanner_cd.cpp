//Libraries
#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

//Scanner function
void Scanner(string s){
    //variable ‘i’ is to keep track of the index of the string that is being checked
    int i=0, state=0;
    char c;
    while(i<s.length()){
        switch(state){ //switch case is to handle different states of the dfa
            //case 0 determines state 0 of the dfa
            case 0: c=s[i];
                if(c=='0')
                    state=0;
                else if(c=='1')
                    state=1;
                else
                    state=4;
                i++;
                break;
            //case 1 determines state 1 of the dfa
            case 1:
                c=s[i];
                if(c=='0')
                    state=1;
                else if(c=='1')
                    state=2;
                else
                    state=4;
                i++;
                break;
            //case 2 determines state 2 of the dfa
            case 2:
                c=s[i];
                if(c=='0')
                    state=2;
                else if(c=='1')
                    state=3;
                else
                    state=4;
                i++;
                break;
            //case 3 determines state 3 of the dfa
            case 3:
                c=s[i];
                if(c=='0')
                    state=3;
                else if(c=='1') 
                    state=4;
                else
                    state=4;
                i++;
                break;
            //case 4 determines state 4 of the dfa or the failure state
            case 4:
                c=s[i];
                state=4;
                i++;
                break; 
            default: 
                state=4;
                i++;
                break;
        }

    }
    //if it’s the state 4 or failure, then only the string is not accepted
    if(state==4)
        cout<<"String "<<s<<" is not accepted by this scanner";
    else
        cout<<"Succesful Scanning!"<<endl<<"String "<<s<<" is accepted by this scanner";

}
int main()
{
    string s;
    cout<<"Enter the string of 0's and 1's that you want to check for the language"<<endl;
    cin>>s;
    Scanner(s);

}
