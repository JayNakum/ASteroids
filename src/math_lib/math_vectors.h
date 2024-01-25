#pragma once

#include <cmath>

namespace math_lib 
{
    class Vec2 
    {
    public:
        static const short int DIMS = 2;

        Vec2();
        Vec2(float v);
        Vec2(float v1, float v2);
        Vec2(float vec[2]);
        Vec2(const Vec2& vec);

    public:
        inline float x() const { return m_vec[0]; }
        inline float y() const { return m_vec[1]; }

        inline float u() const { return m_vec[0]; }
        inline float v() const { return m_vec[1]; }

    public:
        float& operator[](unsigned int index);
        float at(unsigned int index) const;

        Vec2 operator+(Vec2 vec) const;

        Vec2 operator-() const;
        Vec2 operator-(Vec2 vec) const;

        Vec2 operator*(float scaler) const;
        float* operator*();

        float magnitude() const;

        float dot(const Vec2& vec) const;

        float cross(const Vec2& vec) const;

    private:
        float m_vec[2];
    };

    class Vec3 
    {
    public:
        static const short int DIMS = 3;

        Vec3();
        Vec3(float v);
        Vec3(float v1, float v2, float v3);
        Vec3(float vec[3]);
        Vec3(const Vec3& vec);

    public:
        inline float x() const { return m_vec[0]; }
        inline float y() const { return m_vec[1]; }
        inline float z() const { return m_vec[2]; }

        inline float r() const { return m_vec[0]; }
        inline float g() const { return m_vec[1]; }
        inline float b() const { return m_vec[2]; }

        inline float u() const { return m_vec[0]; }
        inline float v() const { return m_vec[1]; }
        inline float w() const { return m_vec[2]; }

    public:
        float& operator[](unsigned int index);
        float at(unsigned int index) const;

        Vec3 operator+(Vec3 vec) const;

        Vec3 operator-() const;
        Vec3 operator-(Vec3 vec) const;

        Vec3 operator*(float scaler) const;

        float magnitude() const;

        float dot(const Vec3& vec) const;

        Vec3 cross(const Vec3& vec) const;

    private:
        float m_vec[3];
    };

    class Vec4 
    {
    public:
        static const short int DIMS = 4;

        Vec4();
        Vec4(float v);
        Vec4(float v1, float v2, float v3, float v4);
        Vec4(float vec[4]);
        Vec4(const Vec4& vec);

    public:
        inline float x() const { return m_vec[0]; }
        inline float y() const { return m_vec[1]; }
        inline float z() const { return m_vec[2]; }
        inline float w() const { return m_vec[3]; }

        inline float r() const { return m_vec[0]; }
        inline float g() const { return m_vec[1]; }
        inline float b() const { return m_vec[2]; }
        inline float a() const { return m_vec[3]; }

    public:
        float& operator[](unsigned int index);
        float at(unsigned int index) const;

        Vec4 operator+(Vec4 vec) const;

        Vec4 operator-() const;
        Vec4 operator-(Vec4 vec) const;

        Vec4 operator*(float scaler) const;

        float magnitude() const;

        float dot(const Vec4& vec) const;

    private:
        float m_vec[4];
    };
} // namespace math_lib