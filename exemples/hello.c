
#include "6ecs9.h"
#include <stdio.h>

// newComp(compName, type)
// newCompStruct(compName, newType)
//   example: newCompStruct(Position, { float x, y; });
// newProp(compName) // just property (no data needed)

newComp(Name, char*);
newComp(Age, int);
newProp(Human);
newProp(Dog);

// system
void Talk(void)
{
  // iterate all entities with those components
  Iter(Human, Name, Age)
  {
    usingComp(Name, name); // using the "Name" component as name
    usingComp(Age, age); // using the "Age" component as age
    printf("hii im %s n im %u\n", name, age);
  }
}

void Bark(void)
{
  Iter(Dog, Name)
  {
    usingComp(Name, name);
    printf("%s is barkin hide\n", name);
  }
}

void GetOld(void)
{
    Iter(Age)
    {
        // usingMutComp get the address (pointer) of the variable so it can be changed
        usingMutComp(Age, age);
        (*age)++;
    }
}

int main(void)
{
  newEntity() // create new entity
    is(Human) // with Human prop
    with(Name, "nmrood") // with name comp
    with(Age, 20); // and age

// i stored the newEntity() in a var so im gonna change it later
  unsigned int gonnaBeChanged = newEntity()
    is(Human)
    with(Name, "noAge");
  newEntity()
    is(Dog)
    with(Name, "TREX");

  Talk(); // system for entities with name, age, human
  Bark();
  GetOld();
  // ima add age comp so talk system can use it
  addComp(gonnaBeChanged, Age, 69);
  Talk();

  return 0;
}
