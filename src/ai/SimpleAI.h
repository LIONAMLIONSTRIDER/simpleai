/**
 * @mainpage SimpleAI documentation
 *
 * @section purpose Purpose
 *
 * SimpleAI is a small C++ AI behaviour tree library
 *
 * @section legal Legal
 *
 * Copyright (C) 2014 Martin Gerhardy <martin.gerhardy@gmail.com>
 *
 * This software is provided 'as-is', without any express or implied
 * warranty.  In no event will the authors be held liable for any damages
 * arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software. If you use this software
 *    in a product, an acknowledgment in the product documentation would be
 *    appreciated but is not required.
 * 2. Altered source versions must be plainly marked as such, and must not be
 *    misrepresented as being the original software.
 * 3. This notice may not be removed or altered from any source distribution.
 */

/**
 * @file
 *
 * Main header file that you should include when you use SimpleAI.
 */
#pragma once

#include "common/Compiler.h"

#include "AI.h"
#include "AIRegistry.h"
#include "ICharacter.h"

#include "tree/TreeNode.h"
#include "tree/ITask.h"
#include "tree/ITimedNode.h"
#include "tree/TreeNodeParser.h"
#include "tree/Sequence.h"
#include "tree/Idle.h"
#include "tree/loaders/lua/LUATreeLoader.h"

#include "pathfinding/IMap.h"
#include "pathfinding/IPathfinder.h"

#include "server/Server.h"
#include "server/IProtocolHandler.h"
#include "server/ProtocolHandlerRegistry.h"
#include "server/ProtocolMessageFactory.h"
#include "server/AICharacterDetailsMessage.h"
#include "server/AIPauseMessage.h"
#include "server/AISelectMessage.h"
#include "server/AIStateMessage.h"

#include "conditions/ICondition.h"
#include "conditions/ConditionParser.h"
#include "conditions/True.h"
