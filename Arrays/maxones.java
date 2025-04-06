package Arrays;
import java.util.*;

class Solution {
    public static int findMaxConsecutiveOnes(int[] nums) {
        int count = 0, currCount=0;
        for(int i=0; i<nums.length; i++){
            if(nums[i]==1)
                currCount++;
            else{
                count = (currCount > count) ? currCount : count;
                currCount = 0;
            }
        }
        return count = (currCount > count) ? currCount : count;
    }
}

public class maxones {
    public static void main(String args[]){
        int range;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter range of the array : ");
        range = sc.nextInt();
        int[] arr = new int[range];
        for(int i=0; i<range; i++)
            arr[i] = sc.nextInt();
        int ans = Solution.findMaxConsecutiveOnes(arr);
        System.out.println("Answer is " + ans);
        System.out.println();
        sc.close();
    }
}
