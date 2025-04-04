package Arrays;
import java.util.*;
class Solution{
    static int missingNo(int[] nums){
        int n = nums.length+1, s, sum=0;
        s = (n*(n-1))/2;
        for(int i : nums)
            sum+=i;
        return s - sum;
    }
}

public class missingNumber {
    public static void main(String[] args) {
        int range;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter range of the array : ");
        range = sc.nextInt();
        int[] arr = new int[range];
        for(int i=0; i<range; i++)
            arr[i] = sc.nextInt();
        int num = Solution.missingNo(arr);
        System.out.println("missing number is " + num);
        sc.close();
    }
}
