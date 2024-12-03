#include <iostream>
using namespace std;


struct node {
    int gtri;      
    node *tiep;      
};

//Ham tao mot node moi
node *taonode(int x) {
    node *nnode = new node();  
    nnode->gtri = x;           
    nnode->tiep = NULL;       
    return nnode;
}

//Ham tao node cuoi
void taoncuoi(node *&head, int x){
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


//Tim so le dau tien co trong dslk
void cau5(node *head){
	node *temp=head;
	while (temp!=NULL){
		if (temp->gtri%2!=0){
			cout<<"So le dau tien trong dslk la: ";
			cout<<temp->gtri<<endl;
			break;
		}
		temp=temp->tiep;
	}
}

//Tim so chan cuoi cung co trong dslk
void cau6(node *head){
	node *temp=head;
	int ans=0;
	while (temp!=NULL){
		if (temp->gtri%2==0){
			ans=temp->gtri;
		}
		temp=temp->tiep;
	}
	cout<<"So chan cuoi cung trong dslk la: "<<ans;
}



int main() {
	node *head=NULL;
	head=taonode(-3);
	taoncuoi(head,-2);
	taoncuoi(head,-3);
	taoncuoi(head,-1);
	taoncuoi(head,5);
	taoncuoi(head,6);
//    node *head = taonode(1);
//    head->tiep = taonode(2);
//    head->tiep->tiep = taonode(-3);
//    head->tiep->tiep->tiep = taonode(5);

    cout << "Danh sach lien ket: ";
    duyetnode(head);
    cau5(head);
	cau6(head);
	
    return 0;
}

