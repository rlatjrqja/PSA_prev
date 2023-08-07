#include <iostream>
#include <string>

using namespace std;

string reverse(string::iterator& it)
{
    char head = *it;
    ++it;

    if (head == 'b' || head == 'w')
    {
        return string(1, head);  // 세미콜론 추가
    }

    string upperLeft = reverse(it);
    string upperRight = reverse(it);
    string lowerLeft = reverse(it);
    string lowerRight = reverse(it);

    return string("x") + lowerLeft + lowerRight+upperLeft + upperRight;
}

int main()
{
    string input = "xbwwb";
    string::iterator it = input.begin();
    string result = reverse(it);
    cout << result << endl;

    return 0;
}