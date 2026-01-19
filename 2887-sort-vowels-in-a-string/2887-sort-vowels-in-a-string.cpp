class Solution {
public:
    string sortVowels(string s) {
        vector<int> a;
        for(auto &ch : s) {
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
               ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
                a.push_back(ch - 'A');
            }
        }
        sort(a.begin(), a.end());
        int i = 0;
        for(auto &ch : s) {
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
               ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
                ch = (char) (a[i] + 'A');
                i++;
            }
        }
        return s;
    }
};