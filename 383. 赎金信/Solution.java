class Solution {
    public boolean canConstruct(String ransomNote, String magazine) {
        int[] record = new int[26];
        for(char i: magazine.toCharArray()){
            record[i - 'a'] += 1;
        }
        for(char i: ransomNote.toCharArray()){
            record[i - 'a'] -= 1;
            if(record[i - 'a'] < 0) return false;
        }
        return true;
    }
}