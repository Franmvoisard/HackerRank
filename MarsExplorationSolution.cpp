#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'marsExploration' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

int marsExploration(string s) {
    int changedLetter = 0;
    for(int i= 0; i < s.size(); i+=3){
        if(s[i] != 'S') changedLetter++;
        if(s[i+1] != 'O') changedLetter++;        
        if(s[i+2] != 'S') changedLetter++;
    }
    return changedLetter;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    int result = marsExploration(s);

    fout << result << "\n";

    fout.close();

    return 0;
}