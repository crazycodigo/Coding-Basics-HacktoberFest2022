
import java.util.Arrays;

public class quickSort {
    public static void main(String[] args) {
        int arr[]={10,2,5,1};
        int n=arr.length;
        sort(arr,0,n-1);
        System.out.println(Arrays.toString(arr));
        
    }

    private static void sort(int arr[],int low,int high)
    {
        if(low>=high) return;

        int s=low;
        int e=high;
        int mid=s+(e-s)/2;
        int pivot=arr[mid];

        while(s<=e)
        {
            // if no violation happens then s++ otherwise break
            while(arr[s]<pivot)
            {
                s++;
            }
            // if no violation happens then s++ otherwise break
            while(arr[e]>pivot)
            {
                e--;
            }
        // if violation occurs then swap the arr[s] with arr[e] otherwise s>=e and consition will false
            if(s<=e)
            {
                int temp=arr[s];
                arr[s]=arr[e];
                arr[e]=temp;
                
                //increase s
                s++;
                //decrese e
                e--;
            }
        }

        // now pivot is at correct position
        // So, call the left part of the pivot 
        sort(arr, low, e);

        //call the right of pivot
        sort(arr, s, high);

    }
}

