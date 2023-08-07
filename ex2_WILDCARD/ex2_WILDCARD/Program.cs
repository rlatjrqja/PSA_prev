Console.Write("와일드카드 패턴 : ");
string wild = Console.ReadLine();

Console.Write("대조될 단어 수 : ");
int num = int.Parse(Console.ReadLine());
Console.Write("\n");

string[] textGroup = new string[num];
for (int i = 0; i < num; i++)
{
    textGroup[i] = Console.ReadLine();
}

//int index = 0;
for(int i=0;i< textGroup.Length;i++)
{
    match(textGroup[i],0);
}

string match(string text,int index)
{
    string ret = "";
    char c = text[index];

    for(int i=0;i<wild.Length;i++)
    {
        if (c == '*' || c == '?')
        {
            match(text, ++index);
        }
        else if (c == wild[i])
        {
            index++;
            ret += c;
        }
        else break;
    }
    Console.WriteLine(c);

    return ret;
}