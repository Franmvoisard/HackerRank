#include <iostream>
#include <string>
using namespace std;

void SwapStringFirstLetters(string& a, string& b);

int main() {
	// Complete the program
    string a, b;
    cin >> a >> b;
    
    cout << a.length() << " " <<  b.length() << endl;
    cout << a+b << endl;
    
    SwapStringFirstLetters(a, b);
    cout << a  << " " << b <<endl;
  
    return 0;
}

void SwapStringFirstLetters(string& first, string& second)
{
    char aux = second[0];
    second[0] = first[0];
    first[0] = aux;
}
