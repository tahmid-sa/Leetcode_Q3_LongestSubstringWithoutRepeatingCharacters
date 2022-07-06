#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int lengthOfLongestSubstring(string s) {
    int length = 0, currLength = 0;
    unordered_map<char, int> substring;

    if (s == string("")) {
        return 0;
    }

    for (int i = 0; i < s.size(); i++) {
        if (substring.find(s[i]) == substring.end()) {
            substring.insert(substring.end(), make_pair(s[i], i));
            currLength++;
        }
        else if (substring.find(s[i]) != substring.end()) {
            int tmp = i;

            //cout << i << endl;
            i = substring.find(s[tmp])->second;
            //cout << i << endl;
            substring.clear();
            

            //substring.erase(substring.find(s[tmp]));
            //substring.insert(substring.end(), make_pair(s[tmp], tmp));

            //substring.find(s[tmp])->second = tmp;

            if (length < currLength) {
                length = currLength;
            }
            
            //currLength = substring.size();
            currLength = 0;
        }

        if (length < currLength && (i + 1 == s.size())) {
            length = currLength;

        }
    }

    return length;
}

int main()
{
    string s = "dvdf";

    cout << lengthOfLongestSubstring(s);
}