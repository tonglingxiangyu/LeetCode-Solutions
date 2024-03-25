class Solution {
    public boolean isHappy(int n) {
        Set<Integer> numbers = new HashSet<>();
        while(true){
            n = getsum(n);
            if(n == 1) return true;
            if(numbers.contains(n)) return false;
            else numbers.add(n);
        }

    }

    public int getsum(int n){
        int sum = 0;
        while(n != 0){
            int t = n % 10;
            sum += t * t;
            n /= 10;
        }
        return sum;
    }
}