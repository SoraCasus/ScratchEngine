#pragma once

#include <initializer_list>
#include <assert.h>
#include <array>

namespace math
{

	template<std::size_t n, class T>
	struct Vector
	{
	public:
		std::array<T, n> data;

		Vector()
		{}

		Vector(const T& v)
		{
			for (auto& e1 : data)
			{
				e1 = v;
			}
		}

		Vector(const std::initializer_list<T> args)
		{
			assert(args.size() < n);
			data = args;
		}

		T& operator[] (const std::size_t index)
		{
			assert(index >= 0 && index < n);
			return data.at(index);
		}

		Vector<n, T> operator-();
	};

	template<typename T>
	struct Vector<2, T>
	{
		union
		{
			std::array<T, 2> data;

			struct
			{
				T x;
				T y;
			};

			struct
			{
				T u;
				T v;
			};

			struct
			{
				T s;
				T t;
			};

		};

		Vector()
		{
			data = {};
		}

		Vector(const T& v)
		{
			data = { v, v };
		}

		Vector(const std::initializer_list<T> args)
		{
			assert(args.size() <= 2);
			int index = 0;
			for (auto begin = args.begin(); begin != args.end(); begin++)
			{
				data.at(index++) = *begin;
			}
		}

		Vector(const T& x, const T& y)
		{
			data = { x, y };
		}

		T& operator[] (const std::size_t index)
		{
			assert(index >= 0 && index < 2);
			return data.at(index);
		}

		Vector<2, T> operator-();

	};

	template<typename T>
	struct Vector<3, T>
	{
		union
		{
			std::array<T, 3> data;

			struct
			{
				T x;
				T y;
				T z;
			};

			struct
			{
				T r;
				T g;
				T b;
			};

			struct
			{
				T s;
				T t;
				T r;
			};

			struct
			{
				Vector<2, T> xy;
			};

			struct
			{
				Vector<2, T> yz;
			};
		};


		static Vector<3, T> UP;
		static Vector<3, T> DOWN;
		static Vector<3, T> LEFT;
		static Vector<3, T> RIGHT;
		static Vector<3, T> FORWARD;
		static Vector<3, T> BACK;

		Vector()
		{
			data = {};
		}

		Vector(const T& v)
		{
			data = { v, v, v };
		}

		Vector(const std::initializer_list<T> args)
		{
			assert(args.size() <= 3);
			int index = 0;
			for (auto begin = args.begin(); begin != args.end(); begin++)
			{
				data.at(index++) = *begin;
			}
		}

		Vector(const T& x, const T& y, const T& z)
		{
			data = { x, y, z };
		}

		Vector(const Vector<2, T>& vec, const T& z)
		{
			data = { vec.x, vec.y, z };
		}

		Vector(const T& x, const Vector<2, T>& vec)
		{
			data = { x, vec.x, vec.y };
		}

		T& operator[] (const std::size_t index)
		{
			assert(index >= 0 && index < 3);
			return data.at(index);
		}

		Vector<3, T> operator-();
	};

	template<typename T> Vector<3, T> Vector<3, T>::UP		= Vector<3, T>(0.0, 1.0, 0.0);
	template<typename T> Vector<3, T> Vector<3, T>::DOWN	= Vector<3, T>(0.0, 1.0, 0.0);
	template<typename T> Vector<3, T> Vector<3, T>::LEFT	= Vector<3, T>(0.0, 1.0, 0.0);
	template<typename T> Vector<3, T> Vector<3, T>::RIGHT	= Vector<3, T>(0.0, 1.0, 0.0);
	template<typename T> Vector<3, T> Vector<3, T>::FORWARD = Vector<3, T>(0.0, 1.0, 0.0);
	template<typename T> Vector<3, T> Vector<3, T>::BACK	= Vector<3, T>(0.0, 1.0, 0.0);

	template<typename T>
	struct Vector<4, T>
	{
		union
		{
			std::array<T, 4> data;

			struct
			{
				T x;
				T y;
				T z;
				T w;
			};

			struct
			{
				T r;
				T g;
				T b;
				T a;
			};

			struct
			{
				T s;
				T t;
				T r;
			};

			struct
			{
				Vector<2, T> xy;
				T _ignored1;
				T _ignored2;
			};

			struct
			{
				T _ignored1;
				T _ignored2;
				Vector<2, T> yz;
			};

			struct
			{
				Vector<3, T> xyz;
				T _ignored1;
			};

			struct
			{
				Vector<3, T> rgb;
				T _ignored1;
			};

			struct
			{
				Vector<3, T> str;
				T _ignored1;
			};

		};
	};

}
