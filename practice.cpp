#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#pragma GCC optimize("Ofast")
static auto _ = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
#define ll long long
int update(int index,int n,string &str,int jump){
    return min(index+jump,n-1);
    // while( index<n && str[index]=='C'){
    //     index--;
    // }
    // return index;
}
bool solveRec(string &str,int index,int swim,int jump){
    // cout<<"Jump is "<<jump<<endl;
    // cout<<"Swim is "<<swim<<endl;
    // cout<<"index is "<<index<<endl;
    int n=str.length();
    if(swim<0){
        // cout<<"Hi"<<endl;
        return false;
    }
    if(index>=n-1){
        // cout<<"Hailu"<<endl;
        return true;
    }
    if(str[index]=='C'){
        // cout<<"Hello"<<endl;
        return false;
    }

    bool xyz=false;
    bool abc=false;
    if(str[index]!='W' && str[index]!='C'){
        
        // int next_idx=update(index,n,str,jump);
        // // cout<<"Updated dx"<<next_idx<<endl;
        // if(next_idx-index>0){
        //     xyz=solveRec(str,next_idx,swim,jump);
        // }
        int next_idx=index+1;
        jump--;
        xyz= xyz || solveRec(str,next_idx,swim,jump);
        while(jump>0){
            xyz= xyz||solveRec(str,next_idx,swim,jump);
            next_idx++;
            jump--;
        }
    }
    if(swim>0 && index<n-1 && str[index+1]!='C'){
        // cout<<"ncf"<<endl;
        abc=solveRec(str,index+1,swim-1,jump);
    }
    return xyz||abc;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k;
        cin>>n>>m>>k;
        string s;
        cin>>s;
        string str="B";
        str+=s;
        str.push_back('B');
        cout<<str<<endl;
        cout<<solveRec(str,0,k,m)<<endl;
    }
}



// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;

// #pragma GCC optimize("Ofast")
// static auto _ = []() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);
//     return nullptr;
// }();

// int update(int index, int n, const string &str) {
//     while (index < n && str[index] == 'C') {
//         index++;
//     }
//     return index;
// }

// bool solveRec(string &str, int index, int swim, int jump, vector<vector<int>> &dp) {
//     int n = str.length();
//     if (index >= n - 1) {
//         return true;
//     }
//     if (swim < 0 || jump < 0) {
//         return false;
//     }
//     if (str[index] == 'C') {
//         return false;
//     }
//     if (dp[index][swim] != -1) {
//         return dp[index][swim];
//     }

//     bool canJump = false;
//     if (str[index] != 'W') {
//         for (int j = 1; j <= jump; j++) {
//             int next_idx = update(index + j, n, str);
//             if (next_idx - index <= jump && solveRec(str, next_idx, swim, jump, dp)) {
//                 canJump = true;
//                 break;
//             }
//         }
//     }

//     bool canSwim = (str[index] != 'C' && swim > 0 && solveRec(str, index + 1, swim - 1, jump, dp));

//     return dp[index][swim] = (canJump || canSwim);
// }

// int main() {
//     int t;
//     cin >> t;
//     while (t--) {
//         int n, m, k;
//         cin >> n >> m >> k;
//         string s;
//         cin >> s;
//         string str = "B" + s + "B";

//         vector<vector<int>> dp(n + 2, vector<int>(k + 1, -1));
//         bool result = solveRec(str, 0, k, m, dp);
//         cout << (result ? "YES" : "NO") << endl;
//     }
//     return 0;
// }

