#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int h = triangle.size(), w = triangle.back().size();

    for (int i = h - 1; i > 0; i--) {
        for (int j = 0; j < w - 1; j++) {
            triangle.at(i - 1).at(j) += max(triangle.at(i).at(j), triangle.at(i).at(j + 1));
        }
        w--;
    }

    return triangle.at(0).at(0);
}
