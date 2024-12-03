#include <iostream>
using namespace std;

struct node {
    char gtri;      
    node *tiep;  
};

// Ham tao 1 node moi
node *taonode(char x) {
    node *nnode = new node();  
    nnode->gtri = x;           
    nnode->tiep = NULL;       
    return nnode;
}

// ham them nut vao cuoi danh sach
void taoncuoi(node *&head, char x) {
    node *nnode = taonode(x);
    if (head == NULL) {
        head = nnode; 
    } else {
        node *p = head;
        while (p->tiep != NULL) { 
            p = p->tiep;
        }
        p->tiep = nnode; 
    }
}

// Duyet danh sach lien ket
void duyetnode(node *head) {
    while (head != NULL) {
        cout << head->gtri << " ";  
        head = head->tiep;        
    }
    cout << endl;
}

// Ham dem so ky tu 'A' co trong dslk
void cau7(node *head) {
    int count = 0; 
    node *temp=head;
    while (temp != NULL) {
        if (temp->gtri == 'A') {
            count++;
        }
        temp = temp->tiep; 
    }
    cout << "So ky tu 'A' trong danh sach: " << count << endl; 
}

//Ham cho biet vi tri cua phan tu cuoi cung la A
void cau8(node *head) {
    int vitri = 1; 
    int vtriA=0;
    node *temp=head;
    while (temp != NULL) {
        if (temp->gtri == 'A') {
            vtriA=vitri;
        }
        temp = temp->tiep; 
        vitri+=1;
    }
    cout << "Vi tri cuoi cung cua phan tu A: " << vtriA << endl; 
}


int main() {
    node *head = NULL; 
    taoncuoi(head, 'B');
    taoncuoi(head, 'A');
    taoncuoi(head, 'C');
    taoncuoi(head, 'A');
    taoncuoi(head, 'D');
    taoncuoi(head, 'A');
	taoncuoi(head, 'E');
    cout << "Danh sach lien ket: ";
    duyetnode(head); 

    cau7(head); 
	cau8(head);
    return 0;
}

