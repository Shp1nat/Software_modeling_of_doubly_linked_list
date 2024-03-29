#include <iostream>
#include <string>
#include <cmath>
using namespace std;

struct Data
{
    char surname[20];
    char name[15];
    char lastname[25];
    int count;
    int day;
    int month;
    int year;
    int duration;
};

struct Node //узел для двусвязного списка
{
    Data val;
    Node* next;
    Node* prev;
    Node(Data _val) : val(_val), next(nullptr), prev(nullptr) {}
};

class list //двусвязный список
{
private:
    Node* first;
    Node* last;
public:
    class ErrorFinding {};
    list() : first(nullptr), last(nullptr) {} // конструктор
    ~list()  //деструктор
    {
        Node* current = first;
        while (current != nullptr)
        {
            Node* buf = current;
            current = current->next;
            delete buf;
        }
    }

    bool isEmpty() //проверка на пустоту
    {
        return first == nullptr;
    }

    void push_back(Data _val)  //добавление в конец
    {
        Node* p = new Node(_val);
        if (isEmpty())
        {
            first = p;
            last = p;
            return;
        }
        last->next = p;
        p->prev = last;
        last = p;
        last->next = nullptr;
    }

    void push_front(Data _val) //добавление в начало
    {
        Node* p = new Node(_val);
        if (isEmpty()) {
            first = p;
            last = p;
            return;
        }
        first->prev = p;
        p->next = first;
        first = p;
    }

    void delete_first() //удалить первый элемент
    {
        if (isEmpty()) return;
        Node* p = first;
        first = p->next;
        first->prev = nullptr;
        delete p;
    }

    void delete_last() //удалить последний элемент
    {
        if (isEmpty()) return;
        if (first == last)
        {
            delete_first();
            return;
        }
        Node* p = last;
        last = p->prev;
        last->next = nullptr;
        delete p;
    }

    void push_insert(Data _val, int _index) //добавление вставкой
    {
        Node* current = first;
        while (_index > 1)
        {
            current = current->next;
            _index--;
        }
        if (current == last) push_back(_val);
        else
        {
            Node* buf1 = current->next;
            current = current->next;
            Node* buf2 = current->prev;
            current = current->prev;
            current->next = new Node(_val);
            current = current->next;
            current->prev = buf2;
            current->next = buf1;
            Node* buf3 = current;
            current = current->next;
            current->prev = buf3;
        }

    }

    void deleteByIndex(int _index)
    {
        Node* current = first;
        if (_index == 1)
            delete_first();
        while (_index > 2)
        {
            current = current->next;
            _index--;
        }
        if (current->next == last) delete_last();
        else
        {
            Node* buf = current->next;
            current->next = buf->next;
            current = current->next;
            current = current->next;
            buf = current->prev;
            current->prev = buf->prev;
        }

    }

    Node* findSurname(string _surname) //поиск фамилии
    {
        if (isEmpty())
            NULL;
        Node* p = first;
        while (p)
        {
            if (string(p->val.surname).find(_surname) != string::npos)
                return p;
            else
                p = p->next;
        }
        throw ErrorFinding();
    }

    Node* findName(string _name) //поиск имени
    {
        if (isEmpty())
            NULL;
        Node* p = first;
        while (p)
        {
            if (string(p->val.name).find(_name) != string::npos)
                return p;
            else
                p = p->next;
        }
        throw ErrorFinding();
    }

    Node* findLastName(string _lastname) //поиск отчества
    {
        if (isEmpty())
            NULL;
        Node* p = first;
        while (p)
        {
            if (string(p->val.lastname).find(_lastname) != string::npos)
                return p;
            else
                p = p->next;
        }
        throw ErrorFinding();
    }

    Node* findCount(int _count) //поиск количества
    {
        if (isEmpty())
            NULL;
        Node* p = first;
        while (p)
        {
            if (p->val.count == _count)
                return p;
            else
                p = p->next;
        }
        throw ErrorFinding();
    }

    Node* findDay(int _day) //поиск дня
    {
        if (isEmpty())
            NULL;
        Node* p = first;
        while (p)
        {
            if (p->val.day == _day)
                return p;
            else
                p = p->next;
        }
        throw ErrorFinding();
    }

    Node* findMonth(int _month) //поиск месяца
    {
        if (isEmpty())
            NULL;
        Node* p = first;
        while (p)
        {
            if (p->val.month == _month)
                return p;
            else
                p = p->next;
        }
        throw ErrorFinding();
    }

    Node* findYear(int _year) //поиск года
    {
        if (isEmpty())
            NULL;
        Node* p = first;
        while (p)
        {
            if (p->val.year == _year)
                return p;
            else
                p = p->next;
        }
        throw ErrorFinding();
    }

    Node* findDuration(int _duration) //поиск длительности
    {
        if (isEmpty())
            NULL;
        Node* p = first;
        while (p)
        {
            if (p->val.duration == _duration)
                return p;
            else
                p = p->next;
        }
        throw ErrorFinding();
    }

    void zatoBezCoutVclasse(char sn[20], char n[15], char ln[25], int c, int d, int m, int y, int du);

    void getDataFromNode(Node* _first)
    {
        char _surname[20];
        for (int i = 0; i < 20; i++)
            _surname[i] = _first->val.surname[i];
        char _name[15];
        for (int i = 0; i < 15; i++)
            _name[i] = _first->val.name[i];
        char _lastname[25];
        for (int i = 0; i < 25; i++)
            _lastname[i] = _first->val.lastname[i];
        int _count = _first->val.count;
        int _day = _first->val.day;
        int _month = _first->val.month;
        int _year = _first->val.year;
        int _duration = _first->val.duration;
        zatoBezCoutVclasse(_surname, _name, _lastname, _count, _day, _month, _year, _duration);
    }

