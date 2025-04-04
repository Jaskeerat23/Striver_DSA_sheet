package Arrays;
import java.util.*;
class Solution{
    static int secondLargest(int[] arr){
        int max = Integer.MIN_VALUE, sec_max = Integer.MIN_VALUE;
        for(int i=0; i<arr.length; i++){
            if(arr[i] > max){
                sec_max = max;
                max = arr[i];
            }
            if(arr[i] > sec_max && arr[i] < max)
                sec_max = arr[i];
        }
        return (sec_max == Integer.MIN_VALUE) ? -1 : sec_max;
    }
}
public class secondlargest{
    public static void main(String args[]){
        int range;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter range of the array : ");
        range = sc.nextInt();
        int[] arr = new int[range];
        for(int i=0; i<range; i++)
            arr[i] = sc.nextInt();
        int sec_max = Solution.secondLargest(arr);
        System.out.println("Second largest is " + sec_max);
        sc.close();
    }
}