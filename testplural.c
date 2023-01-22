#include <stdio.h>
#include <cs50.h>
#include <strings.h>


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
    candidate candidates[argc - 1];
    for (int i = 0; i < argc - 1; i++)
    {
        candidates[i].votes = 0;
    }

    int voters = get_int("Number of voters: ");
    printf("\n");

    for (int i = 0; i < voters; i++)
    {
        string vote = get_string("Vote: ");
        for(int j = 1; j < argc; j++)
        {
            if(strcasecmp(vote, argv[j]) == 0)
            {
                candidates[j].votes++;
            }
        }
        printf("\n");
    }
    // shold I declare its size than assign 1 values first ?
    candidate winner;
    winner = candidates[0];

    for (int i = 0; i < argc - 1; i++)
    {
        if(candidates[i + 1].votes > winner.votes)
        {
            winner.name = candidates[i + 1].name;
        }
    }

    printf("%s\n", winner.name);
    return 0;
}
/*
for each vote , assign +1 to candidates.votes[i]
being i = argv[defined]
strcasecmp(vote, candidates.name)*/