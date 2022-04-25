#pragma once
#include "IComponent.h"
#include "Gameplay/Physics/TriggerVolume.h"
#include "Gameplay/Components/RenderComponent.h"
#include "Gameplay/Physics/TriggerVolume.h"
//#include "Gameplay/Physics/RigidBody.h"

class Winning : public Gameplay::IComponent {
public:
	typedef std::shared_ptr<Winning> Sptr;
	Winning();
	virtual ~Winning();

	Gameplay::GameObject* EnemyObj;
	Gameplay::Physics::RigidBody::Sptr rigidOBJ;

	// Inherited from IComponent
	virtual void OnTriggerVolumeEntered(const std::shared_ptr<Gameplay::Physics::RigidBody>& body) override;
	virtual void OnTriggerVolumeLeaving(const std::shared_ptr<Gameplay::Physics::RigidBody>& body) override;

	virtual void RenderImGui() override;
	virtual nlohmann::json ToJson() const override;
	static Winning::Sptr FromJson(const nlohmann::json& blob);


	MAKE_TYPENAME(Winning);
};

