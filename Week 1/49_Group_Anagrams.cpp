/*
Given an array of strings, group anagrams together.

Example:

Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]

Note:

    All inputs will be in lowercase.
    The order of your output does not matter.


*/

//Solution Anagrams are strings that are equal when sorted

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        map<string,vector<string>> maps;
        
        for(auto s:strs) {
            string t = s;
            sort(t.begin(),t.end());
            maps[t].push_back(s);
        }
        
        for(auto m:maps)
            res.push_back(m.second);
        
        return res;
    }
};

/*
Complexity Analysis
Time: O(NKLogK)
Space: O(NK)
N: number of strings
K: length of longest string
*/
