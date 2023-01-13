#pragma once
// Класс интерфейса, который позволяет работать с классами TableLayerPicture и TableLayerPictureWitnText, не раскрывая их реализации
class ITableLayer
{
protected:
    virtual ~ITableLayer() = default; // Защищенный деструктор

public:
    ITableLayer& operator=(const ITableLayer&) = delete; // Запрет присваивания
    virtual int GetNumInTable() = 0; 
    virtual void SetNumberInTable(int num) = 0; 
    virtual void Delete() = 0;  // Удаляет объект
    virtual void GetUp() = 0; // Увеличивает значение номера на 1
    virtual void GetDown() = 0; // Уменьшает значение номера на 1
    virtual int HaveText() = 0; // Возвращает 1, если объект поддерживает обработку текста, 0 в обратном случае
    virtual int GetNumStrings()=0; // Если объект поддерживает обработку текста, то возратит количество строк текста, выкинет исключение в обратном случае
    virtual void SetNumStrings(int num) =0; // Если объект поддерживает обработку текста, то установит количество строк текста, выкинет исключение в обратном случае

    // Функции-фабрики
    static ITableLayer* CreatePicture(int number_in_table);
    static ITableLayer* CreatePictureWithText(int number_in_table);
};

