
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    vector<string> tmp = strs;
    vector<vector<string>> res;
    unordered_map < string, size_t > check;
    size_t index = 0;
    for (size_t i = 0; i < tmp.size(); i++)
    {
        string str = tmp[i];
        sort(str.begin(), str.end());
        if(check.find(str) == check.end()){
            check.emplace(str,index);
            res.push_back({});
            res[index].push_back(strs[i]);
            index++;
        }else{
            res[check[str]].push_back(strs[i]);   
        }
    }

    return res;
}

int main()
{
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    const auto& res = groupAnagrams(strs);
    for (size_t i = 0; i < res.size(); i++)
    {
        for (size_t j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << " " << endl;
        }
        cout << endl;
    }
    
}

