/*
(This problem is an interactive problem.)

A binary matrix means that all elements are 0 or 1. For each individual row of the matrix, this row is sorted in non-decreasing order.

Given a row-sorted binary matrix binaryMatrix, return leftmost column index(0-indexed) with at least a 1 in it. If such index doesn't exist, return -1.

You can't access the Binary Matrix directly.  You may only access the matrix using a BinaryMatrix interface:

    BinaryMatrix.get(x, y) returns the element of the matrix at index (x, y) (0-indexed).
    BinaryMatrix.dimensions() returns a list of 2 elements [n, m], which means the matrix is n * m.

Submissions making more than 1000 calls to BinaryMatrix.get will be judged Wrong Answer.  Also, any solutions that attempt to circumvent the judge will result in disqualification.

For custom testing purposes you're given the binary matrix mat as input in the following four examples. You will not have access the binary matrix directly.

 

Example 1:

Input: mat = [[0,0],[1,1]]
Output: 0

Example 2:

Input: mat = [[0,0],[0,1]]
Output: 1

Example 3:

Input: mat = [[0,0],[0,0]]
Output: -1

Example 4:

Input: mat = [[0,0,0,1],[0,0,1,1],[0,1,1,1]]
Output: 1


Constraints:

    1 <= mat.length, mat[i].length <= 100
    mat[i][j] is either 0 or 1.
    mat[i] is sorted in a non-decreasing way.

*/

//Solution 1 Using binary search

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        int res = INT_MAX;
        vector<int> dim = binaryMatrix.dimensions();
        int r = dim[0], c=dim[1];
        for(int i=0;i<r;i++) {
            int start=0,end=c-1;
            
            while(start < end) {
                int mid = start + (end-start)/2;
                if(binaryMatrix.get(i,mid) == 1)
                    end = mid;
                else
                    start = mid + 1;                
            }
            if(end < c-1 || binaryMatrix.get(i,end))
                if(end < res)
                    res = end;
        }
        return res == INT_MAX ? -1:res;
    }
};

/*
Complexity analysis
Time: O(nLogm)
Space: O(1)
*/

//Solution 2

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> dim = binaryMatrix.dimensions();
        int r = dim[0], c = dim[1];
        int p = c-1;
        int found = 0;
        for(int i=0;i<r;i++) {
            if(p < 0)
                break;
            if(binaryMatrix.get(i,p)) {
                found = 1;
                p--;
                i--;
            }
        }
        if(p < 0)
            return 0;
        return found ? p+1:-1;
    }
};

/*
Complexity analysis
Time: O(m + n)
Space: O(1)
*/
