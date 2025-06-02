#pragma once
#include <iostream>
#include <vector>
#include <stdexcept>
#include <initializer_list>
#include <iomanip>

template<typename T>
class Array {
private:
	std::vector<std::vector<T>> data;
	size_t rows, cols;

public:
	//constructor with size and inicial value
	Array(size_t r, size_t c, const T& initial = T())
		:data(r, std::vector<T>(c, initial)), rows(r), cols(c) {
	}

	//copy constructor
	Array(const Array<T>& other) = default;

	//initializer_list constructor
	Array(std::initializer_list<std::initializer_list<T>> list) {
		rows = list.size();
		cols = list.begin()->size();
		for (const auto& row : list) {
			if (row.size() != cols)
				throw std::invalid_argument("All lines must be the same size.");
			data.push_back(std::vector<T>(row));
		}
	}

	//access with the operator ()
	T& operator()(size_t i, size_t j) {
		return data[i][j];
	}

	const T& operator()(size_t i, size_t j) const {
		return data[i][j];
	}

	size_t numRows() const { return rows; }
	size_t numCols() const { return cols; }

	//array sum
	Array<T> operator+(const Array<T>& other) const {
		if (rows != other.rows || cols != other.cols)
			throw std::invalid_argument("Incompatible dimensions for sum.");
		Array<T> result(rows, cols);
		for (size_t i = 0; i < rows; ++i)
			for (size_t j = 0; j < cols; ++j)
				result(i, j) = data[i][j] + other(i, j);
		return result;
	}

	//array subtract
	Array<T> operator-(const Array<T>& other) const {
		if (rows != other.rows || cols != other.cols)
			throw std::invalid_argument("Incompatible dimensions for subtract.");
		Array<T> result(rows, cols);
		for (size_t i = 0; i < rows; ++i)
			for (size_t j = 0; j < cols; ++j)
				result(i, j) = data[i][j] - other(i, j);
		return result;
	}

	//array multiply
	Array<T> operator*(const Array<T>& other) const {
		if (cols != other.cols)
			throw std::invalid_argument("Incompatible dimensions for multiply.");
		Array<T> result(rows, other.cols, T());
		for (size_t i = 0; i < rows; ++i)
			for (size_t j = 0; j < other.cols; ++j)
				for (size_t k = 0; k < cols; ++k)
					result(i, j) += data[i][k] * other(k, j);
		return result;
	}

	//composite operators
	Array<T>& operator+=(const Array<T>& other) {
		return *this = *this + other;
	}

	Array<T>& operator-=(const Array<T>& other) {
		return *this = *this - other;
	}

	Array<T>& operator*=(const Array<T>& other) {
		return *this = *this * other;
	}

	//scalars on the right
	Array<T> operator+(const  T& value) const {
		Array<T> result(rows, cols);
		for (size_t i = 0; i < rows; ++i)
			for (size_t j = 0; j < cols; ++j)
				result(i, j) = data[i][j] + value;
		return result;
	}

	Array<T> operator-(const  T& value) const {
		Array<T> result(rows, cols);
		for (size_t i = 0; i < rows; ++i)
			for (size_t j = 0; j < cols; ++j)
				result(i, j) = data[i][j] - value;
		return result;
	}

	Array<T> operator*(const  T& value) const {
		Array<T> result(rows, cols);
		for (size_t i = 0; i < rows; ++i)
			for (size_t j = 0; j < cols; ++j)
				result(i, j) = data[i][j] * value;
		return result;
	}

	Array<T> operator/(const  T& value) const {
		Array<T> result(rows, cols);
		for (size_t i = 0; i < rows; ++i)
			for (size_t j = 0; j < cols; ++j)
				result(i, j) = data[i][j] / value;
		return result;
	}

	Array<T>& operator+=(const T& value) {
		return *this = *this + value;
	}

	Array<T>& operator-=(const T& value) {
		return *this = *this - value;
	}

	Array<T>& operator*=(const T& value) {
		return *this = *this * value;
	}

	Array<T>& operator/=(const T& value) {
		return *this = *this / value;
	}

	//scalars on the left (friends functions)
	friend Array<T> operator+(const T& value, const Array<T>& mat) {
		return mat + value;
	}

	friend Array<T> operator*(const T& value, const Array<T>& mat) {
		return mat * value;
	}

	//transposed
	Array<T> transpose() const {
		Array<T> result(cols, rows);
		for (size_t i = 0; i < rows; ++i)
			for (size_t j = 0; j < cols; ++j)
				result(j, i) = data[i][j];
		return result;
	}
		//print
		friend std::ostream& operator<<(std::ostream & os, const Array<T>&mat) {
			for (size_t i = 0; i < mat.rows; ++i) {
				for (size_t j = 0; j < mat.cols; ++j)
					os << std::setw(5) << mat(i, j) << " ";
				os << "\n";
			}
			return os;
		}
};

