class Solution {
public:
void solve(vector<string>&ans,int n,string &res){
    if(res.size()==n){
        ans.push_back(res);
        return ;
    }
    res.push_back('1');
    solve(ans,n,res);
    res.pop_back();
    if(res.empty()||res.back()!='0'){
        res.push_back('0');
        solve(ans,n,res);
        res.pop_back();
    }

}
    vector<string> validStrings(int n) {
        vector<string>ans;string res;
        solve(ans,n,res);
        return ans;
    }
};