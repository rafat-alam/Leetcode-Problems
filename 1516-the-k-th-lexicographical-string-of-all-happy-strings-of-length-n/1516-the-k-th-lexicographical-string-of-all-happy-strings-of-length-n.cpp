class Solution {
public:
    string getHappyString(int n, int k) {
        vector<string> ss;

        function<void (int, string)> f = [&](int i, string s) -> void {
            if(i >= n) {
                ss.push_back(s);
                return;
            }
            if(i == 0) {
                f(1, "a");
                f(1, "b");
                f(1, "c");
            } else {
                if(s.back() != 'a') f(i + 1, s + 'a');
                if(s.back() != 'b') f(i + 1, s + 'b');
                if(s.back() != 'c') f(i + 1, s + 'c');
            }
        };

        f(0, "");
        if(k > ss.size()) return "";
        else return ss[k - 1];
    }
};