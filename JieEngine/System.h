#pragma once

#include "JieEngine.h"
#include "Entity.h"

void SystemUpdate(std::vector<std::shared_ptr<Entity>> EntityVector);

void MeshSystem(std::vector<std::shared_ptr<Entity>> EntityVector);

void RigidbodySystem(std::vector<std::shared_ptr<Entity>> EntityVector);