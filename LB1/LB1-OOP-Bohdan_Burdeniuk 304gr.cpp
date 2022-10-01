#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <malloc.h>
#include <vector>
#include <fstream>
#include <regex>
#include <time.h>

using namespace std;

template<typename T>
class arrays {
private:
    int staticSize = 15;
public:
    int size_array;
    int get_size_static() {return staticSize;}
    T* array_INT_new = new T[size_array];
    T* array_INT_malloc = (T*)malloc(size_array);
    T* array_INT_calloc = (T*)calloc(size_array, sizeof(T));
    vector<int> array_INT_vector;
    T array_INT_Static_size[15];
};

void setRand() {
    srand(time(NULL));
}

/* Dynamic Array ========================================================================================================== */
template<typename T>
void set_array(T* array, int size_array) {
    for (int i = 0; i < size_array; i++) array[i] = 0;
}

template<typename T>
void consoleInput(T* array, int size_array) {
    for (int i = 0; i < size_array; i++) {
        cout << "Input int. number| element array = " << i + 1 << " | ";
        cin >> array[i];
    }
}

template<typename T>
void randomSeed(T* array, int size_array) {
    setRand();
    for (int i = 0; i < size_array; i++) {
        array[i] = rand() % 100;
        if (rand() % 2) array[i] = ~array[i] + 1;
        cout << "Element array = " << i + 1 << " | " << "DATA = " << array[i] << endl;
    }
}

template<typename T>
void fillingArrayFF(T* array, int size) {
    string path;
    cout << "Input path file: ";
    cin >> path;
    int temp = 0;
    ifstream file;
    file.open(path);
    if (!file.is_open()) {
        cout << "The file does not exist or the path to it is invalid\n";
    }
    else {
        cout << "OK\n";
        char data;
        int countsEment = 0;
        string fDATA;
        while (file.get(data)) {
            if (countsEment > size-1) {
                fDATA = "";
                cout << "\nThe size of the data in the file exceeds the size of the array, so the data has been truncated to the size of the array\n\n";
                break;
            }
            if ((data == ',')) {
                fDATA += '\0';
                array[countsEment] = atoi(fDATA.c_str());
                cout << "Element - " << countsEment << " DATA | " << fDATA << endl;
                countsEment++;
                fDATA = "";
            }
            else fDATA += data;

        }
    }
}

/* Static Array ========================================================================================================== */
template<typename T>
void set_array(T array, int size_array) {
    for (int i = 0; i < size_array; i++) array[i] = 0;
}

template<typename T>
void randomSeed(T array, int size_array) {
    setRand();
    for (int i = 0; i < size_array; i++) {
        array[i] = rand() % 100;
        if (rand() % 2) array[i] = ~array[i] + 1;
        cout << "Element array = " << i + 1 << " | " << "DATA = " << array[i] << endl;
    }
}

template<typename T>
void consoleInput(T array, int size_array) {
    for (int i = 0; i < size_array; i++) {
        cout << "Element array = " << i + 1 << " | ";
        cin >> array[i];
    }
}

template<typename T>
void fillingArrayFF(T array, int size) {
    string path;
    cout << "Input path file: ";
    cin >> path;
    int temp = 0;
    ifstream file;
    file.open(path);
    if (!file.is_open()) {
        cout << "The file does not exist or the path to it is invalid\n";
    }
    else {
        cout << "OK\n";
        char data;
        int countsEment = 0;
        string fDATA;
        while (file.get(data)) {
            if (countsEment > size - 1) {
                fDATA = "";
                cout << "\nThe size of the data in the file exceeds the size of the array, so the data has been truncated to the size of the array\n\n";
                break;
            }
            if ((data == ',')) {
                fDATA += '\0';
                array[countsEment] = atoi(fDATA.c_str());
                cout << "Element - " << countsEment << " DATA | " << fDATA << endl;
                countsEment++;
                fDATA = "";
            }
            else fDATA += data;

        }
    }
}

/* Vector ========================================================================================================== */

template<typename T>
void randomSeed(vector<T> &array, int size_array) {
    setRand();
    for (int i = 0; i < size_array; i++) {
        array.push_back(rand() % 100);
        if (rand() % 2) array[i] = ~array[i] + 1;
        cout << "Element array = " << i + 1 << " | " << "DATA = " << array[i] << endl;
    }
}

template<typename T>
void consoleInput(vector<T> &array, int size_array) {
    for (int i = 0; i < size_array; i++) {
        int temp;
        cout << "Input int. number| element array = " << i + 1 << " | ";
        cin >> temp;
        array.push_back(temp);
    }
}

