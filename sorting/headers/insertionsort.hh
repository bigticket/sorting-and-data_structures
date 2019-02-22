#include <iostream>
#include <vector>

using namespace std;

void insertionsort(vector<int>& tab, int n)
{
  int key, j;
  for(int i=1; i<n; ++i)
  {
    key = tab[i];
    for(j=i;j>0 && tab[j-1]>key;--j)
    {
      tab[j]=tab[j-1];
    }
    tab[j] = key;
  }
}
