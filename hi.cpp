import std;

int main() {
    std::println("hello world!");

    std::vector<int> v{5, 15, 25};
    for (const auto& e : v)
    {
        std::println("{}", e);
    }

    return 0;
}