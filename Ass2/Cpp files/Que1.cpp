#include<bits/stdc++.h>
using namespace std;

 int random(int a,int b)
{
    return rand()%b;

}

int main()
{
     ofstream fout;
     fout.open("Que1.txt");

      int n=random(1,100);

     int i=1;
     while(i<=n)
   {
       int n1=random(1,100);
        string s="T"+to_string(i);

     int j=1;
     while(j<=n1)
       {
        s=s+" i"+to_string(j);
        j++;
       }
       fout<<s;
       fout<<endl;
       i++;
   }

   fout.close();

          return 0;
}

