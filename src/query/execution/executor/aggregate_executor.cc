#include "query/execution/executor/aggregate_executor.h"

#include "common/macros.h"
#include "common/utils.h"
#include "storage/tuple/tuple.h"
#include "type/value.h"

namespace naivedb::query {
void AggregateExecutor::init() {
    // TODO(Project-1): Implement this method
    child_executor_ = child_at(0);
    child_executor_->init();
}

std::vector<storage::Tuple> AggregateExecutor::next() {
    // TODO(Project-1): Implement this method
    const catalog::Schema *schema = plan_->child()->output_schema();
    std::vector<storage::Tuple> tuples;
    if (!(tuples = child_executor_->next()).empty()) {
        std::vector<type::Value> values;
        for (auto const &expr : plan_->aggregate_exprs()) {
            values.emplace_back(expr->evaluate_aggregate(std::move(tuples), schema));
        }
        return make_vector(std::move(storage::Tuple(std::move(values))));
    }

    return {};
}
}  // namespace naivedb::query