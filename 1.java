class Solution {
    public int[] twoSum(int[] nums, int target) {
     HashMap<Integer,Integer> map = new HashMap<>();
     int c[] = new int[2];
     for(int i=0;i<nums.length;i++){
         int num = nums[i];
         int need = target - num;
         if(map.containsKey(need)){
             c[0]=i;
             c[1]=map.get(need);
             return c;
         }
         else{
             map.put(num,i);
         }
     }
     return c;
}
}