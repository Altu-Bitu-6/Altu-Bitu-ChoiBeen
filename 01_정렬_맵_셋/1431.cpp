#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int sum(string str) {
    int result = 0;
    for(int i = 0; i< str.length(); i++) {
        if(isdigit(str[i])) { //숫자인 경우만 더하기
            result += int(str[i]) - '0'; //아스키코드 감안해서 (- '0')
        }
    }
    return result;
}

bool cmp(const string str1, const string str2) {
    if(str1.length() != str2.length()) { //길이가 다르면 짧은 것이 먼저
        return str1.length() < str2.length();
    }

    int sum1 = sum(str1); //모든 자리수의 합 구하기
    int sum2 = sum(str2);

    if(sum1 != sum2) { //모든 자리수의 합 비교해서 작은 것 먼저
        return sum1 < sum2;
    }
    return str1 < str2; //사전순으로 비교
}

int main() {
    int n;

    //입력
    cin >> n;
    vector<string> arr(n);
    
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    //연산
    sort(arr.begin(), arr.end(), cmp);

    //출력
    for(int i = 0; i < n; i++) {
        cout << arr[i] << '\n';
    }

    return 0;
}