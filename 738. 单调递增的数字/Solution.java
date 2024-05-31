class Solution {
    public int monotoneIncreasingDigits(int n) {
        String s = String.valueOf(n);
        char[] N = s.toCharArray();
        int flag = s.length();
        for(int i = s.length() - 1; i > 0; i--){
            if(N[i-1] > N[i]){
                flag = i;
                N[i-1]--;
            }
        }
        for(int i = flag; i < s.length(); i++){
            N[i] = '9';
        }
        return Integer.parseInt(String.valueOf(N));
    }
}