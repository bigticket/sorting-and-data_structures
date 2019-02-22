#include <iostream>
#include <vector>
#include <cstdlib>

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

int main()
{
  vector<int> tab;
  srand((unsigned)time(NULL));
  for(int i=0; i<1000; i++)
  {
    int b = rand() % 1000 + 1;
    tab.push_back(b);
  }
  cout << "before insertionsort:\n" << endl;
  for(unsigned int i =0; i<tab.size(); i++) cout<<tab[i]<<" ";
  cout << endl;
  insertionsort(tab, int(tab.size()));
  cout << "after insertionsort:\n" << endl;
  for(unsigned int i =0; i<tab.size(); i++) cout<<tab[i]<<" ";
  cout << endl;
}
