//Leetcode problem

class Solution {

private:
    void solve(string digits, vector<string>& ans, string output, string mapping[], int index){

        //base case
        if(index >= digits.length()){
            ans.push_back(output);
            return;
        }

        int element = digits[index] - '0';
        string value = mapping[element];

        for(int i=0;i<value.length();i++){
            output.push_back(value[i]);

            solve(digits, ans, output, mapping, index+1);

            output.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length() == 0)
            return ans;
        string output;
        int index=0;

        string mapping[10] = {"", "", "abc", "def","ghi","jkl","mno","pqrs","tuv","wxyz"};

        solve(digits, ans, output, mapping, index);

        return ans;
    }
};
