#include <iostream>

enum Banks
        { PKO, BGZ, BRE, BPH };

struct Account
        {
    Banks bank;
    int balance;
};

struct Person
        {
    char name[20];
    Account account;
};

struct Couple {
    Person he;
    Person she;
};

const Couple* bestClient(const Couple* cpls, int size, Banks bank)
{
    const Couple* bestCouple = nullptr;
    int maxSavings = INT_MIN;

    for (int i = 0; i < size; ++i)
    {
        const Couple& currentCouple = cpls[i];
        int totalSavings = currentCouple.he.account.balance + currentCouple.she.account.balance;

        if (currentCouple.he.account.bank == bank || currentCouple.she.account.bank == bank)
        {
            if (totalSavings > maxSavings)
            {
                maxSavings = totalSavings;
                bestCouple = &currentCouple;
            }
        }
    }
    return bestCouple;
}

int main()
{
    Couple cpls[] =
            {
            { { "Johny", { PKO, 1200 } }, { "Marry", { BGZ, 1400 } } },
            { { "Peter", { BGZ, 1400 } }, { "Suzy", { BRE, -1500 } } },
            { { "Kevin", { PKO, 1600 } }, { "Katy", { BPH, 1500 } } },
            { { "Kenny", { BPH, 200 } }, { "Lucy", { BRE, -201 } } }
            };

    const Couple* p = bestClient(cpls, 4, BRE);
    if (p)
        std::cout << p->he.name << " and " << p->she.name << ": " << p->he.account.balance + p->she.account.balance << std::endl;
    else
        std::cout << "No such couple...\n";
}