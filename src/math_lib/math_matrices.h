#pragma once

#include <cmath>
#include <iostream>

namespace math_lib 
{
    template <unsigned int DIMS>
    class Mat 
    {
    public:
        static Mat<DIMS> identity()
        {
            static Mat<DIMS> identity = createIdentity();
            return identity;
        }

    public:
        Mat() 
            : m_mat{ 0.0f } {}

        Mat(float mat[DIMS][DIMS])
        {
            for (unsigned int i = 0; i < DIMS; ++i)
                for (unsigned int j = 0; j < DIMS; ++j)
                    m_mat[i][j] = mat[i][j];
        }

        Mat(const Mat& mat) 
        {
            for (unsigned int i = 0; i < DIMS; ++i) 
                for (unsigned int j = 0; j < DIMS; ++j) 
                    m_mat[i][j] = mat.at(i, j);
        }

    public:
        float& operator()(unsigned int row, unsigned int col) 
        {
            if (row >= DIMS || col >= DIMS)
                throw std::out_of_range("Mat");

            return m_mat[row][col];
        }

        inline float at(unsigned int row, unsigned int col) const
        {
            if (row >= DIMS || col >= DIMS)
                throw std::out_of_range("Mat");

            return m_mat[row][col];
        }

        Mat<DIMS> operator+(const Mat<DIMS>& mat) const
        {
            Mat<DIMS> result;
            for (unsigned int i = 0; i < DIMS; ++i)
            {
                for (unsigned int j = 0; j < DIMS; ++j)
                {
                    result(i, j) = m_mat[i][j] + mat.at(i, j);
                }
            }
            return result;
        }

        Mat<DIMS> operator-(const Mat<DIMS>& mat) const
        {
            Mat<DIMS> result;
            for (unsigned int i = 0; i < DIMS; ++i)
            {
                for (unsigned int j = 0; j < DIMS; ++j)
                {
                    result(i, j) = m_mat[i][j] - mat.at(i, j);
                }
            }
            return result;
        }

    public:
        float determinant() const
        {
            switch (DIMS)
            {
            case 0:
                return 0.0f;
            case 1:
                return m_mat[0][0];
            case 2:
                return (m_mat[0][0] * m_mat[1][1]) - (m_mat[0][1] * m_mat[1][0]);
            default:
                break;
            }

            float mat[DIMS][DIMS];
            std::copy(&m_mat[0][0], &m_mat[0][0] + DIMS * DIMS, &mat[0][0]);

            float det = 1.0;
            for (int i = 0; i < DIMS; i++)
            {
                int pivot = i;
                
                for (int j = i + 1; j < DIMS; j++)
                {
                    if (std::abs(mat[j][i]) > std::abs(mat[pivot][i]))
                    {
                        pivot = j;
                    }
                }
                
                if (pivot != i)
                {
                    std::swap(mat[i], mat[pivot]);
                    det *= -1;
                }
                
                if (mat[i][i] == 0)
                {
                    return 0.0f;
                }
                
                det *= mat[i][i];
                for (int j = i + 1; j < DIMS; j++)
                {
                    float factor = mat[j][i] / mat[i][i];
                    for (int k = i + 1; k < DIMS; k++)
                    {
                        mat[j][k] -= factor * mat[i][k];
                    }
                }
            }
            return det;
        }

        Mat<DIMS> adjoint() const
        {
            float adjoint[DIMS][DIMS] = { 0.0f };
            switch (DIMS)
            {
            case 2:
                adjoint[0][0] = m_mat[1][1];
                adjoint[1][1] = m_mat[0][0];
                adjoint[0][1] = -m_mat[0][1];
                adjoint[1][0] = -m_mat[1][0];
                return Mat<DIMS>(adjoint);
            default:
                break;
            }

            return Mat<DIMS>(adjoint);
        }

    private:
        static Mat<DIMS> createIdentity()
        {
            Mat<DIMS> identity;
            for (unsigned int i = 0; i < DIMS; ++i)
            {
                identity(i, i) = 1.0f;
            }
            return identity;
        }

    private:
        float m_mat[DIMS][DIMS];
    };

    template <unsigned int DIMS>
    Mat<DIMS> operator*(float scalar, const Mat<DIMS>& mat)
    {
        Mat<DIMS> result;
        for (unsigned int i = 0; i < DIMS; ++i)
        {
            for (unsigned int j = 0; j < DIMS; ++j)
            {
                result(i, j) = scalar * mat.at(i,j);
            }
        }
        return result;
    }

    template <unsigned int DIMS>
    Mat<DIMS> operator*(const Mat<DIMS>& matA, const Mat<DIMS>& matB)
    {
        Mat<DIMS> result;
        for (unsigned int i = 0; i < DIMS; ++i)
        {
            for (unsigned int j = 0; j < DIMS; ++j)
            {
                result(i,j) = 0;
                for (unsigned int k = 0; k < DIMS; ++k)
                {
                    result(i,j) += matA.at(i,k) * matB.at(k,j);
                }
            }
        }
        return result;
    }

    template <unsigned int DIMS>
    Mat<DIMS> operator/(float scalar, const Mat<DIMS>& mat)
    {
        return (1/scalar) * mat;
    }
} // namespace math_lib