class Solution{
    public:
    int max(int a, int b){
        if(a>b) return a;
        else return b;
    }
    
    long long trappingWater(int arr[], int n){
        long long left[n];
        long long right[n];
        
        left[0]=arr[0];
        for(int i=1;i<n;i++){
            left[i]= max(arr[i],left[i-1]); 
        }
        
        right[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--){
            right[i]=max(arr[i], right[i+1]);
        }
        
        long long ans=0;
        
        for(int i=1;i<n-1;i++){
            long long water= min(left[i-1],right[i+1]);
            if(water>arr[i]){
                ans+=  water- arr[i];
            }
        }
        
        return ans;
    }
};
