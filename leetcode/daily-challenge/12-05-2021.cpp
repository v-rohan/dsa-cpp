class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        //return 0;
        int size = cardPoints.size();
        int i;
        vector<int>score(size, 0);
        score[0]=cardPoints[0];
        for(i=1;i<size;i++)
            score[i] = cardPoints[i]+score[i-1];
        int sum;
        if(k==size)return score[size-1];
        i=k-1;
        int j= size;
        int max_sum= score[k-1];
        for(int i=1; i<k; i++){
            max_sum=max(max_sum, score[size-1]-score[size-1-i]+score[k-1-i]);
        }
        max_sum=max(max_sum,score[size-1]-score[size-k-1]);
        return max_sum;
        
    }
};