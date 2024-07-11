// TC = O(2^n) SC = (N)


class Solution {
private:
    void solve(int idx, vector<int>& arr, int target, vector<int> &temp, vector<vector<int>> &ans){
        // base case
        if(idx == arr.size()){
            if(target == 0) ans.push_back(temp);
            return;
        }
        // processing 
        // take it
        if(arr[idx]<=target){
            temp.push_back(arr[idx]);
            solve(idx, arr, target - arr[idx], temp, ans);
            temp.pop_back();
        }
        // not take it
        solve(idx + 1, arr, target, temp, ans);
        // return 
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        vector<vector<int>> ans;
        solve(0, candidates, target, temp, ans);
        return ans;
    }
};