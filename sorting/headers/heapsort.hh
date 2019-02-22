#include <iostream>
#include <vector>

using namespace std;

void heapify(vector<int>& tab, int n, int i)
{
  int largest = i;
  int l = 2*i +1;
  int r = 2*i +2;

  if (l<n && tab[l] > tab[largest]) largest = l;

  if (r<n && tab[r] > tab[largest]) largest = r;

  if (largest != i)
  {
    swap(tab[i], tab[largest]);
    heapify(tab, n, largest);
  }
}

void heapsort(vector<int>& tab, int n)
{
  for (int i = n/2 -1; i >= 0; i--) heapify(tab, n, i);

  for (int i = n-1; i >= 0; i--)
  {
    swap(tab[0], tab[i]);
    heapify(tab, i, 0);
  }
}
