Console.Write("와일드카드 패턴 : ");
string wild = Console.ReadLine();

Console.Write("대조될 단어 수 : ");
int num = Console.Read();
Console.Write("\n");

string[] text = new string[num];
for (int i = 0; i < num; i++)
{
    text[i] = Console.ReadLine();
}

string a = Console.ReadLine();
Console.WriteLine(a);

char match()
{
    return 'a';
}