// given a currency with sets of coins 
// this program sovles the problem to get minimam number of coins to
// given about of cent or money
// for example given 76 sents we can set 1,25,50 coins to represent or less than that
// the problem uses daynamic programing


#include <vector>
int max_lessThan(int value,const vector<int> &vec);

//min bsed on daynamic vector
int min_for_cent(const vector<int> &coins,const vector<int> &knownCents,int cent)
{
    int minCoins = cent;
    for(int i = 0; i<coins.size(); i++)
    {
        if(cent < coins[i])
            continue;
        if( knownCents[cent - coins[i]] +1<minCoins)
            minCoins = knownCents[cent - coins[i]] +1;
    }
    return minCoins;
}


int min_dynamic(const vector<int> &coins,int change)
{
    vector<int> knownCents;
    knownCents.resize(change + 1);//cent-index
    knownCents[0] = 0; // useless cent
    
    for(int cent = 1;cent <= change;cent++) 
    {
        knownCents[cent]=min_for_cent(coins,knownCents,cent);
    }

    return knownCents[change];
}



int min_recursive(const vector<int> &coins, int change)
{

    int minCoin = change;
    for(int i=0;i<coins.size();i++)
    {
        if(change == coins[i])
            return 1;
    }


    for(int i = 1;i < coins.size()&&change>coins[i]; i++)
    {
        if(change - coins[i]<0)
           continue; 
        int thisCoin = 1 + min_recursive(coins,change-coins[i]);
    
        if(thisCoin < minCoin)
            minCoin = thisCoin;
    }


    return minCoin;
}

int min_greedy(const vector<int> &coins,int change)
{
    int minCoins = 0; 

    while(change >0)
    {
        int largest = max_lessThan(change,coins);
        if(largest != 0)
        { 
            minCoins++;
            change -= largest;
        }
    }

    return minCoins;
}

int max_lessThan(int value,const vector<int> &vec)
{
    // will return zero if it find none
    int largest = 0;
    for(int i = 0 ;i<vec.size();i++)
    {
        if(vec[i] > largest && vec[i] <= value)
            largest = vec[i];
    }

    return largest;
}
