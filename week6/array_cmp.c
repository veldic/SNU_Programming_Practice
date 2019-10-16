int array_cmp(int num, int *A, int *B)
{
    for(int i = 0; i < num; i++)
    {
        if(A[i] == B[i]) continue;
        else if(A[i]>B[i]) return 1;
        else return -1;
    }
    return 0;
}