#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'highestValuePalindrome' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. INTEGER n
 *  3. INTEGER k
 */

// from https://www.hackerrank.com/challenges/richie-rich/forum by mr_fng
string highestValuePalindrome(string s, int n, int k)
{
    int lives = k;
    std::vector<bool> mod(n,false);  
        
    for (int i = 0; i < n/2; ++i) 
    {
        if (s[i] != s[n-i-1])
        {
            mod[i] = true;
            lives--;
        }
        
        if (s[i] < s[n-i-1])
            s[i] = s[n-i-1];
        else if (s[i] > s[n-i-1])
            s[n-i-1] = s[i];
        
        if (lives < 0)
            return "-1";       
    }

    int j = 0;

    while ((lives > 0) && (j < n/2))
    {
        if (s[j] != '9')
        {
            if (mod[j])
                lives++;
        
            if (lives > 1)
            {
                s[j] = '9';
                s[n-j-1] = '9';
                lives -= 2;
            }
        }       
        j++;        
    }

    if (n % 2 == 1)
    {
        if (lives > 0)
            s[n/2]='9';
    } 

    return s;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int k = stoi(first_multiple_input[1]);

    string s;
    getline(cin, s);

    string result = highestValuePalindrome(s, n, k);

    fout << result << "\n";

    fout.close();

    return 0;
}


string ltrim(const string &str)
{
    string s(str);
    s.erase(
        s.begin(), find_if(s.begin(), s.end(), [](unsigned char ch) { return !isspace(ch); })
    );
    return s;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
