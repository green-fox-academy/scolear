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
    unsigned long   profit_sum;
} year_t;

int           count_lines(char* filename);
unsigned long parse_profit(const char* profit_string);
int           count_unique_years(movie_t* movies, int number_of_movies);
year_t*       year_sums(movie_t* movies, int number_of_movies);
int           find_best_year(year_t* year_stats, int years);

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

        word = strtok(NULL, "\n");
        movies[row_index].year_released = atoi(word);

        row_index++;
    }

    year_t* year_stats = year_sums(movies, number_of_movies);

    printf("Best year for movies: %d\n", find_best_year(year_stats, count_unique_years(movies, number_of_movies)));
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

int count_unique_years(movie_t* movies, int number_of_movies)
{
    int diff_years = 0;
    for (int i = 0; i < number_of_movies; i++) {
        int match = 0;
        for (int j = 0; j < i && ! match; j++) {
            if (movies[i].year_released == movies[j].year_released) {
                match++;
            }
        }
        if (match == 0) {
            diff_years++;
        }
    }
    return diff_years;
}

year_t* year_sums(movie_t* movies, int number_of_movies)
{
    int     number_of_years = count_unique_years(movies, number_of_movies);
    year_t* yearly_stat = calloc(number_of_years, sizeof(year_t));
    int     years = 0;

    for (int i = 0; i < number_of_movies; ++i) {
        int found = 0;
        for (int j = 0; j < years && !found; ++j) {
            if (movies[i].year_released == yearly_stat[j].year) {
                yearly_stat[j].profit_sum += movies[i].profit;
                found++;
            }
        }

        if (!found) {
            yearly_stat[years].year = movies[i].year_released;
            yearly_stat[years].profit_sum = movies[i].profit;
            years++;
        }
    }
    return yearly_stat;
}

int find_best_year(year_t* year_stats, int years)
{
    unsigned long   max_income = 0;
    int             best_year = 0;

    for (int i = 0; i < years; ++i) {
        if (max_income < year_stats[i].profit_sum) {
            max_income = year_stats[i].profit_sum;
            best_year = year_stats[i].year;
        }
    }
    return best_year;
}