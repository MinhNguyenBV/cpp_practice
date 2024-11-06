#include <iostream>
#include <vector>
#include <stdexcept>

class DynamicThreeStack {
public:
    DynamicThreeStack(size_t initialCapacity = 10)
        : data_(initialCapacity * 3, 0), sizes_{0, 0, 0}, capacities_{initialCapacity, initialCapacity, initialCapacity} {
    }

    void push(int stackNum, int value) {
        if (stackNum < 0 || stackNum >= 3) {
            throw std::invalid_argument("Invalid stack number");
        }

        // Expand capacity if needed
        if (sizes_[stackNum] >= capacities_[stackNum]) {
            expand(stackNum);
        }

        data_[indexOfTop(stackNum) + 1] = value;
        sizes_[stackNum]++;
    }

    void pop(int stackNum) {
        if (stackNum < 0 || stackNum >= 3) {
            throw std::invalid_argument("Invalid stack number");
        }
        if (isEmpty(stackNum)) {
            throw std::out_of_range("Stack is empty");
        }
        sizes_[stackNum]--;
    }

    int top(int stackNum) const {
        if (stackNum < 0 || stackNum >= 3) {
            throw std::invalid_argument("Invalid stack number");
        }
        if (isEmpty(stackNum)) {
            throw std::out_of_range("Stack is empty");
        }
        return data_[indexOfTop(stackNum)];
    }

    bool isEmpty(int stackNum) const {
        if (stackNum < 0 || stackNum >= 3) {
            throw std::invalid_argument("Invalid stack number");
        }
        return sizes_[stackNum] == 0;
    }

private:
    std::vector<int> data_;
    size_t sizes_[3];
    size_t capacities_[3];

    void expand(int stackNum) {
        size_t newCapacity = capacities_[stackNum] * 2;
        std::vector<int> newData(newCapacity * 3, 0);

        // Copy old data to new data
        for (int i = 0; i < 3; ++i) {
            for (size_t j = 0; j < sizes_[i]; ++j) {
                newData[i * newCapacity + j] = data_[i * capacities_[i] + j];
            }
        }

        capacities_[stackNum] = newCapacity;
        data_ = std::move(newData);
    }

    size_t indexOfTop(int stackNum) const {
        return stackNum * capacities_[stackNum] + sizes_[stackNum] - 1;
    }
};

int main() {
    DynamicThreeStack stacks;
    stacks.push(0, 10);
    stacks.push(1, 20);
    stacks.push(2, 30);
    stacks.push(0, 40);
    stacks.push(1, 50);
    stacks.push(2, 60);

    std::cout << "Top of stack 0: " << stacks.top(0) << std::endl;
    std::cout << "Top of stack 1: " << stacks.top(1) << std::endl;
    std::cout << "Top of stack 2: " << stacks.top(2) << std::endl;

    stacks.pop(0);
    stacks.pop(1);
    stacks.pop(2);

    std::cout << "Top of stack 0 after pop: " << stacks.top(0) << std::endl;
    std::cout << "Top of stack 1 after pop: " << stacks.top(1) << std::endl;
    std::cout << "Top of stack 2 after pop: " << stacks.top(2) << std::endl;

    return 0;
}
