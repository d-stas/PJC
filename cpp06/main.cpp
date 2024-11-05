#include <iostream>
#include <string>
#include <cctype>

bool checkpass(std::string pass)
{
    bool is_valid = true;
    if (pass.length() < 8)
    {
        std::cout << "Too short\n";
        is_valid = false;
    }

    std::string::iterator it;
    std::string diff_chars;
    for (it = pass.begin(); it != pass.end(); ++it)
    {
        if (diff_chars.find(*it) == std::string::npos)
        {
            diff_chars += *it;
        }
    }

    if (diff_chars.length() < 6)
    {
        std::cout << "Too few different characters\n";
        is_valid = false;
    }

    bool digit = false, upper = false, lower = false, non_alpha_num = false;
    for (it = pass.begin(); it != pass.end(); ++it)
    {
        if (isdigit(*it)) digit = true;
        else if (isupper(*it)) upper = true;
        else if (islower(*it)) lower = true;
        else non_alpha_num = true;
    }


    if (!lower)
    {
        std::cout << "No lowercase letter\n";
        is_valid = false;
    }

    if (!upper)
    {
        std::cout << "No uppercase letter\n";
        is_valid = false;
    }

    if (!digit)
    {
        std::cout << " No digit\n";
        is_valid = false;
    }

    if (!non_alpha_num)
    {
        std::cout << "No non-alphanumeric character\n";
        is_valid = false;
    }
    return is_valid;
}

int main() {
    using std::cout; using std::endl;
    const std::string passes[] =
            {
                    "AbcDe93", "A1b:A1b>", "Ab:Acb<",
                    "abc123><", "Zorro@123"
            };
    for (size_t i = 0; i < std::size(passes); ++i)
    {
        cout << "checking " << passes[i] << endl;
        if (checkpass(passes[i])) cout << "OK" << endl;
        cout << endl;
    }
}

