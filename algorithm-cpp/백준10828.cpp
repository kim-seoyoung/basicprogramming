#include <iostream>
#include <string.h>

using namespace std;

int stack[10002], top= -1;

void push(int x = 0){
    stack[++top] = x;
    return;
}

void pop(){
    if (top == -1){
        cout << -1 << endl;
    }
    else{
        cout << stack[top] << endl;
        --top;
    }
    
    return;
}

void size(){
    cout << top + 1 << endl;
    return;
}

void empty(){
    if (top == -1) cout << 1 << endl;
    else cout << 0 << endl;
    // cout << endl;
    return;
}

void Top(){
    if(top == -1) cout << -1 << endl;
    else {
        cout << stack[top] << endl;
    }

    return;
}

int main(){
    
    int N;
    
    cin >> N;

    for(int i = 0; i < N; i++){
        char str[10];
        cin >> str;
        if (!strcmp(str,"push")){
            int x;
            cin >> x;
            push(x);
        }
        if (!strcmp(str, "pop")){
            pop();
        }
        if (!strcmp(str, "size")){
            size();
        }
        if (!strcmp(str, "empty")){
            empty();
        }
        if (!strcmp(str, "top")){
            Top();
        }

    }
    return 0;
}