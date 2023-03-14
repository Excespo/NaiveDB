#include "query/execution/executor/projection_executor.h"

#include "query/expr/expr.h"
#include "storage/tuple/tuple.h"
#include "type/value.h"

namespace naivedb::query {
void ProjectionExecutor::init() {
    // TODO(Project-1): Implement this method
    child_plan_ = plan_->child();
    child_executor_ = child_at(0);
    child_executor_->init();
}

std::vector<storage::Tuple> ProjectionExecutor::next() {
    // TODO(Project-1): Implement this method
    const catalog::Schema *child_schema = child_plan_->output_schema();
    std::vector<storage::Tuple> child_tuples = child_executor_->next();
    if (!child_tuples.empty()) {
        std::vector<type::Value> values;
        // ATTENTION cannot copy unique_ptr
        // including a vector of type unique_ptr
        // use reference to visit them
        for (auto const &expr : plan_->project_exprs()) {
            type::Value value = expr->evaluate(child_tuples[0], child_schema);
            values.emplace_back(value);
        }
        storage::Tuple tuple(std::move(values));
        return make_vector(std::move(tuple));
    }
    return {};
}
}  // namespace naivedb::query