    void getAllList()
    {
        Node* fakeFirst = first;
        while (fakeFirst)
        {
            getDataFromNode(fakeFirst);
            fakeFirst = fakeFirst->next;
        }
    }

};


void list::zatoBezCoutVclasse(char sn[20], char n[15], char ln[25], int c, int d, int m, int y, int du)
{
    cout << sn << " " << n << " " << ln << " " << c << " " << d << "." << m << "." << y << " " << du << endl;
}

void printError() //вывод ошибки на экран
{
    cout << "Совпадений не найдено" << endl;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int addCount;
    list l;

    cout << "Сколько элементов добавим? (элементы добавляются в конец списка) : "; //в конец
    cin >> addCount;
    for (int i = 0; i < addCount; i++)
    {
        Data data;
        char ch = '.';
        cout << "ФИО: ";
        cin >> data.surname >> data.name >> data.lastname;
        cout << "Количество переговоров: ";
        cin >> data.count;
        cout << "Дата переговоров через точки: ";
        cin >> data.day >> ch >> data.month >> ch >> data.year;
        cout << "Длительность переговоров: ";
        cin >> data.duration;
        l.push_back(data);
    }
    cout << "Наш текущий список: " << endl;
    l.getAllList();

    cout << "\nСколько элементов добавим? (элементы добавляются в начало списка) : "; //в начало
    cin >> addCount;
    for (int i = 0; i < addCount; i++)
    {
        Data data;
        char ch = '.';
        cout << "ФИО: ";
        cin >> data.surname >> data.name >> data.lastname;
        cout << "Количество переговоров: ";
        cin >> data.count;
        cout << "Дата переговоров через точки: ";
        cin >> data.day >> ch >> data.month >> ch >> data.year;
        cout << "Длительность переговоров: ";
        cin >> data.duration;
        l.push_front(data);
    }
    cout << "\nНаш текущий список: " << endl;
    l.getAllList();

    cout << "\nУдаление первого элемента. Текущий список: " << endl;
    l.delete_first();
    l.getAllList();

    cout << "\nУдаление последнего элемента. Текущий список: " << endl;
    l.delete_last();
    l.getAllList();

    int choice;
    cout << "\nВведите поле структуры, по которому нужно выполнить поиск элемента (1-surname, 2-name, 3-lastname, 4-count, 5-day, 6-month, 7-year, 8-duration) : ";
    cin >> choice;
    string text;
    int IntNumber;
    switch (choice)
    {
    case 1:
        cout << "Введите фамилию: "; cin >> text;
        try
        {
            l.getDataFromNode(l.findSurname(text));
        }
        catch (list::ErrorFinding)
        {
            printError();
        }
        break;
    case 2:
        cout << "Введите имя: "; cin >> text;
        try
        {
            l.getDataFromNode(l.findName(text));
        }
        catch (list::ErrorFinding)
        {
            printError();
        }
        break;
    case 3:
        cout << "Введите отчество: "; cin >> text;
        try
        {
            l.getDataFromNode(l.findLastName(text));
        }
        catch (list::ErrorFinding)
        {
            printError();
        }
        break;
    case 4:
        cout << "Введите количество: "; cin >> IntNumber;
        try
        {
            l.getDataFromNode(l.findCount(IntNumber));
        }
        catch (list::ErrorFinding)
        {
            printError();
        }
        break;
    case 5:
        cout << "Введите день: "; cin >> IntNumber;
        try
        {
            l.getDataFromNode(l.findDay(IntNumber));
        }
        catch (list::ErrorFinding)
        {
            printError();
        }
        break;
    case 6:
        cout << "Введите месяц: "; cin >> IntNumber;
        try
        {
            l.getDataFromNode(l.findMonth(IntNumber));
        }
        catch (list::ErrorFinding)
        {
            printError();
        }
        break;
    case 7:
        cout << "Введите год: "; cin >> IntNumber;
        try
        {
            l.getDataFromNode(l.findYear(IntNumber));
        }
        catch (list::ErrorFinding)
        {
            printError();
        }
        break;
    case 8:
        cout << "Введите длительность: "; cin >> IntNumber;
        try
        {
            l.getDataFromNode(l.findDuration(IntNumber));
        }
        catch (list::ErrorFinding)
        {
            printError();
        }
        break;
    }

    int index;
    Data data;
    cout << "Введите номер элемента, после которого добавить новый: ";
    cin >> index;
    char ch = '.';
    cout << "ФИО: ";
    cin >> data.surname >> data.name >> data.lastname;
    cout << "Количество переговоров: ";
    cin >> data.count;
    cout << "Дата переговоров через точки: ";
    cin >> data.day >> ch >> data.month >> ch >> data.year;
    cout << "Длительность переговоров: ";
    cin >> data.duration;
    l.push_insert(data, index);
    cout << "\nТекущий список: " << endl;
    l.getAllList();

    cout << "Введите номер элемента, который удалить: ";
    cin >> index;
    l.deleteByIndex(index);
    cout << "\nТекущий список: " << endl;
    l.getAllList();

    return 0;
}

/*
    Двухсвязный список.
    Алгоритмы:
        Создание списка
        Добавление элемента в конец списка
        Добавление элемента в начало списка
        Удаление конечного элемента списка
        Удаление начального элемента списка
        Поиск элемента по заданному значению поля структуры
        Добавление элемента после найденного
        Удаление найденного элемента.
    Использовать указатели
*/