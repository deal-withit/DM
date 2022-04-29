#include<bits/stdc++.h>
using namespace std;

int main()
{      ifstream fin;
       string line;

    fin.open("Q1.txt");

   while (fin) {
  getline(fin, line);
  cout << line << endl;
    }

   fin.close();
   return 0;
}
