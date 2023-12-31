class Solution {
private:
    void solve(string digits,string output,int index,vector<string>& ans,string mapping[]){
        //base case
        if(index >= digits.length()){
            ans.push_back(output);
            return;
        }
        int number = digits[index ] - '0';
        string val = mapping[number];
        for(int j=0; j<(val.length()); j++){
            char element = val[j];
            output.push_back(element);
            solve(digits,output,index+1,ans,mapping);
            output.pop_back();
        }
    }    
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string output;
        int index = 0;
        string mapping[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        if(digits.length() == 0){
            return ans;
        }
        solve(digits,output,index,ans,mapping);
        return ans;
    }
};