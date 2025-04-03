package basics;
import java.util.*;
class Solution{
    static int evenlyDivides(int n){
        int copy = n, count = 0;
        while(copy!=0){
            int rem = copy%10;
            if(rem!=0 && n%rem == 0)
                count++;
            copy/=10;
        }
        return count;  
    }
}


public class countDigits{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int tt;
        System.out.print("Enter testcases : ");
        tt = sc.nextInt();
        while(tt!=0){
            int ans, n;
            System.out.print("Enter no. : ");
            n = sc.nextInt();
            ans = Solution.evenlyDivides(n);
            System.out.println("Answer of " + tt + " testcase is " + ans);
            tt--;
        }
        sc.close();
    }
}
