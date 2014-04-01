#pragma once

#include "tree/ITask.h"
#include "common/String.h"
#include "group/GroupMgr.h"

namespace ai {

/**
 * Follow a particular group to its average position
 */
class FollowGroup: public ITask {
protected:
	GroupId _groupId;
public:
	TASK_CLASS_CTOR(FollowGroup) {
		if (_parameters.empty()) {
			_groupId = -1;
		} else {
			_groupId = Str::toInt(_parameters);
		}
	}
	NODE_FACTORY

	TreeNodeStatus doAction(AI& entity, long deltaMillis) override;
};

}