template<typename T>
void fillingArrayFF(vector<T> &array) {
    string path;
    cout << "Input path file: ";
    cin >> path;
    int temp = 0;
    ifstream file;
    file.open(path);
    if (!file.is_open()) {
        cout << "The file does not exist or the path to it is invalid\n";
    }
    else {
        cout << "OK\n";
        char data;
        int countsEment = 0;
        string fDATA;
        while (file.get(data)) {
            if ((data == ',')) {
                fDATA += '\0';
                array.push_back(atoi(fDATA.c_str()));
                cout << "Element - " << countsEment << " DATA | " << fDATA << endl;
                countsEment++;
                fDATA = "";
            }
            else fDATA += data;

        }
    }
}

/* Tasks ========================================================================================================== */
void task1(vector<int> linkArray) {
    int tempData;
    int tempIndex = 0;
    int minElememt = linkArray[0];

    for (int i = 0; i < linkArray.size(); i++) {
        if ((linkArray[i] < minElememt) && (linkArray[i] > 0)) { 
            minElememt = linkArray[i]; 
            tempIndex = i;
        }
    }

    cout << "\nThe least positive element | " << linkArray[tempIndex] << " | Index - " << tempIndex+1 << endl;
}
void task2(vector<int> linkArray) {
    int tempData;
    int tempIndex = 0;
    int maxElememt = linkArray[0];
    int temp = 0;


    for (int i = 0; i < linkArray.size(); i++) {
        if (linkArray[i] < 0) temp = ~linkArray[i] - 1;

        if ((temp > ~maxElememt - 1) && (linkArray[i] < 0)) {
            maxElememt = linkArray[i];
            tempIndex = i;
        }
    }

    cout << "\nThe least positive element | " << linkArray[tempIndex] << " | Index - " << tempIndex + 1 << endl;

    int moreThan;
    cout << "\nEnter a filter number: ";
    cin >> moreThan;

    for (int i = 0; i < tempIndex; i++) {
        if (linkArray[i] > moreThan) {
            cout << "\nThe largest number by given number " << moreThan << " up to number " << linkArray[tempIndex] << " is | " << linkArray[i] << " | Index - " << i + 1 << endl << endl;
        }
    }

}

void task1(int* linkArray, int size) {
    int tempData;
    int tempIndex = 0;
    int minElememt = linkArray[0];

    for (int i = 0; i < size; i++) {
        if ((linkArray[i] < minElememt) && (linkArray[i] > 0)) {
            minElememt = linkArray[i];
            tempIndex = i;
        }
    }

    cout << "\nThe least positive element | " << linkArray[tempIndex] << " | Index - " << tempIndex + 1 << endl;
}
void task2(int* linkArray, int size) {
    int tempData;
    int tempIndex = 0;
    int maxElememt = linkArray[0];
    int temp = 0;


    for (int i = 0; i < size; i++) {
        if (linkArray[i] < 0) temp = ~linkArray[i] - 1;

        if ((temp > ~maxElememt - 1) && (linkArray[i] < 0)) {
            maxElememt = linkArray[i];
            tempIndex = i;
        }
    }

    cout << "\nThe least positive element | " << linkArray[tempIndex] << " | Index - " << tempIndex + 1 << endl;

    int moreThan;
    cout << "\nEnter a filter number: ";
    cin >> moreThan;

    for (int i = 0; i < tempIndex; i++) {
        if (linkArray[i] > moreThan) {
            cout << "\nThe largest number by given number " << moreThan << " up to number " << linkArray[tempIndex] << " is | " << linkArray[i] << " | Index - " << i + 1 << endl << endl;
        }
    }
}


