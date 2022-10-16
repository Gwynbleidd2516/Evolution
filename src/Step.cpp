#include"Step.h"

void Step::doStep(Map & map, vector<Creature> & creatures, Voidness & voidness)
{
    for (int i = 0; i < creatures.size(); ++i)
    {
        int r = -1;

        while (r < creatures[i].comands.size())
        {
            r++;
            int comand = creatures[i].comands[r];

            if (creatures[i].comands[r] < 8)
            {
                Direction dir=creatures[i].getDirection();

                Vector2i cord_in_future;
                Vector2i cord_now;

                switch (dir)
                {
                case Direction::LEFT_UP:
                
                    cord_in_future=Vector2i(creatures[i].getCordinats().x-1, creatures[i].getCordinats().y-1);
                    cord_now=Vector2i(creatures[i].getCordinats().x, creatures[i].getCordinats().y);
                    
                    if(map.getObject(cord_in_future)==Object::Voidness)
                    {
                        map.setObject(cord_in_future,creatures[i]);
                        map.setObject(cord_now,voidness);
                        creatures[i].setCordinats(cord_in_future);
                        r+=comand;
                        if(r>=comands.size())
                        {
                            r-=comands.size();
                        }
                        break;
                    }
                
                    break;
                case Direction::UP:
                
                    cord_in_future=Vector2i(creatures[i].getCordinats().x, creatures[i].getCordinats().y-1);
                    cord_now=Vector2i(creatures[i].getCordinats().x, creatures[i].getCordinats().y);
                    
                    if(map.getObject(cord_in_future)==Object::Voidness)
                    {
                        map.setObject(cord_in_future,creatures[i]);
                        map.setObject(cord_now,voidness);
                        creatures[i].setCordinats(cord_in_future);
                        r+=comand;
                        if(r>=comands.size())
                        {
                            r-=comands.size();
                        }
                        break;
                    }

                    break;
                case Direction::RIGHT_UP:
                
                    cord_in_future=Vector2i(creatures[i].getCordinats().x+1, creatures[i].getCordinats().y-1);
                    cord_now=Vector2i(creatures[i].getCordinats().x, creatures[i].getCordinats().y);
                    
                    if(map.getObject(cord_in_future)==Object::Voidness)
                    {
                        map.setObject(cord_in_future,creatures[i]);
                        map.setObject(cord_now,voidness);
                        creatures[i].setCordinats(cord_in_future);
                        r+=comand;
                        if(r>=comands.size())
                        {
                            r-=comands.size();
                        }
                        break;
                    }

                    break;

                case Direction::RIGHT:
                
                    cord_in_future=Vector2i(creatures[i].getCordinats().x+1, creatures[i].getCordinats().y);
                    cord_now=Vector2i(creatures[i].getCordinats().x, creatures[i].getCordinats().y);
                    
                    if(map.getObject(cord_in_future)==Object::Voidness)
                    {
                        map.setObject(cord_in_future,creatures[i]);
                        map.setObject(cord_now,voidness);
                        creatures[i].setCordinats(cord_in_future);
                        r+=comand;
                        if(r>=comands.size())
                        {
                            r-=comands.size();
                        }
                        break;
                    }
                
                    break;

                case Direction::DOWN_RIGHT:
                
                    cord_in_future=Vector2i(creatures[i].getCordinats().x+1, creatures[i].getCordinats().y+1);
                    cord_now=Vector2i(creatures[i].getCordinats().x, creatures[i].getCordinats().y);
                    
                    if(map.getObject(cord_in_future)==Object::Voidness)
                    {
                        map.setObject(cord_in_future,creatures[i]);
                        map.setObject(cord_now,voidness);
                        creatures[i].setCordinats(cord_in_future);
                        r+=comand;
                        if(r>=comands.size())
                        {
                            r-=comands.size();
                        }
                        break;
                    }
                
                    break;
                case Direction::DOWN:
                
                    cord_in_future=Vector2i(creatures[i].getCordinats().x, creatures[i].getCordinats().y+1);
                    cord_now=Vector2i(creatures[i].getCordinats().x, creatures[i].getCordinats().y);
                    
                    if(map.getObject(cord_in_future)==Object::Voidness)
                    {
                        map.setObject(cord_in_future,creatures[i]);
                        map.setObject(cord_now,voidness);
                        creatures[i].setCordinats(cord_in_future);
                        r+=comand;
                        if(r>=comands.size())
                        {
                            r-=comands.size();
                        }
                        break;
                    }
                
                    break;
                case Direction::DOWN_LEFT:
                
                    cord_in_future=Vector2i(creatures[i].getCordinats().x-1, creatures[i].getCordinats().y+1);
                    cord_now=Vector2i(creatures[i].getCordinats().x, creatures[i].getCordinats().y);
                    
                    if(map.getObject(cord_in_future)==Object::Voidness)
                    {
                        map.setObject(cord_in_future,creatures[i]);
                        map.setObject(cord_now,voidness);
                        creatures[i].setCordinats(cord_in_future);
                        r+=comand;
                        if(r>=comands.size())
                        {
                            r-=comands.size();
                        }
                        break;
                    }
                
                    break;
                case Direction::LEFT:
                
                    cord_in_future=Vector2i(creatures[i].getCordinats().x-1, creatures[i].getCordinats().y);
                    cord_now=Vector2i(creatures[i].getCordinats().x, creatures[i].getCordinats().y);
                    
                    if(map.getObject(cord_in_future)==Object::Voidness)
                    {
                        map.setObject(cord_in_future,creatures[i]);
                        map.setObject(cord_now,voidness);
                        creatures[i].setCordinats(cord_in_future);
                        r+=comand;
                        if(r>=comands.size())
                        {
                            r-=comands.size();
                        }
                        break;
                    }
                
                    break;
                }
            }


            if (comand >= 8 && comand < 16)
            {
                switch (comand)
                {
                case 8:
                    creatures[i].setDirection(Direction::LEFT_UP);
                    
                    break;
                case 9:
                    creatures[i].setDirection(Direction::UP);
                    
                    break;
                case 10:
                    creatures[i].setDirection(Direction::RIGHT_UP);
                    r+=comand;
                    
                    break;
                case 11:
                    creatures[i].setDirection(Direction::RIGHT);
                    
                    break;
                case 12:
                    creatures[i].setDirection(Direction::DOWN_RIGHT);
                    
                    break;
                case 13:
                    creatures[i].setDirection(Direction::DOWN);
                    
                    break;
                case 14:
                    creatures[i].setDirection(Direction::DOWN_LEFT);
                    
                    break;
                case 15:
                    creatures[i].setDirection(Direction::LEFT);
                    
                    break;
                }
            }
        }
    }
}