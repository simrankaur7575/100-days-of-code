/*
QUES - You are given with an array of 1s and 0s. And you are given with an integer M, which signifies number of flips allowed.
Find the position of zeros which when flipped will produce maximum continuous series of 1s.

For this problem, return the indices of maximum continuous series of 1s in order.


*/
vector<int> Solution::maxone(vector<int> &A, int B) {
    int l=0,r=0;

    int max=0,count=0;
    int wl,wr;
    wl=wr=0;
    int flag =0;
    while(wr<A.size())
    {
        if(A[wr] == 0)
        {
            count++;
        }

        if(count > B)
        {
            if(A[wl] == 0){
                count--;
            }
            wl++;
        }

        if(wr-wl+1 > max)
        {
            max=wr-wl+1;
            r=wr;
            l=wl;
            flag=1;
        }
        wr++;
    }
    vector<int> v(max);
    if(flag == 1)
    {
    for(int i=l;i<=r;i++)
    {
        v[i-l] = i;
    }
    }
    return v;
}