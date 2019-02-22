#include <iostream>
#include <vector>
#include <cstdlib>

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

int main()
{
  vector<int> tab;
  srand((unsigned)time(NULL));
  for(int i=0; i<1000; i++)
  {
    int b = rand() % 1000 + 1;
    tab.push_back(b);
  }
  cout << "before quicksort:\n" << endl;
  for(unsigned int i =0; i<tab.size(); i++) cout<<tab[i]<<" ";
  cout << endl;
  quicksort(tab, 0, int(tab.size())-1);
  cout << "after quicksort:\n" << endl;
  for(unsigned int i =0; i<tab.size(); i++) cout<<tab[i]<<" ";
  cout << endl;
}
