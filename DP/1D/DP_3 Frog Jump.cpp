// n stairs, height of i+1 stair = HEIGHT[i], 
// energy lost in jump = HEIGHT[i-1] - HEIGHT[j-1] , 
// if frog is on ith stair he can jump in i+1 or i+2
// min total energy used to reach 1st to nth stair

/* 
    10, 20, 30, 10
    0   1   2   3

    frog can only jump 1 or 2 stairs
    greedy wouldnt work
    Recurrsion will work 
*/

// Recursion -> Try all possible ways 
// index, do all stuf on index, take min of all ways

/* Recursion to DP */
// 1. look which parameter is changing , heres its index
// 2. whats the max value of index, here its 6 (0 to 5) in example, dp[6]
// 3. now do the 3 steps of DP declare, add it, check if it is previously computed , memoization
// tc: O(n), sc: O(n)
#include <vector>;
using namespace std;

/* Recurrsion */
int frogJump (int n, vector<int>& heights){ // index

    return f(n-1, heights);
}

int f( int index, vector <int> &heights){
    if (index == 0) return 0;
    int left =  f(index -1, heights) + abs(heights[index] - heights[index-1]);
    int right = INT_MAX;
    if(index > 1) right = f(index -2, heights) + abs(heights[index] - heights[index-2]);
    return min(left, right);
}

/* Memoization */

// it will throw TLE, so we will use dp memo ization  
int frogJump (int n, vector<int>& heights, vector <int> &dp){ // index
    vector <int> dp(n, -1);
    return f(n-1, heights, dp);
}

int f( int index, vector <int> &heights, vector<int> &dp){
    if (index == 0) return 0;
    if(dp[index] != -1) return dp[index];// memoization

    int left =  f(index -1, heights, dp) + abs(heights[index] - heights[index-1]);
    int right = INT_MAX;
    
    if(index > 1) right = f(index -2, heights, dp) + abs(heights[index] - heights[index-2]);
    return dp[index] =  min(left, right);
}

/* Tabulation */    

int frogJump (int n, vector<int>& heights){ // index
        vector <int> dp(n, 0);
    dp[0]=0;
    for(int i=0; i<n-1; i++ ){
        int first = dp[i-1] + abs(heights[i] - heights[i-1]);
        int second = INT_MAX;
        if(i > 1)
            second = dp[i-2]+ abs(heights[i] - heights[i-2]);

        dp[i] = min(first, second);  
    }
    return dp[n-1];
}


/* Space Optimization*/
// whenever there is something like index -1 and index -2 ,
// we can use 2 variables/pointers instead of array  


int frogJump (int n, vector<int>& heights){ // index
    vector <int> dp(n, 0);
    int prev = 0;
    int prev2 = 0;
    for(int i=1; i<n-1; i++ ){
        int first = prev + abs(heights[i] - heights[i-1]);
        int second = INT_MAX;
        if(i > 1)
            second = prev2+ abs(heights[i] - heights[i-2]);

        int curri = min(first, second);  
        prev2 = prev;
        prev = curri;
    }
    return prev;
}

// follow up question
/* for k jumps */
int frogJump (int n, vector<int>& heights, int k){ // index
    vector <int> dp(n, INT_MAX);
    dp[0]=0;
    for(int i=0; i<n; i++ ){
        for (int j=0; j<=k ; j++){
            if (i>=j){
                dp[i] = min(dp[i], dp[i-j] + abs(heights[i] - heights[i-j]));
            }   
        }
    }
    return dp[n-1];
}
