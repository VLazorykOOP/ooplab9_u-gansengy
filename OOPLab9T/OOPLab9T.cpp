#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <set>
#include <iterator>

using namespace std;

void Task1() {
    vector<pair<int, int>> months(12, { 0, 0 }); // ініціалізуємо вектор нулями
    int client_code, duration, year, month;

    //Ввід данних
    do {
        cin >> client_code >> duration >> year >> month;
        if (cin.fail()) {
            cin.clear();
            break;
        }

        months[month - 1].first += duration; // додаємо тривалість занять до відповідного місяця
        months[month - 1].second = month; // оновлюємо номер місяця
    } while (true);

    sort(months.rbegin(), months.rend()); // сортуємо вектор за спаданням сумарної тривалості

    for (auto p : months) {
        if (p.first > 0) {
            cout << p.first << " " << p.second << endl; // виводимо результат на екран
        }
    }
}

void Task2() {
    vector<int> V = { 1, 2, 3, 4, 5, 6 }; // Вихідний вектор
    list<int> L = { 6, 7, 8, 10 }; // Вихідний список

    // Знаходимо перший елемент другої половини вектора, який співпадає з будь-яким елементом списку
    auto it = find_first_of(V.begin() + V.size() / 2, V.end(), L.begin(), L.end());

    if (it == V.end()) {
        // Знайденого елемента немає, продублюємо перший елемент вектору, який є у списку
        auto found = find_first_of(V.begin(), V.begin() + V.size() / 2, L.begin(), L.end());
        if (found != V.begin() + V.size() / 2) {
            L.insert(L.end(), *found);
        }
    }
    else {
        // Знайдено відповідний елемент, дублюємо його в список
        L.insert(L.end(), *it);
    }

    // Виведення списку після змін
    for (int num : L) {
        cout << num << " ";
    }
    cout << endl;
}

void Task3() {
    std::vector<int> V1 = { 1, 2, 2, 3, 4, 5 }; // Перший вихідний вектор
    std::vector<int> V2 = { 2, 3, 3, 4, 5, 6, 6 }; // Другий вихідний вектор

    // Створюємо дві множини з векторів
    std::set<int, std::greater<int>> set1(V1.begin(), V1.end());
    std::set<int, std::greater<int>> set2(V2.begin(), V2.end());

    // Створюємо вектор для результату
    std::vector<int> result;

    // Знаходимо числа, які входять тільки в один з векторів
    std::set_symmetric_difference(set1.begin(), set1.end(), set2.begin(), set2.end(),
        std::back_inserter(result));

    // Сортуємо вектор у порядку спадання
    std::sort(result.begin(), result.end(), std::greater<int>());

    // Виводимо числа у порядку спадання
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main()
{
    cout << "Lab №9. STL. \n";
    cout << "Pres 'E' to exit." << endl;

    char answer = '0';

    while (answer != 'e' && answer != 'E') {
        cout << "Chose the number of the task that you want to review (1-3) :";
        cin >> answer;

        switch (answer) {
        case '1': Task1(); break;
        case '2': Task2(); break;
        case '3': Task3(); break;
        case 'e': case 'E': break;
        }
    }
    cout << "Thank you for using programm!" << endl;
}

