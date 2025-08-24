class Solution {
    public char findTheDifference(String s, String t) {
        HashMap<Character, Integer> map = new HashMap<>();

        int len = s.length();
        for (int i = 0; i < len; i++) {
            if (map.containsKey(s.charAt(i))) {
                map.put(s.charAt(i), map.get(s.charAt(i)) + 1);
            } else {
                map.put(s.charAt(i), 1);
            }
        }

        for (int i = 0; i <= len; i++) {
            char ch = t.charAt(i);
            if (!map.containsKey(ch))
                return ch;
            else {
                int val = map.get(ch);
                val--;
                if (val == 0)
                    map.remove(ch);
                else
                    map.put(ch, val);
            }
        }

        return 'a';
    }
}