class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1 || numRows >=s.length()){
            return s;
        }

        vector<string>rows(numRows);

        int currentRow=0;
        bool goingdown=true;
        for(int i=0;i<s.length();i++){
            rows[currentRow]+=s[i];
            if(currentRow==0) {
                goingdown=true;

            }
            else if(currentRow == numRows-1){
                goingdown=false;
            }

            if(goingdown){
                currentRow++;
            }else{
                currentRow--;
            }
        }
        string ans="";

        for(int i=0;i<numRows;i++){
            ans+=rows[i];
        }
    return ans;
    }
};