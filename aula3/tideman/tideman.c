#include <stdio.h>
#include <cs50.h>
#include <strings.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2]; //C(Candidates) 2 by 2 = C!/((C-2)!*2!)

int pair_count;
int candidate_count;

//0. Variables added by ME to be used on lock_pairs & print_winner
bool candidate_lost[MAX]; //To keep track who has lost

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
} // END OF MAIN FUNCTION

// 1. Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcasecmp(name, candidates[i]) == 0)
        {
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

// 2. Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // Look 1by1 on ranks[] twice (k & l), when meets searched candidate (i & j), add to correspond matrix[i][j] preferences
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
    return;
}

// 3. Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    //Get number of pairs depending #cand 2 by 2
    pair_count = 0;

    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i; j < candidate_count; j++)
        {
            if (preferences[i][j] > preferences[j][i])
            {
                        pairs[pair_count].winner = i;
                        pairs[pair_count].loser = j;
                        pair_count++;
            }
            else if (preferences[i][j] < preferences[j][i])
            {
                        pairs[pair_count].winner = j;
                        pairs[pair_count].loser = i;
                        pair_count++;
            }
        }
    }
    return;
}

// 4. Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    pair change[1];

    for (int i = 0; i < pair_count; i++)
    {
        //sort_pairs >> to get strengh of vote needs to look in preference, not pairs
        //pairs only gives you final outcome of who has more votes 2by2
        if ((preferences[pairs[i].winner][pairs[i].loser] - preferences[pairs[i].loser][pairs[i].winner]) < (preferences[pairs[i + 1].winner][pairs[i + 1].loser] - preferences[pairs[i + 1].loser][pairs[i + 1].winner]))
        {
            change[0] = pairs[i];
            pairs[i] = pairs[i + 1];
            pairs[i + 1] = change[0];
        }
    }
    return;
}

// 5. Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    for (int k = 0; k < pair_count; k++)
    {
        for (int i = 0; i < candidate_count; i++)
        {
            if (pairs[k].winner = i)
            {
                for (int j = 0; j < candidate_count; j++)
                {
                    if (pairs[k].loser == j)
                    {
                        if (!candidate_lost[j] && qty_losers < candidate_coutn - 1)
                    }
                }
            }
        }
    }
    //candidate_lost[candidate_count]; // 5.1 To keep track who has lost

    /*for (int i = 0; i < candidate_count; i++)
    {
        candidate_lost[i] = false;
    }

    for (int i = 0; i < pair_count; i++)
    {
        //int qty_losers; //To count how many has lost and stop before all lost
        int qty_losers = 0; // 5.2 To count how many has lost and stop before all lost
        for (int j = 0; j < candidate_count; j++)
        {
            if (qty_losers < candidate_count - 1)
            {
                if (!candidate_lost[pairs[i].loser])
                {
                    qty_losers++;
                }

                locked[pairs[i].winner][pairs[i].loser] = true;
                candidate_lost[pairs[i].loser] = true;
            }
        }*/
        /*bool closed_loop = false;
        for (int j = 0; j < candidate_count; j++) //maybe
        {*/
            /*if (candidate_lost[pairs[i].loser] == false && qty_losers < candidate_count - 1)
            {
                    locked[pairs[i].winner][pairs[i].loser] = true;
            }

            if (!candidate_lost[pairs[i].loser]) // 5.3 Will only enter here if it is 1st time losing
            {
                if (qty_losers < candidate_count - 1)
                {
                    candidate_lost[pairs[i].loser] = true;
                    qty_losers++;
                }
                else if (qty_losers == candidate_count - 1)
                {
                    i++;
                }
            }


            if (candidate_lost[pairs[i].loser])
            {
                locked[pairs[i].winner][pairs[i].loser] = true;
            }*/

            // check how many cand lost and input to qty_losers;

            //check in every pair if the loser cand. on this iteration pair has already lost (or haven`t), ie, locked[loser][j] become true
            //needs to be checked for all before change to true in i loop
            /*if(locked[pairs[i].loser][j]) //needs to add without creating any loop (meaning it returns true)
            {
                closed_loop = true;
            }*/

        /*}
        if (!closed_loop)
        {
            locked[pairs[i].winner][pairs[i].loser] = true;
        }*/
    } // Pensar melhor, como checar se o loop concluiu.
    // Não considerar como perdedor, se não houver mais nenhum invicto.
    // Olhar todos os candidatos, quando #loser for cand_count - 1, it is over.
    return;
}

// 6. Print the winner of the election
void print_winner(void)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidate_lost[i] == false)
        {
            printf("%s\n", candidates[i]);
        }
    }
    return;
}

