#pragma once
#include <cstdint>
#include <memory>
#include <initializer_list>

using namespace std;

namespace ZZ {
	template<class T, int N>
	struct Vector
	{
		T data[N];
		Vector() = default;
		Vector(const T val)
		{
			Set(val);
		}
		Vector(const T* pval)
		{
			Set(pval)
		}

		void Set(const T val)
		{
			for (size_t i = 0; i < N; i++)
			{
				data[i] = val;
			}
		}

		void Set(const Vector& v)
		{
			memcpy(this, &v, sizeof(v));
		}

		void Set(initializer_list<T> list)
		{
			for (size_t i = 0; i < N; i++)
			{
				data[i] = list[i];
			}
		}

		T* operator()
		{
			return &data[0];
		}
		const T*operator() const
		{
			return &data[0];
		}

		Vector& operator=(const T val)
		{
			Set(val);
			return *this;
		}

		Vector& operator=(const T* pval)
		{
			Set(pval);
			return *this;
		}

		Vector& operator=(const Vector& v)
		{
			Set(v);
			return *this;
		};
	};


	typedef Vector<float, 2> Vector2f;

	typedef Vector<float, 3> Vector3f;
	typedef Vector<double, 3> Vector3;
	typedef Vector<int16_t, 3> Vector3i16;
	typedef Vector<int32_t, 3> Vector3i32;

	typedef Vector<float, 4> Vector4f;
	typedef Vector<uint8_t, 4> R8G8B8A8Unorm;
	typedef Vector<uint8_t, 4> Vector4i;

	// Matrix

	template <typename T, int ROWS, int COLS>
	struct Matrix
	{
		Vector<T, COLS> data[ROWS];

		Vector<T, COLS>& operator[](int row_index) {
			return data[row_index];
		}

		const Vector<T, COLS>& operator[](int row_index) const {
			return data[row_index];
		}

		operator T*() { return &data[0][0]; };
		operator const T*() const { return static_cast<const T*>(&data[0][0]); };

		Matrix& operator=(const T* _data)
		{
			std::memcpy(data, _data, sizeof(T) * COLS * ROWS);
			return *this;
		}

		Matrix& operator=(const Matrix& rhs)
		{
			std::memcpy(data, rhs, sizeof(Matrix));
			return *this;
		}
	};

	typedef Matrix<float, 3, 3> Matrix3X3f;
	typedef Matrix<float, 4, 4> Matrix4X4f;
	typedef Matrix<int32_t, 8, 8> Matrix8X8i;
	typedef Matrix<float, 8, 8> Matrix8X8f;
}