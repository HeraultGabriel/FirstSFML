#include "CollisionSystem.h"
#include "GameObject.h"

bool CollisionSystem::Check(GameObject& _other)
{
	const float& _xOtherMin = _other.GetColliderSize().position.x;
	const float& _xOtherMax = _xOtherMin + _other.GetColliderSize().size.x;

	const float& _xThisMin = this->GetColliderSize().position.x;
	const float& _xThisMax = _xThisMin + this->GetColliderSize().size.x;

	//Y

	const float& _yOtherMin = _other.GetColliderSize().position.y;
	const float& _yOtherMax = _yOtherMin + _other.GetColliderSize().size.y;

	const float& _yThisMin = this->GetColliderSize().position.y;
	const float& _yThisMax = _yThisMin + this->GetColliderSize().size.y;

	return _xOtherMax >= _xThisMin && _xOtherMin <= _xThisMax &&
		_yOtherMax >= _yThisMin && _yOtherMin <= _yThisMax;
	
}
