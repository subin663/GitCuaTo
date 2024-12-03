#include <iostream>
#include <math.h>
using namespace std;

struct nut {
	int data;
	nut *nleft;
	nut *nright;
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

//Dem so nut chi co 1 nhanh 
int Demnut(Node *t) {
    if (t == NULL) {
        return 0; 
    }
 
    if ((t->nleft == NULL && t->nright != NULL) || (t->nleft != NULL && t->nright == NULL)) {
        return 1 + Demnut(t->nleft) + Demnut(t->nright); 
    }
    
    return Demnut(t->nleft) + Demnut(t->nright);
}

//Tinh chieu cao cua cay
int Chieucao(Node *t) {
    if (t == NULL) {
        return -1; 
    }
    int ccnleft = Chieucao(t->nleft);
    int ccnright = Chieucao(t->nright);
    return 1 + max(ccnleft, ccnright);
}

void Timnut(Node *t){
	if ()
}

//Tim 1 nut co gia tri bat ki va tinh muc va so nut la cua nut tim duoc
void cau5(node *t){
	int n;
	cout<<"Vui long nhap gia tri cua nut muon tim ";
	cin>>n;
	
}


int main() {
	Node *cay=NULL;
	Taocay(cay);


	cout << "Cac phan tu trong cay theo thu tu LNR: ";
	duyetLNR(cay);
	cout << endl;
	cout<<"So nut chi co 1 nhanh tren cay la: "<<Demnut(cay)<<endl;
	
	cout<<"Chieu cao cua cay la: "<<Chieucao(cay);
	return 0;
}

