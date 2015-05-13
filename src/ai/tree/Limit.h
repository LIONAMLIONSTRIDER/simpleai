#pragma once

#include "tree/TreeNode.h"
#include "common/Types.h"
#include "AIRegistry.h"

namespace ai {

/**
 * @brief A decorator node which limits the execution of the attached child to a
 * specified amount of runs.
 *
 * @note If the configured amount is reached, the return @c TreeNodeStatus is
 * @c TreeNodeStatus::FINISHED
 */
class Limit: public TreeNode {
private:
	int _amount;

	Limit(const std::string& name, const std::string& parameters, const ConditionPtr& condition) :
		TreeNode(name, parameters, condition) {
		_type = "Limit";
		if (!parameters.empty())
			_amount = ::atoi(parameters.c_str());
		else
			_amount = 1;
	}
public:
	NODE_FACTORY

	TreeNodeStatus execute(const AIPtr& entity, long deltaMillis) override {
		if (_children.size() != 1) {
			ai_assert(false, "Limit can not have more than one child");
		}

		if (TreeNode::execute(entity, deltaMillis) == CANNOTEXECUTE)
			return CANNOTEXECUTE;

		const int alreadyExecuted = getLimitState(entity);
		if (alreadyExecuted >= _amount)
			return state(entity, FINISHED);

		const TreeNodePtr& treeNode = *_children.begin();
		const TreeNodeStatus status = treeNode->execute(entity, deltaMillis);
		setLimitState(entity, alreadyExecuted + 1);
		if (status == RUNNING)
			return state(entity, RUNNING);
		return state(entity, FAILED);
	}
};

}