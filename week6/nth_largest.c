int nth_largest(int _size, int _N, int* _arr)
{
    for(int i = _size; i > 0; i--)
    {
        for(int j = 0; j < i-1; j++)
        {
            if(_arr[j]>_arr[j+1])
            {
                int temp = _arr[j+1];
                _arr[j+1] = _arr[j];
                _arr[j] = temp;
            }
        }
    }
    return _arr[_size-_N];
}