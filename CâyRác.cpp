#include <iostream>
using namespace std;
struct nut{
	int data;
	nut *nleft;
	nut *nright;
};

typedef nut Node;
Node *root;

void Khoitao(Node *&root){
	root=NULL;
}

void Taonhanh(Node *&root, int x){
	if (root==NULL){
		Node *p=new Node();
		p->data=x;
		p->nleft=NULL;
		p->nright=NULL;
	}else{
		if (root->data<=x){
			Taonhanh(root->nright,x);
		}
		if (root->data>x){
			Taonhanh(root->nleft,x);
		}
	}
}

void Taocay(Node *&root){
	int temp;
	do{
		cout<<"Nhap so nguyen duong. Nhap 0 de dung !";
		cin>>temp;
		if (temp!=0){
		Taonhanh(root,temp);
		}
	}while(temp!=0);
}

int main(){
	Node *cay=NULL;
	Taocay(cay);
	Taonhanh(cay,5);
	
}
