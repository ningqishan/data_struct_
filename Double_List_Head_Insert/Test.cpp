#include<iostream>
using namespace std;
struct double_List{
    int data;
    double_List *Left;
    double_List *Right;
};
double_List *Head  = new double_List;
void Init(){
    Head->Right = NULL;
    Head->Left = NULL;
    Head->data = 0;
}
void Insert(int n){
    double_List *NewNode = new double_List;
    if(Head->Right==NULL){
        Head->Right = NewNode;
        NewNode->Right = NULL;
        NewNode->data = n;
        NewNode->Left = Head;
    }else{
        NewNode->Right = Head->Right;
        Head->Right->Left = NewNode;
        NewNode->Left = Head;
        Head->Right = NewNode;
        NewNode->data = n; 
    }
}
void Insert_OK(){
    for(int i = 1;i<=10;i++)
        Insert(i);
}
void Output(){
    double_List *Tail  =Head->Right;
    double_List *T;
    while(1){
        cout<<Tail->data<<" ";
        Tail = Tail->Right;
        if(Tail->Right==NULL){
            T = Tail;
            cout<<Tail->data<<" ";
            break;
        }
    }
    cout<<endl<<endl;
    while(1){
        if(T->Left ==Head){
            cout<<T->data;
            break;
        }
        cout<<T->data<<" ";
        T = T->Left;
    }
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