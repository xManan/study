#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int sum(vector<int> v){
    int s = 0;
    for(vector<int>::iterator it=v.begin(); it!=v.end(); ++it) s+=*it;
    return s;
}

void dfs(int i, const vector<int> &set, vector<int> sub, vector<int> const &pset, vector<int> proset, int &maxP, vector<vector<int>> &ans, int s){
    if(i > set.size()-1) return;
    sub.push_back(set[i]); 
    proset.push_back(pset[i]); 
    if(sum(sub) <= s){
        maxP = max(maxP, sum(proset));
        ans.push_back(sub);
    }
    //ans.push_back(sub);
    dfs(i+1, set, sub, pset, proset, maxP, ans, s);
    sub.pop_back();
    proset.pop_back();
    dfs(i+1, set, sub, pset, proset, maxP, ans, s);
}

int main ()
{
    vector<int> v = {10,19,8,10,12,8}; 
    vector<int> p = {6,10,4,5,6,4}; 
    int maxP = 0;
    int s = 34;
    vector<int> x;
    vector<int> y;
    vector<vector<int>> ans;
    dfs(0, v, x, p, y,maxP, ans, s);
    // for(int i=0; i<ans.size(); ++i){
    //     for(int j=0; j<ans[i].size(); ++j){
    //         cout << ans[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << maxP << endl;
    return 0;
}
