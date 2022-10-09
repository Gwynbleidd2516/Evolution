#include"Step.h"

void Step::doStep(Map & map, vector<Creature> & creatures, Voidness & voidness)
{
    for (int i = 0; i < creatures.size(); ++i)
    {
        for (int r = 0; r < creatures[i].comands.size(); ++r)
        {
            if (creatures[i].comands[r] < 8)
            {
                #ifdef DEBUG_STEP
                cout<<i<<"\t"<<r<<endl;
                #endif
                switch (creatures[i].comands[r])
                {
                case 0:
                    if (map.getObject(creatures[i].getCordinats().x-1, creatures[i].getCordinats().y-1)!=Object::Wall /* || map.getObject(creatures[i].getCordinats().x-1, creatures[i].getCordinats().y-1)!=Object::Creature*/)
                    {
                        map.setObject(creatures[i].getCordinats().x-1, creatures[i].getCordinats().y-1,creatures[i]);
          
                        map.setObject(creatures[i].getCordinats().x, creatures[i].getCordinats().y, voidness);

                        creatures[i].setCordinats(creatures[i].getCordinats().x-1, creatures[i].getCordinats().y-1);
                    }
                    break;
                    break;
                case 1:
                    if (map.getObject(creatures[i].getCordinats().x, creatures[i].getCordinats().y-1)!=Object::Wall /*|| map.getObject(creatures[i].getCordinats().x, creatures[i].getCordinats().y-1)!=Object::Creature*/)
                    {
                        map.setObject(creatures[i].getCordinats().x, creatures[i].getCordinats().y-1,creatures[i]);
                        map.setObject(creatures[i].getCordinats().x, creatures[i].getCordinats().y, voidness);
                        creatures[i].setCordinats(creatures[i].getCordinats().x, creatures[i].getCordinats().y-1);
                    }
                    break;
                    break;
                case 2:
                    if (map.getObject(creatures[i].getCordinats().x+1, creatures[i].getCordinats().y-1)!=Object::Wall /*|| map.getObject(creatures[i].getCordinats().x+1, creatures[i].getCordinats().y-1)!=Object::Creature*/)
                    {
                        map.setObject(creatures[i].getCordinats().x+1, creatures[i].getCordinats().y-1,creatures[i]);
                        map.setObject(creatures[i].getCordinats().x, creatures[i].getCordinats().y, voidness);
                        creatures[i].setCordinats(creatures[i].getCordinats().x+1, creatures[i].getCordinats().y-1);
                    }
                    break;
                    break;
                case 3:
                    if (map.getObject(creatures[i].getCordinats().x+1, creatures[i].getCordinats().y)!=Object::Wall /*|| map.getObject(creatures[i].getCordinats().x+1, creatures[i].getCordinats().y)!=Object::Creature*/)
                    {
                        map.setObject(creatures[i].getCordinats().x+1, creatures[i].getCordinats().y,creatures[i]);
                        map.setObject(creatures[i].getCordinats().x, creatures[i].getCordinats().y, voidness);
                        creatures[i].setCordinats(creatures[i].getCordinats().x+1, creatures[i].getCordinats().y);
                    }
                    break;
                    break;
                case 4:
                    if (map.getObject(creatures[i].getCordinats().x+1, creatures[i].getCordinats().y+1)!=Object::Wall /*|| map.getObject(creatures[i].getCordinats().x+1, creatures[i].getCordinats().y+1)!=Object::Creature*/)
                    {
                        map.setObject(creatures[i].getCordinats().x+1, creatures[i].getCordinats().y+1,creatures[i]);
                        map.setObject(creatures[i].getCordinats().x, creatures[i].getCordinats().y, voidness);
                        creatures[i].setCordinats(creatures[i].getCordinats().x+1, creatures[i].getCordinats().y+1);
                    }
                    break;
                    break;
                case 5:
                    if (map.getObject(creatures[i].getCordinats().x, creatures[i].getCordinats().y+1)!=Object::Wall /*|| map.getObject(creatures[i].getCordinats().x, creatures[i].getCordinats().y+1)!=Object::Creature*/)
                    {
                        map.setObject(creatures[i].getCordinats().x, creatures[i].getCordinats().y+1,creatures[i]);
                        map.setObject(creatures[i].getCordinats().x, creatures[i].getCordinats().y, voidness);
                        creatures[i].setCordinats(creatures[i].getCordinats().x, creatures[i].getCordinats().y+1);
                    }
                    break;
                    break;
                case 6:
                    if (map.getObject(creatures[i].getCordinats().x-1, creatures[i].getCordinats().y+1)!=Object::Wall /*|| map.getObject(creatures[i].getCordinats().x-1, creatures[i].getCordinats().y+1)!=Object::Creature*/)
                    {
                        map.setObject(creatures[i].getCordinats().x-1, creatures[i].getCordinats().y+1,creatures[i]);
                        map.setObject(creatures[i].getCordinats().x, creatures[i].getCordinats().y, voidness);
                        creatures[i].setCordinats(creatures[i].getCordinats().x-1, creatures[i].getCordinats().y+1);
                    }
                    break;
                    break;
                case 7:
                    if (map.getObject(creatures[i].getCordinats().x-1, creatures[i].getCordinats().y)!=Object::Wall /*|| map.getObject(creatures[i].getCordinats().x-1, creatures[i].getCordinats().y)!=Object::Creature*/)
                    {
                        map.setObject(creatures[i].getCordinats().x-1, creatures[i].getCordinats().y, creatures[i]);
                        map.setObject(creatures[i].getCordinats().x, creatures[i].getCordinats().y, voidness);
                        creatures[i].setCordinats(creatures[i].getCordinats().x-1, creatures[i].getCordinats().y);
                    }
                    break;
                    break;
                }
            }
        }
    }
}