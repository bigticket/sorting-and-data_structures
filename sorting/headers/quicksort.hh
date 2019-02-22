#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int>& tab, int l, int r)
{
  int pivot = tab[r];
  int i = (l-1);
  for (int j=l; j<=r-1;j++)
  {
    if (tab[j] <= pivot)
    {
      i++;
      swap(tab[i], tab[j]);
    }
  }
  swap(tab[i+1], tab[r]);
  return (i+1);
}

void quicksort(vector<int>& tab, int l, int r)
{
  if (l < r)
  {
    int pi = partition(tab, l, r);
    quicksort(tab, l, pi-1);
    quicksort(tab, pi+1, r);
  }
}
