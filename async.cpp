#include <iostream>
#include <future>
#include <chrono>

int foo(int id, int duration) {
    std::cout << "task " << id << " started\n";

    std::this_thread::sleep_for(std::chrono::seconds(duration));

    std::cout << "task " << id << " finished\n";
    return id * 10;
}

int main() {
    auto f1 = std::async(std::launch::async, foo, 1, 2);
    auto f2 = std::async(std::launch::async, foo, 2, 3);

    std::cout << "Both tasks launched\n";

    std::cout << "Main thread free to do other work\n";

    int result1 = f1.get();
    int result2 = f2.get();

    std::cout << "Results: " << result1 << ", " << result2 << "\n";

    return 0;
}