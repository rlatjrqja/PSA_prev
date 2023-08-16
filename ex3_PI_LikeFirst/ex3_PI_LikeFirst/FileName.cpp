#include <iostream>
#include <cstring>
#include <string>

using namespace std;

const int INF = 987654321;
int memo[101], digit;
string PI;

inline int min(const int a, const int b) { return a < b ? a : b; }

int solution(int start)
{
	if (start == digit) return 0;

	int& ret = memo[start];
	if (ret != -1)
	{
		return ret;
	}
	ret = INF;

	if (start + 2 < digit)
	{
		int a = PI[start] - '0';
		int b = PI[start + 1] - '0';
		int c = PI[start + 2] - '0';

		if (a == b == c)
		{
			ret = min(ret, solution(start + 3) + 1);
		}
		else if ((b == a + 1 && c == b + 1)
			|| (b == a - 1 && c == b - 1))
		{
			ret = min(ret, solution(start + 3) + 2);
		}
		else if (a == c && a != b)
		{
			ret = min(ret, solution(start + 3) + 4);
		}
		else if (a - b == b - c)
		{
			ret = min(ret, solution(start + 3) + 5);
		}
		else
		{
			ret = min(ret, solution(start + 3) + 10);
		}
	}

	if (start + 3 < digit)
	{
		int a = PI[start] - '0';
		int b = PI[start + 1] - '0';
		int c = PI[start + 2] - '0';
		int d = PI[start + 3] - '0';

		if (a == b == c)
		{
			ret = min(ret, solution(start + 4) + 1);
		}
		else if ((b == a + 1 && c == b + 1 && d == c + 1)
			|| (b == a - 1 && c == b - 1 && d == c - 1))
		{
			ret = min(ret, solution(start + 4) + 2);
		}
		else if (a == c && b == d)
		{
			ret = min(ret, solution(start + 4) + 4);
		}
		else if (a - b == b - c && b - c == c - d)
		{
			ret = min(ret, solution(start + 4) + 5);
		}
		else
		{
			ret = min(ret, solution(start + 4) + 10);
		}
	}

	if (start + 4 < digit)
	{
		int a = PI[start] - '0';
		int b = PI[start + 1] - '0';
		int c = PI[start + 2] - '0';
		int d = PI[start + 3] - '0';
		int e = PI[start + 4] - '0';

		if (a == b && b == c && c == d && d == e)
		{
			ret = min(ret, solution(start + 5) + 1);
		}
		else if ((b == a + 1 && c == b + 1 && d == c + 1 && e == d + 1) ||
			(b == a - 1 && c == b - 1 && d == c - 1 && e == d - 1))
		{
			ret = min(ret, solution(start + 5) + 2);
		}
		else if (a == c && a == e && b == d)
		{
			ret = min(ret, solution(start + 5) + 4);
		}
		else if (a - b == b - c && b - c == c - d && c - d == d - e)
		{
			ret = min(ret, solution(start + 5) + 5);
		}
		else
		{
			ret = min(ret, solution(start + 5) + 10);
		}
	}

	return ret;
}

int main()
{
	int tc;
	cin >> tc;
	while (memset(memo,-1,sizeof(memo)))
	{
		cin >> PI;
		digit = PI.size();
		cout << solution(0) << endl;
	}
}