#include <stdio.h>
#include <iostream>
using namespace std;
int main(){
	int n;
	cout<<"Nhap n: ";
	cin>>n;
	int ans=1;
	for (int i=0;i<=n;i++){
		ans*=(2*i+1);
	}
	cout<<"Ket qua: "<<ans;
	return 0;
}


