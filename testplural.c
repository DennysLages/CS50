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
    const int CANDIDATE_COUNT = argc - 1;
    candidate candidates[CANDIDATE_COUNT];

    for (int i = 0; i < CANDIDATE_COUNT; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    //2. Get # of voters & validate input
    int voters = get_positive_int("Number of voters: ");

    //3. Assign votes to each candidate
    for (int i = 0; i < voters; i++)
    {
        string single_vote = \0;
        if (single_vote )

        string single_vote = get_valid_vote(CANDIDATE_COUNT, "Vote: ");
        for(int j = 0; j < CANDIDATE_COUNT; j++)
        {
            if(strcasecmp(single_vote, candidates[j].name) == 0)
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

string get_valid_vote(int qty, string phrase)
{
    string valid_vote = '\0';
    int check = 0;
    do
    {
        for (int i = 0; i < qty; i++)
        {
            if(
            {

            }
                valid_vote = get_string("%s", phrase);
        }
    }
    while(val< 1);

    return valid_vote;
}
/*
1. for each vote , assign +1 to candidates.votes[i]
being i = argv[defined]
strcasecmp(vote, candidates.name)

2. Check vote if matches candidates
do
check for vote input
if vote == candidade[0].name
do sum 1 & check = 1;
while check = 0 >> check again for input
*/