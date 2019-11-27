//In the file you can find the best grossing movies in the format: [Title] [Profit] [Release date]

//Make a function that reads the data and returns a pointer to the data and the size. The function should not use more memory than necessary.
//Print the summed profit grouped by year
//Which was the most successful year in the movie industry?

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 100

typedef struct Movie {
    char*           title;
    unsigned long   profit;
    int             year_released;
} movie_t;

typedef struct Year {
    int             year;
    unsigned long   profit;
} year_t;

int           count_lines(char* filename);
unsigned long parse_profit(const char* profit_string);
int           find_best_year(movie_t* movies, int number_of_movies);

int main()
{
    char*   file_path = "../movies.txt";
    FILE*   fptr;
    int     number_of_movies = count_lines(file_path);
    movie_t movies[number_of_movies];
    char    buffer[BUFFER_SIZE];
    char*   word;
    int     row_index = 0;

    if (!(fptr = fopen(file_path, "r"))) return -1;

    while (fgets(buffer, BUFFER_SIZE, fptr))
    {
        word = strtok(buffer, "$");
        movies[row_index].title = word;

        word = strtok(NULL, " ");
        movies[row_index].profit = parse_profit(word);
        printf("%lu\n", movies[row_index].profit);

        word = strtok(NULL, "\n");
        movies[row_index].year_released = atoi(word);

        row_index++;
    }

    printf("%d", find_best_year(movies,number_of_movies));
    return 0;
}


int count_lines(char* filename)
{
    FILE* fptr;
    if (!(fptr = fopen(filename, "r"))) return -1;
    int i = 0;
    char buffer[BUFFER_SIZE];
    while(fgets(buffer, BUFFER_SIZE, fptr)){
        i++;
    }
    fclose(fptr);
    return i;
}

unsigned long parse_profit(const char* profit_string)
{
    unsigned long result = 0;
    int multiplier = 1;

    for (int i = strlen(profit_string) - 1; i >= 0; i--) {
        if (profit_string[i] != ',') {
            result += ((profit_string[i] - '0') * multiplier);
            multiplier *= 10;
        }
    }
    return result;
}

int find_best_year(movie_t* movies, int number_of_movies)
{
    year_t* years = (year_t*) malloc(sizeof(year_t));
    years[0].year = movies[0].year_released;
    years[0].profit = movies[0].profit;

    // todo: count unique years
    for (int i = 1; i < number_of_movies; ++i) {




    }


}