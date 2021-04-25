#include<iostream>
using namespace std;
struct SinglyList{
    int data;
    SinglyList *Next;
};
SinglyList *Head = new SinglyList;
//this is the Head Node,if we have'n the Node,we can't built the Ndoe
void Init(){  //Init the SinglyList
    Head->Next = NULL;
}
void HeadInsert(int n){
    SinglyList *p =new SinglyList;
    p->data = n;
    p->Next = Head->Next;
    Head->Next = p;
}
void Output(){
    for(SinglyList *p = Head->Next;;p = p->Next){
        if(p->Next==NULL){
            cout<<p->data<<" ";
            break;
        }else{
            cout<<p->data<<" ";
        }
    }
}

void I_Like_Insert_More_data(){
    cout<<"Please input the numbers of digits!"<<" ";
    int n;
    cin>>n;
    while(n--){
        int b;
        cout<<"please you input you favourite number!"<<" ";
        cin>>b;
        HeadInsert(b);
    }
}
void freePointer(){
    for(SinglyList *p = Head;;p = p->Next){
        if(p->Next==NULL){
            free(p);
            break;
        }else{
            free(p);
        }
    }
}
void Delete(){
    Head->Next = Head->Next->Next;
}

void Use(){
    Init();
    I_Like_Insert_More_data();
    Delete();
    Output();
    freePointer();
}
int main(){
    Use();
    return 0;
}