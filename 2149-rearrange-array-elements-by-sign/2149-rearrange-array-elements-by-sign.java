class Solution {
    public int[] rearrangeArray(int[] arr) {
     //  vector<int>pos,neg,ans;
     ArrayList<Integer>pos=new ArrayList<>();
     ArrayList<Integer>neg=new ArrayList<>();
     ArrayList<Integer>ans=new ArrayList<>();


        int n=arr.length;
        for(int i=0; i<n; i++){
            if(arr[i]>0) pos.add(arr[i]);
            else neg.add(arr[i]);
        }
        int i=0;
        int j=0;
        while(i<pos.size() && j<neg.size()){
            ans.add(pos.get(i++));
            ans.add(neg.get(j++));
        }
        //if still elements are rem then push back
        if(i<pos.size()) ans.add(pos.get(i++));
        if(j<neg.size()) ans.add(neg.get(j++));
//convert arraylist into int[]
        int[] result = new int[ans.size()];

        for(int k = 0; k < ans.size(); k++) {
            result[k] = ans.get(k);
        }

        return result;
    }
}