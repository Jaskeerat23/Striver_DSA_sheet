package Arrays;
import java.util.*;
class Solution {
    static public void moveZeroes(int[] nums) {
        int i=0, j=-1;
        for(i = 0; i<nums.length; i++)
            if(nums[i]==0){
                j = i;
                break;
            }
        if(j==-1)
            return;
        for(i = j+1; i<nums.length; i++)
            if(nums[i]!=0){
                nums[j] = nums[i];
                nums[i] = 0;
                j++;
            }
    }
}

public class movezeros {
    public static void main(String args[]){
        int range;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter range of the array : ");
        range = sc.nextInt();
        int[] arr = new int[range];
        for(int i=0; i<range; i++)
            arr[i] = sc.nextInt();
        Solution.moveZeroes(arr);
        for(int i : arr) { System.out.print(i + "\t"); }
        System.out.println();
        sc.close();
    }
}
