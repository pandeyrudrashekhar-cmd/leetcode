class Solution {
    public void sortColors(int[] arr) {
        int n=arr.length;
        int low=0;
        int mid=0;
        int high=n-1;
        while(mid<=high){
            if(arr[mid]==0){
               // swap(arr[low],arr[mid]);
               int temp=arr[low];
               arr[low]=arr[mid];
               arr[mid]=temp;
                low++;
                mid++;
            }
            else if(arr[mid]==1) mid++;
            else{
                //swap(arr[mid],arr[high]);
                int temp=arr[mid];
                arr[mid]=arr[high];
                arr[high]=temp;


                high--;
            }
        }
    }
}