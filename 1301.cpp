class Solution {
public:
    int mod = 1e9 + 7;
    vector<vector<vector<int>>> dp;

    vector<int> find(int r, int c, vector<string>& board)
    {
        int n = board.size();

        if(r >= n || c >= n || board[r][c] == 'X')
            return {-1, 0};

        if(r == n - 1 && c == n - 1)
            return {0, 1};

        if(dp[r][c][0] != -2)
            return dp[r][c];

        int mx = -1;
        long long cnt = 0;

        vector<pair<int,int>> dir = {{1,0}, {0,1}, {1,1}};

        for(int i = 0; i < dir.size(); ++i)
        {
            int nr = r + dir[i].first;
            int nc = c + dir[i].second;

            vector<int> temp = find(nr, nc, board);

            if(temp[0] == -1)
                continue;

            if(temp[0] > mx)
            {
                mx = temp[0];
                cnt = temp[1];
            }
            else if(temp[0] == mx)
            {
                cnt = (cnt + temp[1]) % mod;
            }
        }

        if(mx == -1)
            return dp[r][c] = {-1, 0};

        if(board[r][c] != 'E')
            mx += board[r][c] - '0';

        return dp[r][c] = {mx, (int)cnt};
    }

    vector<int> pathsWithMaxScore(vector<string>& board)
    {
        int n = board.size();
        dp.assign(n, vector<vector<int>>(n, vector<int>(2, -2)));
        vector<int> ans = find(0, 0, board);
        if(ans[0] == -1)
            return {0, 0};

        return ans;
    }
};
