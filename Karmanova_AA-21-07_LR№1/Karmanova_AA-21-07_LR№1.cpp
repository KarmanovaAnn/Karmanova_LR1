
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <cstdlib>
#include <Windows.h>
#include <string>
#include <fstream>
#include <locale.h> 
#include <locale> 

using namespace std;

struct pipe{
    string condition;
    double diameter, length;
};

struct compressor_station{
    string name;
    double amount_shop, amount_Wshop, indicator;
};

void showMenu() {
    system("cls");//очистка экрана
    cout << "1.Добавить трубу" << endl;
    cout << "2.Добавить компрессорную станцию" << endl;
    cout << "3.Просмотреть все объекты" << endl;
    cout << "4.Изменить параметры трубы" << endl;
    cout << "5.Изменить параметры компрессорной станции" << endl;
    cout << "6.Сохранить данные в файл" << endl;
    cout << "7.Загрузить данные из файла" << endl;
    cout << "8.Выйти" << endl;
}

pipe Add_a_pipe() {
    system("cls");
    pipe p;
    p.condition = "хорошем";
    cout << "Труба в состоянии " << p.condition << endl;
    //диаметр трубы
    while (true) {
        cout << "Введите диаметр трубы:" << endl;
        cin >> p.diameter;
        if (cin.good()==true) {
            if (p.diameter == 0) {
                cout << "Ошибка:диаметр не может быть нулевым, труба не создана" << endl;
                cin.clear();
                cin.ignore(1000, '\n');
            }
            else if (p.diameter < 0) {
                cout << "Ошибка: диаметр не может быть отрицательным числом" << endl;
                cin.clear();
                cin.ignore(1000, '\n');
            }
            else {
                cout << "Диаметр трубы : " << " " << p.diameter << " " << "метров" << endl;
                break;
            }
        }
        else if (!cin.good()) {
            cout << "Ошибка: введено не число" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
    }
    //длина трубы
    while (true) {
        cout << "Введите длину трубы:" << endl;
        cin >> p.length;
        if (cin.good() == true) {
            if (p.length == 0) {
                cout << "Ошибка:длина не может быть нулевой, труба не создана" << endl;
                cin.clear();
                cin.ignore(1000, '\n');
            }
            else if (p.length < 0) {
                cout << "Ошибка: длина не может быть отрицательным числом" << endl;
                cin.clear();
                cin.ignore(1000, '\n');
            }
            else {
                cout << "Длина трубы:" << " " << p.length << " " << "метров" << endl;
                break;
            }
        }
        else {
            cout << "Ошибка: введено не число" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
    }
    system("pause");
    return p;
}

compressor_station Add_a_CS() {  
    system("cls");
    compressor_station cs;
    //имя станции
    cout << "Введите название компрессорной станции:" << endl;
    cin.ignore(1000, '\n');
    cin.clear();
    getline(cin, cs.name);
    cout << "Название компрессорной станции:" << cs.name << endl;
    //количество цехов
    while (true) {
        cout << "Введите количество цехов компрессорной станции :" << endl;
        cin >> cs.amount_shop;
        if (cin.good() == true) {
            if (cs.amount_shop < 0) {
                cout << "Ошибка:количество цехов не может быть отрицательным числом" << endl;
                cin.clear();
                cin.ignore(1000, '\n');
            }
            else if (cs.amount_shop == 0) {
                cout << "Ошибка:количество цехов не может равняться 0, КС не создана" << endl;
                cin.clear();
                cin.ignore(1000, '\n');
            }
            else if (int(cs.amount_shop) != cs.amount_shop) {
                cout << "Ошибка:количество цехов не может быть дробным числом" << endl;
                cin.clear();
                cin.ignore(1000, '\n');
            }
            else {
                cout << "Количество цехов:" << " " << cs.amount_shop << endl;
                break;
            }
        }
        else {
            cout << "Ошибка: введено не число" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
    }
    //кол-во рабочих цехов
    while (true) {
        cout << "Введите количество рабочих цехов компрессорной станции :" << endl;
        cin >> cs.amount_Wshop;
        if (cin.good() == true) {
            if (cs.amount_Wshop < 0) {
                cout << "Ошибка:количество рабочих цехов не может быть отрицательным числом" << endl;
                cin.clear();
                cin.ignore(1000, '\n');
            }
            else if (cs.amount_Wshop > cs.amount_shop) {
                cout << "Ошибка: количество рабочих цехов не может превышать количество цехов" << endl;
                cin.clear();
                cin.ignore(1000, '\n');
            }
            else if (int(cs.amount_Wshop) != cs.amount_Wshop) {
                cout << "Ошибка:количество цехов не может быть дробным числом" << endl;
                cin.clear();
                cin.ignore(1000, '\n');
            }
            else {
                cout << "Количество рабочих цехов:" << " " << cs.amount_Wshop << endl;
                break;
            }
        }
        else {
            cout << "Ошибка: введено не число" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
    }
    //оценка работы цеха
    cs.indicator= (cs.amount_Wshop/cs.amount_shop)*100;
    cout << "Показатель эффективности: " << " " << cs.indicator << "%" << endl;
    system("pause");
    return cs;
}

void Viewing_pipe(pipe & p) {
    system("cls");
    if ((p.length == 0) || (p.diameter == 0)) {
        cout << "Параметры трубы не введены" << endl << endl;
    }
    else {
        cout << "Параметры трубы:" << endl << endl;
        cout << "Труба в состоянии " << p.condition << endl;
        cout << "Диаметр трубы:" << " " << p.diameter << " " << "метров" << endl;
        cout << "Длина трубы" << " " << p.length << " " << "метров" << endl << endl;
    }
}

void Viewing_CS(compressor_station & cs) {
    if (cs.amount_shop == 0) {
        cout << "Параметры компрессорной станциии не введены" << endl << endl;
    }
    else {
        cout << "Параметры компрессорной станции:" << endl << endl;
        cout << "Название компрессорной станции: " << " " << cs.name << endl;
        cout << "Количество цехов: " << " " << cs.amount_shop << endl;
        cout << "Количество рабочих цехов: " << " " << cs.amount_Wshop << endl;
        cout << "Показатель эффективности рабочих цехов: " << " " << cs.indicator << "%" << endl << endl;
    }
    system("pause");
}

void Edit_pipe(pipe & p) {
    system("cls");
    cout << "На данный момент труба в состоянии " << p.condition  << endl << "Вы хотите отправить трубу в ремонт? Введите 1, если да, введите 0, если нет" << endl;
    int answer;
    cin >> answer;
    if ((answer == 1) && (p.condition== "хорошем")) {
        p.condition = "ремонта";
        cout << "Труба в состоянии " << p.condition << endl;
    }
    else if ((answer == 1) && (p.condition == "ремонта")) {
        p.condition = "хорошем";
        cout << "Труба в состоянии " << p.condition << endl;
    }
    else if (answer == 0) {
        cout << "Труба в состоянии " << p.condition << endl;
    }
    system("pause");
}

void Edit_CS(compressor_station & cs) {
    system("cls");
    cout << "На данный момент количество рабочих цехов:" << " " << cs.amount_Wshop << endl<< "Вы хотите изменить количество рабочих цехов? Введите 1, если хотите увеличить кол-во, введите 0, если хотите уменьшить" << endl;
    int answer;
    cin >> answer;
    while (true) {
        if (answer == 1) {
            cs.amount_Wshop = cs.amount_Wshop + 1;
            if (cs.amount_Wshop > cs.amount_shop) {
                cout << "Ошибка: количество рабочих цехов не может превышать количество цехов" << endl;
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Вы хотите оставить прежнее количество рабочих цехов?"<<endl<<"Введите 1, если хотите оставить прежнее кол - во, введите 0, если хотите уменьшить" << endl;
                cin >> answer;
                if (answer == 1) {
                    cs.amount_Wshop = cs.amount_Wshop - 1;
                    cout << "Количество рабочих цехов:" << " " << cs.amount_Wshop << endl;
                    break;
                }
                else {
                    cs.amount_Wshop = cs.amount_Wshop - 2;
                    cout << "Количество рабочих цехов:" << " " << cs.amount_Wshop << endl;
                    break;
                }
            }
            else {
                cout << "Количество рабочих цехов:" << " " << cs.amount_Wshop << endl;
                break;
            }
        }
        else if (answer == 0) {
            cs.amount_Wshop = cs.amount_Wshop - 1;
            if (cs.amount_Wshop <0) {
                cout << "Количество рабочих цехов не может быть отрицательным числом" << endl;
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Вы хотите оставить прежнее количество рабочих цехов?" << endl << "Введите 1, если хотите увеличить кол - во, введите 0, если оставить прежним" << endl;
                cin >> answer;
                if (answer == 1) {
                    cs.amount_Wshop = cs.amount_Wshop + 2;
                    cout << "Количество рабочих цехов:" << " " << cs.amount_Wshop << endl;
                    break;
                }
                else {
                    cs.amount_Wshop = cs.amount_Wshop +1;
                    cout << "Количество рабочих цехов:" << " " << cs.amount_Wshop << endl;
                    break;
                }
            }
            else  {
                cout << "Количество рабочих цехов:" << " " << cs.amount_Wshop << endl;
                break;
            }
 
        }
     
    }  
    system("pause");
}

void Save(pipe & p , compressor_station & cs) {
    system("cls");
    if ((cs.amount_shop == 0) && ((p.length == 0) || (p.diameter == 0))) {
        cout << "Параметры трубы и КС не введены. Вы сможете загрузить данные в файл только после выполнения 1 и 2 пунктов меню." << endl;
    }
    else if (cs.amount_shop == 0) {
        cout << "Параметры компрессорной станциии не введены. Вы сможете загрузить данные в файл только после выполнения 2 пункта меню." << endl;
    }
    else if ((p.length == 0) || (p.diameter == 0)) {
        cout << "Параметры трубы не введены. Вы сможете загрузить данные в файл только после выполнения 1 пункта меню." << endl;
    }
    else {
        ofstream fout;
        fout.open("NewFile.txt", ios::out);
        if (!fout.is_open()) {
            cout << "Ошибка! Не удалось открыть файл" << endl;
        }
        else {
            cout<<"Данные успешно записаны!" << endl;
            fout << p.condition << endl << p.diameter << endl << p.length << endl << cs.name << endl << cs.amount_shop << endl << cs.amount_Wshop << endl << cs.indicator << endl << endl;  
        }
        fout.close();
    }
    system("pause");
}

void Download(pipe& p, compressor_station& cs) {
    system("cls");
    ifstream fin;
    fin.open("NewFile.txt", ios::in);
    if (!fin.is_open()) {
        cout << "Ошибка! Не удалось открыть файл" << endl;
    }
    else if (fin.peek() == EOF) {
        cout << "Файл пустой" << endl;
    }
    else {
        cout << "Данные успешно загружены из файла!" << endl;
        //файл испортлися
        cout << "Параметры трубы:" << endl;
        //состояние
        fin >> p.condition;
        if ((p.condition != "хорошем") && (p.condition != "ремонта")) {
            cout << "Файл был испорчен" << endl;
        }
        else {
            cout << "Труба в состоянии " << p.condition << endl;
        }
        //диаметр
        fin >> p.diameter;
        if (fin.good() == true) {
            if (p.diameter < 0) {
                cout << "Файл был испорчен: диаметр - отрицательное число" << endl;
            }
            else if (p.diameter == 0) {
                cout << "Файл был испорчен: диаметр равен 0, труба не создана" << endl;
            }
            else {
                cout << "Диаметр трубы:" << " " << p.diameter << endl;      
            }
        }
        else  {
            cout << "Файл был испорчен: значение диаметра представлено не числом" << endl;     
        }
        //длина
        fin >> p.length;
        if (fin.good() == true) {
            if (p.length < 0) {
                cout << "Файл был испорчен: длина - отрицательное число" << endl;
            }
            else if (p.length == 0) {
                cout << "Файл был испорчен: длина равен 0, труба не создана" << endl;
            }
            else {
                cout << "Длина трубы:" << " " << p.length << endl;
            }
        }
        else {
            cout << "Файл был испорчен: значение длины представлено не числом" << endl;
        }
        //КС
        cout << "Параметры компрессорной станции:" << endl;
        fin.ignore();
        getline(fin, cs.name);
        cout << "Название компрессорной станции:" << cs.name<< endl;
        //кол-во цехов
        fin >> cs.amount_shop;
        if (fin.good() == true) {
            if (cs.amount_shop < 0) {
                cout << "Файл был испорчен: кол-во цехов - отрицательное число" << endl;
            }
            else if (int(cs.amount_shop) != cs.amount_shop) {
                cout << "Файл был испорчен: кол-во цехов - дробное число" << endl;
            }
            else if (cs.amount_shop == 0) {
                cout << "Файл был испорчен: кол-во цехов равно 0, КС не создана" << endl;
            }
            else {
                cout << "Количество цехов:" << " " << cs.amount_shop << endl;
                
            }
        }
        else {
            cout << "Файл был испорчен: значение кол-ва цехов представлено не числом" << endl;
        }
        //кол-во рабочих цехов
        fin >> cs.amount_Wshop;
        if (fin.good() == true) {
            if (cs.amount_Wshop < 0) {
                cout << "Файл был испорчен: кол-во рабочих цехов - отрицательное число" << endl;
            }
            else if (cs.amount_Wshop > cs.amount_shop) {
                cout << "Файл был испорчен: количество рабочих цехов превышает количество цехов" << endl;
            }
            else if (int(cs.amount_Wshop) != cs.amount_Wshop) {
                cout << "Файл был испорчен: кол-во рабочих цехов - дробное число" << endl;
            }
            else {
                cout << "Количество рабочих цехов:" << " " << cs.amount_Wshop << endl;
            }
        }
        else {
            cout << "Файл был испорчен: значение кол-ва рабочих цехов представлено не числом" << endl;
        }
        fin >> cs.indicator;
        if (fin.good() == true) {
            if ((cs.indicator < 0) || (cs.indicator > 100)) {
                cout << "Файл был испорчен: показатель эффективности рабочих цехов находится в недопустимых пределах" << endl;
            }
            else {
                cout << "Показатель эффективности рабочих цехов: " << cs.indicator << endl;
            }
        }
        else {
            cout << "Файл был испорчен: значение показателя эффективности цехов представлено не числом" << endl;
        }
    }
    fin.close();
    system("pause");
}

void Exit(pipe& p, compressor_station& cs) {
    system("cls");
    cout << "Вы хотите сохранить текущее данные в файл или очистить его? Введите 1, если да, введите 0, если нет" << endl;
    int answer;
    cin >> answer;
    if (answer == 1) {
        ofstream fout;
        fout.open("NewFile.txt", ios::out);
        fout << p.condition << endl << p.diameter << endl << p.length << endl << cs.name << endl << cs.amount_shop << endl << cs.amount_Wshop << endl << cs.indicator << endl << endl;
        cout << "Текущее данные сохранены в файл" << endl;
        fout.close();
    }
    else {
        ofstream ofs;
        ofs.open("NewFile.txt", ofstream::out | ofstream::trunc);
        ofs.close();
        cout << "Файл был очищен" << endl;
    }
}

//https://www.youtube.com/watch?v=PQyVWMaAJLg  - структура меню
void gotoxy(short x, short y) {
    COORD p = { x,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
}
int main(){
    setlocale(LC_ALL, "Russian");
    srand(time(0));
    system("cls");//очистка экрана
    const int POINT_OF_MENU = 8;
    int activeMenuItem = 0;
    int ch = 0;
    bool exit = false;
    pipe truba{};
    compressor_station shop{};
    while (!exit) {
        showMenu();
        //Функция помещает курсор к выбранному пункту меню
        gotoxy(0, activeMenuItem);
        //Функция getch нужна считывания символа с клавиатуры
        ch = _getch();
        if (ch == 224) {
            ch = _getch();
        }
        //обработка нажатых клавиш
        switch (ch) {
        case 27:
            exit = true;
            break;
        case 72:
            activeMenuItem--;
            break;
        case 80:
            activeMenuItem++;
            break;
        case 13:
            if (activeMenuItem == 0) {
                truba = Add_a_pipe();
            }
            else if (activeMenuItem == 1) {
                shop = Add_a_CS();
            }
            else if (activeMenuItem == 2) {
                Viewing_pipe(truba);
                Viewing_CS(shop);
            }
            else if (activeMenuItem == 3) {
                Edit_pipe(truba);
            }
            else if (activeMenuItem == 4) {
                Edit_CS(shop);
            }
            else if (activeMenuItem == 5) {
                Save(truba,shop);
            }
            else if (activeMenuItem == 6) {
                Download(truba, shop);
            }
            else if (activeMenuItem == 7) {
                Exit(truba, shop);
                exit = true;
            }
            break;
        }
        //ограничение перехода курсора по меню
        if (activeMenuItem < 0) {
            activeMenuItem = 0;
        }
        if (activeMenuItem > POINT_OF_MENU - 1) {
            activeMenuItem = POINT_OF_MENU - 1;
        }
    }
    return 0;
}


