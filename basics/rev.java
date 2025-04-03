package basics;

import java.util.Scanner;

class Solution{
    static int reverse(int x){
        long rev=0;
        while(x!=0){
            rev = rev*10 + x%10;
            x = x/10;
        }
        if(rev > Integer.MAX_VALUE || rev < Integer.MIN_VALUE)
            return 0;
        return (int)rev;
    }
}

public class rev {
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int tt;
        System.out.print("Enter testcases : ");
        tt = sc.nextInt();
        while(tt!=0){
            int ans, n;
            System.out.print("Enter no. : ");
            n = sc.nextInt();
            ans = Solution.reverse(n);
            System.out.println("Answer of " + tt + " testcase is " + ans);
            tt--;
        }
        sc.close();
    }
}
