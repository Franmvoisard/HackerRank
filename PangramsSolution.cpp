#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'pangrams' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string pangrams(string s) {
    map<char,int> dictionaryKeys;
    for (int i=0; i< s.size(); i++) {
        char currentChar = tolower(s[i]);
        if(currentChar == ' ') continue;
        dictionaryKeys[currentChar] = 1;
    }
    return dictionaryKeys.size() == 26 ? "pangram" : "not pangram";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = pangrams(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
