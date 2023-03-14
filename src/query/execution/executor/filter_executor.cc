#include "query/execution/executor/filter_executor.h"

#include "storage/tuple/tuple.h"
#include "type/value.h"

namespace naivedb::query {
void FilterExecutor::init() {
    // TODO(Project-1): Implement this method'
    child_plan_ = plan_->child();
    child_executor_ = child_at(0);  // Method in FilterExecutor, inherited from Executor
    child_executor_->init();
}

std::vector<storage::Tuple> FilterExecutor::next() {
    // TODO(Project-1): Implement this method
    const catalog::Schema *schema = child_plan_->output_schema();
    const Expr *predicate = plan_->predicate();
    if (predicate == nullptr)
        return {};
    std::vector<storage::Tuple> child_tuples;
    while (!(child_tuples = child_executor_->next()).empty()) {
        if (predicate->evaluate(child_tuples[0], schema).as<bool>())
            return child_tuples;
    }
    // return child_executor_->next();
    return {};
}
}  // namespace naivedb::query