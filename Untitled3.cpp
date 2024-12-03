#include <iostream>
#include <stack>
using namespace std;
int main(){
    string s;
    getline (cin,s);
    stack<char> st;
    int biendem=0;
    for (int i=0;i<s.length();i++){
		for (int j=i+1;j<s.length();j++){
			if (s[i]==s[j]){
				biendem++;
			}
		}
		st.push(biendem);
		biendem=0;
    }
    
    char a=s[0];
    cout<<a;
    
}
