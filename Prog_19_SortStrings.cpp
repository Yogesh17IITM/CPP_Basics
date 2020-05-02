/*
Objective:
    Sort string lexicographically

Problem:
    There are list of string sets (in lower case) available with an 
    identifier (alpha-numeric) at the beginning of the each string sets. 
    You have to sort the string sets lexicographically.

Sample Input:
    {"ab1 pillow bed fan towel",
     "gh2 goat cow tiger lion",
     "h34 44 67 34 56",
     "yr1 love friend enemy brother"}

Sample Output:
    {"gh2 goat cow tiger lion",
     "yr1 love friend enemy brother"
     "ab1 pillow bed fan towel",
     "h34 44 67 34 56",
    }

Explanation:
    String are sorted out lexicographically (alphabetical order). 
    [G]oat < [L]ove < [P]illow
    Numerics should be kept at the last in the ascending order.
*/

// Std Libraries
#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<unordered_map>
#include<algorithm>

// Using directive
using namespace std;

// Function Prototype
vector<string> SortStringLexicographically(vector<string> & iStringSets);
bool compare(string x, string y);

// GlobalVariable
unordered_map<char, int> g_mapCharVal;  // global variable

/* Main Program */
int main()
{
    vector<string> StringSets{"ab1 pillow bed fan towel",
    "gh2 goat cow tiger lion",
    "h34 44 67 34 56",
    "yr1 love friend enemy brother"};

    vector<string> SortedStrings;
    SortedStrings = SortStringLexicographically(StringSets);

    for(auto iStr:SortedStrings)
        cout<<iStr<<endl;

    return 0;
}

/* Function definition */
vector<string> SortStringLexicographically(vector<string> & iStringSets)
{
    vector<string> oSortedString(iStringSets.size());
    unordered_map<string, string> umapKeyVal;

    // Separate Identifier and the string sets
    for(auto currStringSet:iStringSets)
    {
        stringstream strStream(currStringSet);
        string word;
        string StrID;
        string currStrVal;
        bool IsIdentifierFound = false;
        while(getline(strStream, word, ' '))
        {   
            if(!IsIdentifierFound)
            {
                IsIdentifierFound = true;          
                StrID = word;
            }
            else
            {
                currStrVal += ' ' + word;
            }
        }
        umapKeyVal[currStrVal] = StrID;
    }

    vector<string> sortStrSets;
    for(auto imapKeyVal:umapKeyVal)
        sortStrSets.push_back(imapKeyVal.first);

    // Set Preferred alphabetical order and map it to value of increasing order
    string preferredStrAlphaOrder = "abcdefghijklmnopqrstuvwxyz0123456789";
    for (int i = 0; i < preferredStrAlphaOrder.size(); i++)
    {
        g_mapCharVal[preferredStrAlphaOrder[i]] = i;
    }
    
    // Sort the string sets (using customized function 'compare()' for comparision)
    sort(sortStrSets.begin(), sortStrSets.end(), compare);

    // Add mapped identifier in the beginning against each sorted stringsets
    int temp=0;
    for(auto istr:sortStrSets)
    {
        oSortedString[temp] = umapKeyVal[istr] + istr;     
        temp++;
    }        

    return oSortedString;
}

// Method used for string comparision while sorting
bool compare(string x, string y)
{
    for(int i=0; i<min(x.size(), y.size()); ++i)
    {
        if(g_mapCharVal[x[i]] == g_mapCharVal[y[i]])
            continue;
        return g_mapCharVal[x[i]] < g_mapCharVal[y[i]];
    }
    return x.size() < y.size();
}

