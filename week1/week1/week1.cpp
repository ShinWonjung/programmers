using namespace std;

long long solution(int price, int money, int count)
{
    long long n = 0;
    for (int i = 1; i <= count; i++)
        n += price * i;

    if (n > money)
        return n - money;
    else
        return 0;
}