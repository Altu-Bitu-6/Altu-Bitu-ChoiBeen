#include <iostream>

using namespace std;

void perform(string order, int x, int& s) {
    if(order == "add") {
        s |= (1 << x);
    }
    else if(order == "remove") {
        s &= ~(1 << x);
    }
    else if(order == "toggle") {
        s ^= (1 << x);
    }
}

int check(int x, int& s) {
    if(s & (1 << x)) {
        return 1;
    }
    else {
        return 0;
    }
}


int main() {
    //입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //입력
    int m;
    cin >> m;

    string order;
    int x = 0;
    int s = 0;

    //연산&출력
    while(m--) {
        cin >> order;
        if(order == "all") {
            s = (1 << 21) - 1;
        } else if(order == "empty") {
            s = 0;
        }
        else {
            cin >> x;
            if(order == "check") {
                cout << check(x, s) << '\n';
            }
            else {
                perform(order, x, s);
            }
        }
    }
    return 0;
}