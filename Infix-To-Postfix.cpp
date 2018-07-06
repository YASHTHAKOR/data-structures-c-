#include <iostream>
#include <stack>
#include <vector>

using namespace std;

bool isOperant(char x) {
    if(x>='A'&&x<='Z'){
        return true;
    }
    return false;
}


bool isHighPrio (char a,char b) {
    if((a == '+' || a == '-') && (b=='/' || b=='*')) {
        return true;
    } else {
        return false;
    }
}

void inFixToPostFix(string expr){
    stack<char> S;

    int a = expr.length();
    vector<char> postFix(a);
    int index=0;
    for(int i=0;expr[i]!='\0';i++) {
        if(isOperant(expr[i])) {
            postFix[index++] = (expr[i]);
        } else if(!S.empty()){
            if(isHighPrio(S.top(),expr[i])) {
                S.push(expr[i]);
            } else {
                while(!S.empty()) {
                   postFix[index++]=(S.top()); 
                   S.pop();
                }
                S.push(expr[i]);
            }
        } else {
            S.push(expr[i]);
        }
    }
     while(!S.empty()) {
                   postFix[index++]=(S.top()); 
                   S.pop();
                }
    puts(&postFix[0]);
}

int main() {
	inFixToPostFix("A+B*C-D*E");
}
