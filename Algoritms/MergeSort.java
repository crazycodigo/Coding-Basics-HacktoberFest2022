public class MergeSort
{

    public void sort(int[] a, int n) 
    {
        //Base case
        if (n < 2) 
        {
            return;
        }
        //Finds the middle and splits into 2 empty arrays
        int mid = n / 2;
        int[] l = new int[mid];
        int[] r = new int[n - mid];

        //Fills the new arrays
        for (int i = 0; i < mid; i++) 
        {
            l[i] = a[i];
        }
        for (int i = mid; i < n; i++) 
        {
            r[i - mid] = a[i];
        }
        //Recursively calls itself for each of the new arrays
        sort(l, mid);
        sort(r, n - mid);

        //Merges the arrays with length 1
        merge(a, l, r, mid, n - mid);
    }

    private void merge(int[] a, int[] l, int[] r, int left, int right)    {
        int i = 0;    //Left array index
        int j = 0;    //Right array index
        int k = 0;    //Sorted array index

        //Merges the 2 arrays
        while (i < left && j < right)
        {
            if (l[i] <= r[j]) 
            {
                a[k] = l[i];
                i++;
            }
            else 
            {
                a[k] = r[j];
                j++;
            }
            k++;
        }
        //Adds the rest of the left array if any are leftover
        while (i < left) 
        {
            a[k] = l[i];
            i++;
            k++;
        }
        //Adds the rest of the right array if any are leftover
        while (j < right) 
        {
            a[k] = r[j];
            j++;
            k++;
        }
    }
}
