/*
Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Example: 

Input: 19
Output: true
Explanation: 
1^2 + 9^2 = 82
8^2 + 2^2 = 68
6^2 + 82 = 100
1^2 + 0^2 + 0^2 = 1

*/

// Solution 1 - Recursive with extra memory

class Solution {
public:
    int squareSum(int n) {
        int sum = 0;
        while(n){
            sum += (n%10) * (n%10);
            n /= 10;
        }
        return sum;
    }
    
    set<int> seen;
        
    bool isHappy(int n) {
        if(n == 1)
            return true;
        if(seen.find(n) != seen.end())
            return false;
        seen.insert(n);
        return isHappy(squareSum(n));
    }
};

// Solution 2 - Without extra memory(using linked list cycle detection technique)

class Solution {
public:
    int squareSum(int n) {
        int sum = 0;
        while(n){
            sum += (n%10) * (n%10);
            n /= 10;
        }
        return sum;
    }
        
    bool isHappy(int n) {
        int slow,fast;
        slow = fast = n;
        do{
            slow = squareSum(slow);
            fast = squareSum(squareSum(fast));
            if(fast == 1)
                return true;
        } while(slow != fast);
        return false;
    }
};
