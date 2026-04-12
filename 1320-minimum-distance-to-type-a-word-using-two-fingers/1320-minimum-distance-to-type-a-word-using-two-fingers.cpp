

class Solution {
public:
    int minimumDistance(string word) {
        int n = word.length();
        // dp[i][j] = min distance after typing i characters, 
        // with the 'other' finger at character j (0-25 or 26 for 'not placed')
        vector<vector<int>> dp(n + 1, vector<int>(27, 1e9));
        
        // Initial state: first finger hasn't moved yet (cost 0)
        dp[0][26] = 0;

        for (int i = 0; i < n; ++i) {
            int curr = word[i] - 'A';
            int prev = (i == 0) ? 26 : word[i-1] - 'A';

            for (int other = 0; other <= 26; ++other) {
                if (dp[i][other] == 1e9) continue;

                // Option 1: Move the finger that was at 'prev' to 'curr'
                dp[i + 1][other] = min(dp[i + 1][other], dp[i][other] + getDist(prev, curr));

                // Option 2: Move the finger that was at 'other' to 'curr'
                dp[i + 1][prev] = min(dp[i + 1][prev], dp[i][other] + getDist(other, curr));
            }
        }

        int result = 1e9;
        for (int j = 0; j <= 26; ++j) {
            result = min(result, dp[n][j]);
        }
        return result;
    }

private:
    int getDist(int a, int b) {
        if (a == 26 || b == 26) return 0; // Free movement for first placement
        int r1 = a / 6, c1 = a % 6;
        int r2 = b / 6, c2 = b % 6;
        return abs(r1 - r2) + abs(c1 - c2);
    }
};