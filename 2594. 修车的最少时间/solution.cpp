class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        /*
            如果时间 t 固定，那么就可以通过 r * n_2 来计算出可以修好的车辆数，只要通过二分查找找到大于等于cars的t即可。

            二分查找笔记：
            def lower_bound(nums: List[int], target: int) -> int:
                left = 0
                right = len( nums) - 1  # 闭区间[left, right]
                while left <= right:  #区间不为空
                    # left + (right - left) / 2 在c++和java中可以不溢出
                    mid = (left + right)l // 2
                    if nums[mid] < target:
                        left = mid + 1 #[mid+1, right]
                    else:
                        right = mid - 1 #[left, mid-1]
                return left

            1.上面代码在闭区间 [left, right] 中查找，当 left > right 时区间为空退出循环。
            2.也可以用左闭右开 [left, right)，这时候当 left == right 时区间为空退出循环，代码更新 right = mid
            e.也可以用开区间 (left, right)，这时候当 left+1 == right 时区间为空退出循环，代码更新 left = mid, right = mid
        */

        double n = ranks.size();
        long long stime = 0;
        long long ltime = 1LL * small * cars * cars; // 这里的值超过了 2^31 即int的范围，故使用long long
        
        while(stime <= ltime){ // 闭区间
            long long mid = stime + (ltime - stime) / 2;
            long long res = 0;
            for(int i = 0; i < n; i++){
                res += sqrt(mid / ranks[i]);
            }
            if(res >= cars){
                ltime = mid - 1;
            }
            else{
                stime = mid + 1;
            }
        }
        long long ans = stime;
        return ans;
    }
};