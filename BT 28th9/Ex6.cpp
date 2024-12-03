#include <iostream>
#include <stdio.h>
using namespace std;
int USC(int a, int b){

		while (b!=0){
			int c=a;
			a=b;
			b=c%b;
			USC(a,b);
	}
	return a;
}
int BSC(int a, int b){
	int ans=1;
	while (ans>0){
		if (ans%a==0 && ans%b==0){
			return ans;
		}
		else{
			ans++;
		}
	}
}
int main(){
	int a,b;
	cout<<"Nhap a: ";
	cin>>a;
	cout<<endl<<"Nhap b: ";
	cin>>b;
	if (a<b){
		int c=a;
		a=b;
		b=c;
	}
//	cout<<"Uoc so chung la: "<<USC(a,b);
	cout<<"Boi so chung la: "<<BSC(a,b);
	
	return 0;
}
