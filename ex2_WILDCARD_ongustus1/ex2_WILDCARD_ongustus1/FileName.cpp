#include <iostream>
#include <string>
#include<cstring>
#include <vector>
#include <algorithm>
using namespace std;
string  wild, file;

int cache[101][101];

bool matchMemoized(int w, int f) {
    //ret�� cache[w][f]�� �������̶� ret�� ���� �ٲٸ� cache[w][f]�� ���� ����
    int& ret = cache[w][f];

    if (ret != -1)
        //�̹� ret�� ���ŵ� ���
        return ret;

    while (w < wild.length() && f < file.length() && (wild[w] == '?' || wild[w] == file[f])) {
        //���̻� ������ �� ���� ������ w,f �ø���
        w++;
        f++;
    }
    //while�� ������ �� while���� �������� Ȯ��
    if (w == wild.size() && f == file.size()) {
        //���ڿ��� ������ ���ϵ� ���� ���
        return ret = 1;
    }
    if (wild[w] == '*') {
        //*�� ������ ���� ��� : *�� �� ���ڸ� �����ؾ� ���� ��� ȣ���ϸ鼭 Ȯ��
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