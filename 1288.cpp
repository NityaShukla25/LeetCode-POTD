class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end(), [](auto &a, auto &b) {
            if (a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });

        int count=0;
        int end=-1;
        for(int i=0;i<n;++i){
            int a = arr[i][0];
            int b = arr[i][1];
            if(b>end){
                count++;
                end=b;
            }
        }
        return count;
        
    }
};
