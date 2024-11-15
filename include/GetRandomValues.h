#pragma once
#include <random>
#include <iostream>

bool get_random_wozek()
{
    std::random_device rd;
    std::mt19937 bl(rd());
    std::uniform_int_distribution<int> dist(0, 1);
    return dist(bl);
}
int get_random_obserwujacy()
{
    std::random_device rd;
    std::mt19937 it(rd());
    std::uniform_int_distribution<unsigned int> dist(1000, 10000000);
    return dist(it);
}
double get_random_but()
{
    std::random_device rd;
    std::mt19937 db(rd());
    std::uniform_real_distribution<double> dist(37.0, 50.0);
    return dist(db);
}
