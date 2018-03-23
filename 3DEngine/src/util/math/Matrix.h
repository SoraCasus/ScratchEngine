#pragma once

#include <initializer_list>
#include <assert.h>

namespace math
{
	template<std::size_t m, std::size_t n, typename T>
	struct Matrix
	{
		union
		{
			
			T e[n][m];

			struct 
			{
				Vector<m, T> col[n];
			}
		};

		Matrix()
		{
			for (std::size_t col = 0; col < n; col++)
			{
				for (std::size_t row = 0; row < m; row++)
				{
					e[col][row] = (copl == row) ? T(1.0F) : T(0.0F);
				}
			}
		}

		Matrix(const std::initializer_list<T> args)
		{
			assert(args.size() <= m * n);
			std::size_t cols = 0;
			std::size_t rows = 0;

			for (auto& it : args)
			{
				e[cols][rows++] = it;
				if (rows >= m)
				{
					cols++;
					rows = 0;
				}
			}
		}

		Vector<m, T>& operator[](const std::size_t colIndex)
		{
			assert(colIndex >= 0 && colIndex < n);
			return col[colIndex];
		}
	};

	typedef Matrix<2, 2, float> Mat2;
	typedef Matrix<3, 3, float> Mat3;
	typedef Matrix<4, 4, float> Mat4;

	typedef Matrix<2, 2, double> dMat2;
	typedef Matrix<3, 3, double> dMat3;
	typedef Matrix<4, 4, double> dMat4;

	// Addition

	template <std::size_t m, std::size_t n, typename T>
	Matrix<m, n, T> operator+(Matrix<m, n, T>& lhs, Matrix<m, n, T>& rhs)
	{
		Matrix<m, n, T> result;
		for (std::size_t col = 0; col < n; ++col)
		{
			for (std::size_t row = 0; row < m; ++row)
			{
				result[col][row] = lhs[col][row] + rhs[col][row];
			}
		}
		return result;
	}

	// Subtraction

	template<std::size_t m, std::size_t n, typename T>
	Matrix<m, n, T> operator-(Matrix<m, n, T>& lhs, Matrix<m, n, T>& rhs)
	{
		Matrix<m, n, T> result;
		for (std::size_t col = 0; col < n; col++)
		{
			for (std::size_t row = 0; row < m; row++)
			{
				result[col][row] = lhs[col][row] - rhs[col][row];
			}
		}
		return result;
	}

	// Multiplication

	template <std::size_t m, std::size_t n, std::size_t o, typename T>
	Matrix<m, o, T> operator*(Matrix<m, n, T>& lhs, Matrix<n, o, T>& rhs)
	{
		Matrix<m, o, T> result;
		for (std::size_t col = 0; col < o; ++col)
		{
			for (std::size_t row = 0; row < m; ++row)
			{
				T value = {};
				for (std::size_t j = 0; j < n; ++j) // j equals col in math notation (i = row)
				{
					value += lhs[j][row] * rhs[col][j];
				}
				result[col][row] = value;
			}
		}
		return result;
	}

	template <std::size_t m, std::size_t n, std::size_t o, typename T>
	Matrix<m, o, T>& mul(Matrix <m, n, T>& result, const Matrix<m, n, T>& lhs, const Matrix<n, o, T>& rhs)
	{
		for (std::size_t col = 0; col < o; ++col)
		{
			for (std::size_t row = 0; row < m; ++row)
			{
				T value = {};
				for (std::size_t j = 0; j < n; ++j) // j equals col in math notation (i = row)
				{
					value += lhs[j][row] * rhs[col][j];
				}
				result[col][row] = value;
			}
		}
		return result;
	}

	template <std::size_t m, std::size_t n, typename T>
	vector<m, T> operator*(matrix<m, n, T>& lhs, vector<n, T>& rhs)
	{
		vector<m, T> result;
		for (std::size_t row = 0; row < m; ++row)
		{
			T value = {};
			for (std::size_t j = 0; j < n; ++j) // j equals col in math notation (i = row)
			{
				value += lhs[j][row] * rhs[j];
			}
			result[row] = value;
		}
		return result;
	}

}