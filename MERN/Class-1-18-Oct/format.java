public class Solution {
    public ArrayList<Integer> solve(ArrayList<Integer> arr, int left, int right) {
        ArrayList<Integer> ans = new ArrayList<>();
        int n = arr.size();
        for(int i=left; i<=right;i++){
            ans.add(arr.get(i));
        }
        return ans;
    }
}
