#include <vector>

std::vector<int> bubbleSort(std::vector<int> numbers) {
    for (int i = 0; i < numbers.size(); i++) {
        for (int j = 0; j < numbers.size() - 1; j++) {
            if (numbers[j] > numbers[j + 1]) {
                std::swap(numbers[j], numbers[j + 1]);
            }
        }
    }
    return numbers;
}
