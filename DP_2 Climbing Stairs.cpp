// to reach the nth stairs
// each time u can climb 1 stair or 2 stairs
// no. of ways u can go from 0 to n

// How to know that this is a DP problem?
/* 
* count the total no. of ways 
* multiple ways to reach the same state
* minimum or maximum value
* 
*/

/* Whenever try all possible way is asked (it can be count, best etc) we use Recurrsion */
// where we try all possible ways 

/* ShortCuts */ // Recursion
// 1. Represent the problem in index
// 2. Do every possible steps given in the problem statement 
// 3. if question says "Count All ways", "Minimum ways", "Maximum ways" then do a sum of all the ways, min of all the ways, max of all the ways

int function (int n){ // index
    // edge cases
    if(n == 0) return 1;
    if(n == 1) return 0;
    // doing every possible steps
    int left = function (n-1);
    int right = function (n-2);
    return left + right; // count all ways
}

#include <vector>;
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
      
        vector <int >dp (n+1, -1);
        return function(n, dp);
    }
    int function (int n, vector<int>&dp){
        if(n == 1)return 1;
        if(n == 2)return 2;
    
        if(dp[n] != -1) return dp[n];
        dp[n] = function (n-1, dp) + function (n-2, dp);
        return dp[n];
    
    }
};