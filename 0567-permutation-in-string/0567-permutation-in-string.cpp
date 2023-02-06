class Solution {
public:
    bool checkInclusion(string s1, string s2) {
//         unordered_map<char, int >  mp ;
//         vector<int> v(26,0);
//         int count=s1.size();
//         int n =count; 
//         for(int i = 0;i<s1.size();i++)
//         {
//             mp[s1[i]]++;
//             v[s1[i]-'a']++;
//         }
// int start =0;
//         for(int i=0;i <s2.size() ;i++)
//         {
//              if(count==0)
//                break;
//            if(mp.find(s2[i])==mp.end()){
//                cout<<count;
              
//                count=n; 
//            }
//            else{
            
//                if(mp[s2[i]]==0){
//               mp[s2[i]]=v[s2[i]-'a'];
//               count++;

//                }
           
//                count--;
               
//                mp[s2[i]]--;
               
//                 cout<<count<<i<<"   ";
//            }

//         }
//         // if(count==0)
//         // return true;
//         //  else 
//         for(auto it :mp)
//         {
//             if(it.second!=0)
//                  return false;
//         }
//          return true;;
// vector<char> v1(26,0);
// vector<char> v2(26,0);
// int n =s1.size();
// int m =s2.size();
//     for(int i=0; i <  n ; i++)
//     {
//         v1[s1[i]-'a']++;
//     }

//     int  i=0,j=0;
//     while(i<m)
//     {
//           v2[s2[i]-'a']++;
//     if(i>=n){
//     cout<<i;
//     v2[s2[j++]-'a']--;
//     }
// if(v1==v2)
// return true;
//     i++;
//     }
//     return false;
//     }
 
int n =s1.size();
int m =s2.size();
if(n>m)
return false;
vector<char > v1(26,0);
vector<char>v2(26,0);

for(int i =0;i<n;i++)
{
    v1[s1[i]-'a']++;
    v2[s2[i]-'a']++;
}
 

vector<int >v ;
if(v1==v2)
return true;

for(int i =n;i<m;i++){
    v2[s2[i-n]-'a']--;
    v2[s2[i]-'a']++;

    if(v1==v2)
   return true;
}
return false;

    
    }
};