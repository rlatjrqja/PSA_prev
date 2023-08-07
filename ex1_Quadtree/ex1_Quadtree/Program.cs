using System;

class Program
{
    static int currentIndex = 0; // 현재 인덱스

    static string Reverse(ref string input)
    {
        char head = input[currentIndex];
        currentIndex++;

        if (head == 'b' || head == 'w')
        {
            return new string(head, 1);
        }

        string upperLeft = Reverse(ref input);
        string upperRight = Reverse(ref input);
        string lowerLeft = Reverse(ref input);
        string lowerRight = Reverse(ref input);

        return "x" + lowerLeft + upperRight + lowerRight;
    }

    static void Main(string[] args)
    {
        Console.WriteLine("문자열을 입력하세요:");
        string input = Console.ReadLine();

        string reversed = Reverse(ref input);
        Console.WriteLine("역순 변환 결과: " + reversed);
    }
}