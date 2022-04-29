#include<bits/stdc++.h>
using namespace std;

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


      ifstream fin;
       string line;

       unordered_map<string,int>um;

   fin.open("Q1.txt");

   while (fin) {
        getline(fin, line);

 int pos=line.find(" ");
 string sub = line.substr(pos + 1);

 ///////////
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

  // Minimum support is 2 for Assignment 1 dataset
    int minimum_support=2;

    ofstream fout;
     fout.open("Que5.txt");

       for(auto pr:um)
        if(pr.second>=minimum_support)
        {cout<<pr.first<<endl;
        fout<<pr.first<<endl;}

         fout.close();

          return 0;
}

