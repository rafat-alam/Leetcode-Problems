class Solution {
public:
    vector<string> validStrings(int n) {
        vector<string> ans;
        function<void (int, int, string)> f = [&] (int i, int j, string temp) -> void {
            if(i == n) {
                ans.push_back(temp);
                return;
            }
            if(j == 0) {
                f(i + 1, j + 1, temp + "0");
            }
            f(i + 1, 0, temp + "1");
        };
        f(0, 0, "");

        return ans;
    }
};