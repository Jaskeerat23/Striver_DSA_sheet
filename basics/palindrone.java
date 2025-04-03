/*STRIVER STEP : 1, LEC 4 */
/*Given an integer x, return true if x is a palindrome, and false otherwise. */

package basics;

import java.util.Scanner;

class Solution {
    static public boolean isPalindrome(int x) {
        if(x<0) return false;
        long rev = 0, copy = x;
        while(x!=0){
            rev= rev*10 + x%10;
            x/=10;
        }
        if(copy == rev)
            return true;
        return false;
        
    }
}

public class palindrone {
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int tt;
        System.out.print("Enter testcases : ");
        tt = sc.nextInt();
        while(tt!=0){
            int n;
            System.out.print("Enter no. : ");
            n = sc.nextInt();
            boolean ans = Solution.isPalindrome(n);
            System.out.println("Answer of " + tt + " testcase is " + ans);
            tt--;
        }
        sc.close();
    }
}
