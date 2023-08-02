Console.Write("케이스 수 입력 : ");
int C = int.Parse(Console.ReadLine());
Console.WriteLine("\n\n");

void ex1()
{
    bool[,] areFriends = new bool[10, 10];

    Console.Write("학생 수 : ");
    int n = int.Parse(Console.ReadLine());
    Console.Write(n * (n - 1) / 2 + " 이하의 친구 쌍의 수 : ");
    int m = int.Parse(Console.ReadLine());
    bool[] taken = new bool[n];

    Console.WriteLine("0부터 " + (n - 1) + "사이의 번호를 갖는 친구 쌍 " + m + "개 입력");
    string partnerS = Console.ReadLine();
    partnerS = partnerS.Replace(" ", "");
    char[] partnerC = partnerS.ToCharArray();
    int[] partnerI = Array.ConvertAll(partnerC, c => (int)Char.GetNumericValue(c));

    for (int i = 0; i < m; i++)
    {
        areFriends[partnerI[2 * i], partnerI[2 * i + 1]] = true;
    }

    int countPairings(bool[] taken)
    {
        int firstFree = -1;
        for (int i = 0; i < n; ++i)
        {
            if (!taken[i])
            {//짝이 지어지지 않은 첫번째 찾음
                firstFree = i;
                break;
            }
        }

        if (firstFree == -1)
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

    Console.WriteLine("가능한 짝의 조합 수 : "+countPairings(taken));
    Console.WriteLine("=====================");
    Console.WriteLine("\n");
}



for (int i = 0; i < C;i++)
{
    ex1();
}