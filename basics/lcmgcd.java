package basics;

import java.util.Scanner;

class Solution {
    public static int[] lcmAndGcd(int a, int b) {
        int largest = Math.max(a, b), smallest = Math.min(a, b), lcm=0, gcd=0;
        System.out.println("Max is " + largest + " Min is " + smallest);
        for(int i = smallest; i>0; i--){
            if(a%i==0 && b%i==0){
                System.out.println(i);
                gcd = i;
                break;
            }
        }
        for(int i = largest; i>0; i+=largest){
            if(i%a==0 && i%b==0){
                lcm = i;
                break;
            }
        }
        int[] arr = {lcm, gcd};
        return arr;
    }
}


public class lcmgcd {
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int tt;
        System.out.print("Enter testcases : ");
        tt = sc.nextInt();
        while(tt!=0){
            int n1, n2;
            System.out.print("Enter first no. : ");
            n1 = sc.nextInt();
            System.out.print("Enter second no. : ");
            n2 = sc.nextInt();
            int[] ans = Solution.lcmAndGcd(n1, n2);
            System.out.println("LCM : " + ans[0] + " GCD : " + ans[1]);
            tt--;
        }
        sc.close();
    }
}
