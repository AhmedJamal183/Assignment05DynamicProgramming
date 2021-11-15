#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main()
{
    string X = "ABAB", Y = "BABA";
    int m = X.length(), n = Y.length();
    cout << "The longest common substring is " << LongestCommonSubString(X, Y, m, n);
    return 0;
}

string LongestCommonSubString(string X, string Y, int m, int n)
{
    int maxLength = 0; 
    int endingIndex = m; 
    int lookup[m + 1][n + 1];

    memset(lookup, 0, sizeof(lookup));
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (X[i - 1] == Y[j - 1])
            {
                lookup[i][j] = lookup[i - 1][j - 1] + 1;
                if (lookup[i][j] > maxLength)
                {
                    maxLength = lookup[i][j];
                    endingIndex = i;
                }
            }
        }
    }
    return X.substr(endingIndex - maxLength, maxLength);
}