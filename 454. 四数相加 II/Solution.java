class Solution {
    public int fourSumCount(int[] nums1, int[] nums2, int[] nums3, int[] nums4) {
        int ans = 0;
        Map<Integer, Integer> dict1 = new HashMap<>();
        for(int i = 0; i < nums1.length; i++){
            for(int j = 0; j < nums2.length; j++){
                int t = nums1[i] + nums2[j];
                if(dict1.containsKey(t)){
                    int c = dict1.get(t);
                    dict1.replace(t, c+1);
                }
                else{
                    dict1.put(t, 1);
                }
            }
        }

        for(int i = 0; i < nums3.length; i++){
            for(int j = 0; j < nums4.length; j++){
                int t = nums3[i] + nums4[j];
                if(dict1.containsKey(0-t)){
                    ans += dict1.get(0-t);
                }
            }
        }
        return ans;
    }
}