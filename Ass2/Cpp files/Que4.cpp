#include <bits/stdc++.h>
using namespace std;

int main()
{
     ifstream fin;
       string line;


   fin.open("Que1.txt");

   unordered_map<string,string> um;

   while (fin) {
        getline(fin, line);

 int pos=line.find(" ");
 string temp="";
 for(int i=0;i<pos;i++)
    temp=temp+line[i];

 string sub = line.substr(pos + 1);

stringstream ss(sub);
string stri;
 while(ss>>stri)
    um[stri]=um[stri]+" "+temp;

 }

    fin.close();

     ofstream fout;
     string str;

    fout.open("Que4.txt");


      for(auto pr:um)
        {cout<<pr.first<<" "<<pr.second<<endl;
        fout<<pr.first<<" "<<pr.second<<endl;}

        fout.close();



    return 0;
}
