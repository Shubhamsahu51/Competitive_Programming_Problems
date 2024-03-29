
Given a string s and a non-empty string p, find all the start indices of p's anagrams in s. 

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".


*****************************************************************************Solution***********************************************************************************
https://leetcode.com/submissions/detail/466764871/

class Solution {
public:
     // This function returns true if contents of arr1[] and arr2[] 
     // are same, otherwise false. 
    bool aresame (int arr[],int brr[]) {           
        for (int i=0;i<256;i++) {
            if (arr[i]!=brr[i])
                return false;
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {     
        
        int counttxt[256]={0};
        int countpat[256]={0};
        int n=s.length();
        int m=p.length();
        vector<int>ans;
        if (n < m)
            return {};
      
        for (int i=0;i<m;i++) {
            counttxt[s[i]]++;
            countpat[p[i]]++;
        }
   
            

       for (int i=m;i<n;i++) {
            if (aresame(counttxt,countpat)) {  // Compare counts of current windowof text with                                                // counts of pattern[] 
                ans.push_back(i-m);
            
            }
            counttxt[s[i]]++;
            counttxt[s[i-m]]--;
        }
        if (aresame(counttxt,countpat))    // Check for the last window in text 
                ans.push_back(n-m);
        return ans;
    }
};

