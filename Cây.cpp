#include <iostream>
using namespace std;

struct nut {
	int data;
	nut *nleft;
	nut *nright;
	//tao moi sua o day
};

typedef nut Node;



void Taonhanh(Node *&root, int x) {
	if (root == NULL) {
		Node *p = new Node();
		p->data = x;
		p->nleft = NULL;
		p->nright = NULL;
		root = p; 
	} else {
		if (root->data <= x) {
			Taonhanh(root->nright, x);
		} else {
			Taonhanh(root->nleft, x);
		}
	}
}


void Taocay(Node *&root) {
	int temp;
	do {
		cout << "Nhap so nguyen duong. Nhap 0 de dung: ";
		cin >> temp;
		if (temp != 0) {
			Taonhanh(root, temp);
		}
	} while (temp != 0);
}


void duyetLNR(Node *root) {
	if (root != NULL) {
		duyetLNR(root->nleft);
		cout << root->data << " ";
		duyetLNR(root->nright);
	}
}

//void duyetNRL(Node *root){
//	if (root !=NULL){
//		cout<<root->data<<" ";
//		duyetNRL(root->nright);
//		duyetNRL(root->nleft);
//	}
//}

//Dem so nut, tinh tong cac nut
int Demnut(Node *t){
	if (t==NULL){
		return 0;
	}else{
		return 1+Demnut(t->nright)+Demnut(t->nleft);
	}
}

//Tinh tong cac nut
int Tongnut(Node *t){
	if (t==NULL){
		return 0;
	}else{
		return t->data+Tongnut(t->nleft)+Tongnut(t->nright);
	}
}



int main() {
	Node *cay=NULL;
	Taocay(cay);


	cout << "Cac phan tu trong cay theo thu tu LNR: ";
	duyetLNR(cay);
	cout << endl;
	cout<<"So nut tren cay la: ";
	Demnut(cay);
	cout<<endl;
	cout<<"Tong so nut la: "<<Tongnut(cay);
	return 0;
}

