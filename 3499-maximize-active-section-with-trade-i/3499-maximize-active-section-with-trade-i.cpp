class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n=s.size();
        int ones=0;

        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                ones++;
            }
        }

        vector<pair<char, int >> runs;

        for(int i=0;i<n;i++){
            if(runs.empty() || runs.back().first != s[i]){
                runs.push_back({s[i],1});
            }else{
                runs.back().second++;
            }
        }
        int gain =0;

        for (int i = 1; i < runs.size() - 1; i++) {
            if (runs[i].first == '1' &&
                runs[i - 1].first == '0' &&
                runs[i + 1].first == '0') {

                int leftZeros = runs[i - 1].second;
                int rightZeros = runs[i + 1].second;

                if (leftZeros + rightZeros > gain)
                    gain = leftZeros + rightZeros;
            }
        }

        return ones + gain;
    }
};