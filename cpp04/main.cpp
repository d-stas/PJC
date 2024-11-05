#include <iostream>

unsigned short koduj(int plec, int stan_cyw, int grupa_wiek, int edu, int zam, int region, int odp)
{
    unsigned short kod = 0;
    kod |= (plec & 0x1);
    kod |= (stan_cyw & 0x3) << 1;
    kod |= (grupa_wiek & 0x3) << 3;
    kod |= (edu & 0x3) << 5;
    kod |= (zam & 0x3) << 7;
    kod |= (region & 0xF) << 9;
    kod |= (odp & 0x7) << 13;
    return kod;
}

void info(unsigned short kod)
{
    std::cout << "plec: " << (kod & 0x1) << std::endl;
    std::cout << "stan cywilny: " << ((kod >> 1) & 0x3) << std::endl;
    std::cout << "grupa wiekowa: " << ((kod >> 3) & 0x3) << std::endl;
    std::cout << "wyksztalcenie: " << ((kod >> 5) & 0x3) << std::endl;
    std::cout << "miejsce zam: " << ((kod >> 7) & 0x3) << std::endl;
    std::cout << "region: " << ((kod >> 9) & 0xF) << std::endl;
    std::cout << "odpowiedz: " << ((kod >> 11) & 0x7) << std::endl;
}

int main()
{
    int plec, stan_cyw, grupa_wiek, edu, zam, region, odp;

    std::cout << "Podaj plec (0 lub 1): ";
    std::cin >> plec;
    std::cout << "Podaj stan cywilny (0-3): ";
    std::cin >> stan_cyw;
    std::cout << "Podaj grupe wiekową (0-3): ";
    std::cin >> grupa_wiek;
    std::cout << "Podaj wyksztalcenie (0-3): ";
    std::cin >> edu;
    std::cout << "Podaj miejsce zamieszkania (0-3): ";
    std::cin >> zam;
    std::cout << "Podaj region (0-15): ";
    std::cin >> region;
    std::cout << "Podaj odpowiedz (0-7): ";
    std::cin >> odp;

    unsigned short kod = koduj(plec, stan_cyw, grupa_wiek, edu, zam, region, odp);

    info(kod);
};