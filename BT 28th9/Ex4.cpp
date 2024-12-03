#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;
int giaithua(int n){
	int ansGT=1;
	for (int i=1;i<=n;i++){
		ansGT*=i;
	}
	return ansGT;
}
int ketqua(int n){
	int tongGT=0;
	for (int i=1;i<=n;i++){
		tongGT+=giaithua(i);
	}
	return tongGT;
}
int main(){
	int n;
	cout<<"Nhap n: ";
	cin>>n;
//	if (n<0){
//		cout<<"Vui long nhap n>0";
//		return 0;
//	}
	cout<<"Ket qua la: "<<ketqua(n);
	return 0;
}
