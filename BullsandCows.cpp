class Solution {
public:
    string getHint(string secret, string guess) {
    unordered_map<char,int> secret_freq;
    unordered_map<char,int> guess_freq;
    // dry run for this test case-->
    // secret="1123" guess="01111"
    // in first iteration they don't match so

   // secret_freq=['1'->1] and guess_freq=['0'->1]
   // in 2 nd iteration they match hence bulls=1;
   // in 2 rd iteration secret-_freq=['1'->1,'2'->1] and guess_freq=['0'->1, '1'->1]
   // in 3 rd iteration secret_freq=['1'->1,'2'->1,'3'->1] guess_freq=[0'->1, '1'->2]

   int size = secret.size();

        int bulls = 0;
        int cows = 0;
        for(int i = 0; i < size; i++){
            if(secret[i] == guess[i]){
                bulls++;
            }else{
                secret_freq[secret[i]]++;
                guess_freq[guess[i]]++;
            }
    }
   for(auto it:guess_freq){
       // find frequency of 0 in both the maps which is 0 so cows=0;
       // find frequecny of 1 in both the maps and take minimum which is 1 so cows=1
       //cout<<it.second<<" ";
       cows+=min(it.second,secret_freq[it.first]);
       //cout<<secret_freq[it.first]<<" ";
       
   }
   //cout<<cows<<" ";
   return to_string(bulls)+"A"+to_string(cows)+"B";
    }
};
