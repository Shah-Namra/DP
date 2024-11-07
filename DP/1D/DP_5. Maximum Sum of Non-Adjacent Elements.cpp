// pre requiste: Lect 6 7 of Recursion for take and skip concept

// House Robber
/* You are a professional robber planning to rob houses along a street. 
Each house has a certain amount of money stashed, 
the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and
 it will automatically contact the police if two adjacent houses were broken into on the same night.
Given an integer array nums representing the amount of money of each house, 
return the maximum amount of money you can rob tonight without alerting the police.

Example 1:
Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.

Example 2:
Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.

*/
using namespace std;
#include <vector> // Include the vector header

/* Brute force*/
int Name (vector <int> &rob){
    int n = rob.size();
    return f(n-1, rob)
}
int f(int i, vector <int> &rob){
    if(i == 0)return rob[i];
    if(i < 0)return 0;  
    int pick = rob[i] + f(i-2, rob);
    int skip = f(i-1, rob);
    return max(pick, skip);
}//tle

/* Memoization*/   
int Name (vector <int> &rob){
    int n = rob.size();
    vector <int> dp(n, -1);
    return f(n-1, rob, dp)
}
int f(int i, vector <int> &rob, vector <int> &dp){
    if(i == 0)return rob[i];
    if(i < 0)return 0;  
    if(dp[n] != -1)return dp[n];
    int pick = rob[i] + f(i-2, rob, dp);
    int skip = f(i-1, rob, dp);
    return dp[n] =max(pick, skip);
}


// tabultion
int Name (vector <int> &rob){
    int n = rob.size();
    vector <int> dp(n, -1);
    return f(n-1, rob, dp)
}
int f(int i, vector <int> &rob, vector <int> &dp){
    if(i == 0)return rob[i];
    if(i < 0)return 0;  
    dp[0] = rob[0];
    int negative = 0;
    for( int i=0; i<n; i++){
        //int pick = rob[i] + dp[i-2]; // it can be negative so we need to keep track of the negative value
        int pick = rob[i];
       
        if(i > 1)
            pick += dp[i-2];    
        
        int skip = 0 + dp[i-1];
        
        dp[i] = max(pick, skip);
        negative = skip;
    }

}
// tc = O(n). sc = O(n)

/* Space optimization */
int Name (vector <int> &rob){
    int n = rob.size();
    int prev = rob[0];
    int prev2 = 0;
    for(int i=1; i<n; i++){
        int take = rob[i];
        if(i >1)
            take += prev2;
        
        int skip = prev;    
        int curri  = max(take, skip);
        prev2 = prev;
        prev = curri;
    }
    return prev;
}

