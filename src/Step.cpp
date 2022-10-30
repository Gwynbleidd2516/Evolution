#include"Step.h"

void Step::doStep(Map & map, vector<Creature> & creatures, Voidness & voidness, Food& food, Poison& poison)
{
    srand(time(0));
    for (int i = 0; i < creatures.size(); i++)
    {
        int r = -1;
        if(!creatures[i].isDead()) 
        {
            while (true/*r > creatures[i].comands.size()-1*/)
            {
                r++;
            
                if(r>=creatures[i].comands.size())
                {
                    break;
                }

                int comand = creatures[i].comands[r];


                if (comand < 8)
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
                            r=creatures[i].comands.size()+2;

                        }
                        #ifdef DEBUG_STEP
                            cout<<"LEFT_UP"<<endl;
                            #endif
                        break;
                    case Direction::UP:
                    
                        cord_in_future=Vector2i(creatures[i].getCordinats().x, creatures[i].getCordinats().y-1);
                        cord_now=Vector2i(creatures[i].getCordinats().x, creatures[i].getCordinats().y);
                        
                        if(map.getObject(cord_in_future)==Object::Voidness)
                        {
                            map.setObject(cord_in_future, creatures[i]);
                            map.setObject(cord_now,voidness);
                            creatures[i].setCordinats(cord_in_future);
                            r=creatures[i].comands.size()+2;

                            #ifdef DEBUG_STEP
                            cout<<"UP"<<endl;
                            #endif

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
                            r=creatures[i].comands.size()+2;

                            #ifdef DEBUG_STEP
                            cout<<"RIGHT_UP"<<endl;
                            #endif

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
                            r=creatures[i].comands.size()+2;

                            #ifdef DEBUG_STEP
                            cout<<"RIGHT"<<endl;
                            #endif

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
                            r=creatures[i].comands.size()+2;
                            

                            #ifdef DEBUG_STEP
                            cout<<"DOWN_RIGHT"<<endl;
                            #endif

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
                            r=creatures[i].comands.size()+2;

                            #ifdef DEBUG_STEP
                            cout<<"DOWN"<<endl;
                            #endif

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
                            r=creatures[i].comands.size()+2;

                            #ifdef DEBUG_STEP
                            cout<<"DOWN_LEFT"<<endl;
                            #endif

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
                            r=creatures[i].comands.size()+2;

                            #ifdef DEBUG_STEP
                            cout<<"LEFT"<<endl;
                            #endif

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

                        #ifdef DEBUG_STEP
                            cout<<"setLEFT_UP"<<endl;
                        #endif
                        
                        break;
                    case 9:
                        creatures[i].setDirection(Direction::UP);

                        #ifdef DEBUG_STEP
                            cout<<"setUP"<<endl;
                        #endif
                        
                        break;
                    case 10:
                        creatures[i].setDirection(Direction::RIGHT_UP);

                        #ifdef DEBUG_STEP
                            cout<<"setRIGHT_UP"<<endl;
                        #endif
                        
                        break;
                    case 11:
                        creatures[i].setDirection(Direction::RIGHT);
                        
                        #ifdef DEBUG_STEP
                            cout<<"setRIGHT"<<endl;
                        #endif

                        break;
                    case 12:
                        creatures[i].setDirection(Direction::DOWN_RIGHT);
                        
                        #ifdef DEBUG_STEP
                            cout<<"setDOWN_RIGHT"<<endl;
                        #endif

                        break;
                    case 13:
                        creatures[i].setDirection(Direction::DOWN);

                        #ifdef DEBUG_STEP
                            cout<<"setDOWN"<<endl;
                        #endif
                        
                        break;
                    case 14:
                        creatures[i].setDirection(Direction::DOWN_LEFT);

                        #ifdef DEBUG_STEP
                            cout<<"setDOWN_LEFT"<<endl;
                        #endif
                        
                        break;
                    case 15:
                        creatures[i].setDirection(Direction::LEFT);
                        
                        #ifdef DEBUG_STEP
                            cout<<"setLEFT"<<endl;
                        #endif

                        break;
                    }
                }

                if(comand>=16 && comand<24)
                {
                    Vector2i cord;

                    switch (comand)
                    {
                    case 16:
                        cord=Vector2i(creatures[i].getCordinats().x-1,creatures[i].getCordinats().y-1);
                        
                        
                        break;
                    case 17:
                        cord=Vector2i(creatures[i].getCordinats().x,creatures[i].getCordinats().y-1);
                        
                        break;
                    case 18:
                        cord=Vector2i(creatures[i].getCordinats().x+1,creatures[i].getCordinats().y-1);
                        
                        break;
                    case 19:
                        cord=Vector2i(creatures[i].getCordinats().x+1,creatures[i].getCordinats().y);
                        
                        break;
                    case 20:
                        cord=Vector2i(creatures[i].getCordinats().x+1,creatures[i].getCordinats().y+1);
                        
                        break;
                    case 21:
                        cord=Vector2i(creatures[i].getCordinats().x,creatures[i].getCordinats().y+1);
                        
                        break;
                    case 22:
                        cord=Vector2i(creatures[i].getCordinats().x-1,creatures[i].getCordinats().y+1);
                        
                        break;
                    case 23:
                        cord=Vector2i(creatures[i].getCordinats().x-1,creatures[i].getCordinats().y);
                        
                        break;
                    }

                    int x,y;

                    if(map.getObject(cord)==Object::Food)
                    {
                        map.setObject(cord, voidness);
                        creatures[i]+=food.getFood();
                        if(!creatures[i].isDead())
                            map.setObject(creatures[i].getCordinats(), creatures[i]);
                        while(true)
                        {
                            x=rand()%map.getWidth();
                            y=rand()%map.getHeight();
                            if(map.getObject(x,y)==Object::Voidness)
                            {
                                map.setObject(x,y,food);
                                break;
                            }
                        }
                    }

                    if(map.getObject(cord)==Object::Poison)
                    {
                        map.setObject(cord, voidness);
                        creatures[i]-=poison.getPoison();
                        if(!creatures[i].isDead())
                            map.setObject(creatures[i].getCordinats(), creatures[i]);
                        while(true)
                        {
                            x=rand()%map.getWidth();
                            y=rand()%map.getHeight();
                            if(map.getObject(x,y)==Object::Voidness)
                            {
                                map.setObject(x,y,poison);
                                break;
                            }
                        }
                    }
                }

                if(comand>=24 && comand<32)
                {
                    Vector2i cord;
                    switch (comand)
                    {
                    case 24:
                        cord=Vector2i(creatures[i].getCordinats().x-1,creatures[i].getCordinats().y-1);

                        if(map.getObject(cord)==Object::Poison)
                        {
                            map.setObject(cord, food);
                            #ifdef DEBUG_STEP
                            cout<<"ChANGE_POISON"<<endl;
                            #endif
                        }
                        break;
                    case 25:
                        cord=Vector2i(creatures[i].getCordinats().x,creatures[i].getCordinats().y-1);
                        
                        if(map.getObject(cord)==Object::Poison)
                        {
                            map.setObject(cord, food);
                            #ifdef DEBUG_STEP
                            cout<<"ChANGE_POISON"<<endl;
                            #endif
                        }
                        break;
                    case 26:
                        cord=Vector2i(creatures[i].getCordinats().x+1,creatures[i].getCordinats().y-1);
                        
                        if(map.getObject(cord)==Object::Poison)
                        {
                            map.setObject(cord, food);
                            #ifdef DEBUG_STEP
                            cout<<"ChANGE_POISON"<<endl;
                            #endif
                        }
                        break;
                    case 27:
                        cord=Vector2i(creatures[i].getCordinats().x+1,creatures[i].getCordinats().y);
                        
                        if(map.getObject(cord)==Object::Poison)
                        {
                            map.setObject(cord, food);
                            #ifdef DEBUG_STEP
                            cout<<"ChANGE_POISON"<<endl;
                            #endif
                        }
                        break;
                    case 28:
                        cord=Vector2i(creatures[i].getCordinats().x+1,creatures[i].getCordinats().y+1);
                        
                        if(map.getObject(cord)==Object::Poison)
                        {
                            map.setObject(cord, food);
                            #ifdef DEBUG_STEP
                            cout<<"ChANGE_POISON"<<endl;
                            #endif
                        }
                        break;
                    case 29:
                        cord=Vector2i(creatures[i].getCordinats().x,creatures[i].getCordinats().y+1);
                        
                        if(map.getObject(cord)==Object::Poison)
                        {
                            map.setObject(cord, food);
                            #ifdef DEBUG_STEP
                            cout<<"ChANGE_POISON"<<endl;
                            #endif
                        }
                        break;
                    case 30:
                        cord=Vector2i(creatures[i].getCordinats().x-1,creatures[i].getCordinats().y+1);
                        
                        if(map.getObject(cord)==Object::Poison)
                        {
                            map.setObject(cord, food);
                            #ifdef DEBUG_STEP
                            cout<<"ChANGE_POISON"<<endl;
                            #endif
                        }
                        break;
                    case 31:
                        cord=Vector2i(creatures[i].getCordinats().x-1,creatures[i].getCordinats().y);
                        
                        if(map.getObject(cord)==Object::Poison)
                        {
                            map.setObject(cord, food);
                            #ifdef DEBUG_STEP
                            cout<<"ChANGE_POISON"<<endl;
                            #endif
                        }
                        break;
                    }
                }
                
                if(comand>=32 && comand<40)
                {
                    Vector2i cord;
                    switch (comand)
                    {
                    case 32:
                        cord=Vector2i(creatures[i].getCordinats().x-1,creatures[i].getCordinats().y-1);

                        break;
                    case 33:
                        cord=Vector2i(creatures[i].getCordinats().x,creatures[i].getCordinats().y-1);
                        
                        break;
                    case 34:
                        cord=Vector2i(creatures[i].getCordinats().x+1,creatures[i].getCordinats().y-1);
                        
                        break;
                    case 35:
                        cord=Vector2i(creatures[i].getCordinats().x+1,creatures[i].getCordinats().y);
                        
                        break;
                    case 36:
                        cord=Vector2i(creatures[i].getCordinats().x+1,creatures[i].getCordinats().y+1);
                        
                        break;
                    case 37:
                        cord=Vector2i(creatures[i].getCordinats().x,creatures[i].getCordinats().y+1);
                        
                        break;
                    case 38:
                        cord=Vector2i(creatures[i].getCordinats().x-1,creatures[i].getCordinats().y+1);
                        
                        break;
                    case 39:
                        cord=Vector2i(creatures[i].getCordinats().x-1,creatures[i].getCordinats().y);
                        
                        break;
                    }

                    if(map.getObject(cord)==Object::Creature)
                    {
                        for(int h = 0; h<creatures.size(); h++)
                        {
                            if(creatures[h].getCordinats()==cord && !creatures[h].isDead())
                            {
                                creatures[h]-=5;
                                creatures[i]+=5;
                                break;

                                #ifdef DEBUG_STEP
                                    cout<<i <<" got from "<< h<<endl;
                                #endif
                            }
                        }
                    }
                }
            }
        }
        --creatures[i];
        if(!creatures[i].isDead())
            map.setObject(creatures[i].getCordinats(), creatures[i]);
    }
}