#include <bits/stdc++.h>
using namespace std;

int main()
{
       ifstream fin;
       string line;


   fin.open("Que1.txt");

   unordered_map<string,int>um;

   while (fin) {
        getline(fin, line);

 int pos=line.find(" ");
 string sub = line.substr(pos + 1);

stringstream ss(sub);
string stri;
 while(ss>>stri)
    um[stri]++;

  }

    fin.close();

     ofstream fout;
     string str;

    fout.open("Que3.txt");


      for(auto pr:um)
        {cout<<pr.first<<" "<<pr.second<<endl;
        fout<<pr.first<<" "<<pr.second<<endl;}

        fout.close();



    return 0;
}
