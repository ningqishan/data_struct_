#include<iostream>
using namespace std;
struct SinglyListCycle{
    int data;
    SinglyListCycle *Next;
};
SinglyListCycle *Head = new SinglyListCycle;
void Init(){
    Head->Next = Head;
}
void Insert(int n){
    SinglyListCycle *NewNode = new SinglyListCycle;
    NewNode->Next = Head->Next;
    NewNode->data = n;
    Head->Next = NewNode;
}
void Output(){
    int cnt = 0;
    for(SinglyListCycle *p = Head->Next;;p = p->Next){
        if(p->Next == Head){
            p->Next = Head->Next; 
        }
        cout<<p->data<<" ";
        cnt++;
        if(cnt%10==0)
            cout<<endl;
        if(cnt==100)
            break;
    }
}

void Insert_OK(){
    for(int i  =1;i<=10;i++)
        Insert(i);
}

void Use(){
    Init();
    Insert_OK();
    Output();
}
int main(){
    Use();
    return 0;
}