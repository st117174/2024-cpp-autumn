#include "dataset.h"

Dataset::Dataset(const std::string& filePath, const std::vector<std::string>& columnNames, bool hasIndex)
    : columnNames(columnNames), hasIndexColumn(hasIndex), size(0) {
    parseFile(filePath);
}

void Dataset::parseFile(const std::string& filePath) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        throw std::runtime_error("Error: Unable to open file " + filePath);
    }

    std::string line;
    bool isFirstLine = true;

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string cell;
        std::vector<std::string> row;

        while (std::getline(ss, cell, ',')) {
            row.push_back(cell);
        }

        if (isFirstLine) {
            if (columnNames.empty()) {
                columnNames = row;
            }
            isFirstLine = false;
        } else {
            data.push_back(row);
        }
    }
    size = data.size();
    file.close();
}

void Dataset::head(int n) const {
    n = std::min(n, size);
    printRow(columnNames);
    for (int i = 0; i < n; ++i) {
        printRow(data[i]);
    }
}

void Dataset::tail(int n) const {
    n = std::min(n, size);
    printRow(columnNames);
    for (int i = size - n; i < size; ++i) {
        printRow(data[i]);
    }
}

void Dataset::insert(int index, const std::vector<std::string>& row) {
    if (index < 0 || index > size) {
        throw std::out_of_range("Error: Index out of range");
    }
    data.insert(data.begin() + index, row);
    size++;
}

void Dataset::remove(int index) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Error: Index out of range");
    }
    data.erase(data.begin() + index);
    size--;
}

void Dataset::describe(const std::string& columnName) const {
    int colIndex = getColumnIndex(columnName);
    std::vector<double> numericColumn;

    for (const auto& row : data) {
        numericColumn.push_back(std::stod(row[colIndex]));
    }

    double sum = 0, maxVal = numericColumn[0], minVal = numericColumn[0];
    for (double value : numericColumn) {
        sum += value;
        if (value > maxVal) maxVal = value;
        if (value < minVal) minVal = value;
    }

    double mean = sum / numericColumn.size();
    double sqSum = 0;
    for (double value : numericColumn) {
        sqSum += (value - mean) * (value - mean);
    }
    double stddev = std::sqrt(sqSum / numericColumn.size());

    std::cout << "Statistics for column '" << columnName << "':\n"
              << "Max: " << maxVal << "\n"
              << "Min: " << minVal << "\n"
              << "Mean: " << mean << "\n"
              << "Std Dev: " << stddev << "\n";
}

std::vector<std::string>& Dataset::operator[](int index) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Error: Index out of range");
    }
    return data[index];
}

const std::string& Dataset::operator()(int rowIndex, int colIndex) const {
    if (rowIndex < 0  rowIndex >= size  colIndex < 0 || colIndex >= columnNames.size()) {
        throw std::out_of_range("Error: Index out of range");
    }
    return data[rowIndex][colIndex];
}

int Dataset::getColumnIndex(const std::string& columnName) const {
    auto it = std::find(columnNames.begin(), columnNames.end(), columnName);
    if (it == columnNames.end()) {
        throw std::invalid_argument("Error: Column name not found");
    }
    return std::distance(columnNames.begin(), it);
}

void Dataset::printRow(const std::vector<std::string>& row) const {
    for (const auto& cell : row) {
        std::cout << cell << "\t";
    }
    std::cout << "\n";
}
