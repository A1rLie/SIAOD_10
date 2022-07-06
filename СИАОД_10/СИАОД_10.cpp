#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <time.h>

using namespace std;

void fillPreSu(string subline, vector<int>& pi)
{

    pi[0] = 0;
    int i = 1, j = 0;
    for ( ; i < subline.size();)
    {
        if (subline[i] == subline[j])
        {
            pi[i] = j + 1;
            i++;
            j++;
        }
        else if (j == 0)
        {
            pi[i] = 0;
            i++;
        }
        else
        {
            j = pi[j - 1]; 
        }
    }
}

int KMP(string line, string subline, vector<int> pi)
{
    if (line == "") return -1;
    int i = 0, j = 0;
    
    for (;;)
    {
        if (line[i] == subline[j])
        { 
           
            j++;
            i++;
            if (j == subline.size() - 1) return i - 1;
        }
        else
        {
            if (j == 0)
            {
                i++;
                if (i >= line.size() - 1) return -1;
            }
            else j = pi[j - 1];
        }
    }
}

//string minLine(string line, string subline)
//{
//    string newSubLine;
//    for (int i = 0; i < subline.size(); i++)
//    {
//        for (int j = i + 1; j <= subline.size(); j++)
//        {
//            newSubLine = subline.substr(i, j - i);
//            int firstIndex = KMP(line, newSubLine);
//            int secondIndex = firstIndex + newSubLine.size() + KMP(line.substr(firstIndex + newSubLine.size()), newSubLine);
//            if (secondIndex - firstIndex == newSubLine.size() && firstIndex == 0)  return to_string(newSubLine.size());
//        }
//    }
//    return to_string(subline.size()) + "<"; //Возврат того, что минимальный размер строки больше размера переданной подстроки
//}

bool isCorrect(string line, regex regular)
{
    cmatch result;
    if (!regex_search(line.c_str(), result, regular))
    {
        for (int i = 0; i < result.size(); i++)
        {
            cout << result[i] << " ";
        }
        return true;
    }
    else
    {
        for (int i = 0; i < result.size(); i++)
        {
            cout << result[i] << " ";
        }
        return false;
    }
}

int main()
{

    string line;
   /* cin >> line;

    string subline;
    cin >> subline;*/
    
    //Задание №2
    regex regular("\\W|_");
    cmatch result;
    getline(cin, line);
    cout << isCorrect(line, regular);

}
