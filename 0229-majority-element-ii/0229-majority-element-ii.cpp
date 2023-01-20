class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
//         unordered_map<int,int> mp;
//         for(int i =0 ; i < n ; i ++)
//         {
//             mp[nums[i]]++;
//         }
// n=n/3+1;

// vector<int> v;
//         for(auto it:mp)
//         {
//     if(it.second>=n)
//     {
// v.push_back(it.first);
//     }        
//         }
//         return v;

int num1 =-1;
 int num2=-1;
  int count1 =0;
   int count2=0;
    for(int i =0;i <nums.size(); i++)
    {
        if(num1==nums[i])
        count1++;
        else if(num2==nums[i])
        count2++;
        else if(count1==0)
        {
         num1=nums[i];
     count1=1; 
        }
        else if(count2==0)
        {
num2=nums[i];
count2=1;
        }
        else
    {
        count1--;
        count2--;
    }
    }

    vector<int> ans; 
    count1=0;
    count2=0;
    for(int i =0; i < nums.size();i++){
        if(num1==nums[i])
        count1++;
       else if(num2==nums[i])
        count2++;
    }

    if(count1>n/3)
    ans.push_back(num1);
 if(count2>n/3)
ans.push_back(num2);

return ans;

    
    }
};