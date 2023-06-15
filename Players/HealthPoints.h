#ifndef MTM4_HEALTHPOINTS_H
#define MTM4_HEALTHPOINTS_H
#include <iostream>

class HealthPoints {
public:
    HealthPoints( const int hp = m_defaultHP);
    HealthPoints& operator-=(const int);
    HealthPoints& operator+=(const int);
    HealthPoints& operator=(const int);
    int getCurrentHP() const;
    // Default Copy C'tor, D'tor and assigment operator
    HealthPoints(const HealthPoints&) = default;
    HealthPoints& operator=(const HealthPoints&) = default;
    ~HealthPoints() = default;

    // Exceptions
    class InvalidArgument{};

private:
    int m_maxHP;
    int m_currentHP;
    static const int m_defaultHP = 100;

    friend bool operator>(const HealthPoints&, const HealthPoints&);
    friend std::ostream& operator<<(std::ostream&, const HealthPoints&);
};
bool operator==(const HealthPoints&, const HealthPoints&);
HealthPoints operator+(const HealthPoints&,const int);
HealthPoints operator-(const HealthPoints& ,const int);
// Bidirectional compatibility
HealthPoints operator+(const int,const HealthPoints&);
HealthPoints operator-(const int,const HealthPoints&);

// Boolean operators
bool operator!=(const HealthPoints&, const HealthPoints&);
bool operator>=(const HealthPoints&, const HealthPoints&);
bool operator<=(const HealthPoints&, const HealthPoints&);
bool operator<(const HealthPoints&, const HealthPoints&);

#endif //MTM4_HEALTHPOINTS_H
