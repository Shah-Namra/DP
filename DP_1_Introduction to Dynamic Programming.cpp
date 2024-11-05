/* Fibonacci  */

/* Recursion*/
#include <iostream> // Include the iostream header for cout
using namespace std; // Use the standard namespace

int f(int n){
    if(n<=1) 
        return n;
    return f(n-1)+f(n-2); // recursive call
}

int main(){
    int n=5;
    cout << f(n); 
    return 0;
}
/* Recursion Tree*/

/*Overlapping */
// solving the same subproblem multiple times, which is not efficient

/*Memoization */
// tend to store the value of sub problems in hashmap/tables 
// whenever the we solve a problem we store the result in a table 
// and when we need to solve the same problem we can use the result from the table


/*
* Steps to solve a DP problem
1. Always declare a dp array, 
- dp [n+1]
2. Storing the result of subproblems
3. Checking if the prpoblem is previously solved, if it is previously solved then the value will not be -1
- if(dp[n]!=-1) return dp[n]
4. If the problem is not solved then we solve the problem and store the result in the dp array

*/
int f(int n){
    if(n<=1) 
        return n;
    return f(n-1)+f(n-2); // dp[n]
}

#include <vector>   
using namespace std; 

int main(){
    int n;
    cin >> n;
    vector<int> dp(n+1, -1);
    cout << f(n); 
    return 0;    
}

int f(int n, vector<int> &dp){
    if(n <= 1) 
        return n;

    if(dp[n] != -1) 
        return dp[n];

    return dp[n] = f(n-1, dp) + f(n-2, dp); // dp[n]
}
// timecomplexity O(n)
// spacecomplexity O(n) + O(n)

/* Tabulation */
// Bottom up approach
// base case to top case

// base case here would be dp[0] and dp[1]
 dp[0] = 0;
 dp[1] = 1;   
for( int i = 2; i <= n; i++){
    dp[i] = dp[i - 1] + dp[i - 2];
}
// this would take SC O(n), how to reduce it?
// using 2 pointers prev and prev2
// as we move forward these pointers will be updated and also move forward  
int prev = 0
int prev2 = 1;

for(int i = 2; i <= n; i++){
    int curr = prev + prev2;
    prev2 = prev;
    prev = curr;
}
cout << prev;
// this would take SC O(1)