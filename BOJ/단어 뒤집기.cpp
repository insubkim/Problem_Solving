#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;
    cin.ignore();
    while (T--)
    {
        string s;
        getline(cin, s);
        
        //get start
        //get end
        //reverse
        //set start
        //loop until eof


        
        string::iterator start = s.begin();
        string::iterator end = s.begin();
        do {
            while (end != s.end() && *end != ' ')
                end++;
            // end is ' ' or eof  

            //reverse
            reverse(start, end);


            // set start to next vocab
            // move end to eof or next char
            while (end != s.end() && *end == ' ')
                end++;
            start = end;
        }
        while (start != s.end());

        cout << s << endl;
    }

}