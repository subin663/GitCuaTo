// S = 1 - 2 + 3 - 4 + (-1)^(n+1)*n  
#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;
int dequy(int n){
	int ans=0;
	for (int i=1;i<=n;i++){
		ans+=pow(-1,i+1)*i;	
	}
	return ans;
}
int main(){
	int n;
	cout<<"Nhap n: ";
	cin>>n;
	cout<<"Ket qua la: "<<dequy(n);
	return 0;
}
