void f(int &x)
{ // requires an lvalue
}

int main()
{
    // lvalue is a name or an address (x)
    int x = 5;
    // rvalue is (5)

    f(5);      // 5 is an rvalue, invalid
    f(x);      // x is an lvalue, valid
    f(x == 5); // x == 5 is a bool rvalue, invalid
    f(++x);    // ++x is an lvalue, valid
    return 0;

    // whenever we create a string, make it const
    const char *ch = "name";
}