#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define endl                            '\n'
#define PI                              3.14159265358979323846

const ll   N                            = (ll) 1e6+5;
const ll   MOD                          = (ll) 1e9+7;
const ll   Modulo                       = (ll) 998244353;

// ================================== take ip/op like vector,pairs directly!==================================
template<typename typC,typename typD> istream &operator>>(istream &cin,pair<typC,typD> &a)
{
    return cin>>a.first>>a.second;
}
template<typename typC> istream &operator>>(istream &cin,vector<typC> &a)
{
    for (auto &x:a) cin>>x;
    return cin;
}
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const pair<typC,typD> &a)
{
    return cout<<a.first<<' '<<a.second;
}
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const vector<pair<typC,typD>> &a)
{
    for (auto &x:a) cout<<x<<'\n';
    return cout;
}
template<typename typC> ostream &operator<<(ostream &cout,const vector<typC> &a)
{
    int n=a.size();
    if (!n) return cout;
    cout<<a[0];
    for (int i=1; i<n; i++) cout<<' '<<a[i];
    return cout;
}
// ===================================END Of the input module ================================================
ll GCD(ll a, ll b)
{
    return (a) ? GCD(b % a, a) : b;
}
ll LCM(ll a, ll b)
{
    return a * b / GCD(a, b);
}
void Solve()
{


    map <string, ll> Elizabeths_grandchildren, Dianas_brother_in_law, Zaras_great_grandparents, Eugenies_ancestors;

    Elizabeths_grandchildren["William"]++;
    Elizabeths_grandchildren["Harry"]++;
    Elizabeths_grandchildren["Peter"]++;
    Elizabeths_grandchildren["Beatrice"]++;
    Elizabeths_grandchildren["Eugenie"]++;
    Elizabeths_grandchildren["Louise"]++;
    Elizabeths_grandchildren["James"]++;

    Dianas_brother_in_law["Charles"]++;
    Dianas_brother_in_law["Anne"]++;
    Dianas_brother_in_law["Andrew"]++;
    Dianas_brother_in_law["Edward"]++;



    Zaras_great_grandparents["George"]++;
    Zaras_great_grandparents["Mum"]++;

    Eugenies_ancestors["Andrew"]++;
    Eugenies_ancestors["Sarah"]++;
    Eugenies_ancestors["Elizabeth"]++;
    Eugenies_ancestors["Philip"]++;
    Eugenies_ancestors["George"]++;
    Eugenies_ancestors["Mum"]++;

    cout << "Your Query = ";
    string Query;
    cin >> Query;


    cout << endl;
    cout << "Here is your desire output for \"" << Query << "\" Query: " << endl;

    if(Query == "Elizabeths_grandchildren")
    {
        for(auto x : Elizabeths_grandchildren)
        {
            cout << x.first << endl;
        }
    }

    else if(Query == "Dianas_brother_in_law")
    {
        for(auto x : Dianas_brother_in_law)
            cout << x.first << endl;
    }
    else if(Query == "Zaras_great_grandparents")
    {
        for(auto x : Zaras_great_grandparents)
            cout << x.first << endl;
    }
    else
    {
        if(Query == "Eugenies_ancestors")
        {
            for(auto x : Eugenies_ancestors)
                cout << x .first << endl;
        }
        else
        {
            cout << "Sorry, at current time there is no data in my dataset, I have to update my full data!" << endl;
        }
    }
    cout << endl;
}

int main()
{
    // codeid: brainsoft
    //ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    ll Testcase = 1;
    cout << "TestCase = ";
    cin >> Testcase;

    for(ll TestCase = 1; TestCase <= Testcase; TestCase++)
    {
        //cout << "Case " << TestCase << ": ";
        Solve();
    }
    return 0;
}
