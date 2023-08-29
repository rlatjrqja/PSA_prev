#include<iostream>
#include<cstring>

using namespace std;

const int MAXN = 20;
//candidate[����][��][�̹� ���� ���� ����] = ������ �ִ� ���� ����
int candidate[10][46][1024];

//set�� �ִ� ���ڵ� ����
int getSize(int set)
{
	int ret = 0;
	for (int i = 1; i < 10; i++)
		if (set & (1 << i)) ret++;
	return ret;
}

//set�� �ִ� ���ڵ��� ��
int getSum(int set)
{
	int ret = 0;
	for (int i = 1; i < 10; i++)
		if (set & (1 << i)) ret+=i;
	return ret;
}

void generateCadidates()
{
	memset(candidate, 0, sizeof(candidate));

	for (int set = 0; set < 1024; set += 2)
	{
		int l = getSize(set);
		int s = getSum(set);
		int subset = set;

		while (true)
		{
			candidate[l][s][subset] |= (set & ~subset);
			if (subset == 0) break;
			subset = (subset - 1) & set;
		}
	}
}

//color: �� ĭ�� �� (��,��Ʈ 0,	�� 1)
//value: �� ��ĭ�� �� ����
//hint: �� ĭ�� �ش��ϴ� ��Ʈ ��ȣ
int n, color[MAXN][MAXN], value[MAXN][MAXN], hint[MAXN][MAXN][2];

//sum: ��Ʈĭ�� ���� ����
//length: ��Ʈĭ�� �ش��ϴ� ��ĭ ��
//known: ��Ʈĭ�� �ش��ϴ� ��ĭ�� ���� ���ڵ��� ����
int q, sum[MAXN * MAXN], length[MAXN * MAXN], known[MAXN * MAXN];

//(y,x)�� val�� �ִ´�
void put(int y, int x, int val)
{
	for (int h = 0; h < 2; h++)
		known[hint[y][x][h]] += (1 << val);
	value[y][x] = val;
}

void remove(int y, int x, int val)
{
	for (int h = 0; h < 2; h++)
		known[hint[y][x][h]] -= (1 << val);
	value[y][x] = 0;
}

//��Ʈ ��ȣ�� �־��� �� �ĺ��� ������ ��ȯ
int getCandHint(int hint)
{
	return candidate[length[hint]][sum[hint]][known[hint]];
}

//��ǥ�� �־��� �� �ش� ĭ�� �� �� �ִ� �ĺ��� ������ ��ȯ
int getCandCoord(int x, int y)
{
	return getCandHint(hint[y][x][0]) & getCandHint(hint[y][x][1]);
}

//value�� ���� ���� ���
void printSolution()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << value[i][j] << " ";
		cout << endl;
	}	
}

//���� ã���� true, �ƴϸ� false
bool search()
{
	int y = 1, x = -1, minCands = 1023;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (color[i][j] == 1 && value[i][j] == 0)
			{
				int cands = getCandCoord(i, j);
				if (getSize(minCands) > getSize(cands))
				{
					minCands = cands;
					y = i;
					x = j;
				}
			}
		}
	}

	//��ĭ�� �ִµ� ���� �ִ� ���ڰ� ������ return false
	if (minCands == 0) return false;

	//���ĭ�� ä�������� ����� return true
	if (y == -1)
	{
		printSolution();
		return true;
	}

	//��ĭ�� ���� ����� �κ������� ��� �ϳ��� ����
	for (int val = 1; val < 10; val++)
	{
		if (minCands & (1 << val))
		{
			put(y, x, val);
			if (search()) return true;
			remove(y, x, val);
		}
	}
	return false;
}

int main()
{
	int testcase;
	cin >> testcase;
	while (testcase--)
	{
		memset(hint, 0, sizeof(hint));
		memset(hint, 0, sizeof(value));
		memset(hint, 0, sizeof(color));
		memset(hint, 0, sizeof(sum));
		memset(hint, 0, sizeof(length));
		memset(hint, 0, sizeof(known));
		memset(hint, 0, sizeof(hint));

		cin >> n;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> color[i][j];
			}
		}

		cin >> q;
		for (int i = 0; i < q; i++)
		{
			int y, x, dir, s;
			cin >> y >> x >> dir >> s;
			hint[y - 1][x - 1][dir] = i;
			sum[i] = s;
			int len = 0;

			//��Ʈ�� ����ϴ� ��ĭ���� ���μ��� ������ 
			//�� ��Ʈ�� length�� ��ĭ�� ���� hint�� ����
			if (dir == 0)
			{
				int leny = y - 1, lenx = x;
				while (color[leny][lenx])
				{
					hint[leny][lenx][0] = i;
					lenx++; len++;
				}
			}
			else
			{
				int leny = y , lenx = x - 1;
				while (color[leny][lenx])
				{
					hint[leny][lenx][1] = i;
					leny++; len++;
				}
			}
			length[i] = len;
		}
		generateCadidates();
		search();
	}
}