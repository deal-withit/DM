#include<bits/stdc++.h>
using namespace std;

 int random(int a,int b)
{
    return rand()%b;

}

void subsetsUtil(vector<string>& A, vector<vector<string> >& res,
				vector<string>& subset, int index)
{
	res.push_back(subset);
	for (int i = index; i < A.size(); i++) {


		subset.push_back(A[i]);


		subsetsUtil(A, res, subset, i + 1);

		subset.pop_back();
	}

	return;
}

vector<vector<string> > subsets(vector<string>& A)
{
	vector<string> subset;
	vector<vector<string> > res;

	int index = 0;
	subsetsUtil(A, res, subset, index);

	return res;
}


int main()
{
     ofstream fout;
     fout.open("Que6.txt");

      int n=random(1,15);

     int i=1;
     while(i<=n)
   {
       int n1=random(1,15);
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


      ifstream fin;
       string line;

       unordered_map<string,int>um;

   fin.open("Que6.txt");

   while (fin) {
        getline(fin, line);

 int pos=line.find(" ");
 string sub = line.substr(pos + 1);


 	vector<string> array;
 	stringstream ss(sub);
 	string stri="";
 	while(ss>>stri)
 	array.push_back(stri);


	vector<vector<string> > res = subsets(array);


		for (int i = 0; i < res.size(); i++) {
		string st="";
		for (int j = 0; j < res[i].size(); j++)
         {
           st=st+res[i][j]+" ";
         }

          if(st!="")
          um[st]++;

}


    }


   fin.close();



   fout.open("Que6.txt");
// Minimum support is 30% of Transition database
    int minimum_support=0.3*n;

    for(auto pr:um)
        if(pr.second>=minimum_support)
        {cout<<pr.first<<endl;
        fout<<pr.first<<endl;}


        fout.close();


          return 0;
}

