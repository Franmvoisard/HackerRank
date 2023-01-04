#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'caesarCipher' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. INTEGER k
 */
char RotateLetter(int charAsIndex, int rotations, int limit);
const int totalAlphabetLetters = 26;

//Lowercase Alphabet 
const int lowercaseAlphabetStartIndex = 97;
const int lowercaseAlphabetEndIndex = lowercaseAlphabetStartIndex + totalAlphabetLetters;

//Uppercase Alphabet
const int uppercaseAlphabetStartIndex = 65;
const int uppercaseAlphabetEndIndex = uppercaseAlphabetStartIndex + totalAlphabetLetters;

string caesarCipher(string encodedString, int rotations) {
    string result;

    for (int i = 0; i < encodedString.size(); i++) {
        int charAsIndex = (int)(encodedString[i]);
        
        if(charAsIndex >= uppercaseAlphabetStartIndex && charAsIndex < uppercaseAlphabetEndIndex){
            result += RotateLetter(charAsIndex, rotations, uppercaseAlphabetEndIndex);
        }
        else if(charAsIndex >= lowercaseAlphabetStartIndex && charAsIndex < lowercaseAlphabetEndIndex){
            result += RotateLetter(charAsIndex, rotations, lowercaseAlphabetEndIndex);
        }
        else {
            result += encodedString[i];
        }
    }
    return result;
}

char RotateLetter(int charIndex, int rotations, int limit){
    int rotatedIndex = charIndex + rotations % totalAlphabetLetters;
        if(rotatedIndex >= limit){
            rotatedIndex = rotatedIndex - totalAlphabetLetters;
        }
    return (char)rotatedIndex;
}
 
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string s;
    getline(cin, s);

    string k_temp;
    getline(cin, k_temp);

    int k = stoi(ltrim(rtrim(k_temp)));

    string result = caesarCipher(s, k);

    fout << result << "\n";

    fout.close();

    return 0;
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
