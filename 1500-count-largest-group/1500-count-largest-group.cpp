class Solution {
public:
    int countLargestGroup(int n) {
        string s = to_string(n + 1);
        int sm = s.length() * 9 + 1;
        vector<int> dp(sm, 0);
        int x = 0;

        for (char ch : s) {
            int digit = ch - '0';
            vector<int> dp2(sm, 0);

            for (int j = 0; j < sm; ++j)
                for (int k = 0; k < 10; ++k)
                    if (j + k < sm)
                        dp2[j + k] += dp[j];

            dp = dp2;

            for (int j = 0; j < digit; ++j)
                if (x + j < sm)
                    dp[x + j] += 1;

            x += digit;
        }

        dp[0] = 0;
        int maxFreq = *max_element(dp.begin(), dp.end());
        return count(dp.begin(), dp.end(), maxFreq);
    }
};