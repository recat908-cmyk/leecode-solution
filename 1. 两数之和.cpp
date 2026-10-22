class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>twoSum;
        /* 暴力求解*/
            // 外循环
            // for(int i=0;i<nums.size();i++){
            //     // 内循环
            //     for(int j=1;j<nums.size();j++){
            //         if( nums[i]+nums[j]==target && i!=j){ 
            //             twoSum.push_back(i);
            //             twoSum.push_back(j);
            //             return twoSum;
            //         }

            //     }
            // }
            // return twoSum;

            /* 利用哈希表算法*/
             //查询有没有 nums[i]= target-nums[j];
            //创建哈希表，保存未被录用的数据
        unordered_map<int, int>map;
        for (int i = 0; i < nums.size(); i++) {
            //检查是否前面有一个数与nums[i]相加等于target
            auto it = map.find(target - nums[i]);
            //检查这个值是否存在
            //it是迭代器，
            //哈希表如果没有查找见，就会返回map.end()
            if (it != map.end())
            {
                return { it->second,i };
            }
            //不存在的话就把这个数据存进去
            // map[i]=nums[i];
            map[nums[i]] = i;
        }
        //----解释：map.find()：find指向的是key，我们是通过key来查询value
        //---- 所以要把数字设置成key，下标是value。我们看有没有这个数据，有就返回下标
        //---- 

        return {};

    }
};