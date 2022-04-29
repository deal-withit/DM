#include<bits/stdc++.h>
using namespace std;

int main()
{  // Creation of ofstream class object
    ofstream fout;
    string line;

    fout.open("Q1.txt");
    int n;
    // I am taking total transitions from user
    cout<<"Enter total Transitions : ";
    cin>>n;
    cin.ignore();

    while (n--) {

            getline(cin, line);
            fout << line << endl;
    }
          fout.close();
          return 0;
}
