#include <bits/stdc++.h>
using namespace std;

int main()
{     ifstream fin;
       string line;

    // by default open mode = ios::in mode
    fin.open("Q1.txt");


    map<char,int>mp;

    while (fin) {
    getline(fin, line);

         for(int i=3;i<line.size();i++)
            {
                if(line[i]==' ')
                continue;
                else
                {char cr=line[i];
                mp[cr]++;}
            }


    }

    fin.close();

     ofstream fout;
     string str;

    fout.open("Q3.txt");

    map<char,int>::iterator it;
    for(it =mp.begin();it!=mp.end();it++)
        {cout<<it->first<<" "<<it->second<<endl;
        fout<<it->first<<" "<<it->second<<endl;}
        fout.close();

    return 0;
}
