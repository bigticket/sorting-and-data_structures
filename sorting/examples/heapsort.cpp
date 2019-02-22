#include <iostream>
#include <vector>
#include <cstdlib>

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


int main()
{
  vector<int> tab;
  srand((unsigned)time(NULL));
  for(int i=0; i<1000; i++)
  {
    int b = rand() % 1000 + 1;
    tab.push_back(b);
  }
  cout << "before heapsort:\n" << endl;
  for(unsigned int i =0; i<tab.size(); i++) cout<<tab[i]<<" ";
  cout << endl;
  heapsort(tab, int(tab.size()));
  cout << "after heapsort:\n" << endl;
  for(unsigned int i =0; i<tab.size(); i++) cout<<tab[i]<<" ";
  cout << endl;
}
