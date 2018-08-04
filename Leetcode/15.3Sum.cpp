class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> rt;
        if(nums.size() <= 2) return rt;
        sort(nums.begin(), nums.end());
        vector<int> num = nums;
        num.resize(distance(num.begin(), unique(num.begin(), num.end())));
        int sz_a = nums.size(), sz_b = num.size();
        vector<int> cnt(sz_b, 0);
        int i = 0, j = 0;
        while(i < sz_a && j < sz_b){
            if(nums[i] == num[j])
                cnt[j] ++, i++;
            else
                cnt[++j]++, i++;
        }

        for(vector<int>::iterator it1 = num.begin(); it1 != num.end(); it1++){
            for(vector<int>::iterator it2 = cnt[distance(num.begin(), it1)]>1?it1:it1+1; it2 != num.end(); it2++){
                vector<int>::iterator it3 = lower_bound(*it1==*it2?(cnt[distance(num.begin(), it1)]>2?it1:it1+1):(cnt[distance(num.begin(), it2)]>1?it2:it2+1), num.end(), -(*it1)-(*it2));
                if(it3 != num.end() && *it1 + *it2 + *it3 == 0){
                    vector<int> tmp;
                    tmp.push_back(*it1);
                    tmp.push_back(*it2);
                    tmp.push_back(*it3);
                    rt.push_back(tmp);
                }
            }
        }

        return rt;
    }
};

