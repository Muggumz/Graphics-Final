#include "Gameplay/Components/Winning.h"
#include "Gameplay/Components/ComponentManager.h"
#include "Gameplay/GameObject.h"


Winning::Winning() :
	IComponent()
{ }
Winning::~Winning() = default;

void Winning::OnTriggerVolumeEntered(const std::shared_ptr<Gameplay::Physics::RigidBody>&trigger)
{
		std::cout << "You win!!" << std::endl;
		std::cout << "Game have Reset!!" << std::endl;
		trigger->GetGameObject()->SetPostion(glm::vec3(1.5f, 0.0f, 1.0f));
}

void Winning::OnTriggerVolumeLeaving(const std::shared_ptr<Gameplay::Physics::RigidBody>&trigger) 
{
	
}

void Winning::RenderImGui() { }

nlohmann::json Winning::ToJson() const {
	return { };
}

Winning::Sptr Winning::FromJson(const nlohmann::json & blob) {
	Winning::Sptr result = std::make_shared<Winning>();
	return result;
}