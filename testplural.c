#include <stdio.h>
#include <cs50.h>


//vote >> string each vote
//voters >> int # of voters
//votes >> string # of votes to each candidate
//candidate >> type of variable
//candidates >> string w/ single candidates

typedef struct
{
    string name;
    int votes;
}
candidate;

int main(int argc, string argv[])
{
    candidate candidates[argc];

    int voters = get_int("Number of voters: \n");

    for (i = 0; i < voters; i++)
    {
        string vote = get_string("Vote: ");
        for(j = 1, j < argc, j++)
        {
            if(strcasecmp(vote,argv[j]) == 0)
            {
                candidates.votes++;
            }
        }
        printf("\n");
    }
}

for each vote , assign +1 to candidates.votes[i]
being i = argv[defined]
strcasecmp(vote, candidates.name)