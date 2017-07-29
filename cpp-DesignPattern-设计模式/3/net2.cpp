
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

/*void functimetoolong(map<string ,string>& table,vector<string> line16)
{
    int ans=0;
    std::sort(line16.begin(),line16.end());
    map<vector<string>,int> visited;
    while (next_permutation(line16.begin(),line16.end()))
    {
        if(visited[line16]==1)
            break;
        else
        {
            visited[line16]=1;
            for(int i=0;i<line16.size();i+=2)
            {
                string area1=line16[i].substr(3,2);
                string area2=line16[i+1].substr(3,2);
                if(area1==area2)
                    break;

                char numth1=line16[i][1];
                char numth2=line16[i+1][1];
                if(numth1==numth2 )
                    break;
                char group1=line16[i][0];
                char group2=line16[i+1][0];
                if(group1==group2 )
                    break;

                ++ans;
                cout<<"ok: ";
                for(auto it:line16)
                    cout<<it<<" .";
                cout<<endl;
            }
        }
    }
    cout<<ans<<endl;
}*/

int ans=0;
void func(vector<string>& line16)
{
    if(line16.empty())
        ++ans;
    string last=line16.back();
    if(last.empty())
        return;
    line16.pop_back();
    string area1=last.substr(3,2);
    char numth1=last[1];
    char group1=last[0];

    for (int i = 0; i < line16.size(); ++i) {
        string last2=line16[i];
        if(last.empty())
            return;
        string area2=last2.substr(3,2);
        char numth2=last2[1];
        char group2=last2[0];
        if(area1!=area2 && numth1!=numth2 && group1!=group2)
        {
            line16.erase(line16.begin()+i);
            func(line16);
            if(!last2.empty())
            line16.push_back(last2);
        }
    }
    if(!last.empty())
    line16.push_back(last);


}

int main()
{
    int T=0,t=0;
    cin>>T;
    string line;
    vector<string> line16;
    getline(cin,line);
    while ( getline(cin,line) )
    {
        //cout<<line<<endl;
        if(line16.size()==16)
        {
            ++t;
            std::sort(line16.begin(),line16.end());
            ans=0;
            func(line16);

            cout<<ans<<endl;

            if(t==T)
                break;
            line16.clear();
            getline(cin,line);

        }

        line16.push_back(line);

    }

}