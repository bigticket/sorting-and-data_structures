#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>&tab, int l, int m, int r)
{
    int size = r - l + 1;
    vector<int> container(size);
    int i=l, j=m+1, k=0;
    while(i < m+1 && j < r+1)
    {
      if(tab[i] <= tab[j])
      {
        container[k] = tab[i]; i++;
      }
      else
      {
        container[k] = tab[j]; j++;
      }
      k++;
    }
    while(i < m+1)
      {
        container[k] = tab[i];
        i++; k++;
      }
    while(j < r+1)
      {
        container[k] = tab[j];
        j++; k++;
      }
    k=0;
    for(i=l; i<r+1; i++)
    {
      tab[i] = container[k]; k++;
    }
}

void mergesort(vector<int>& tab, int l, int r)
{
  if(l < r)
  {
    int m = (l+r)/2;
    mergesort(tab, l, m);
    mergesort(tab, m+1, r);
    merge(tab, l, m, r);
  }
}
