using System;

string[] pi = { "11111222" };
//string[] test = { "12341234", "11111222", "12122222", "22222222", "12673939" };
int used = 0;

for (int i = 0; i < pi.Length; i++)
{
    int ret = 0;
    //bool[] used = new bool[pi[i].Length];

    for (int j = 0; j < pi[i].Length - 2; j++)
    {
        //diff1(pi[i][j], pi[i][j+1]);

        //ret += diff0(pi[i],j,1);
        //j = used;


    }

    Console.WriteLine(ret);
}

int diff0(string pii,int j,int len)
{
    if (pii[j] == pii[j+1] && len<5)
    {
        len++;

        if (diff0(pii, j + 1, len + 1) == 1)
        {
            return 1;
        }
    }
    else if(len>=3&&len<=5)//같은 수가 이어지지 않거나 5자리를 넘었을 때
    {
        return 1;
    }

    return 0;
}

int diff1(char a,char b)
{
    if(a==b) return 1;

    return 0;
}

int diff2(char a,char b)
{
    if(a+1 == b || a-1==b) return 2;

    return 0;
}

int diff4(char a, char b)
{
    if (a == b) return 4;

    return 0;
}

int diff5(char a, char b,int margin)
{
    if(a+margin == b || a-margin==b) return 5;

    return 0;
}