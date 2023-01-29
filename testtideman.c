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
if loser is false, check first if all others have lost already and skip 1 and did not lock true


1o pair >>

Rodar tds os candidate_lost e checar se tem +2 em disputa (false).
Se tiver
pairs[i].loser >> true
candidate_lost[pairs[i].loser] = true

Se n tiver (tem apenas 1 em disputa (true))
i++; (Go to next pairs)

Locked trava o pairs, não o loser

Go through each pairs, locked [i][j] (there will be pairs that do not exist)
check if there is a pair for this match locked[i][j]

loop k
loop i
if pairs[k].winner == i
{
loop j
if pairs[k].loser == j
{
    if (!candidate_lost[j] && qty_losers < candidate_count - 1)
    {
        candidade_lost[pairs[i].loser] = true
        qty_losers++;
    }

    if (candidate_lost[j]) //can be done after checking and converting candidate_lost to true
    {
        locked[i][j] = true;
    }
    quero locked mas 1o confirmar se n é o último lost ou se candidate_lost pode ser transformado em true
    * quero lost = true mas 1o confirmar se n é o último lost
    quero que locked possa ser feito sem que obrigatório o lost estar false
}
}
check if candidade_lost[pairs[i].loser] is true
if no,
locked pairs & make candidade_lost[pairs[i].loser] true

if yes,

