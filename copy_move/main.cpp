#include <iostream>
#include <vector>
using std::cout;
using std::endl;

class Foo
{
public:
    Foo()
    {
        cout << "Default ctor" << endl;
    }
    Foo(const Foo &)
    {
        cout << "Copy ctor" << endl;
    }
    Foo(const Foo &&)
    {
        cout << "Move ctor" << endl;
    }
    Foo &operator=(const Foo &)
    {
        cout << "Copy assignment" << endl;
        return *this;
    }
    Foo &operator=(const Foo &&)
    {
        cout << "Move assignment" << endl;
        return *this;
    }
    ~Foo()
    {
        cout << "Destructor" << endl;
    }
};

int main()
{
    Foo f1{};
    Foo f2{f1};
    Foo f3 = f1;
    f3 = f2;
    Foo f4 = std::move(f1);
    Foo f5{};
    f5 = std::move(f1);
    Foo f6 = Foo{}; // doesn't not call move ctor because of copy elision

    int N = 5;
    char *pArr = new char[N + 1];
    for (int i = 0; i < N; ++i)
    {
        pArr[i] = 'H';
    }
    for (int i = 0; i < N; ++i)
    {
        cout << pArr[i];
    }
    cout << endl;
    delete[] pArr;

    std::vector<int> vec{1, 2, 3, 4, 5};
    int sum{0};
    for (auto val : vec)
    {
        sum += val;
    }
    cout << sum << endl;

    const char *str = "My str";
    str = "another str"; // i can change the string pointed to
    // but not the string itself
    cout << str << endl;

    const int &a = 10;
    cout << "a: " << a << endl;
    return 0;
}