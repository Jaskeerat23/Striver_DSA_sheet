package Arrays;
import java.util.*;
class Solution{
    static public void moveZeros(int[] nums){
        int i=0, j=0;
        while(i<nums.length){
            if(nums[i] == 0){
                j = i+1;
                while(j<nums.length && nums[j]==0) j++;
                if(j!=nums.length){
                    nums[i] = nums[j];
                    nums[j]=0;
                }
            }
            i++;
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
        Solution.moveZeros(arr);
        for(int i : arr) { System.out.print(i + "\t"); }
        System.out.println();
        sc.close();
    }
}
