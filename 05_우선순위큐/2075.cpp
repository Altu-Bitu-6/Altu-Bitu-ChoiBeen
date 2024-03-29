#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //입력
    int n, x;
    cin >> n;

    //연산&출력
    priority_queue<int, vector<int>, greater<int>> max_heap; //크기가 n보다 커지면 작은 숫자부터 pop하기 위해서 내림차순 정렬
    for(int i = 0; i < n * n; i++) {
        cin >> x;
        max_heap.push(x);
        if(max_heap.size() > n) { // 항상 최대 힙의 크기가 n
            max_heap.pop();
        }
    }
    cout << max_heap.top();

    return 0;
}