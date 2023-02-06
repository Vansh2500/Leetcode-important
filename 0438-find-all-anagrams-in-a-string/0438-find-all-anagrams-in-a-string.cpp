class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(s.size() < p.size()) return {};
int n =p.size();
int m =s.size();
vector<char > v1(26,0);
vector<char>v2(26,0);

for(int i =0;i<n;i++)
{
    v1[p[i]-'a']++;
    v2[s[i]-'a']++;
}
 

vector<int >v ;
if(v1==v2)
v.push_back(0);

for(int i =n;i<m;i++){
    v2[s[i-n]-'a']--;
    v2[s[i]-'a']++;

    if(v1==v2)
    v.push_back(i-n+1);
}
return v;

    
    }

};