
#include <bits/stdc++.h>
using namespace std;


int main()
{
     string line;
     ifstream fin;

    // by default open mode = ios::in mode
    fin.open("Q1.txt");


    map<char,string>mp;
    string st2="";

   // Execute a loop until EOF (End of File)
    while (fin) {

    getline(fin, line);
        string st="";
        st=st+line[0]+line[1];


         for(int i=3;i<line.size();i++)
            {
                if(line[i]==' ')
                continue;
                else
                {char cr=line[i];

                string str=" "+mp[cr];
                mp[cr]=st+str;}
            }


    }


    fin.close();

     ofstream fout;
     string str;

    fout.open("Q4.txt");

    map<char,string>::iterator it;
    for(it = mp.begin();it!=mp.end();it++)
        {cout<<it->first<<" "<<it->second<<endl;
        fout<<it->first<<" "<<it->second<<endl;}
        fout.close();

    return 0;
}
