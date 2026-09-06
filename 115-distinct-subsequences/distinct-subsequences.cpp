class Solution {
public:
    int numDistinct(std::string s, std::string t) {
        int m = s.length();
        int n = t.length();
        
        // Use unsigned long long or long long to prevent overflow during intermediate steps,
        // though the problem states the final answer fits in a 32-bit signed integer.
        std::vector<std::vector<unsigned long long>> dp(m + 1, std::vector<unsigned long long>(n + 1, 0));
        
        // Empty t can be formed 1 way
        for (int i = 0; i <= m; ++i) {
            dp[i][0] = 1;
        }
        
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        
        return static_cast<int>(dp[m][n]);
    }
};