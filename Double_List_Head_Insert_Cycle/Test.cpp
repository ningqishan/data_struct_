#include<iostream>
using namespace std;
struct double_List{
    int data;
    double_List *Left;
    double_List *Right;
};//
double_List *Head  = new double_List;
void Init(){
    Head->Right = Head;
    Head->Left = Head;
    Head->data = 0;
}
void Insert(int n){
    double_List *NewNode = new double_List;
    if(Head->Right==Head){
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
    int ans = 0;
    int cnt = 0;
    while(1){
        if(ans%10==0)
            cout<<endl;
        if(ans==40)
            break;
        cout<<Tail->data<<" ";
        ans++;
        Tail = Tail->Right;
        if(Tail->Right==NULL){
            T = Tail;
            cout<<Tail->data<<" ";
            break;
        }
    }
    cout<<endl<<endl;
    for(double_List *p = Head->Left;;p = p->Left){
        if(p==Head)
            p = p->Left;
        cout<<p->data<<" ";
        cnt++;
        if(cnt==40)
            break;
        if(cnt%10==0)
            cout<<endl;
    }
}
void Cycle(){
    double_List *p = Head;
    for(p;;p = p->Right){
        if(p->Right==NULL){
            p->Right = Head->Right;
            Head->Left = p;
            break;
        }
    }
}

void Use(){
    Init();
    Insert_OK();
    Cycle();
    Output();
}

int main(){
    Use();
    return 0;
}