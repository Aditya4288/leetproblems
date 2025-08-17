class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n1=g.size();
        int n2=s.size();
        sort(g.begin(),g.end(),[](const int a, const int b){
            return a>b;
        });
        sort(s.begin(),s.end(),[](const int a, const int b){
            return a>b;
        });
        int i=0,j=0,cnt=0;

        while(i<n1 && j<n2){
            if(s[j]>=g[i]){
                cnt++;
                j++;
            }
            i++;
        }
        return cnt;
    }
};