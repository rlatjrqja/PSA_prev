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
Console.Write("\n");

for (int i=0;i< textGroup.Length;i++)
{
    Console.WriteLine(match(textGroup[i],wild,0));
}

string match(string text,string wild, int index)
{
    string ret = "";
    char w;

    for (int i=index;i<wild.Length;i++)
    {
        w = wild[index];

        if (w == '?')
        {
            ret = ret + text[i] + match(text, wild, ++i);
        }
        else if (w == '*')
        {
            while (wild[index + 1] != text[i])
            {
                ret += text[i];
                i++;
                if (i == text.Length)
                {
                    break;
                }
            }
            ret += text[i];
            index++;
        }
        else if (index < text.Length && w == text[i])
        {
            ret += text[i];
        }
        else
        {
            ret = "";
            break;
        }

        index++;
    }

    return ret;
}