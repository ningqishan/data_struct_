#include<iostream>
using namespace std;
struct SinglyList{
    int data;
    SinglyList *Next;
};
SinglyList *Head =new  SinglyList;
SinglyList *Tail;
void Init(){
    Head->Next = NULL;
}
void Insert(int n){
    SinglyList *NewNode = new  SinglyList;
    for(SinglyList *p = Head;;p = p->Next){
        if(p->Next==NULL){
            p->Next = NewNode;
            p->Next->data = n;
            p->Next->Next = NULL;
            break;
        }
    }
}
void OutPut(){
    for(SinglyList*p = Head->Next;;p = p->Next){
        if(p->Next==NULL){
            cout<<p->data;
            break;
        }else{
            cout<<p->data<<" ";
        }
    }
}
void ok_Insert(){
    for(int i  =1;i<=10;i++)
        Insert(i);
}
void Delete(){
    Head->Next = Head->Next->Next;
}
void use(){
    Init();
    ok_Insert();
    Delete();
    OutPut();
}
int main(){
    use();
    return 0;
}