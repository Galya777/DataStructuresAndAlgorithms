#include <iostream>
#include <list>
#include <stack>
#include <queue>

template <typename T>
class Container {
public:
    virtual bool member(const T& x) const = 0;
    virtual bool exists(bool (*cond)(const T&)) const = 0;
    virtual void filter(bool (*cond)(const T&)) = 0;
};

template <typename T>
class CList : public Container<T> {
public:
    CList(const std::list<T>& data) : data_(data) {}

    bool member(const T& x) const override {
        return std::find(data_.begin(), data_.end(), x) != data_.end();
    }

    bool exists(bool (*cond)(const T&)) const override {
        for (const T& element : data_) {
            if (cond(element)) {
                return true;
            }
        }
        return false;
    }

    void filter(bool (*cond)(const T&)) override {
        auto it = data_.begin();
        while (it != data_.end()) {
            if (cond(*it)) {
                it = data_.erase(it);
            }
            else {
                ++it;
            }
        }
    }

private:
    std::list<T> data_;
};

template <typename T>
class CStack : public Container<T> {
public:
    CStack(const std::stack<T>& data) : data_(data) {}

    bool member(const T& x) const override {
        std::stack<T> tempStack = data_;
        while (!tempStack.empty()) {
            if (tempStack.top() == x) {
                return true;
            }
            tempStack.pop();
        }
        return false;
    }

    bool exists(bool (*cond)(const T&)) const override {
        std::stack<T> tempStack = data_;
        while (!tempStack.empty()) {
            if (cond(tempStack.top())) {
                return true;
            }
            tempStack.pop();
        }
        return false;
    }

    void filter(bool (*cond)(const T&)) override {
        std::stack<T> tempStack;
        while (!data_.empty()) {
            if (!cond(data_.top())) {
                tempStack.push(data_.top());
            }
            data_.pop();
        }
        data_ = tempStack;
    }

private:
    std::stack<T> data_;
};

template <typename T>
class CQueue : public Container<T> {
public:
    CQueue(const std::queue<T>& data) : data_(data) {}

    bool member(const T& x) const override {
        std::queue<T> tempQueue = data_;
        while (!tempQueue.empty()) {
            if (tempQueue.front() == x) {
                return true;
            }
            tempQueue.pop();
        }
        return false;
    }

    bool exists(bool (*cond)(const T&)) const override {
        std::queue<T> tempQueue = data_;
        while (!tempQueue.empty()) {
            if (cond(tempQueue.front())) {
                return true;
            }
            tempQueue.pop();
        }
        return false;
    }

    void filter(bool (*cond)(const T&)) override {
        std::queue<T> tempQueue;
        while (!data_.empty()) {
            if (!cond(data_.front())) {
                tempQueue.push(data_.front());
            }
            data_.pop();
        }
        data_ = tempQueue;
    }

private:
    std::queue<T> data_;
};

int main() {
    // Пример за използване
    std::list<int> myList = { 1, 2, 3, 4, 5 };
    CList<int> listContainer(myList);
    bool result = listContainer.member(3);
    std::cout << "Member result: " << result << std::endl;

    return 0;
}
