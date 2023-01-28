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
int qty_losers; //To count how many has lost and stop before all lost

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
    //Need to go through each candidate and compare his position to next
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            // tenho que olhar dentro do resultado de ranks para saber se a posicao (i) será menor (acima no rank) e somar voto em preferencias 2 a 2.
            if (ranks[i] > ranks[j])
            {
                preferences[ranks[i]][ranks[j]]++;
            }
            else if (ranks[i] > ranks[j])
            {
                preferences[ranks[j]][ranks[i]]++;
            }
            else if (ranks[i] == ranks[j])
            {
                preferences[ranks[i]][ranks[j]] = 0;
            }
        }
    }
    return;

    if (i > j)
    {

    }

        //inside preferences loop
        for (int k = 0; k < candidates_count; k++)
        {
            if (candidate[i] == rank[k])
            {
                
            }
        }
}

// 3. Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    //Get number of pairs depending #cand 2 by 2
    pair_count = (candidate_count * (candidate_count - 1)) / 2;

    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if ((i != j) && (preferences[i][j] >= preferences[j][i]))
            {
                for (int k = 0; k < pair_count; k++)
                {
                        pairs[k].winner = i;
                        pairs[k].loser = j;
                        k = pair_count;
                }
            }
            else if ((i != j) && (preferences[i][j] < preferences[j][i]))
            {
                for (int k = 0; k < pair_count; k++)
                {
                        pairs[k].winner = j;
                        pairs[k].loser = i;
                        k = pair_count;
                }
            }
        }
    }
    return;
}

// 4. Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    pair change[1];

    for (int i = 0; i < pair_count - 1; i++)
    {
        if ((pairs[i].winner - pairs[i].loser) < (pairs[i + 1].winner - pairs[i + 1].loser))
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
    //candidate_lost[candidate_count]; // 5.1 To keep track who has lost
    qty_losers = 0; // 5.2 To count how many has lost and stop before all lost
    for (int i = 0; i < candidate_count; i++)
    {
        candidate_lost[i] = false;
    }

    for (int i = 0; i < pair_count; i++)
    {
        /*bool closed_loop = false;
        for (int j = 0; j < candidate_count; j++) //maybe
        {*/
            if (qty_losers < candidate_count)
            {
                if (!candidate_lost[pairs[i].loser]) // 5.3 Will only enter here if it is 1st time losing
                {
                    candidate_lost[pairs[i].loser] = true;
                    qty_losers++;
                }
            }
            if (candidate_lost[pairs[i].loser])
            {
            locked[pairs[i].winner][pairs[i].loser] = true;
            }

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

