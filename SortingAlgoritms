// diffrent algoritms to sort an array 

#include <vector>

void print_array(const vector<int> &array)
{
    for(int i=0;i<array.size();i++)
        cout<<array[i]<<" ";
    cout<<endl;
}

//driver 
void merge(const vector<int> &a,vector<int> &sorted,int left,int center,int right)
{
    


}
vector<int> merge_sort(const vector<int> &a)
{
   vector<int> sorted(a.size());
   merge_sort(a,sorted,0,a.size()-1);
   return sorted;
}

   
vector<int> insertion_sort(vector<int> array)
{
    for(int p = 1; p<array.size(); p++)
    {
        int temp = array[p];
        int i;
        for(i=p; temp < array[i-1] && i>0 ; i--) 
            array[i] = array [i-1];
        array[i] = temp; 

    }
    return array;
}


void insertion_gaps(vector<int> &array,int gaps)
{
    for(int p = gaps; p< array.size(); p++)
    {

        int i;
        int temp = array[p];
        for(i = p; i>=gaps &&temp<array[i-gaps];i-=gaps)
            array[i] = array[i-gaps];
        array[i] = temp;
    }

}

vector<int> shellsort(vector<int> array)
{
    for(int gap = array.size()/2; gap>0;gap--) 
    {
        gap = gap == 2? 1: static_cast<int>(gap/2.2);
        insertion_gaps(array,gap);
    }
    return array;
}
// use less
// I don't think this code works
vector<int> linear_merge(const vector<int> &a,const vector<int> &b)
{
    vector<int> c; 
    int i = 0;int j = 0;
    for(;i<a.size() && j<b.size();)
    {
        if(a[i] > b[j])
            c.push_back(b[j++]);
        else
            c.push_back(a[i++]);
    }
    for(; i<a.size();i++)
        c.push_back(a[i]);
    for(; j<b.size();j++)
        c.push_back(b[j]);
    return c;
}
