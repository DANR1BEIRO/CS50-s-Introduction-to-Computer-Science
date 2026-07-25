#include <stdio.h>
#include <cs50.h>
#include <string.h>

#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

typedef struct
{
    string name;
    int votes;
    bool eliminated;
} candidate;

bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(void);
void eliminate(int min);

candidate candidates[MAX_CANDIDATES];
int preferences[MAX_VOTERS][MAX_CANDIDATES];

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: ./ runoff [candidate...]");
        return 1;
    }
}

bool vote(int voter, int rank, string name)
{
    int lenght = sizeof(candidates) / sizeof(candidates[0]);
    for (size_t i = 0; i < lenght; i++)
    {
        if (strcmp(name, candidates[i].name) != 0)
        {
            return false;
        }
    }
}
