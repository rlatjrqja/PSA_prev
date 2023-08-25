#include <iostream>
#include <cstring>

using namespace std;

int C, K;
const int Max = 15;
string word[15];
int dp[15][1 << 15], over[15][15];

int restore(int last, int used)
{
	if (used == (1 << K) - 1) return 0;

	int& res = dp[last][used];
	if (res != -1) return res;

	res = 0;
	for (int i = 0; i < K; i++)                                                                    //i�� i��° ������ �ǹ��ϳ�?
	{
		if ((used & (1 << i)) == 0)
		{
			int cand = over[last][i] + restore(i, used + (1 << i));
			res = max(res, cand);
		}
	}
	return res;
}

string reconstruct(int last, int used)                                                                    //(K,0)���� ����
{
	if (used == (1 << K) - 1) return "";
	for (int next = 0; next < K; next++)
	{
		if (used & (1 << next)) continue;

		int ifUsed = restore(next, used + (1 << next)) + over[last][next];

		if (restore(last, used) == ifUsed)
		{
			cout << word[next].substr(over[last][next]) << endl;
			return (word[next].substr(over[last][next])	+ reconstruct(next, used + (1 << next)));
		}
	}
}

int overlap(string& s1, string& s2)
{
	for (int len = min(s1.size(), s2.size()); len > 0; len--)
	{
		if (s1.substr(s1.size() - len) == s2.substr(0, len))                     //�ں��� n����, �տ��� n���� ������
			return len;
	}
	return 0;
}

int main()
{
	cin >> C;
	while (C--)
	{
		cin >> K;
		for (int i = 0; i < K; i++)
		{
			cin >> word[i];
		}

		memset(dp, -1, sizeof(dp));
		memset(over, -1, sizeof(over));

		while (true)
		{
			bool removed = false;

			for (int i = 0; i < K && !removed; i++)
			{
				for (int j = 0; j < K; j++)
				{
					if (i != j && word[i].find(word[j]) != -1)                                     //word[i]�� �ٸ� ���� ������ �����ϰ� �ִ���
					{
						word[j] = word[K - 1];
						K--;
						removed = true;
					}
				}
			}
			if (!removed) break;															//�迭 ��ü�� �� ���� ���� �� �ܾ ������ Ż��
		}
		word[K] = "";

		for (int i = 0; i <= K; i++)
		{
			for (int j = 0; j <= K; j++)
			{
				over[i][j] = overlap(word[i], word[j]);                                        //i��°, j��° �ܾ�� n�� ���ڰ� ��ģ��
			}
		}
		cout << reconstruct(K, 0) << endl;
	}
}

//https://chosh95.tistory.com/33
//https://sangdo913.tistory.com/77