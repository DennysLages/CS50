#include <stdio.h>
#include <cs50.h>
#include <strings.h>


//single_vote >> string each vote
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

int get_positive_int(void);

int main(int argc, string argv[])
{
    //1. Create candidates profile and assign start of 0 votes for everyone
    candidate candidates[argc - 1];
    for (int i = 0; i < argc - 1; i++)
    {
        candidates[i].votes = 0;
    }

    //2. Get # of voters & validate input
    int voters = get_positive_int("Number of voters: ");
    printf("\n");

    //3. Assign votes to each candidate
    for (int i = 0; i < voters; i++)
    {
        string single_vote = get_string("Vote: ");
        for(int j = 1; j < argc; j++)
        {
            if(strcasecmp(single_vote, argv[j]) == 0)
            {
                candidates[j].votes++;
            }
        }
        printf("\n");
    }

    //4. Find highest # of votes and return winner candidate
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

int get_positive_int(string phrase)
{
    do
    {
        n = get_int("%s\n", phrase);
    }
    while(n < 1);

    return n;
}
/*
for each vote , assign +1 to candidates.votes[i]
being i = argv[defined]
strcasecmp(vote, candidates.name)*/