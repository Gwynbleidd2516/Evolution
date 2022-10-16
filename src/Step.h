#pragma once

#include"SFML/Graphics.hpp"
#include<vector>
#include"Map.h"
#include"Creatures.h"
#include"Voidness.h"

//#define DEBUG_STEP
#ifdef DEBUG_STEP
#include<iostream>
#endif

using namespace sf;
using namespace std;

class Step : public Creature
{
public:
    void doStep(Map & map, vector<Creature> & creatures, Voidness & voidness);

};