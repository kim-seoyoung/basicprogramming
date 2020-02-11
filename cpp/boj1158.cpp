#include <iostream>
using namespace std;

struct node{
    int data;
    node* link;
};

void delete_node(node *head);
void add_node(node *head, int data){
    node *new_node = new node;
    new_node->data = data;
    new_node->link = head->link;
    head->link = new_node;
}

node* find_Kth(int K, node *curr){
    int tmp;
    for(int k(0);k < K-2; k++){
        curr = curr->link;
    }
    return curr;
}

int main(){
    freopen("input.txt", "r", stdin);
    int N, K;
    node *n1 = new node;
    n1->link=nullptr;
    cin >> N >> K;

    node *curr =n1;
    n1->data = 1;
    for(int n(2); n < N+1; n++){
        add_node(curr, n); 
        curr = curr->link;
    }
    curr->data=N;
    curr->link=n1;

    curr=n1;
    if(K == 1){
        cout << "<";
        while(curr->link !=n1){
            cout << curr->data << ", ";
            curr = curr->link;
        }
        cout << curr->data << ">";
    }
    else{
        cout << "<";
        while(curr != curr->link){
            curr = find_Kth(K, curr);
            cout << curr->link->data << ", ";
            delete_node(curr);
            curr = curr->link;
        }
        cout << curr->data << ">";
    }

    fclose(stdin);

    return 0;

}

void delete_node(node *head){
    node* target = head->link;
    head->link=target->link;
    delete target;
}