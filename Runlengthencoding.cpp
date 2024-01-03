
string encode(string src) {
    int n=src.length();
    string ans="";
    int i=0; // so w
    while(i<n){
        char ele=src[i]; // w
        i++; // now it's w
        int cnt=1;
        while(i<n && src[i]==ele){
            // w=w
            cnt++;
            i++;
        }
        ans+=ele;
        ans+=to_string(cnt);
    }
    return ans;
}
