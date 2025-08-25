class Solution {
    public int strStr(String s, String n) {
        for(int i=0;i<=s.length()-n.length();i++){
            if(s.substring(i,i+n.length()).equals(n)){
                return i;
            }
        }
        return -1;
    }
}