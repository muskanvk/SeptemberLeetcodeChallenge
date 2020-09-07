class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<pair<int, bool>> mp(26, {0, false}); //{frequency, isPresent}
        for(char &ch : S){
            int curr = ch - 'a';
            mp[curr].first++;
        }
        vector<int> op;
        int sum = 0; //sum of imaginary partition
        int l = 0; //length of imaginary partition
        for(char &ch : S){
            int curr = ch - 'a';
            l++;
            if(!mp[curr].second){
                sum += (mp[curr].first - 1);
                mp[curr].second = true;
            }
            else{
                sum--;
            }
            if(sum == 0){
                op.push_back(l);
                l = 0;
            }
        }
        return op;
    }
};