class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int>freq(26,0);
        vector<bool>vis(26,false);

        for(int i=0;i<s.length();i++){
            freq[s[i]-'a']++;
        }
        string st="";

        for(int i=0;i<s.length();i++){
            char ch=s[i];

            freq[ch-'a']--;

            if(vis[ch-'a']){
                continue;
            }

            while(!st.empty() && ch<st.back() && freq[st.back()-'a']>0){
                vis[st.back()-'a']=false;
                st.pop_back();
            }
            st.push_back(ch);
            vis[ch-'a']=true;
        }
        return st;
    }
};