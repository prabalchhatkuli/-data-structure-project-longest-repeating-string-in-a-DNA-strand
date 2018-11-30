#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<algorithm>

using namespace std;

string makeSubstring (string MainStr, int start, int end)
{
   string substring;
   for(int i=start; i<end; i++)
   {
      substring+=MainStr[i];
   }
   return substring;
}


//funtion to find the longest the longest substring at the beginning of two strings
string LongestCommonPrefix(string str1, string str2)
{
   int length;
   //find which string is smaller and find its length
   if(str1.length()>str2.length())
   {
      length= str2.length();
   }
   else
   {
      length= str1.length();
   }
   
   //find the prefix string that is common in the two string
   for(int i = 0; i<length; i++)
   {
      if(str1[i] != str2[i])
      {
         return makeSubstring(str1, 0, i);
      }
   }
   return makeSubstring(str1, 0, length);
}

string FindLargestMaxString(string DNAstrand)
{
   //make a list of N elements where each element is a substring of the DNAstrand
   int N = DNAstrand.length();
   vector<string> suffixes(N);
   
   for(int i=0; i< N; i++)
   {
      suffixes[i]=makeSubstring(DNAstrand, i, N);
   }
   //sort them by utilizing <algorithm> 
   sort(suffixes.begin(),suffixes.end());

   //find the longest common prefix among them
   string lrs = "";
   for(int i=0; i< N-1; i++)
   {
      string x = LongestCommonPrefix(suffixes[i], suffixes[i+1]);
      if(x. length()>lrs.length())
      {
         lrs=x;
      }
   }
   return lrs;
}


int main()
{
   //variable declaration
   string filename;
   string DNAstrand;
   string DNAstrandTemp;
   //input the name of the file
   cout<<"Please enter the name of the file to";
   cout<<" find the longest string with the maximum characters:"<<endl;
   getline(cin, filename);

   //opening the file to read from
   //create read object
   ifstream input(filename.c_str());
   
   //if the file does not exits
   if(input.fail())
   {
      cout<< filename << "does not exit" << endl;
      cout<< "Exit Program" << endl;
      return 0;
   }

   //if the file exists
   
     while(!input.eof())
     {
        getline(input, DNAstrandTemp);
        DNAstrand+=DNAstrandTemp;
     }
   //display the longest repeating DNA strand
      cout<<endl<<"The string that appears the maximum number of times is:"<<endl;
      cout<<FindLargestMaxString(DNAstrand);

      cout<<endl;
   
   return 0;
}


