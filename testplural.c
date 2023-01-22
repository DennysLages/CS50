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

int get_positive_int(string phrase);
int validate_input(int argc);

int main(int argc, string argv[])
{
    //0. Validate input to receive at least 2 candidates
    if(validate_input(argc) != 0)
    {
        return 1;
    }

    //1. Create candidates profile with all names and assign start of 0 votes for everyone
    candidate candidates[argc - 1];
    for (int i = 0; i < argc - 1; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    //2. Get # of voters & validate input
    int voters = get_positive_int("Number of voters: ");

    //3. Assign votes to each candidate
    for (int i = 0; i < voters; i++)
    {
        string single_vote = get_valid_vote("Vote: ");
        for(int j = 1; j < argc; j++)
        {
            if(strcasecmp(single_vote, argv[j]) == 0)
            {
                candidates[j - 1].votes++;
            }
        }
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
    int n = 0;
    do
    {
        n = get_int("%s", phrase);
    }
    while(n < 1);

    return n;
}

int validate_input(int argc)
{
    if(argc < 3)
    {
        printf("Usage: ./plurality list of candidate names\n");
        return 1;
    }
    return 0;
}

string get_valid_vote(string phrase)
{
    string valid_vote = '\0';
    do
    {
        valid_vote = get_string("%s", phrase);
    }
    while(val< 1);

    return valid_vote;
}
/*
for each vote , assign +1 to candidates.votes[i]
being i = argv[defined]
strcasecmp(vote, candidates.name)*/