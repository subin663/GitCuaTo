#include <iostream>
using namespace std;


struct node {
    float gtri;      
    node *tiep;      
};

//Ham tao mot node moi
node *taonode(float x) {
    node *nnode = new node();  
    nnode->gtri = x;           
    nnode->tiep = NULL;       
    return nnode;
}

//Ham tao node cuoi
void taoncuoi(node *&head, float x){
	node *nnode=taonode(x);
	node *p=head;
	if (head==NULL){
		head=nnode;
		}else{
			while(p->tiep!=NULL){
				p=p->tiep;
				}
			p->tiep=nnode;				
		}
	}
	

//Duyet danh sach lien ket
void duyetnode(node *head) {
    while (head != NULL) {
        cout << head->gtri << " ";  
        head = head->tiep;        
    }
    cout << endl;
}

//Tim so duong nho nhat
void cau1(node *&head) {
    node *temp = head;
    float min = -1;  
    
    while (temp != NULL) {
        if (temp->gtri > 0 && (min == -1 || temp->gtri < min)) {
            min = temp->gtri;  
        }
        temp = temp->tiep;
    }
    
    if (min == -1) {
        cout << "Khong co so duong trong danh sach." << endl;
    } else {
        cout << "So duong nho nhat: " << min << endl;
    }
}


//Tim so am lon nhat
void cau2(node *&head) {
    node *temp = head;
    float max = 0;  
    
    while (temp != NULL) {
        if (temp->gtri < 0 && (max == 0 || temp->gtri > max)) {
            max = temp->gtri;  
        }
        temp = temp->tiep;
    }
    
    if (max == 0) {
        cout << "Khong co so am trong danh sach." << endl;
    } else {
        cout << "So am lon nhat: " << max << endl;
    }
}

//Tinh tong cac so duong trong dslk
void cau3(node *head){
	node *temp=head;
	float tong=0;
	while (temp!=NULL){
		if (temp->gtri>0){
			tong+=temp->gtri;
		}
		temp=temp->tiep;
	}
	cout<<"Tong cac so duong la: "<< tong<<endl;
}

//Tinh tong cac so am trong dslk
void cau4(node *head){
	node *temp=head;
	float tong=0;
	while (temp!=NULL){
		if (temp->gtri<0){
			tong+=temp->gtri;
		}
		temp=temp->tiep;
	}
	cout<<"Tong cac so am la: "<< tong<<endl;
}




int main() {
	node *head=NULL;
	head=taonode(-3.5);
	taoncuoi(head,-2.5);
	taoncuoi(head,-3.5);
	taoncuoi(head,-1.5);
	taoncuoi(head,5);
	taoncuoi(head,6);
//    node *head = taonode(1);
//    head->tiep = taonode(2);
//    head->tiep->tiep = taonode(-3);
//    head->tiep->tiep->tiep = taonode(5);

    cout << "Danh sach lien ket: ";
    duyetnode(head);

    cau1(head);
    cau2(head);
    cau3(head);
	cau4(head);
	
	
    return 0;
}

