bool[,] areFriends = new bool[10,10];

//Console.Write("케이스 수 : ");
//int C = int.Parse(Console.ReadLine());

Console.Write("학생 수 : ");
int n = int.Parse(Console.ReadLine());
Console.Write(n * (n - 1) / 2 + " 이하의 친구 쌍의 수 : ");
int m = int.Parse(Console.ReadLine());
bool[] taken = new bool[n];

Console.WriteLine("0부터 " + (m - 1) + "사이의 번호를 갖는 친구 쌍 " + m + "개 입력");
string partnerS = Console.ReadLine();
partnerS = partnerS.Replace(" ","");
char[] partnerC = partnerS.ToCharArray();
int[] partnerI = Array.ConvertAll(partnerC,c=>(int)Char.GetNumericValue(c));

for (int i = 0; i < m;i++)
{
    for(int j= 0; j < m;j++)
    {
        areFriends[partnerI[2 * i], partnerI[2 * i + 1]] = true;
    }
}

/*
Console.Write(partnerC);

for (int i=0; i<10; i++)
{
    for(int j=0; j<10; j++)
    {
        areFriends[i,j] = true;
    }
}
*/

int countPairings(bool[] taken)
{
    /*
    //taken 짝이 지어졌는가 유무
    bool finished = true;

    for(int i = 0;i<n;++i)
    {//배열 전체 검사
        if (!taken[i])//짝이 없는가?
        {
            finished = false;
        }
    }
    if (finished)
    {
        return 1;
    }
    int ret = 0;//지어진 짝의 수

    for (int i = 0;i<n;++i)
    {
        for(int j = 0;j<n;++j)
        {
            if (!taken[i] && !taken[j] && areFriends[i,j])
            {//양쪽이 짝이 없고 친구인가?
                taken[i] = taken[j] = true;
                ret += countPairings(taken);//재귀를 통해 1씩 증가
                taken[i] = taken[j] = false;
            }
        }
    }

    return ret;
    */






    int firstFree = -1;
    for(int i = 0;i<n;++i)
    {
        if (!taken[i])
        {//짝이 지어지지 않은 첫번째 찾음
            firstFree = i;
            break;
        }
    }

    if(firstFree == -1)
    {
        return 1;//전부 짝이 지어짐(한 가지 케이스 종료)
    }

    int ret = 0;
    for (int pairWith = firstFree + 1; pairWith < n; ++pairWith)
    {
        if (!taken[pairWith] && areFriends[firstFree, pairWith])
        {
            taken[firstFree] = taken[pairWith] = true;
            ret += countPairings(taken);
            taken[firstFree] = taken[pairWith] = false;
        }
    }

    return ret;
}

Console.WriteLine(countPairings(taken));

/*
for (int i = 0; i < C;i++)
{
    Console.WriteLine(countPairings(taken));
}
*/