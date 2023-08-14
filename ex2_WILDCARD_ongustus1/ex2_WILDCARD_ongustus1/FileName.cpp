#include <iostream>
#include <string>
#include<cstring>
#include <vector>
#include <algorithm>
using namespace std;
string  wild, file;

int cache[101][101];

bool matchMemoized(int w, int f) {
    //ret가 cache[w][f]의 참조형이라 ret의 값을 바꾸면 cache[w][f]의 값도 변함
    int& ret = cache[w][f];

    if (ret != -1)
        //이미 ret가 갱신된 경우
        return ret;

    while (w < wild.length() && f < file.length() && (wild[w] == '?' || wild[w] == file[f])) {
        //더이상 대응할 수 없을 때까지 w,f 늘리기
        w++;
        f++;
    }
    //while문 끝나면 왜 while문이 끝났는지 확인
    if (w == wild.size() && f == file.size()) {
        //문자열도 끝나고 패턴도 끝난 경우
        return ret = 1;
    }
    if (wild[w] == '*') {
        //*를 만나서 끝난 경우 : *에 몇 글자를 대응해야 할지 재귀 호출하면서 확인
        for (int skip = 0; skip + f <= file.length(); skip++) {
            if (matchMemoized(w + 1, f + skip)) {
                return ret = 1;
            }
        }
    }
    return ret = 0;
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t, n;
    cin >> t;
    while (t--) {
        vector<string> vt;
        cin >> wild;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> file;

            memset(cache, -1, sizeof(cache));
            if (matchMemoized(0, 0) == 1) {
                vt.push_back(file);
            }

        }
        sort(vt.begin(), vt.end());
        for (int i = 0; i < vt.size(); i++) {
            cout << vt[i] << '\n';
        }
    }




    return 0;
}