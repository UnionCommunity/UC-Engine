#include "Utils.h"
#pragma once

namespace eng
{

class Component;

//component
class Serializable
{
  public:

    virtual json Serialize()
    {
        json j;
        return j;
    };

    virtual void Deserialize(json s){};
};
} // namespace eng