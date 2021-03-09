#include <iostream>
#include <string>

using namespace std;

int maxPower(string s) {
    if (s.length() == 0 || s.length() == 1)
        return s.length();

    int count(1);
    int maxCount(1);
    char c(s[0]);

    for (int idx=1; idx<s.length(); idx++)
    {
        if (c == s[idx])
        {
            count++;
        }
        else
        {
            c = s[idx];
            count = 1;
        }
        maxCount = max(maxCount, count);
    }
    return maxCount;
}

int main()
{
    string s("aaabbbccc");
    cout << (maxPower(s)) << endl;

    return 0;
}