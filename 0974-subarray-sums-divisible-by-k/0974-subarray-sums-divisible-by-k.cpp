class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int sum = 0;
        int n=nums.size();
          unordered_map<int, int > mp;
int count =0; 
mp[0]++;
          for(int i = 0; i < n;i++)
          {
              sum+=nums[i];
                int remainder= sum%k;
                if(remainder<0)
                {
                    remainder+=k;
                }
                    
            if(mp.find(remainder)!=mp.end())
            {
        count+=mp[remainder];
            }
            
                   
            mp[remainder]++;
            
          }
return count ;
    }
};