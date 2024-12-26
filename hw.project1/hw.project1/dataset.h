#ifndef DATASET_H
#define DATASET_H

#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <fstream>
#include <sstream>
#include <cmath>

class Dataset {
private:
    std::vector<std::vector<std::string>> data; // Данные в виде строк
    std::vector<std::string> columnNames;       // Названия столбцов
    bool hasIndexColumn;                        // Наличие индексного столбца
    int size;                                   // Количество строк

    void parseFile(const std::string& filePath);

public:
    Dataset(const std::string& filePath, const std::vector<std::string>& columnNames = {}, bool hasIndex = false);
    void head(int n = 5) const;
    void tail(int n = 5) const;
    void insert(int index, const std::vector<std::string>& row);
    void remove(int index);
    void describe(const std::string& columnName) const;
    std::vector<std::string>& operator[](int index);
    const std::string& operator()(int rowIndex, int colIndex) const;

    // Вспомогательные методы
    int getColumnIndex(const std::string& columnName) const;
    void printRow(const std::vector<std::string>& row) const;
};

#endif
