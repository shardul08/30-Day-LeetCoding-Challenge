/*
Given two strings S and T, return if they are equal when both are typed into empty text editors. # means a backspace character.

Example 1:

Input: S = "ab#c", T = "ad#c"
Output: true
Explanation: Both S and T become "ac".

Example 2:

Input: S = "ab##", T = "c#d#"
Output: true
Explanation: Both S and T become "".

Example 3:

Input: S = "a##c", T = "#a#c"
Output: true
Explanation: Both S and T become "c".

Example 4:

Input: S = "a#c", T = "b"
Output: false
Explanation: S becomes "c" while T becomes "b".

Note:

    1 <= S.length <= 200
    1 <= T.length <= 200
    S and T only contain lowercase letters and '#' characters.

Follow up:

    Can you solve it in O(N) time and O(1) space?
*/

//Soultion 1 Using stack O(N) space

class Solution {
public:    
    bool backspaceCompare(string S, string T) {
        stack<char> s1,s2;
        int i = 0;
        while(i < S.length()) {
            if(S[i] == '#' ) {
                if( s1.size() != 0)
                    s1.pop();
            }
            else
                s1.push(S[i]);
            i++;
        }
        i = 0;
        while(i < T.length()) {
            if(T[i] == '#') {
                if( s2.size() != 0)
                    s2.pop();
            }
            else
                s2.push(T[i]);
            i++;
        }

        if(s1.size() != s2.size())
            return false;
        while(s1.size() != 0) {
            char c1 = s1.top();
            char c2 = s2.top();
            if(c1 != c2)
                return false;
            s1.pop();
            s2.pop();
        }
        return true;
    }
};

/*
Complexity analysis
Time: O(M+N)
Space: O(M+N)
M: length of S
N: length of T
*/

//Solution 2 Using two pointers O(1) space

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int i = S.length()-1;
        int j= T.length()-1;
        int back;
        while(i>=0 || j>=0) {
            back = 0;
            while(i>=0) {
                if(S[i] == '#') {
                    back++;
                    i--;
                }
                else if(back > 0) {
                    i--;
                    back--;
                }
                else
                    break;
            }
            
            back = 0;
            while(j>=0) {
                if(T[j] == '#') {
                    back++;
                    j--;
                }
                else if(back > 0) {
                    j--;
                    back--;
                }
                else
                    break;
            }
            
            if(i>=0 && j>=0 && S[i] != T[j])
                return false;
            if((i>=0) != (j>=0))
                return false;
            i--;
            j--;            
        }
        return true;
    }
};

/*
Complexity analysis
Time: O(M+N)
Space: O(1)
M: length of S
N: length of T
*/
   

