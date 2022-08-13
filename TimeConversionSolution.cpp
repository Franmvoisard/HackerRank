#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s) {
    const string amToken = "AM";
    string result = s.substr(0,8);
    int hour = stoi(s.substr(0,2));
    string hourTime = s.substr(8,2);
    string hourAsString = "";

    if(hourTime == amToken){
        if (hour == 12) {
            hour = 0;
        }
    }
    else {
        if (hour < 12) {
            hour += 12;    
        }
    }
    
    std::stringstream ss;
    ss << std::setw(8) << std::setfill('0') << result.replace(0,2,to_string(hour));
    return ss.str();
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
