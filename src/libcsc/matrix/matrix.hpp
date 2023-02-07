#include <iostream>
#include <random>
#include <iterator>

namespace myMatrix
{
    template <typename T>
    class Matrix
    {
    private:
        T *data = nullptr;
        size_t rows;
        size_t cols;

    public:
        Matrix() : data(nullptr), rows(0), cols(0) {}

        Matrix(size_t rows, size_t cols) : data(new T[rows * cols]), rows(rows), cols(cols) {}

        Matrix(const Matrix &other) : data(new T[other.rows * other.cols]), rows(other.rows), cols(other.cols)
        {
            for (size_t i = 0; i < rows * cols; ++i)
            {
                data[i] = other.data[i];
            }
        }

        Matrix &operator=(const Matrix<T> &other)
        {
            if (&other == this)
            {
                return *this;
            }

            clean();

            rows = other.rows;
            cols = other.cols;
            data = new T[other.rows * other.cols];

            for (size_t i = 0; i < rows * cols; ++i)
            {
                data[i] = other.data[i];
            }

            return *this;
        }

        Matrix(Matrix &&other) noexcept : data(other.data), rows(other.rows), cols(other.cols)
        {
            other.data = nullptr;
            other.rows = 0;
            other.cols = 0;
        }

        Matrix &operator=(Matrix<T> &&other) noexcept
        {
            if (&other == this)
            {
                return *this;
            }

            clean();

            std::swap(data, other.data);
            std::swap(rows, other.rows);
            std::swap(cols, other.cols);

            other.data = nullptr;
            other.rows = 0;
            other.cols = 0;

            return *this;
        }

        ~Matrix() { clean(); }
    public:
        class Iterator
        {
            friend Matrix;

        private:
            T *curr = nullptr;

        public:
            using iterator_category = std::input_iterator_tag;
            using value_type = T;
            using difference_type = std::ptrdiff_t;
            using pointer = value_type *;
            using reference = value_type &;

            Iterator() = default;

            explicit Iterator(T *other) : curr(other) {}

            ~Iterator() = default;

            bool operator==(const Iterator &it) const { return curr == it.curr; }
            bool operator!=(const Iterator &it) const { return curr != it.curr; }

            Iterator &operator++()
            {
                ++curr;
                return *this;
            }

            Iterator operator++(int)
            {
                Iterator temp = *this;
                operator++();
                return temp;
            }

            Iterator &operator+(int n)
            {
                for (int i = 0; i < n; i++)
                {
                    ++(*this);
                }
                return *this;
            }

            T &operator*() const { return *curr; }

            T *operator->() const { return curr; }
        };

        Iterator begin()
        {
            Iterator it(data);
            return it;
        }

        Iterator end()
        {
            Iterator it(data + rows * cols);
            return it;
        }

        void clean()
        {
            rows = 0;
            cols = 0;
            delete[] data;
        }

        [[nodiscard]] size_t getRows() const
        {
            return rows;
        }
        [[nodiscard]] size_t getCols() const
        {
            return cols;
        }

        Matrix<T> operator*(const Matrix<T> &other)
        {
            Matrix<T> result(rows, other.cols);
            if (cols == other.rows)
            {
                for (size_t i = 0; i < rows; i++)
                {
                    for (size_t j = 0; j < other.cols; j++)
                    {
                        result.data[i * other.cols + j] = 0.0;

                        for (size_t k = 0; k < cols; k++)
                        {
                            result.data[i * other.cols + j] += data[i * cols + k] * other.data[k * other.cols + j];
                        }
                    }
                }
            }
            else
            {
                throw std::logic_error("Размеры матриц не совпадают");
            }
            return result;
        }

        Matrix<T> operator+(const Matrix<T> &other)
        {
            Matrix result(rows, cols);
            if (rows == other.rows && cols == other.cols)
            {
                for (size_t i = 0; i < rows * cols; i++)
                {
                    result.data[i] = data[i] + other.data[i];
                }
            }
            else
            {
                throw std::logic_error("Размеры матриц не совпадают");
            }
            return result;
        }

        Matrix<T> operator-(const Matrix<T> &other)
        {
            Matrix result(rows, cols);
            if (rows == other.rows && cols == other.cols)
            {

                for (size_t i = 0; i < rows * cols; i++)
                {
                    result.data[i] = data[i] - other.data[i];
                }
            }
            else
            {
                throw std::logic_error("Размеры матриц не совпадают");
            }
            return result;
        }

        void fillMatrix()
        {
            for (size_t i = 0; i < rows * cols; i++)
            {
                data[i] = static_cast<T>(random() % 100);
            }
        }
        void printMatrix()
        {
            for (size_t i = 0; i < rows * cols; i++)
            {
                std::cout << data[i] << " ";
            }
            std::cout << std::endl;
        }

        const T *operator[](size_t value) const
        {
            return &data[value * cols];
        }

        T *operator[](size_t value)
        {
            return &data[value * cols];
        }
    };
} //namespace myMatrix
