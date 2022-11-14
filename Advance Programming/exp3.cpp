#include<bits/stdc++.h> 

using namespace std;

int main()
{
    cout << "Enter the number of test cases: ";
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cout << "\nEnter the String: ";
        cin >> str;
        int count = 0, a = 0;
        int len = str.length();
        for (int i = 1; i < len; i++)
        {
            if ((str[i] == 65 && str[a] == 66) || (str[i] == 66 && str[a] == 65))
                a = i;
            else
                count++;
        }
        cout << "Number of characters to be deleted: " << count << endl;
    }
    return 0;
}