int main()
{ 
    arrays<int> arr;
    char choise;
    while (true) {
        int tasks = 0;
        cout << "-----------------------------------------------------\nInput number task 1 or 2: ";
        cin >> tasks;
        system("cls");
        cout << "Choise d-(Dynamic Array), s-(Static Array) and v-(Vector): ";
        cin >> choise;
        system("cls");
        switch (choise)
        {
        case 'd':
            char choise1;
            cout << "Choise how creating array: n-(new), m-(malloc) and c-(calloc): ";
            cin >> choise1;
            cout << "Input size array: ";
            cin >> arr.size_array;
            system("cls");
            switch (choise1)
            {
            case 'n':
                switch (tasks)
                {
                case 1:
                    char choise6;
                    cout << "Choise methot input in array: f-(file), r-(random) and c-(console):";
                    cin >> choise6;
                    system("cls");
                    switch (choise6)
                    {
                    case 'f':
                        set_array(arr.array_INT_new, arr.size_array);
                        fillingArrayFF(arr.array_INT_new, arr.size_array);
                        task1(arr.array_INT_new, arr.size_array);
                        break;
                    case 'r':
                        set_array(arr.array_INT_new, arr.size_array);
                        randomSeed(arr.array_INT_new, arr.size_array);
                        task1(arr.array_INT_new, arr.size_array);
                        break;
                    case 'c':
                        set_array(arr.array_INT_new, arr.size_array);
                        consoleInput(arr.array_INT_new, arr.size_array);
                        task1(arr.array_INT_new, arr.size_array);
                        break;
                    }
                    break;
                case 2:
                    char choise2;
                    cout << "Choise methot input in array: f-(file), r-(random) and c-(console):";
                    cin >> choise2;
                    system("cls");
                    switch (choise2)
                    {
                    case 'f':
                        set_array(arr.array_INT_new, arr.size_array);
                        fillingArrayFF(arr.array_INT_new, arr.size_array);
                        task2(arr.array_INT_new, arr.size_array);
                        break;
                    case 'r':
                        set_array(arr.array_INT_new, arr.size_array);
                        randomSeed(arr.array_INT_new, arr.size_array);
                        task2(arr.array_INT_new, arr.size_array);
                        break;
                    case 'c':
                        set_array(arr.array_INT_new, arr.size_array);
                        consoleInput(arr.array_INT_new, arr.size_array);
                        task2(arr.array_INT_new, arr.size_array);
                        break;
                    }
                    break;
                }
                break;
            case 'm':
                switch (tasks)
                {
                case 1:
                    char choise3;
                    cout << "Choise methot input in array: f-(file), r-(random) and c-(console):";
                    cin >> choise3;
                    system("cls");
                    switch (choise3)
                    {
                    case 'f':
                        set_array(arr.array_INT_malloc, arr.size_array);
                        fillingArrayFF(arr.array_INT_malloc, arr.size_array);
                        task1(arr.array_INT_malloc, arr.size_array);
                        break;
                    case 'r':
                        set_array(arr.array_INT_malloc, arr.size_array);
                        randomSeed(arr.array_INT_malloc, arr.size_array);
                        task1(arr.array_INT_malloc, arr.size_array);
                        break;
                    case 'c':
                        set_array(arr.array_INT_malloc, arr.size_array);
                        consoleInput(arr.array_INT_malloc, arr.size_array);
                        task1(arr.array_INT_malloc, arr.size_array);
                        break;
                    }
                    break;
                case 2:
                    char choise4;
                    cout << "Choise methot input in array: f-(file), r-(random) and c-(console):";
                    cin >> choise4;
                    system("cls");
                    switch (choise4)
                    {
                    case 'f':
                        set_array(arr.array_INT_malloc, arr.size_array);
                        fillingArrayFF(arr.array_INT_malloc, arr.size_array);
                        task2(arr.array_INT_malloc, arr.size_array);
                        break;
                    case 'r':
                        set_array(arr.array_INT_malloc, arr.size_array);
                        randomSeed(arr.array_INT_malloc, arr.size_array);
                        task2(arr.array_INT_malloc, arr.size_array);
                        break;
                    case 'c':
                        set_array(arr.array_INT_malloc, arr.size_array);
                        consoleInput(arr.array_INT_malloc, arr.size_array);
                        task2(arr.array_INT_malloc, arr.size_array);
                        break;
                    }
                    break;
                }
                break;
            case 'c':
                switch (tasks)
                {
                case 1:
                    char choise5;
                    cout << "Choise methot input in array: f-(file), r-(random) and c-(console):";
                    cin >> choise5;
                    system("cls");
                    switch (choise5)
                    {
                    case 'f':
                        set_array(arr.array_INT_calloc, arr.size_array);
                        fillingArrayFF(arr.array_INT_calloc, arr.size_array);
                        task1(arr.array_INT_calloc, arr.size_array);
                        break;
                    case 'r':
                        set_array(arr.array_INT_calloc, arr.size_array);
                        randomSeed(arr.array_INT_calloc, arr.size_array);
                        task1(arr.array_INT_calloc, arr.size_array);
                        break;
                    case 'c':
                        set_array(arr.array_INT_calloc, arr.size_array);
                        consoleInput(arr.array_INT_calloc, arr.size_array);
                        task1(arr.array_INT_calloc, arr.size_array);
                        break;
                    }
                    break;
                case 2:
                    char choise7;
                    cout << "Choise methot input in array: f-(file), r-(random) and c-(console):";
                    cin >> choise7;
                    system("cls");
                    switch (choise7)
                    {
                    case 'f':
                        fillingArrayFF(arr.array_INT_calloc, arr.size_array);
                        task2(arr.array_INT_calloc, arr.size_array);
                        break;
                    case 'r':
                        randomSeed(arr.array_INT_calloc, arr.size_array);
                        task2(arr.array_INT_calloc, arr.size_array);
                        break;
                    case 'c':
                        consoleInput(arr.array_INT_calloc, arr.size_array);
                        task2(arr.array_INT_calloc, arr.size_array);
                        break;
                    }
                    break;
                }
                break;
            }
            break;
        case 's':
            switch (tasks)
            {
            case 1:
                char choise8;
                cout << "Choise methot input in array: f-(file), r-(random) and c-(console):";
                cin >> choise8;
                system("cls");
                switch (choise8)
                {
                case 'f':
                    set_array(arr.array_INT_Static_size, arr.get_size_static());
                    fillingArrayFF(arr.array_INT_Static_size, arr.get_size_static());
                    task1(arr.array_INT_Static_size, arr.get_size_static());
                    break;
                case 'r':
                    set_array(arr.array_INT_Static_size, arr.get_size_static());
                    randomSeed(arr.array_INT_Static_size, arr.get_size_static());
                    task1(arr.array_INT_Static_size, arr.get_size_static());
                    break;
                case 'c':
                    set_array(arr.array_INT_Static_size, arr.get_size_static());
                    consoleInput(arr.array_INT_Static_size, arr.get_size_static());
                    task1(arr.array_INT_Static_size, arr.get_size_static());
                    break;
                }
                break;
            case 2:
                char choise9;
                cout << "Choise methot input in array: f-(file), r-(random) and c-(console):";
                cin >> choise9;
                system("cls");
                switch (choise9)
                {
                case 'f':
                    set_array(arr.array_INT_Static_size, arr.get_size_static());
                    fillingArrayFF(arr.array_INT_Static_size, arr.get_size_static());
                    task2(arr.array_INT_Static_size, arr.get_size_static());
                    break;
                case 'r':
                    set_array(arr.array_INT_Static_size, arr.get_size_static());
                    randomSeed(arr.array_INT_Static_size, arr.get_size_static());
                    task2(arr.array_INT_Static_size, arr.get_size_static());
                    break;
                case 'c':
                    set_array(arr.array_INT_Static_size, arr.get_size_static());
                    consoleInput(arr.array_INT_Static_size, arr.get_size_static());
                    task2(arr.array_INT_Static_size, arr.get_size_static());
                    break;
                }
                break;
            }
            break;
        case 'v':
            switch (tasks)
            {
            case 1:
                char choise10;
                cout << "Choise methot input in array: f-(file), r-(random) and c-(console):";
                cin >> choise10;
                system("cls");
                switch (choise10)
                {
                case 'f':
                    fillingArrayFF(arr.array_INT_vector);
                    task1(arr.array_INT_vector);
                    break;
                case 'r':
                    cout << "Input size array: ";
                    cin >> arr.size_array;
                    randomSeed(arr.array_INT_vector, arr.size_array);
                    task1(arr.array_INT_vector);
                    break;
                case 'c':
                    cout << "Input size array: ";
                    cin >> arr.size_array;
                    consoleInput(arr.array_INT_vector, arr.size_array);
                    task1(arr.array_INT_vector);
                    break;
                }
                break;
            case 2:
                char choise11;
                cout << "Choise methot input in array: f-(file), r-(random) and c-(console):";
                cin >> choise11;
                system("cls");
                switch (choise11)
                {
                case 'f':
                    fillingArrayFF(arr.array_INT_vector);
                    task2(arr.array_INT_vector);
                    break;
                case 'r':
                    cout << "Input size array: ";
                    cin >> arr.size_array;
                    randomSeed(arr.array_INT_vector, arr.size_array);
                    task2(arr.array_INT_vector);
                    break;
                case 'c':
                    cout << "Input size array: ";
                    cin >> arr.size_array;
                    consoleInput(arr.array_INT_vector, arr.size_array);
                    task2(arr.array_INT_vector);
                    break;
                }
                break;
            }
            break;
        case 'e':
            return  0;
        }
    }

    return 0;
} 