class Solution {
    public boolean isAnagram(String s, String t) {
        int[] alphas = new int[26];
        for(int i = 0; i < s.length(); i++){
            alphas[s.charAt(i) - 'a'] += 1;
        }
        for(int i = 0; i < t.length(); i++){
            alphas[t.charAt(i) - 'a'] -= 1;
        }
        for(int i = 0; i < alphas.length; i++){
            if(alphas[i] != 0){
                return false;
            }
        }
        return true;
    }
}