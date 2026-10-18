class Solution {
    public static boolean isVowel(char ch){
        return ch == 'a'||ch == 'e'||ch == 'i'||ch == 'o'||ch == 'u'||ch == 'A'||ch == 'E'||ch == 'I'||ch == 'O'||ch == 'U';
    }
    public String reverseVowels(String s) {
        char[] a = s.toCharArray();
        int n = a.length;
        int l = 0, h = n-1;
        while(l<h){
            if(isVowel(a[l]) && isVowel(a[h])){
                char temp = a[l];
                a[l] = a[h];
                a[h] = temp;
                l++;
                h--;
            }
            else if(!isVowel(a[l]))
                l++;
            else
                h--;

        }
        return new String(a);
    }
}