Function record_preferences
//To record preferences checking by rank[] order
//Meaning Rank 1 cmp to rank 2, 3
//Rank 2 cmp rank 3
//Always recording on preferences[rank[i]][rank[j]]

for (int i = 0; i < candidate_count; i++)
{
    for (int j = 0; j < candidate_count; j++)
    {
        for (int k = 0; k < candidate_count; k++)
        {
            if (k == ranks[i])
            {

            }
        }
    }
}

i. candidate[k] (k)

1. Alice (0)
2. Charlie (2)
3. Bob (1)

i and j are to check inside ranks[]
k is to compare and return the position of candidate[i]or[j]


for (int i = 0; i < candidate_count; i++)
    {
        for (int k = 0; k < candidate_count; k++)
        {
            if (i == ranks[k]) //i meaning candidate[i]
            {
                for (int j = i; j < candidate_count; j++)
                {
                    for (int l = 0; l < candidate_count; l++)
                    {
                        if (j == ranks[l])
                        {
                            if (k < l)
                            {
                                preferences[i][j]++;
                            }
                            else if (l < k)
                            {
                                preferences[j][i]++;
                            }
                            else if (l == k)
                            {
                                preferences[i][j] = 0;
                            }
                        }
                    }
                }
            }
        }
    }

Function add_pairs
preferences[i][j] can be used
if winner - loser != 0 , record pair[i]{winner,loser}
loop i
loop j

if ((i != j) && ( ))

sort_pairs >> to get strengh of vote needs to look in preference, not pairs
pairs only gives you final outcome of who has more votes 2by2


Function lock_pairs
Go pairs by pairs locking true , cmp winner,loser.
Need to skip when finding last cand to lose

Look every pairs and lock loser.
if loser is false, check first if all others have lost already and skip 1