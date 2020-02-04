#include <iostream>
#include <vector>
#include <algorithm>



void magicRotate(std::vector<std::vector<int>> arr)
{
    if (arr[0].size() != arr[1].size()) return;

    int N = arr[0].size();

    std::vector<int> temp(N);
    std::vector<std::vector<int>> result(N, std::vector<int>(N));

    for (int j = 0; j < N; ++j) {

        temp.assign(N, 0);

        for (int i = 0; i < N; ++i) {
            temp.push_back(arr[i][j]);
        }
        rotateColumn(temp);
    }
}

int main()
{
    std::vector<std::vector<int>> array = { {1, 2, 3, 4},
                                            {11, 12, 13, 14},
                                            {21, 22, 23, 24},
                                            {31, 32, 33, 34}};


    magicRotate(array);

    return 0;
}
