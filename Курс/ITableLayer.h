#pragma once
#include <string>
using namespace std;
class ITableLayer
{
protected:
    virtual ~ITableLayer() = default; // защищенный деструктор

public:
    virtual void Delete() = 0;  // удаляет объект

    ITableLayer& operator=(const ITableLayer&) = delete; // запрет присваивания
    virtual void Activate(bool activate) = 0;
    // Функции-фабрики
    static ITableLayer* CreatePicture(int number_in_table);
};

