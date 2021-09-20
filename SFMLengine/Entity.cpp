#include "Entity.h"

void Entity::logic()
{
	get<BPhysComponent*>()->gravity(pos);
	get<ShapeComponent*>()->set(pos);
}
